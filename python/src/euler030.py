def solve():
    """
    Digit fifth powers
    Surprisingly there are only three numbers that can be written as the sum of fourth powers
    of their digits: 1634, 8208, 9474. As 1 = 1^4, 2 = 2^4... etc are not sums they are not included.
    The sum of these numbers is 1634 + 8208 + 9474 = 19316.
    Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
    https://projecteuler.net/problem=30
    """
    # Upper bound: 9^5 * 6 = 354294, so 7-digit numbers can't work (9^5*7=413343 < 9999999)
    return sum(
        n for n in range(2, 354295)
        if n == sum(int(d)**5 for d in str(n))
    )
