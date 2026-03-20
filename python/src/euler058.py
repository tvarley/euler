# Problem 58: Spiral Primes
# Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
# 37 36 35 34 33 32 31
# 38 17 16 15 14 13 30
# 39 18  5  4  3 12 29
# 40 19  6  1  2 11 28
# 41 20  7  8  9 10 27
# 42 21 22 23 24 25 26
# 43 44 45 46 47 48 49
# It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.
# If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
# Answer: 26241
# Execution time: About 0.2 seconds
# Optimizations: Used incremental corner calculation and prime checking, stopped when ratio drops below threshold.
# Notes: The spiral generates numbers in a predictable pattern, allowing efficient diagonal extraction.
def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

def solve():
    primes = 0
    total = 1
    corner = 1
    side = 1
    while True:
        side += 2
        for _ in range(4):
            corner += side - 1
            if is_prime(corner):
                primes += 1
            total += 1
        if primes / total < 0.1:
            return side