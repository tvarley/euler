# Project Euler — Go Solutions [![Go](https://img.shields.io/badge/Go-00ADD8?style=flat-square&logo=go&logoColor=white)](https://golang.org/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../LICENSE)

## Description

This directory contains Go solutions to Project Euler problems 1-75, leveraging Go's simplicity, concurrency features, and strong standard library. The implementations demonstrate idiomatic Go code with efficient algorithms and clear structure.

**Note:** All solutions now compute answers algorithmically - no cheating! (Caught you on euler054.go)

## Features

- Clean, idiomatic Go code following Go conventions
- Efficient algorithms optimized for performance
- Comprehensive testing with Go's built-in testing framework
- Simple build and run process with `go run`
- Cross-platform compatibility

## Installation

### Requirements

- Go 1.21 or later

### Setup

```bash
# No additional setup required
go version  # Verify Go installation
```

## Usage

### Running Solutions

```bash
# Run all problems
./run.sh

# Run individual problem
go run euler001.go

# Run tests
./test.sh
```

## Examples

```bash
# Run Problem 1
go run euler001.go
# Output: Solution to problem 1: 233168

# Run all tests
./test.sh
```

## Project Structure

```
go/
├── euler001.go          # Individual problem solutions
├── euler002.go
├── ...
├── euler050.go
├── p022_names.txt       # Data files for specific problems
├── p042_words.txt
├── run.sh               # Script to run all solutions
├── test.sh              # Script to run all tests
└── README.md
```

## Problems Solved

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
| 031 | Coin sums | 73682 |
| 032 | Pandigital products | 45228 |
| 033 | Digit cancelling fractions | 100 |
| 034 | Digit factorials | 40730 |
| 035 | Circular primes | 55 |
| 036 | Double-base palindromes | 872187 |
| 037 | Truncatable primes | 748317 |
| 038 | Pandigital multiples | 932718654 |
| 039 | Integer right triangles | 840 |
| 040 | Champernowne's constant | 210 |
| 041 | Pandigital prime | 7652413 |
| 042 | Coded triangle numbers | 162 |
| 043 | Sub-string divisibility | 16695334890 |
| 044 | Pentagon numbers | 5482660 |
| 045 | Triangular, pentagonal, and hexagonal | 1533776805 |
| 046 | Goldbach's other conjecture | 5777 |
| 047 | Distinct primes factors | 134043 |
| 048 | Self powers | 9110846700 |
| 049 | Prime permutations | 296962999629 |
| 050 | Consecutive prime sum | 997651 |
| 051 | Prime Digit Replacements | 121313 |
| 052 | Permuted Multiples | 142857 |
| 053 | Combinatoric Selections | 4075 |
| 054 | Poker Hands | 376 |
| 055 | Lychrel Numbers | 249 |
| 061 | Cyclical Figurate Numbers | 28684 |
| 062 | Cubic Permutations | 127035954683 |
| 063 | Powerful Digit Counts | 49 |
| 064 | Odd Period Square Roots | 1322 |
| 065 | Convergents of e | 272 |

| 066 | Diophantine equation | 661 |
| 067 | Maximum path sum II | 7273 |
| 068 | Magic 5-gon ring | 6531031914842725 |
| 069 | Totient maximum | 510510 |
| 070 | Totient permutation | 8319823 |
| 071 | Ordered fractions | 428571 |
| 072 | Counting fractions | 303963552391 |
| 073 | Counting fractions in a range | 7295372 |
| 074 | Digit factorial chains | 402 |
| 075 | Singular integer right triangles | 161667 |

## Contributing

To contribute:

1. Implement a new problem solution as `eulerXXX.go`
2. Add corresponding tests if applicable
3. Update this README with the new problem entry
4. Ensure `./test.sh` passes

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.
