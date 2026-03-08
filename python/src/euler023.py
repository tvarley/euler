def solve():
    """
    Non-abundant sums
    A perfect number is a number for which the sum of its proper divisors is exactly equal
    to the number. A number n is called deficient if the sum of its proper divisors is less
    than n and it is called abundant if this sum exceeds n.
    As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number
    that can be written as the sum of two abundant numbers is 24. By mathematical analysis,
    it can be shown that all integers greater than 28123 can be written as the sum of two
    abundant numbers. Find the sum of all the positive integers which cannot be written as
    the sum of two abundant numbers.
    https://projecteuler.net/problem=23
    """
    LIMIT = 28123

    def sum_divisors(n):
        s = 1
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                s += i
                if i != n // i:
                    s += n // i
        return s

    abundants = [n for n in range(2, LIMIT + 1) if sum_divisors(n) > n]
    abundant_set = set(abundants)

    non_sum = 0
    for n in range(1, LIMIT + 1):
        if not any((n - a) in abundant_set for a in abundants if a <= n):
            non_sum += n
    return non_sum
