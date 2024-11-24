use std::env;
use std::fs;

use crate::backend::crypto;

pub fn check_hazmat() {
    let home = env::var("HOME").unwrap();
    let hazmat_dir = home.clone() + "/.hazmat";
    if !fs::metadata(&home).is_ok() {
        panic!("What are you, homeless?");
    }
    if !fs::metadata(&hazmat_dir).is_ok() {
        fs::create_dir(hazmat_dir.clone()).unwrap();
        println!("Hazmat directory created at: {}", hazmat_dir);
        crypto::master_key_generate();
        return;
    }
    if fs::metadata(&hazmat_dir).is_ok() {
        println!("Hazmat directory found at: {}", hazmat_dir);
    }
}
