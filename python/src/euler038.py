def solve():
    """
    Pandigital Multiples
    Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

    By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3).

    The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

    What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, …, n) where n > 1?
    https://projecteuler.net/problem=38
    """
    def is_pandigital(s):
        return len(s) == 9 and set(s) == set('123456789')

    max_pandigital = 0
    for n in range(1, 10000):  # reasonable upper limit
        concatenated = ''
        multiplier = 1
        while len(concatenated) < 9:
            concatenated += str(n * multiplier)
            multiplier += 1
            if len(concatenated) == 9 and is_pandigital(concatenated):
                max_pandigital = max(max_pandigital, int(concatenated))
                break
            elif len(concatenated) > 9:
                break
    return max_pandigital