def solve():
    """
    Double-base Palindromes
    The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.

    Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

    (Please note that the palindromic number, in either base, may not include leading zeros.)
    https://projecteuler.net/problem=36
    """
    def is_palindrome(s):
        return s == s[::-1]

    total = 0
    for n in range(1, 1000000):
        if is_palindrome(str(n)) and is_palindrome(bin(n)[2:]):
            total += n
    return total