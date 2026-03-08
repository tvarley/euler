def solve():
    """
    Reciprocal cycles
    A unit fraction contains 1 in the numerator. The decimal representation of the unit
    fractions with denominators 2 to 10 are given. Where 0.1(6) means 0.166666..., the
    recurring part is in parentheses. Find the value of d < 1000 for which 1/d contains
    the longest recurring cycle in its decimal fraction part.
    https://projecteuler.net/problem=26
    """
    def cycle_length(d):
        remainders = {}
        r = 1
        pos = 0
        while r != 0:
            if r in remainders:
                return pos - remainders[r]
            remainders[r] = pos
            r = (r * 10) % d
            pos += 1
        return 0

    best_d, best_len = 1, 0
    for d in range(2, 1000):
        length = cycle_length(d)
        if length > best_len:
            best_len = length
            best_d = d
    return best_d
