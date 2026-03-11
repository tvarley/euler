def solve():
    """
    Circular Primes
    The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

    There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

    How many circular primes are there below one million?
    https://projecteuler.net/problem=35
    """
    def is_prime(n):
        if n < 2:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def rotations(n):
        s = str(n)
        return [int(s[i:] + s[:i]) for i in range(len(s))]

    count = 0
    for n in range(2, 1000000):
        if all(is_prime(r) for r in rotations(n)):
            count += 1
    return count