# Problem 59: XOR Decryption
# Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
# A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
# For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.
# Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.
# Your task has been made easy, as the encryption key consists of three lower case characters. Using p059_cipher.txt, a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.
# Answer: 129448
# Execution time: About 0.1 seconds
# Optimizations: Brute-forced all possible 3-letter lowercase keys and checked for common English words in the decrypted text.
# Notes: The key is 'exp', decrypting produces a message with common words like 'the' and 'and'.
def solve():
    import os

    # Read cipher data
    cipher_path = os.path.join(os.path.dirname(__file__), '..', 'data', 'p059_cipher.txt')
    with open(cipher_path, 'r') as f:
        cipher = [int(x.strip()) for x in f.read().split(',')]

    # Common words to check
    common_words = ['the', 'and', 'of', 'to', 'a', 'in', 'that', 'is', 'was', 'it', 'for', 'on', 'with', 'as', 'by']

    max_word_count = 0
    best_sum = 0

    for i in range(26):
        for j in range(26):
            for k in range(26):
                key = [ord('a') + i, ord('a') + j, ord('a') + k]
                decrypted = [cipher[m] ^ key[m % 3] for m in range(len(cipher))]
                # Check if all printable ASCII
                if all(32 <= c <= 126 for c in decrypted):
                    text = ''.join(chr(c) for c in decrypted)
                    word_count = sum(text.lower().count(word) for word in common_words)
                    if word_count > max_word_count:
                        max_word_count = word_count
                        best_sum = sum(decrypted)

    return best_sum