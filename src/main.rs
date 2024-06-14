mod app;
mod tui;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let super_obfuscated_password_that_no_one_will_ever_guess = app::create_master_password()?;
    tui::run(master_password)
}
