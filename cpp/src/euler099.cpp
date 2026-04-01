// Problem 99: Largest exponential
// https://projecteuler.net/problem=99
// Find the line number of the base-exponent pair with the greatest numerical value.

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

long long largest_exponential() {
    std::ifstream file("src/p099_base_exp.txt");
    if (!file) return 0;
    std::string line;
    int line_num = 0;
    int max_line = 0;
    double max_val = 0;
    while (std::getline(file, line)) {
        line_num++;
        size_t comma = line.find(',');
        int base = std::stoi(line.substr(0, comma));
        int exp = std::stoi(line.substr(comma + 1));
        double val = exp * std::log(base);
        if (val > max_val) {
            max_val = val;
            max_line = line_num;
        }
    }
    return max_line;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << largest_exponential() << std::endl;
    return 0;
}
#endif