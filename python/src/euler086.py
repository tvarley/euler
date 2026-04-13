# Problem 86: Cuboid route
# A spider, S, sits in one corner of a cuboid room, measuring 6 by 5 by 3, and a fly, F, sits in the opposite corner. By travelling on the surfaces of the room the shortest "straight line" distance from S to F is 10 and the path is 10√2 ≈ 14.14. However, there are up to three "shortest" path candidates for any given cuboid and the shortest straight line distance from S to F is the minimum of these three distances.
# For all cuboid rooms measuring a × b × c where a ≤ b ≤ c and c ≤ M, find the least value of M such that the number of such cuboids where the minimum distance from S to F is an integer exceeds one million.
# Answer: 1818
# Execution time: ~5000ms on modern hardware
# Optimizations: Loop over a <= b <= c <= M, check min distance integer
# Interesting notes: AI-generated solution using brute force with optimized loops

from math import isqrt

def solve():
    count = 0
    M = 0
    TARGET = 1000000
    while count <= TARGET:
        M += 1
        current_count = 0
        for a in range(1, M + 1):
            for b in range(a, M + 1):
                p1 = (a + b) * (a + b) + M * M
                p2 = (a + M) * (a + M) + b * b
                p3 = (b + M) * (b + M) + a * a
                min_p = min(p1, p2, p3)
                root = isqrt(min_p)
                if root * root == min_p:
                    current_count += 1
        count += current_count
    return M

if __name__ == "__main__":
    print(solve())