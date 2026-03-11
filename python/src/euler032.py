def solve():
    """
    Pandigital Products
    We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

    The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

    Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

    HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
    https://projecteuler.net/problem=32
    """
    import itertools
    digits = '123456789'
    products = set()
    for perm in itertools.permutations(digits):
        # Case 1: 1-digit * 4-digit = 4-digit
        a = int(''.join(perm[:1]))
        b = int(''.join(perm[1:5]))
        c = int(''.join(perm[5:]))
        if a * b == c:
            products.add(c)
        # Case 2: 2-digit * 3-digit = 4-digit
        a = int(''.join(perm[:2]))
        b = int(''.join(perm[2:5]))
        c = int(''.join(perm[5:]))
        if a * b == c:
            products.add(c)
    return sum(products)