# Project Euler — C++ Solutions [![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://isocpp.org/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../LICENSE)

## Description

This directory contains C++ solutions to Project Euler problems 1-100, implemented using modern C++17 features. The solutions emphasize performance, readability, and algorithmic efficiency, showcasing C++ best practices for mathematical computing.

## Features

- High-performance implementations leveraging C++17 features
- Comprehensive unit testing with Catch2 framework
- Optimized algorithms for mathematical computations
- Modern C++ idioms and RAII principles
- Cross-platform compatibility with standard make build system

## Installation

### Dependencies

1. A C++ compiler with C++17 support (e.g., `g++ 7+` or `clang++`)
2. Make build system
3. Catch2 testing framework (included as `src/catch_amalgamated.hpp`)

### Setup

```bash
# No additional setup required - dependencies are included
make  # to verify compiler availability
```

## Usage

### Building

```bash
# Build all executables
make all

# Build specific problem
make bin/euler001
```

### Running Solutions

```bash
# Run unit tests
./bin/unittest -s

# Run individual problem
./bin/euler001

# Run all problems
for f in bin/euler*; do ./$f; done
```

## Examples

```bash
# Build and run Problem 1
make bin/euler001 && ./bin/euler001
# Output: Solution to problem 1: 233168

# Run tests to verify all solutions
./bin/unittest
```

## Project Structure

```
cpp/
├── Makefile              # Build configuration
├── src/
│   ├── catch_amalgamated.hpp  # Testing framework
│   ├── euler001.cpp     # Individual problem solutions
│   ├── euler002.cpp
│   └── ...
├── bin/                  # Built executables (generated)
└── README.md
```

## Problems Solved

*Note: Problems 1-25 were hand-written implementations. Problems 26-85 were generated with AI assistance.*

| #  | Problem | Answer |
|----|---------|--------|
| 001 | Multiples of 3 or 5 | 233168 |
| 002 | Even Fibonacci numbers | 4613732 |
| 003 | Largest prime factor | 6857 |
| 004 | Largest palindrome product | 906609 |
| 005 | Smallest multiple | 232792560 |
| 006 | Sum square difference | 25164150 |
| 007 | 10001st prime | 104743 |
| 008 | Largest product in a series | 23514624000 |
| 009 | Special Pythagorean triplet | 31875000 |
| 010 | Summation of primes | 142913828922 |
| 011 | Largest product in a grid | 70600674 |
| 012 | Highly divisible triangular number | 76576500 |
| 013 | Large sum | 5537376230 |
| 014 | Longest Collatz sequence | 837799 |
| 015 | Lattice paths | 137846528820 |
| 016 | Power digit sum | 1366 |
| 017 | Number letter counts | 21124 |
| 018 | Maximum path sum I | 1074 |
| 019 | Counting Sundays | 171 |
| 020 | Factorial digit sum | 648 |
| 021 | Amicable numbers | 31626 |
| 022 | Names scores | 871198282 |
| 023 | Non-abundant sums | 4179871 |
| 024 | Lexicographic permutations | 2783915460 |
| 025 | 1000-digit Fibonacci number | 4782 |
| 026 | Reciprocal cycles | 983 |
| 027 | Quadratic primes | -59231 |
| 028 | Number spiral diagonals | 669171001 |
| 029 | Distinct powers | 9183 |
| 030 | Digit fifth powers | 443839 |
| 031 | How many different ways can £2 be made using any number of coins? | 73682 |
| 032 | Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital. | 45228 |
| 033 | If the product of these four fractions is given in its lowest common terms, find the value of the denominator. | 100 |
| 034 | Find the sum of all numbers which are equal to the sum of the factorial of their digits. | 40730 |
| 035 | How many circular primes are there below one million? | 55 |
| 036 | Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2. | 872187 |
| 037 | Find the sum of the only eleven primes that are both truncatable from left to right and right to left. | 748317 |
| 038 | What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, …, n) where n > 1? | 932718654 |
| 039 | For which value of p ≤ 1000, is the number of solutions maximised? | 840 |
| 040 | If d_n represents the nth digit of the fractional part, find the value of the following expression. | 210 |
| 041 | What is the largest n-digit pandigital prime that exists? | 7652413 |
| 042 | Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words? | 162 |
| 043 | Find the sum of all 0 to 9 pandigital numbers with this property. | 16695334890 |
| 044 | Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk - Pj| is minimised; what is the value of D? | 5482660 |
| 045 | Find the next triangle number that is also pentagonal and hexagonal. | 1533776805 |
| 046 | Goldbach's Other Conjecture | 5777 |
| 047 | Distinct Primes Factors | 134043 |
| 048 | Self Powers | 9110846700 |
| 049 | Prime Permutations | 296962999629 |
| 050 | Consecutive Prime Sum | 997651 |
| 051 | Prime Digit Replacements | 121313 |
| 052 | Permuted Multiples | 142857 |
| 053 | Combinatoric Selections | 4075 |
| 054 | Poker Hands | 376 |
| 055 | Lychrel Numbers | 249 |
| 056 | Powerful Digit Sum | 972 |
| 057 | Square Root Convergents | 153 |
| 058 | Spiral Primes | 26241 |
| 059 | XOR Decryption | 129448 |
| 060 | Prime Pair Sets | 26033 |
| 061 | Cyclical Figurate Numbers | 28684 |
| 062 | Cubic Permutations | 127035954683 |
| 063 | Substring Divisibility | 16695334890 |
| 064 | Odd Period Square Roots | 1322 |
| 065 | Convergents of e | 272 |
| 066 | Diophantine Equation | 661 |
| 067 | Maximum Path Sum II | 7273 |
| 068 | Magic 5-gon Ring | 6531031914842725 |
| 069 | Totient Maximum | 510510 |
| 070 | Totient Permutation | 8319823 |
| 071 | Ordered Fractions | 428570 |
| 072 | Counting Fractions | 303963552391 |
| 073 | Counting Fractions in a Range | 7295372 |
| 074 | Digit Factorial Chains | 402 |
| 075 | Singular Integer Right Triangles | 161667 |
| 076 | Counting Summations | 190569291 |
| 077 | Prime Summations | 71 |
| 078 | Coin Partitions | 55374 |
| 079 | Passcode Derivation | 73162890 |
| 080 | Square Root Digital Expansion | 40886 |
| 081 | Path Sum: Two Ways | 427337 |
| 082 | Path Sum: Three Ways | 260324 |
| 083 | Path Sum: Four Ways | 425185 |
| 084 | Monopoly Odds | 101524 |
| 085 | Counting Rectangles | 2772 |
| 086 | Cuboid Route | 1818 |
| 087 | Prime Power Triples | 1097343 |
| 088 | Product-sum Numbers | 7587457 |
| 089 | Roman Numerals | 743 |
| 090 | Cube Digit Pairs | 1217 |
| 091 | Right Triangles with Integer Coordinates | 14234 |
| 092 | Square Digit Chains | 8581146 |
| 093 | Arithmetic Expressions | 1258 |
| 094 | Almost Equilateral Triangles | 518408346 |
| 095 | Amicable Chains | 14316 |
| 096 | Su Doku | 24702 |
| 097 | Large Non-Mersenne Prime | 8739992577 |
| 098 | Anagramic Squares | 18769 |
| 099 | Largest Exponential | 709 |
| 100 | Arranged Probability | 756872327473 |

## Contributing

To contribute:

1. Implement a new problem solution following existing patterns
2. Add corresponding unit tests in `src/`
3. Update this README with the new problem entry
4. Ensure `make all && ./bin/unittest` passes

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.

