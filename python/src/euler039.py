def solve():
    """
    Integer Right Triangles
    If p is the perimeter of a right angle triangle with integral length sides, {a, b, c}, there are exactly three solutions for p = 120.

    {20,48,52}, {24,45,51}, {30,40,50}

    For which value of p ≤ 1000, is the number of solutions maximised?
    https://projecteuler.net/problem=39
    """
    max_solutions = 0
    max_p = 0
    for p in range(1, 1001):
        solutions = 0
        for a in range(1, p // 2):
            for b in range(a, (p - a) // 2):
                c = p - a - b
                if a**2 + b**2 == c**2:
                    solutions += 1
        if solutions > max_solutions:
            max_solutions = solutions
            max_p = p
    return max_p