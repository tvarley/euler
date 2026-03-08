// https://projecteuler.net/problem=26

// A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

// 1/2 = 0.5
// 1/3 = 0.(3)
// 1/4 = 0.25
// 1/5 = 0.2
// 1/6 = 0.1(6)
// 1/7 = 0.(142857)
// 1/8 = 0.125
// 1/9 = 0.(1)
// 1/10 = 0.1

// Where 0.1(6) means 0.1666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

// Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
//
// Answer: 983
//
// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 <crush@charm.land>

#include <iostream>
#include <map>

int longest_reciprocal_cycle(int max_d) {
    int max_cycle = 0;
    int max_d_val = 0;
    for (int d = 2; d < max_d; ++d) {
        std::map<int, int> remainder_positions;
        int remainder = 1;
        int position = 0;
        while (remainder != 0 && remainder_positions.find(remainder) == remainder_positions.end()) {
            remainder_positions[remainder] = position;
            remainder *= 10;
            remainder %= d;
            ++position;
        }
        if (remainder != 0) {
            int cycle_length = position - remainder_positions[remainder];
            if (cycle_length > max_cycle) {
                max_cycle = cycle_length;
                max_d_val = d;
            }
        }
    }
    return max_d_val;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << longest_reciprocal_cycle(1000) << std::endl;
}
#endif // UNITTEST_MODE