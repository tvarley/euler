def solve():
    """
    Digit Factorials
    145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

    Find the sum of all numbers which are equal to the sum of the factorial of their digits.

    Note: As 1! = 1 and 2! = 2 are not sums they are not included.
    https://projecteuler.net/problem=34
    """
    import math
    fact = [math.factorial(i) for i in range(10)]
    total = 0
    # Upper limit: 9! * 7 = 2540160, 7 digits; 9! * 8 would be more but 8 digits > sum
    for n in range(10, 2540161):
        if sum(fact[int(d)] for d in str(n)) == n:
            total += n
    return total