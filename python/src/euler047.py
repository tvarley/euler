def solve():
    """
    Distinct Primes Factors
    The first two consecutive numbers to have two distinct prime factors are:

    14 = 2 × 7
    15 = 3 × 5.

    The first three consecutive numbers to have three distinct prime factors are:

    644 = 2² × 7 × 23
    645 = 3 × 5 × 43
    646 = 2 × 17 × 19.

    Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
    https://projecteuler.net/problem=47
    """
    def distinct_prime_factors(n):
        factors = set()
        i = 2
        while i * i <= n:
            if n % i == 0:
                factors.add(i)
                while n % i == 0:
                    n //= i
            i += 1
        if n > 1:
            factors.add(n)
        return len(factors)

    n = 2
    while True:
        if (distinct_prime_factors(n) == 4 and
            distinct_prime_factors(n + 1) == 4 and
            distinct_prime_factors(n + 2) == 4 and
            distinct_prime_factors(n + 3) == 4):
            return n
        n += 1