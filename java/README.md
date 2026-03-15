# Project Euler — Java Solutions [![Java](https://img.shields.io/badge/Java-ED8B00?style=flat-square&logo=openjdk&logoColor=white)](https://openjdk.java.net/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../LICENSE)

Java solutions to [Project Euler](https://projecteuler.net/) problems, built with Gradle.

## Structure

```
java/
├── build.gradle
├── src/
│   ├── main/java/org/tvarley/euler/
│   │   ├── Main.java
│   │   ├── Solution.java          # interface
│   │   ├── solutions/
│   │   │   ├── Solution001.java
│   │   │   └── ...
│   │   └── util/
│   │       ├── Prime.java
│   │       └── Factor.java
│   └── test/java/
│       ├── EulerTest.java
│       └── UtilTest.java
```

## Features

- Object-oriented design with clean interfaces
- Comprehensive unit testing with JUnit
- Gradle build system for easy dependency management
- Modular architecture with separate solution and utility classes
- Efficient algorithms implemented in Java

## Requirements

- Java 8+
- Gradle (wrapper included)

## Building

```bash
./gradlew build
```

## Running Tests

```bash
./gradlew test
```

## Examples

```bash
# Build the project
./gradlew build

# Run all tests
./gradlew test

# Run a specific test class
./gradlew test --tests EulerTest
```

## Problems Solved

| # | Problem | Answer |
|---|---------|--------|
| 001 | Multiples of 3 and 5 | 233168 |
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
| 031 | Coin Sums | 73682 |
| 032 | Pandigital Products | 45228 |
| 033 | Digit Canceling Fractions | 100 |
| 034 | Digit Factorials | 40730 |
| 035 | Circular Primes | 55 |
| 036 | Double-base Palindromes | 872187 |
| 037 | Truncatable Primes | 748317 |
| 038 | Pandigital Multiples | 932718654 |
| 039 | Integer Right Triangles | 840 |
| 040 | Champernowne's Constant | 210 |
| 041 | Pandigital Prime | 7652413 |
| 042 | Coded Triangle Numbers | 162 |
| 043 | Sub-string Divisibility | 16695334890 |
| 044 | Pentagon Numbers | 5482660 |
| 045 | Triangular, Pentagonal, and Hexagonal | 1533776805 |
| 046 | Goldbach's Other Conjecture | 5777 |
| 047 | Distinct Primes Factors | 134043 |
| 048 | Self Powers | 9110846700 |
| 049 | Prime Permutations | 296962999629 |
| 050 | Consecutive Prime Sum | 997651 |

## Contributing

To contribute:

1. Implement a new solution class following the existing pattern
2. Add corresponding unit tests in `src/test/java/`
3. Update this README with the new problem entry
4. Ensure `./gradlew build && ./gradlew test` passes

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.
