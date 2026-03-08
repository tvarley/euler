def solve():
    """
    Quadratic primes
    Euler discovered the remarkable quadratic formula: n² + n + 41.
    It turns out that the formula n² + 79n + 1601 can produce 80 primes for the consecutive
    values 0 ≤ n ≤ 79. The product of the coefficients, −79 and 1601, is −126479.
    Considering quadratics of the form: n² + an + b, where |a| < 1000 and |b| ≤ 1000,
    find the product of the coefficients, a and b, for the quadratic expression that produces
    the maximum number of primes for consecutive values of n, starting with n = 0.
    https://projecteuler.net/problem=27
    """
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

    best_count, best_product = 0, 0
    for a in range(-999, 1000):
        for b in range(-1000, 1001):
            n = 0
            while is_prime(n * n + a * n + b):
                n += 1
            if n > best_count:
                best_count = n
                best_product = a * b
    return best_product
