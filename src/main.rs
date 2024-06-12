
use crossterm::event::{DisableMouseCapture, EnableMouseCapture};
use crossterm::terminal::{disable_raw_mode, enable_raw_mode, EnterAlternateScreen, LeaveAlternateScreen};
use crossterm::ExecutableCommand;
use std::io::stdout;
use tui::backend::CrosstermBackend;
use tui::layout::{Constraint, Direction, Layout};
use tui::style::{Color, Style};
use tui::text::Text;
use tui::widgets::{Block, Borders, Paragraph};
use tui::Terminal;
use crossterm::event::{poll, read, Event, KeyCode, KeyModifiers};
use std::time::Duration;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Enable raw mode and alternate scree # 
    let mut stdout = stdout();
    stdout.execute(EnterAlternateScreen)?;
    enable_raw_mode()?;
    stdout.execute(EnableMouseCapture)?;

    let backend = CrosstermBackend::new(stdout);
    let mut terminal = Terminal::new(backend)?;

    terminal.draw(|f| {
        let chunks = Layout::default()
            .direction(Direction::Vertical)
            .margin(1)
            .constraints([Constraint::Percentage(100)].as_ref())
            .split(f.size());

        let text = Text::raw("Hello, World!");
        let block = Block::default().borders(Borders::ALL).title("TUI");
        let paragraph = Paragraph::new(text).block(block).style(Style::default().fg(Color::White).bg(Color::Black));

        f.render_widget(paragraph, chunks[0]);
    })?;

    // Wait for Ctrl+C
    loop {
        if poll(Duration::from_millis(100))? {
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

