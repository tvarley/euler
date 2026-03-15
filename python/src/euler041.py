def solve():
    """
    Pandigital Prime
    We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

    What is the largest n-digit pandigital prime that exists?
    https://projecteuler.net/problem=41
    """
    import itertools

    def is_prime(n):
        if n < 2:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    digits = '1234567'
    max_prime = 0
    for perm in itertools.permutations(digits):
        num = int(''.join(perm))
        if is_prime(num):
            max_prime = max(max_prime, num)
    return max_prime