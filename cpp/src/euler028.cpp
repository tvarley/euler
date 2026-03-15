// https://projecteuler.net/problem=28

// Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
//
// 21 22 23 24 25
// 20  7  8  9 10
// 19  6  1  2 11
// 18  5  4  3 12
// 17 16 15 14 13
//
// It can be verified that the sum of the numbers on the diagonals is 101.
//
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
//
// Answer: 669171001

// Authored by: Tim Varley 💘

#include <iostream>

long long spiral_diagonal_sum(int size) {
    if (size == 1) return 1;
    long long sum = 1;  // center
    for (int n = 3; n <= size; n += 2) {
        // corners: n², n²-n+1, n²-2n+2, n²-3n+3
        long long corner1 = (long long)n * n;
        long long corner2 = corner1 - (n - 1);
        long long corner3 = corner2 - (n - 1);
        long long corner4 = corner3 - (n - 1);
        sum += corner1 + corner2 + corner3 + corner4;
    }
    return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << spiral_diagonal_sum(1001) << std::endl;
}
#endif // UNITTEST_MODE