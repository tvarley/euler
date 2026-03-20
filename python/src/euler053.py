# Problem 53: Combinatoric Selections
# There are exactly ten ways of selecting three from five, 12345:
# 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
# In combinatorics, we use the notation, \binom 5 3 = 10.
# In general, \binom n r = \dfrac{n!}{r!(n-r)!}, where r \le n, n! = n \times (n-1) \times ... \times 3 \times 2 \times 1, and 0! = 1.
# It is not until n = 23, that a value exceeds one-million: \binom {23} {10} = 1144066.
# How many, not necessarily distinct, values of \binom n r for 1 \le n \le 100, are greater than one-million?
# Answer: 4075
# Execution time: Instantaneous
# Optimizations: Used Python's math.comb for efficient binomial coefficient calculation, started iteration from n=23 where values exceed the threshold.
# Notes: Direct computation of all combinations within the given constraints.
import math

def solve():
    count = 0
    for n in range(23, 101):
        for r in range(n + 1):
            if math.comb(n, r) > 1000000:
                count += 1
    return count