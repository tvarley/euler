// https://projecteuler.net/problem=48

// The series, 1¹ + 2² + 3³ + … + 10¹⁰ = 10405071317.

// Find the last ten digits of the series, 1¹ + 2² + 3³ + … + 1000¹⁰⁰⁰.

// Answer: 9110846700

// Authored by: Tim Varley 💘

#include <iostream>
#include <string>

std::string self_powers() {
    const long long MOD = 10000000000LL; // 10^10
    long long sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        long long power = 1;
        for (int j = 0; j < i; ++j) {
            power = (power * i) % MOD;
        }
        sum = (sum + power) % MOD;
    }
    std::string result = std::to_string(sum);
    while (result.size() < 10) result = "0" + result;
    return result;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << self_powers() << std::endl;
}
#endif // UNITTEST_MODE