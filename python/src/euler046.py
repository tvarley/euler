def solve():
    """
    Goldbach's Other Conjecture
    It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

    9 = 7 + 2×1²
    15 = 7 + 2×2²
    21 = 3 + 2×3²
    25 = 7 + 2×3²
    27 = 19 + 2×2²
    33 = 31 + 2×1²

    It turns out that the conjecture was false.

    What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
    https://projecteuler.net/problem=46
    """
    def is_prime(n):
        if n < 2:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    def is_composite(n):
        return n > 1 and not is_prime(n)

    primes = []
    n = 2
    while n < 10000:  # arbitrary limit
        if is_prime(n):
            primes.append(n)
        n += 1

    odd_composite = 9
    while True:
        if is_composite(odd_composite):
            found = False
            for p in primes:
                if p >= odd_composite:
                    break
                remainder = odd_composite - p
                if remainder % 2 == 0:
                    s = remainder // 2
                    sqrt_s = int(s**0.5 + 0.5)
                    if sqrt_s * sqrt_s == s:
                        found = True
                        break
            if not found:
                return odd_composite
        odd_composite += 2