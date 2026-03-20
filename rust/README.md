# Project Euler — Rust Solutions [![Rust](https://img.shields.io/badge/Rust-000000?style=flat-square&logo=rust&logoColor=white)](https://www.rust-lang.org/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../LICENSE)

## Description

This directory contains Rust solutions to Project Euler problems 1-45, leveraging Rust's performance, memory safety, and zero-cost abstractions. The implementations showcase Rust's strengths in systems programming and mathematical computing.

## Features

- High-performance Rust code with memory safety guarantees
- Comprehensive testing with Rust's built-in test framework
- Cargo package manager for dependency management
- Zero-cost abstractions and efficient algorithms
- Cross-platform compilation with `rustc`

## Installation

### Dependencies

- Rust toolchain (stable, 2021 edition)
- `num-bigint` crate for arbitrary-precision integers

### Setup

```bash
# No additional setup required - dependencies managed by Cargo
cargo build  # to verify installation
```

## Usage

### Building

```bash
# Build all solutions
cargo build

# Build optimized release
cargo build --release
```

### Running Solutions

```bash
# Run all solutions
cargo run

# Run unit tests
cargo test

# Run single test
cargo test euler_001
```

## Examples

```bash
# Build and run all solutions
cargo run

# Run tests to verify correctness
cargo test

# Build optimized version
cargo build --release && ./target/release/euler
```

## Project Structure

```
rust/
├── src/
│   ├── main.rs              # Entry point and solution dispatcher
│   ├── lib.rs               # Library with solution functions
│   └── eulerXXX.rs          # Individual problem modules
├── Cargo.toml               # Package configuration
└── README.md
```

## Problems Solved

*Note: Problems 1-6 were hand-written implementations. Problems 7-50 were generated with AI assistance.*

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
| 056 | Powerful Digit Sum | 972 |
| 057 | Square Root Convergents | 153 |
| 058 | Spiral Primes | 26241 |
| 059 | XOR Decryption | 107359 |
| 060 | Prime Pair Sets | 26033 |

## Contributing

To contribute:

1. Implement a new solution module following Rust conventions
2. Add corresponding unit tests
3. Update this README with the new problem entry
4. Ensure `cargo test` passes

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.
