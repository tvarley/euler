# Project Euler Python Solutions

This directory contains Python solutions for Project Euler problems 1 through 30.

## Structure

- `src/`: Solution files (euler001.py to euler030.py)
- `tests/`: Unit tests for each problem
- `run_all.py`: Script to execute all solutions
- `requirements.txt`: Python dependencies
- `pyproject.toml`: Configuration for Black and Ruff

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

## Problems Solved

1. Multiples of 3 and 5
2. Even Fibonacci numbers
3. Largest prime factor
4. Largest palindrome product
5. Smallest multiple
6. Sum square difference
7. 10001st prime
8. Largest product in a series
9. Special Pythagorean triplet
10. Summation of primes
11. Largest product in a grid
12. Highly divisible triangular number
13. Large sum
14. Longest Collatz sequence
15. Lattice paths
16. Power digit sum
17. Number letter counts
18. Maximum path sum I
19. Counting Sundays
20. Factorial digit sum
21. Amicable numbers
22. Names scores
23. Non-abundant sums
24. Lexicographic permutations
25. 1000-digit Fibonacci number
26. Reciprocal cycles
27. Quadratic primes
28. Number spiral diagonals
29. Distinct powers
30. Digit fifth powers

## Notes

- All solutions follow PEP 8 and are formatted with Black
- Algorithms are optimized for efficiency where possible
- Solutions should complete in under 1 second each on modern hardware
- Tests verify against known Project Euler answers
- For problem-specific data (grids, numbers, names), see the source code comments
- Problem 22 requires `data/p022_names.txt` (included)