def solve():
    """
    Largest palindrome product
    A palindromic number reads the same both ways. The largest palindrome made from the product
    of two 2-digit numbers is 9009 = 91 × 99.
    Find the largest palindrome made from the product of two 3-digit numbers.
    """
    max_pal = 0
    for i in range(100, 1000):
        for j in range(100, 1000):
            prod = i * j
            if str(prod) == str(prod)[::-1] and prod > max_pal:
                max_pal = prod
    return max_pal