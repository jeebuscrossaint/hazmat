mod frontend {
    pub mod help;
    pub mod initialize;
}

mod backend {
    pub mod parser;
}

use backend::parser;
use frontend::{help, initialize};

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
    } else {
        // export command work
        let _subcommand = &_args[2];
        if _command == "export" && _subcommand == "help" {
            help::export_help();
        }
        if _command == "export" {
            parser::export(_subcommand);
        }
        if _command == "import" {
            match parser::import(_subcommand) {
                Ok(entries) => {
                    println!("Succesfully imported {} entries,", entries.len());
                    // idk do smthin
                }
                Err(e) => println!("Error importing file: {}", e),
            }
        }
    }
}
