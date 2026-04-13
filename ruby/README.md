# Project Euler — Ruby Solutions [![Ruby](https://img.shields.io/badge/Ruby-CC342D?style=flat-square&logo=ruby&logoColor=white)](https://www.ruby-lang.org/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../LICENSE)

**Note:** Ruby implementations are deprecated and no new solutions will be generated for this language.

## Description

This directory contains Ruby solutions to Project Euler problems 1-30, showcasing Ruby's elegant syntax and powerful standard library. The implementations demonstrate Ruby idioms and efficient algorithms.

## Features

- Elegant Ruby code following Ruby conventions
- Comprehensive testing with RSpec framework
- Bundler for dependency management
- Modular design with separate solution files
- Ruby's expressive syntax for mathematical computations

## Installation

### Requirements

- Ruby (version specified in `.ruby-version`)
- Bundler

### Setup

```bash
# Install dependencies
gem install bundler
bundle install
```

## Usage

### Running Tests

```bash
./test.sh
```

### Running All Solutions

```bash
./run.sh
```

### Running Individual Solutions

```bash
ruby lib/euler001.rb
```

## Examples

```bash
# Install dependencies
bundle install

# Run tests
./test.sh

# Run all solutions
./run.sh

# Run a specific solution
ruby lib/euler001.rb
```

## Project Structure

```
ruby/
├── lib/
│   └── euler001.rb – euler030.rb  # Solution files
├── spec/
│   └── euler001_spec.rb – euler030_spec.rb  # Test files
├── Gemfile                       # Dependencies
├── run.rb                        # Script to run solutions
├── test.sh                       # Test runner script
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

## Contributing

To contribute:

1. Implement a new solution file following Ruby conventions
2. Add corresponding RSpec tests in `spec/`
3. Update this README with the new problem entry
4. Ensure `bundle exec rspec` passes

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.