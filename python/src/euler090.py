# Problem 90: Cube digit pairs
# Each of the six faces on a cube has a different digit (0 to 9) printed on it; the same is done to a second cube. By placing the two cubes side-by-side in different positions we can form a variety of 2-digit numbers.
# For example, the square number 01 is a 2-digit number but 00 is not considered a valid 2-digit number.
# Find how many distinct square numbers can be formed.
# Answer: 1217
# Execution time: ~10ms on modern hardware
# Optimizations: Generate all possible cube configurations
# Interesting notes: AI-generated solution enumerating cube digit assignments

def has_digit(cube, d):
    if d in cube:
        return True
    if d == 6 and 9 in cube:
        return True
    if d == 9 and 6 in cube:
        return True
    return False

def solve():
    from itertools import combinations
    squares = [1, 4, 9, 16, 25, 36, 49, 64, 81]
    digits = list(range(10))
    cubes = list(combinations(digits, 6))
    count = 0
    n = len(cubes)
    for i in range(n):
        for j in range(i + 1, n):
            cube1, cube2 = cubes[i], cubes[j]
            ok = True
            for sq in squares:
                d1, d2 = sq // 10, sq % 10
                can = (has_digit(cube1, d1) and has_digit(cube2, d2)) or \
                      (has_digit(cube1, d2) and has_digit(cube2, d1))
                if not can:
                    ok = False
                    break
            if ok:
                count += 1
    return count

if __name__ == "__main__":
    print(solve())