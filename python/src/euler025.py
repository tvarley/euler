def solve():
    """
    1000-digit Fibonacci number
    The Fibonacci sequence is defined by the recurrence relation:
    F_n = F_(n-1) + F_(n-2), where F_1 = 1 and F_2 = 1.
    What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
    https://projecteuler.net/problem=25
    """
    a, b = 1, 1
    index = 2
    while len(str(b)) < 1000:
        a, b = b, a + b
        index += 1
    return index
