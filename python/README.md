# Project Euler Python Solutions [![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white)](https://www.python.org/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](../LICENSE)

This directory contains Python solutions for Project Euler problems 1 through 50.

## Structure

- `src/`: Solution files (euler001.py to euler050.py)
- `tests/`: Unit tests for each problem
- `run_all.py`: Script to execute all solutions
- `requirements.txt`: Python dependencies
- `pyproject.toml`: Configuration for Black and Ruff

## Features

- Clean, readable Python code following PEP 8 standards
- Comprehensive testing with pytest framework
- Code formatting with Black and linting with Ruff
- Efficient algorithms optimized for performance
- Modular design with separate solution files

## Setup

1. Install dependencies:
   ```bash
   pip install -r requirements.txt
   ```

2. Run all solutions:
   ```bash
   python run_all.py
   ```

3. Run tests:
   ```bash
   pytest
   ```

4. Format code:
   ```bash
   black src/ tests/
   ```

5. Lint code:
   ```bash
   ruff check src/ tests/
   ```

## Examples

```bash
# Install dependencies
pip install -r requirements.txt

# Run all solutions
python run_all.py

# Run tests
pytest

# Format code
black src/ tests/

# Run a specific solution
python src/euler001.py
```

## Problems Solved

| #  | Problem | Answer |
|----|---------|--------|
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

## Notes

- All solutions follow PEP 8 and are formatted with Black
- Algorithms are optimized for efficiency where possible
- Solutions should complete in under 1 second each on modern hardware
- Tests verify against known Project Euler answers
- For problem-specific data (grids, numbers, names), see the source code comments
- Problem 22 requires `data/p022_names.txt` (included)

## Contributing

To contribute:

1. Implement a new solution file following PEP 8
2. Add corresponding tests in `tests/`
3. Update this README with the new problem entry
4. Ensure `pytest` passes and `black` formatting is applied

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.