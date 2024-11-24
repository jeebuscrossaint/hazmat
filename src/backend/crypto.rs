use base64::{engine::general_purpose::URL_SAFE, Engine as _};

pub fn to_base64(input: &str) -> String {
    URL_SAFE.encode(input.as_bytes())
}

pub fn from_base64(input: &str) -> Result<String, base64::DecodeError> {
    let decoded = URL_SAFE.decode(input)?;
    String::from_utf8(decoded).map_err(|_| base64::DecodeError::InvalidByte(0, 0))
}

pub fn master_key_generate() {}

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
