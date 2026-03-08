# Project Euler — Java Solutions

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
