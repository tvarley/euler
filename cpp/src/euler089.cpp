// Problem 89: Roman numerals
// https://projecteuler.net/problem=89
// Find the number of characters saved by writing each of these in their minimal form.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int roman_to_int(const std::string& s) {
    std::vector<std::pair<std::string, int>> values = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
        {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };
    int total = 0;
    size_t i = 0;
    while (i < s.length()) {
        bool found = false;
        for (const auto& p : values) {
            if (s.substr(i, p.first.length()) == p.first) {
                total += p.second;
                i += p.first.length();
                found = true;
                break;
            }
        }
        if (!found) i++;
    }
    return total;
}

std::string int_to_roman(int num) {
    std::vector<std::pair<int, std::string>> values = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    std::string result;
    for (const auto& p : values) {
        while (num >= p.first) {
            result += p.second;
            num -= p.first;
        }
    }
    return result;
}

long long roman_numerals() {
    std::ifstream file("src/p089_roman.txt");
    if (!file) return 0;
    std::string line;
    long long saved = 0;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        int value = roman_to_int(line);
        std::string minimal = int_to_roman(value);
        saved += line.length() - minimal.length();
    }
    return saved;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << roman_numerals() << std::endl;
    return 0;
}
#endif