use base64::{engine::general_purpose::URL_SAFE, Engine as _};
use rand::distributions::{Alphanumeric, DistString, Uniform};
use rand::Rng;

pub fn to_base64(input: &str) -> String {
    URL_SAFE.encode(input.as_bytes())
}

pub fn from_base64(input: &str) -> Result<String, base64::DecodeError> {
    let decoded = URL_SAFE.decode(input)?;
    String::from_utf8(decoded).map_err(|_| base64::DecodeError::InvalidByte(0, 0))
}

pub fn random_gen() {
    // adheres to NIST specifications
    let mut rng = rand::thread_rng();
    let mut charset = Vec::new();

    // printable ascii characters
    for c in 32..=126 {
        charset.push(c as u8);
    }

    // explicitely add space
    charset.push(b' ');

    // unicode characters that are printable
    for i in 0x20..=0x7E {
        if let Some(c) = char::from_u32(i) {
            // limit characters to those that are printable
            if c.is_ascii() || c.is_whitespace() || c.is_alphanumeric() {
                charset.push(c as u8);
            }
        }
    }

    let len: usize = rng.gen_range(15..=64);

    // generate the string finally
    let random_string: String = (0..len)
        .map(|_| {
            let idx = rng.gen_range(0..charset.len());
            charset[idx] as char
        })
        .collect();
    println!("String length: {}", len);
    println!("{}", random_string);
}

pub fn master_key_generate(master: &str) {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_base64_roundtrip() {
        let original = "Hello, world!";
        let encoded = to_base64(original);
        let decoded = from_base64(&encoded).unwrap();
    }
}
