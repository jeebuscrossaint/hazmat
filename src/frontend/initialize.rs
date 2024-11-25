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
    println!("Your passworud must be at least 15 characters long, and a max of 64 characters long, as specified by the NIST. (National Institute of Standards and Technology)\n Always remember, some of the best security comes from physical security as well, so maybe write your master password down somewhere, maybe write it in a different base too, and maybe keep a sharp object close by or even a firearm. You never know.");
    println!(
        "\x1b[1mTheir specifications are:\x1b[0m\n
        \x1b[1m- minimum of 15 characters, maximum of 64 characters\x1b[0m\n
        \x1b[1m- accept all printable ASCII characters including spaces\x1b[0m\n
        \x1b[1m- accept all Unicode/ISO/ISC 10646 characters. Each point will count as a single character\x1b[0m\n
        \x1b[1m- will not impose composition rules for passwords\x1b[0m\n
        \x1b[1m- will not require users to change passwords arbitrarily\x1b[0m\n
        \x1b[1m- will not permit a master password hint\x1b[0m\n
        \x1b[1m- will not permit usage of KBA (Knowledge Based Authentication) for password recovery\x1b[0m\n
        \x1b[1m- will verify the entire submitted password\x1b[0m\n"
    );
    print!("Do you understand these requirements? (y/n) ");
    std::io::stdout().flush().unwrap();

    let mut response = String::new();
    std::io::stdin().read_line(&mut response).unwrap();
    if response.trim() != "y" {
        println!("You must understand the requirements to continue.");
        return;
    }
    if response.trim() == "y" {
        println!("Please enter your master password: ");
        std::io::stdout().flush().unwrap();
        let master = read_password().unwrap();
        //dbg
        //println!("The master password is: {}", master);
        let masterkeyfile = env::var("HOME").unwrap() + "/.hazmat/masterkey";
        let mut file = fs::File::create(masterkeyfile).unwrap();
        write!(file, "{}", master).unwrap();
        // supposede to call another function to do all the crypto setup for master pass
    }
    return;
}
