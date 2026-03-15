// https://projecteuler.net/problem=42

// The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

// 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

// By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

// Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

// Answer: 162

// Authored by: Tim Varley 💘

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

bool is_triangle(long long n) {
    double k = (-1 + sqrt(1 + 8 * n)) / 2;
    return k == floor(k);
}

long long word_value(const std::string& word) {
    long long sum = 0;
    for (char c : word) {
        sum += c - 'A' + 1;
    }
    return sum;
}

long long triangle_words() {
    std::ifstream file("src/0042_words.txt");
    if (!file) return 0;
    std::string line;
    std::getline(file, line);
    std::vector<std::string> words;
    std::string word;
    for (char c : line) {
        if (c == '"') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else if (c != ',') {
            word += c;
        }
    }
    if (!word.empty()) words.push_back(word);
    long long count = 0;
    for (const auto& w : words) {
        long long val = word_value(w);
        if (is_triangle(val)) count++;
    }
    return count;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << triangle_words() << std::endl;
}
#endif // UNITTEST_MODE