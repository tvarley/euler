// https://projecteuler.net/problem=59

// XOR Decryption

// Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107. A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65. For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message. Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable. Your task has been made easy, as the encryption key consists of three lower case characters. Using 0059_cipher.txt (right click and 'Save Link/Target As...), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.

// Answer: 129448

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <sstream>

int xor_decryption() {
    std::vector<uint8_t> cipher;
    std::ifstream cipher_file("src/059_cipher.txt");
    if (!cipher_file) {
        std::cerr << "Error opening 059_cipher.txt" << std::endl;
        return 0;
    }
    std::string line;
    std::getline(cipher_file, line);
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ',')) {
        cipher.push_back(std::stoi(token));
    }

    std::vector<std::string> common_words;
    std::ifstream words_file("src/059_common_words.txt");
    if (!words_file) {
        std::cerr << "Error opening 059_common_words.txt" << std::endl;
        return 0;
    }
    std::string word;
    while (std::getline(words_file, word)) {
        if (!word.empty()) {
            common_words.push_back(word);
        }
    }
    
    int max_word_count = 0;
    int best_sum = 0;
    
    for (char k1 = 'a'; k1 <= 'z'; ++k1) {
        for (char k2 = 'a'; k2 <= 'z'; ++k2) {
            for (char k3 = 'a'; k3 <= 'z'; ++k3) {
                std::string decrypted;
                for (size_t i = 0; i < cipher.size(); ++i) {
                    char key_char = (i % 3 == 0) ? k1 : (i % 3 == 1) ? k2 : k3;
                    char c = cipher[i] ^ key_char;
                    decrypted += c;
                }
                // Check for printable ASCII
                bool valid = true;
                for (char c : decrypted) {
                    if (c < 32 || c > 126) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
                int word_count = 0;
                for (const auto& word : common_words) {
                    size_t pos = 0;
                    while ((pos = decrypted.find(word, pos)) != std::string::npos) {
                        ++word_count;
                        pos += word.length();
                    }
                }
                int sum = 0;
                for (char c : decrypted) {
                    sum += static_cast<unsigned char>(c);
                }
                if (word_count > max_word_count) {
                    max_word_count = word_count;
                    best_sum = sum;
                }
            }
        }
    }
    return best_sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << xor_decryption() << std::endl;
}
#endif // UNITTEST_MODE