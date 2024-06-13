 use crossterm::event::{DisableMouseCapture, EnableMouseCapture, Event,  MouseEventKind};
use crossterm::terminal::{disable_raw_mode, enable_raw_mode, EnterAlternateScreen, LeaveAlternateScreen};
use crossterm::ExecutableCommand;
use std::io::stdout;
use tui::backend::CrosstermBackend;
use tui::layout::{Constraint, Direction, Layout, Rect};
use tui::style::{Color, Modifier, Style};
use tui::text::Text;
use tui::widgets::{Block, Borders, Paragraph};
use tui::Terminal;
use crossterm::event::{poll, read, KeyCode, KeyModifiers};
use std::time::Duration;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Enable raw mode and alternate screen
    let mut stdout = stdout();
    stdout.execute(EnterAlternateScreen)?;
    enable_raw_mode()?;
    stdout.execute(EnableMouseCapture)?;

    let backend = CrosstermBackend::new(stdout);
    let mut terminal = Terminal::new(backend)?;

    let mut button_area = Rect::default();
    let mut display_text = "Click the button";

    terminal.draw(|f| {
        let chunks = Layout::default()
            .direction(Direction::Vertical)
            .margin(1)
            .constraints([Constraint::Percentage(50), Constraint::Percentage(50)].as_ref())
            .split(f.size());

        let button = Block::default()
            .title("Click me")
            .borders(Borders::ALL)
            .style(Style::default().fg(Color::White).bg(Color::Black).add_modifier(Modifier::BOLD));
        f.render_widget(button, chunks[0]);
        button_area = chunks[0];

        let text = Text::raw(display_text);
        let block = Block::default().borders(Borders::ALL).title("TUI");
        let paragraph = Paragraph::new(text).block(block).style(Style::default().fg(Color::White).bg(Color::Black));

        f.render_widget(paragraph, chunks[1]);
    })?;

    // Wait for Ctrl+C or button click
    loop {
        if poll(Duration::from_millis(100))? {
            if let Event::Mouse(mouse_event) = read()? {
                match mouse_event.kind {
                    MouseEventKind::Down(_) => {
                        if (mouse_event.column >= button_area.left())
                            && (mouse_event.column <= button_area.right())
                            && (mouse_event.row >= button_area.top())
                            && (mouse_event.row <= button_area.bottom())
                        {
                            display_text = "Hello, World!";
                            terminal.draw(|f| {
                                let chunks = Layout::default()
                                    .direction(Direction::Vertical)
                                    .margin(1)
                                    .constraints([Constraint::Percentage(50), Constraint::Percentage(50)].as_ref())
                                    .split(f.size());

                                let button = Block::default()
                                    .title("Click me")
                                    .borders(Borders::ALL)
                                    .style(Style::default().fg(Color::White).bg(Color::Black).add_modifier(Modifier::BOLD));
                                f.render_widget(button, chunks[0]);

                                let text = Text::raw(display_text);
                                let block = Block::default().borders(Borders::ALL).title("TUI");
                                let paragraph = Paragraph::new(text).block(block).style(Style::default().fg(Color::White).bg(Color::Black));

                                f.render_widget(paragraph, chunks[1]);
                            })?;
                        }
                    },
                    _ => {}
                }
            }
            if let Event::Key(key_event) = read()? {
                if key_event.code == KeyCode::Char('c') && key_event.modifiers == KeyModifiers::CONTROL {
                    break;
                }
            }
        }
    }

    // Disable raw mode and alternate screen
    terminal.backend_mut().execute(LeaveAlternateScreen)?;
    disable_raw_mode()?;
    terminal.backend_mut().execute(DisableMouseCapture)?;

    Ok(())
}

