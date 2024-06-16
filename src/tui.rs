use crossterm::event::{DisableMouseCapture, EnableMouseCapture, Event,  MouseEventKind};
use crossterm::terminal::{disable_raw_mode, enable_raw_mode, EnterAlternateScreen, LeaveAlternateScreen};
use crossterm::ExecutableCommand;
use std::io::stdout;
use tui::backend::CrosstermBackend;
use tui::Terminal;
use crossterm::event::{poll, read, KeyCode, KeyModifiers};
use std::time::{Instant, Duration};
use std::thread::sleep;

use crate::app;

pub fn run(master_password: String) -> Result<(), Box<dyn std::error::Error>> {
    // Enable raw mode and alternate screen
    let mut stdout = stdout();
    stdout.execute(EnterAlternateScreen)?;
    enable_raw_mode()?;
    stdout.execute(EnableMouseCapture)?;

    let backend = CrosstermBackend::new(stdout);
    let mut terminal = Terminal::new(backend)?;

    // TUI code goes here

    // Wait for Ctrl+C or button click
    loop {
        if poll(Duration::from_millis(100))? {
            // ...

            if let Event::Key(key_event) = read()? {
                if key_event.code == KeyCode::Char('c') && key_event.modifiers == KeyModifiers::CONTROL {
                    break;
                }
            }
        }

        // If the user is idle for 5 minutes, log the user out
        if app::check_inactivity() {
            println!("You have been logged out due to inactivity.");
            break;
        }
    }

    // Disable raw mode and alternate screen
    terminal.backend_mut().execute(LeaveAlternateScreen)?;
    disable_raw_mode()?;
    terminal.backend_mut().execute(DisableMouseCapture)?;

    Ok(())
}
