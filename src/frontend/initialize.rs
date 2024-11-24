use std::env;
use std::fs;
use std::io::Write;

extern crate rpassword;

use rpassword::read_password;

pub fn check_hazmat() {
    let home = env::var("HOME").unwrap();
    let hazmat_dir = home.clone() + "/.hazmat";
    if !fs::metadata(&home).is_ok() {
        panic!("What are you, homeless?");
    }
    if !fs::metadata(&hazmat_dir).is_ok() {
        fs::create_dir(hazmat_dir.clone()).unwrap();
        println!("Hazmat directory created at: {}", hazmat_dir);
        create_master();
        //        crypto::master_key_generate();
        return;
    }
    if fs::metadata(&hazmat_dir).is_ok() {
        println!("Hazmat directory found at: {}", hazmat_dir);
    }
}

fn create_master() {
    // should return a string
    println!("This is your first time using Hazmat. Please create a master password.");
    println!("Remember, if you forget this password, you will lose access to everything. The only option you will have is to crush.");
    println!("Your passworud must be at least 15 characters long, and a max of 64 characters long, as specified by the NIST. (National Institute of Standards and Technology");
    println!(
        "Their specfications are: \n
        - minimum of 15 characters, maximum of 64 characters\n
        - accept all printable ASCII characters including spaces\n
        - accept all Unicode/ISO/ISC 10646 characters. Each point will count as a single character\n
        - will not impose composition rules for passwords\n
        - will not require users to change passwords arbitrarily\n
        - will not permit a master password hint\n
        - will not permit usage of KBA (Knowledge Based Authentication) for password recovery\n
        - will verify the entire submitted password\n"
    );
    println!("Do you understand these requirements? (y/n)");
    let mut response = String::new();
    std::io::stdin().read_line(&mut response).unwrap();
    if response.trim() != "y" {
        println!("You must understand the requirements to continue.");
        return;
    }
    if response.trim() == "y" {
        std::io::stdout().flush().unwrap();
        let master = read_password().unwrap();
        //dbg
        println!("The master password is: {}", master);
        // supposede to call another function to do all the crypto setup for master pass
    }
    return;
}
