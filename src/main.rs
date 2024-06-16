mod app;
mod tui;
mod db;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let db = db::Database::new()?;
    db.initialize()?;

    let super_obfuscated_password_that_no_one_will_ever_guess = app::create_master_password()?;
    tui::run(super_obfuscated_password_that_no_one_will_ever_guess)
}
