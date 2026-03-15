def solve():
    """
    Sub-string Divisibility
    The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

    Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

    d2 d3 d4=406 is divisible by 2
    d3 d4 d5=063 is divisible by 3
    d4 d5 d6=635 is divisible by 5
    d5 d6 d7=357 is divisible by 7
    d6 d7 d8=572 is divisible by 11
    d7 d8 d9=728 is divisible by 13
    d8 d9 d10=289 is divisible by 17

    Find the sum of all 0 to 9 pandigital numbers with this property.
    https://projecteuler.net/problem=43
    """
    import itertools

    def check(num_str):
        d = [int(num_str[i]) for i in range(10)]
        if d[3] % 2 != 0:
            return False
        if (d[2] + d[3] + d[4]) % 3 != 0:
            return False
        if d[5] not in [0, 5]:
            return False
        if int(num_str[4:7]) % 7 != 0:
            return False
        if int(num_str[5:8]) % 11 != 0:
            return False
        if int(num_str[6:9]) % 13 != 0:
            return False
        if int(num_str[7:10]) % 17 != 0:
            return False
        return True

    total = 0
    for perm in itertools.permutations('0123456789'):
        num_str = ''.join(perm)
        if num_str[0] == '0':
            continue
        if check(num_str):
            total += int(num_str)
    return total