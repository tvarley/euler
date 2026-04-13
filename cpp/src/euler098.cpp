// Problem 98: Anagramic squares
// https://projecteuler.net/problem=98
// Find the largest square number formed by substituting letters of an anagram pair with digits.
// 
// Optimization: Use recursive backtracking to generate digit assignments instead of std::next_permutation
// on a full 10-element vector. This avoids unnecessary permutations when fewer than 10 unique letters
// and provides early pruning for invalid mappings (e.g., leading zeros).

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

bool is_square(long long n) {
    long long root = (long long)std::sqrt(n);
    return root * root == n;
}

void try_mapping(const std::vector<char>& letter_list, int pos, std::vector<bool>& used, std::map<char, int>& mapping, const std::string& w1, const std::string& w2, long long& max_square) {
    // Recursive backtracking to assign distinct digits 0-9 to letters, checking for valid square numbers
    if (pos == letter_list.size()) {
        if (mapping[w1[0]] == 0 || mapping[w2[0]] == 0) return;
        long long num1 = 0, num2 = 0;
        for (char c : w1) num1 = num1 * 10 + mapping[c];
        for (char c : w2) num2 = num2 * 10 + mapping[c];
        if (is_square(num1) && is_square(num2)) {
            max_square = std::max({max_square, num1, num2});
        }
        return;
    }
    for (int d = 0; d < 10; ++d) {
        if (used[d]) continue;
        mapping[letter_list[pos]] = d;
        used[d] = true;
        try_mapping(letter_list, pos + 1, used, mapping, w1, w2, max_square);
        used[d] = false;
    }
}

long long anagramic_squares() {
    std::ifstream file("src/p098_words.txt");
    if (!file) return 0;
    std::string content;
    std::getline(file, content);
    // parse words - split by comma and remove quotes
    std::vector<std::string> words;
    std::string word;
    bool in_quote = false;
    for (char c : content) {
        if (c == '"') {
            in_quote = !in_quote;
            if (!in_quote && !word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else if (in_quote) {
            word += c;
        }
    }
    // group by sorted letters
    std::map<std::string, std::vector<std::string>> anagrams;
    for (const std::string& word : words) {
        std::string sorted = word;
        std::sort(sorted.begin(), sorted.end());
        anagrams[sorted].push_back(word);
    }
    long long max_square = 0;

    for (const auto& p : anagrams) {
        if (p.second.size() < 2) continue;
        for (size_t i = 0; i < p.second.size(); ++i) {
            for (size_t j = i + 1; j < p.second.size(); ++j) {
                std::string w1 = p.second[i], w2 = p.second[j];
                // get unique letters
                std::set<char> letters;
                for (char c : w1) letters.insert(c);
                for (char c : w2) letters.insert(c);
                if (letters.size() > 10) continue; // impossible
                // generate digit assignments using backtracking for efficiency
                std::vector<char> letter_list(letters.begin(), letters.end());
                std::vector<bool> used(10, false);
                std::map<char, int> mapping;
                try_mapping(letter_list, 0, used, mapping, w1, w2, max_square);
            }
        }
    }
    return max_square;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << anagramic_squares() << std::endl;
    return 0;
}
#endif