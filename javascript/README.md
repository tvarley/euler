# Project Euler — JavaScript Solutions [![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=flat-square&logo=javascript&logoColor=black)](https://developer.mozilla.org/en-US/docs/Web/JavaScript) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../LICENSE)

JavaScript solutions to [Project Euler](https://projecteuler.net/) problems 1–30.

## Requirements

- Node.js
- Yarn

## Setup

```bash
yarn install
```

## Running Tests

```bash
yarn test
```

## Running All Solutions

```bash
node src/index.js
```

## Examples

```bash
# Install dependencies
yarn install

# Run tests
yarn test

# Run all solutions
node src/index.js

# Run a specific solution
node src/euler/solution001.js
```

## Structure

```
src/
  euler/
    solution001.js – solution030.js   # individual problem solutions
  index.js                            # runs and prints all answers
test/
  solution001_test.js – solution030_test.js
```

## Features

- Modern JavaScript ES6+ syntax with async/await support
- Comprehensive testing with Jest framework
- Modular design with separate solution files
- Node.js environment for server-side execution
- Efficient algorithms optimized for JavaScript runtime

## Problems Solved

| # | Problem | Answer |
|---|---------|--------|
| 001 | Multiples of 3 or 5 | 233168 |
| 002 | Even Fibonacci Numbers | 4613732 |
| 003 | Largest Prime Factor | 6857 |
| 004 | Largest Palindrome Product | 906609 |
| 005 | Smallest Multiple | 232792560 |
| 006 | Sum Square Difference | 25164150 |
| 007 | 10001st Prime | 104743 |
| 008 | Largest Product in a Series | 23514624000 |
| 009 | Special Pythagorean Triplet | 31875000 |
| 010 | Summation of Primes | 142913828922 |
| 011 | Largest Product in a Grid | 70600674 |
| 012 | Highly Divisible Triangular Number | 76576500 |
| 013 | Large Sum | 5537376230 |
| 014 | Longest Collatz Sequence | 837799 |
| 015 | Lattice Paths | 137846528820 |
| 016 | Power Digit Sum | 1366 |
| 017 | Number Letter Counts | 21124 |
| 018 | Maximum Path Sum I | 1074 |
| 019 | Counting Sundays | 171 |
| 020 | Factorial Digit Sum | 648 |
| 021 | Amicable Numbers | 31626 |
| 022 | Names Scores | 871198282 |
| 023 | Non-Abundant Sums | 4179871 |
| 024 | Lexicographic Permutations | 2783915460 |
| 025 | 1000-digit Fibonacci Number | 4782 |
| 026 | Reciprocal Cycles | 983 |
| 027 | Quadratic Primes | -59231 |
| 028 | Number Spiral Diagonals | 669171001 |
| 029 | Distinct Powers | 9183 |
| 030 | Digit Fifth Powers | 443839 |

## Contributing

To contribute:

1. Implement a new solution file following the existing pattern
2. Add corresponding tests in `test/`
3. Update this README with the new problem entry
4. Ensure `yarn test` passes

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.
