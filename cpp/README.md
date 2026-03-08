# Project Euler — C++ Solutions [![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://isocpp.org/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../LICENSE)

## Description

This directory contains C++ solutions to Project Euler problems 1-30, implemented using modern C++17 features. The solutions emphasize performance, readability, and algorithmic efficiency, showcasing C++ best practices for mathematical computing.

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

*Note: Problems 1-25 were hand-written implementations. Problems 26-30 were generated with AI assistance.*

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

## Contributing

To contribute:

1. Implement a new problem solution following existing patterns
2. Add corresponding unit tests in `src/`
3. Update this README with the new problem entry
4. Ensure `make all && ./bin/unittest` passes

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.

