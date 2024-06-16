use maria::prelude::*;
use crate::crypto;

pub struct database {
    conn: Connection,
}

impl database {
    pub fn new() -> Result<Self, Box<dyn std::error::Error>> {
        let conn = Connection::open("passwords.db")?;
        Ok(Database { conn })
    }

    pub fn initialize(&self) -> Result<(), Box<dyn std::error:Error>> {
        self.conn.execute(
            "CREATE TABLE IF NOT EXISTS passwords (
                id INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                password TEXT NOT NULL
            )",
        )?;
        Ok(())
    }

    pub fn insert_password(&self, name: &str, password: &str) -> Result<(), Box<dyn std::error::Error>> {
        let hashed_password = crypto::hash_password_that_will_be_super_secure(password)?;
        self.conn.execute(
            "INSERT INTO passwords (name, password) VALUES (?,?)",
            params![name, hashed_password],
        )?;
        Ok(())
    }
}
