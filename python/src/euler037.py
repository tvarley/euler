def solve():
    """
    Truncatable Primes
    The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

    Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

    NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
    https://projecteuler.net/problem=37
    """
    def is_prime(n):
        if n < 2:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def truncatable_left(n):
        s = str(n)
        for i in range(1, len(s)):
            if not is_prime(int(s[i:])):
                return False
        return True

    def truncatable_right(n):
        s = str(n)
        for i in range(1, len(s)):
            if not is_prime(int(s[:-i])):
                return False
        return True

    truncatable_primes = []
    n = 11
    while len(truncatable_primes) < 11:
        if is_prime(n) and truncatable_left(n) and truncatable_right(n):
            truncatable_primes.append(n)
        n += 2
    return sum(truncatable_primes)