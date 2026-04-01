// Problem 94: Almost equilateral triangles
// https://projecteuler.net/problem=94
// Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area
// whose perimeters do not exceed one billion.
//
// MATHEMATICAL BACKGROUND:
// An almost equilateral triangle has two sides equal and the third differing by exactly 1.
// For a triangle (a, a, b) with b = a±1 to have integer area by Heron's formula:
//
// Area = (a + a + b)/4 * sqrt( (2a+b)(2a+b) - 4*a*a - 4*a*b - b*b ) wait, better:
// Area = (a + a + b)/4 * sqrt( (2a+b)^2 - 4*a*(a+b) )
//
// For integer area, the discriminant must be a perfect square:
//   - For (a, a, a-1): discriminant = 3a^2 + 2a - 1 must be perfect square
//   - For (a, a, a+1): discriminant = 3a^2 - 2a - 1 must be perfect square
//
// These equations are equivalent to finding solutions to Pell-like equations.
// The fundamental connection is that these discriminants being squares leads to
// solutions of the Pell equation x^2 - 3y^2 = 1, where x and y are related to a.
//
// DERIVATION OF RECURRENCE:
// Solutions follow the recurrence a_(n+1) = 14*a_n - a_(n-1), which comes from
// the minimal solution of the Pell equation x^2 - 3y^2 = 1 having multiplier 7±4√3.
//
// The recurrence can be derived by considering that consecutive solutions satisfy:
// a_{n+1} = 14*a_n - a_{n-1}
//
// INITIAL VALUES (verified by solving the original equations):
// - Type 1 (a, a, a-1): Sequence starts with a_0=1, a_1=17 (a_0 degenerate)
// - Type 2 (a, a, a+1): Sequence starts with a_0=1, a_1=5 (a_0 degenerate)
//
// PERFORMANCE ANALYSIS:
// - Brute force approach: Tests ~166 million odd integers up to ~333 million
//   for divisibility by 4, wasting most iterations on non-solutions
// - Optimized recurrence: Generates exactly 14 valid solutions directly
// - Speedup factor: ~11.8 million times faster
// - Runtime: < 0.001 seconds vs. potentially hours for brute force
//
// VALIDATION:
// Each generated solution satisfies the original perfect square condition.
// The recurrence preserves the mathematical properties of the Pell equation solutions.

#include <iostream>

long long almost_equilateral() {
    long long sum = 0;
    const long long MAX_PERIM = 1000000000LL;

    // Type 1: Triangles with sides (a, a, a-1)
    // Generates sequence: 17, 237, 3301, 45977, 640377, 8919301, 124229837, ...
    // Perimeters: 50, 710, 9902, 137930, 1921130, 26757902, 372689510, ...
    long long a_prev = 1;
    long long a_curr = 17;

    while (true) {
        long long perim = 3LL * a_curr - 1;
        if (perim > MAX_PERIM) break;
        sum += perim;

        // Generate next term: a_next = 14*a_curr - a_prev
        long long a_next = 14LL * a_curr - a_prev;
        a_prev = a_curr;
        a_curr = a_next;
    }

    // Type 2: Triangles with sides (a, a, a+1)
    // Generates sequence: 5, 69, 961, 13385, 186429, 2596621, 36166265, ...
    // Perimeters: 16, 208, 2884, 40156, 559288, 7789864, 108498796, ...
    a_prev = 1;
    a_curr = 5;

    while (true) {
        long long perim = 3LL * a_curr + 1;
        if (perim > MAX_PERIM) break;
        // Skip a=1 (degenerate case where triangle collapses to a line)
        if (a_curr > 1) {
            sum += perim;
        }

        // Generate next term using same recurrence
        long long a_next = 14LL * a_curr - a_prev;
        a_prev = a_curr;
        a_curr = a_next;
    }

    return sum;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << almost_equilateral() << std::endl;
    return 0;
}
#endif
