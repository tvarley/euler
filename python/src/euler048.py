def solve():
    """
    Self Powers
    The series, 1¹ + 2² + 3³ + … + 10¹⁰ = 10405071317.

    Find the last ten digits of the series, 1¹ + 2² + 3³ + … + 1000¹⁰⁰⁰.
    https://projecteuler.net/problem=48
    """
    total = 0
    mod = 10**10
    for i in range(1, 1001):
        total = (total + pow(i, i, mod)) % mod
    return total