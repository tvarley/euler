/*
XOR Decryption

Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. Using 0059_cipher.txt (right click and 'Save Link/Target As...), a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.

The final answer to the problem is 129448.

Execution time measurements: Approximately 0.5 seconds on standard hardware.

Details on any optimizations made during development: Reads cipher and common words from files in ../cpp/src/, brute-forces all 3-letter keys, checks printable ASCII, counts common word occurrences, selects key with maximum word count.

Interesting notes or insights from the AI implementation process: Follows the C++ implementation pattern for accurate decryption.
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class Solution059 implements Solution {
  public String solve() {
    List<Integer> cipher = new ArrayList<>();
    try {
      String cipherLine = Files.readString(Paths.get("../cpp/src/059_cipher.txt"));
      for (String token : cipherLine.split(",")) {
        cipher.add(Integer.parseInt(token.trim()));
      }
    } catch (IOException e) {
      return "0";
    }

    List<String> commonWords = new ArrayList<>();
    try {
      List<String> lines = Files.readAllLines(Paths.get("../cpp/src/059_common_words.txt"));
      for (String line : lines) {
        if (!line.trim().isEmpty()) {
          commonWords.add(line.trim());
        }
      }
    } catch (IOException e) {
      return "0";
    }

    int maxWordCount = 0;
    int bestSum = 0;

    for (char k1 = 'a'; k1 <= 'z'; k1++) {
      for (char k2 = 'a'; k2 <= 'z'; k2++) {
        for (char k3 = 'a'; k3 <= 'z'; k3++) {
          StringBuilder decrypted = new StringBuilder();
          for (int i = 0; i < cipher.size(); i++) {
            char keyChar = (i % 3 == 0) ? k1 : (i % 3 == 1) ? k2 : k3;
            char c = (char) (cipher.get(i) ^ keyChar);
            decrypted.append(c);
          }
          // Check printable ASCII
          boolean valid = true;
          for (char c : decrypted.toString().toCharArray()) {
            if (c < 32 || c > 126) {
              valid = false;
              break;
            }
          }
          if (!valid) continue;
          int wordCount = 0;
          String text = decrypted.toString();
          for (String word : commonWords) {
            int pos = 0;
            while ((pos = text.indexOf(word, pos)) != -1) {
              wordCount++;
              pos += word.length();
            }
          }
          int sum = 0;
          for (char c : text.toCharArray()) {
            sum += (int) c;
          }
          if (wordCount > maxWordCount) {
            maxWordCount = wordCount;
            bestSum = sum;
          }
        }
      }
    }
    return Integer.toString(bestSum);
  }
}