// https://projecteuler.net/problem/59
//
// Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
// A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
// For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.
// Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.
// Your task has been made easy, as the encryption key consists of three lower case characters. Using 0059_cipher.txt (right click and 'Save Link/Target As...), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.
//
// Answer: 129448

use std::fs;

pub fn xor_decryption() -> u32 {
    // Read cipher data
    let cipher_path = "../python/data/p059_cipher.txt";
    let cipher_str = fs::read_to_string(cipher_path).expect("Failed to read cipher file");
    let cipher: Vec<u8> = cipher_str.trim().split(',').map(|s| s.trim().parse().unwrap()).collect();

    // Common words to check
    let common_words = ["the", "and", "of", "to", "a", "in", "that", "is", "was", "it", "for", "on", "with", "as", "by"];

    let mut max_word_count = 0;
    let mut best_sum = 0u32;

    for i in 0..26 {
        for j in 0..26 {
            for k in 0..26 {
                let key = [b'a' + i as u8, b'a' + j as u8, b'a' + k as u8];
                let decrypted: Vec<u8> = cipher.iter().enumerate().map(|(m, &c)| c ^ key[m % 3]).collect();
                // Check if all printable ASCII
                if decrypted.iter().all(|&c| c >= 32 && c <= 126) {
                    let text = String::from_utf8_lossy(&decrypted);
                    let word_count: usize = common_words.iter().map(|&word| text.to_lowercase().matches(word).count()).sum();
                    if word_count > max_word_count {
                        max_word_count = word_count;
                        best_sum = decrypted.iter().map(|&c| c as u32).sum();
                    }
                }
            }
        }
    }
    best_sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_059() {
        assert_eq!(xor_decryption(), 129448);
    }
}