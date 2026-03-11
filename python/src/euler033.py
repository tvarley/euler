def solve():
    """
    Digit Cancelling Fractions
    The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

    We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

    There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

    If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
    https://projecteuler.net/problem=33
    """
    from fractions import Fraction
    result = Fraction(1, 1)
    for num in range(10, 100):
        for den in range(num + 1, 100):
            if num % 10 == 0 and den % 10 == 0:
                continue
            num_str = str(num)
            den_str = str(den)
            common_digits = set(num_str) & set(den_str)
            if not common_digits or '0' in common_digits:
                continue
            for d in common_digits:
                if d in num_str and d in den_str:
                    new_num = int(num_str.replace(d, '', 1))
                    new_den = int(den_str.replace(d, '', 1))
                    if new_den != 0 and Fraction(num, den) == Fraction(new_num, new_den):
                        result *= Fraction(num, den)
                        break
    return result.denominator