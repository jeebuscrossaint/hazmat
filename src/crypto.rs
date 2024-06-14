use argon2rs::{Argon2, Variant};
use rand::Rng;

pub fn hash_password_that_will_be_super_secure(password: &str) -> Result<String, &'static str> {
    // gen salt 
    let salt: [u8; 16] = rand::thread_rng().gen();

    // use alg (argon2) to hash
    let argon2 = Argon2::new(2, 8, 1<<16, Variant::Argon2id).unwrap();
    let mut hashed_password = [0u8; 32];
    argon2.hash(&mut hashed_password, password.as_bytes(), &salt, &[], &[]);

    // convert hash to string 
    let hashed_password_str = base64::encode(&hashed_password);

    Ok(hashed_password_str)
}
