def solve():
    """
    Number spiral diagonals
    Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral
    is formed. The sum of the numbers on the diagonals is 101.
    What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
    https://projecteuler.net/problem=28
    """
    total = 1
    n = 1
    for step in range(2, 1002, 2):
        for _ in range(4):
            n += step
            total += n
    return total
