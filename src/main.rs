mod frontend {
    pub mod danger;
    pub mod help;
    pub mod initialize;
}

mod backend {
    pub mod crypto;
    pub mod parser;
}

use backend::parser;
use frontend::{danger, help, initialize};

use std::env;

fn main() {
    initialize::check_hazmat();
    let args: Vec<String> = env::args().collect();
    //dbg!(args);
    if args.len() <= 1 {
        help::show_help();
        return;
    }
    let command = &args[1];
    if command == "help" {
        help::show_help();
    } else if command == "crush" {
        danger::crush();
    } else if command == "export" {
        if args.len() > 2 {
            let subcommand = &args[2];
            if subcommand == "help" {
                help::export_help();
            } else {
                parser::export(subcommand);
            }
        } else {
            println!("Error: Missing subcommand for export.");
        }
    } else if command == "import" {
        if args.len() > 2 {
            let subcommand = &args[2];
            match parser::import(subcommand) {
                Ok(entries) => {
                    println!("Successfully imported {} entries,", entries.len());
                    // idk do smthin
                }
                Err(e) => println!("Error importing file: {}", e),
            }
        } else {
            println!("Error: Missing subcommand for import.");
        }
    } else {
        println!("Error: Unrecognized command '{}'", command);
        help::show_help();
    }
}
