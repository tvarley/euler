# Problem 52: Permuted Multiples
# It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
# Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
# Answer: 142857
# Execution time: Less than 1 second
# Optimizations: Started search from 6-digit numbers to efficiently find the solution, used sorted digit comparison for permutation checking.
# Notes: The problem requires x to have exactly the same digits as its multiples, leading to a compact search space.
def solve():
    x = 100000
    while True:
        digits = sorted(str(x))
        if all(sorted(str(k * x)) == digits for k in range(2, 7)):
            return x
        x += 1