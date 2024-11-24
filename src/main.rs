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
    let _args: Vec<String> = env::args().collect();
    //dbg!(_args);
    if _args.len() <= 1 {
        help::show_help();
        return;
    }
    let _command = &_args[1];
    if _command == "help" {
        help::show_help();
    } else if _command == "crush" {
        danger::crush();
    } else if _command == "export" {
        if _args.len() > 2 {
            let _subcommand = &_args[2];
            if _subcommand == "help" {
                help::export_help();
            } else {
                parser::export(_subcommand);
            }
        } else {
            println!("Error: Missing subcommand for export.");
        }
    } else if _command == "import" {
        if _args.len() > 2 {
            let _subcommand = &_args[2];
            match parser::import(_subcommand) {
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
        println!("Error: Unrecognized command '{}'", _command);
        help::show_help();
    }
}
