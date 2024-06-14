use std::time::{Instant, Duration};
use std::thread::sleep;
use std::env;

mod crypto;

pub fn create_master_password() -> Result<String, &'static str> {
    // Examine if the master password has been made prior to now.
    if let Ok(master_password) = env::var("MASTER_PASSWORD") {
        return Ok(master_password);
    }

    // If not, prompt.
    env::set_var("MASTER_PASSWORD", &master_password);

    Ok(master_password)
}

pub fn check_inactivity_security_measure() -> bool {
    let now = Instant::now();
    while now.elapsed() < Duraction::from_secs(300) {
        sleep(Duration::from_secs(1));
    }
    true
}
