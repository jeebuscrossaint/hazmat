use colored::*;
use std::env;
use std::fs;

pub fn crush() {
    fs::remove_dir_all(env::var("HOME").unwrap() + "/.hazmat").unwrap();
    println!("{} {}", "Crushed hazmat.".green(), "Goodluck.".red());
}
