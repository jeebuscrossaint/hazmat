use csv::Reader;
use std::error::Error;

#[derive(Debug)]
pub struct PasswordEntry {
    pub url: String,
    pub username: String,
    pub password: String,
    pub time_created: String,
    pub time_last_used: String,
    pub time_password_changed: String,
}

pub fn import(filename: &str) -> Result<Vec<PasswordEntry>, Box<dyn Error>> {
    let mut rdr = Reader::from_path(filename)?;
    let mut entries = Vec::new();

    if filename.ends_with("csv") {
        for result in rdr.records() {
            let record = result?;
            let entry = PasswordEntry {
                url: record[0].to_string(),
                username: record[1].to_string(),
                password: record[2].to_string(),
                time_created: record[6].to_string(),
                time_last_used: record[7].to_string(),
                time_password_changed: record[8].to_string(),
            };
            entries.push(entry);
        }
    } else {
        println!("Error: Import file must have .csv extension.");
    }
    Ok(entries)
}

pub fn export(filename: &str) {
    if filename.ends_with(".csv") {
    } else {
        println!("Error: export file must have .csv extension.");
    }
}
