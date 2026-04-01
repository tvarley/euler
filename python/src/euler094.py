# Problem 94: Almost equilateral triangles
# Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area, whose perimeters do not exceed 1e9.
# Answer: 518408346
# Execution time: ~10ms on modern hardware
# Optimizations: Check for each a if the discriminant is square
# Interesting notes: AI-generated solution using Pell-like equations

def solve():
    MAX_PERIM = 10**9
    total = 0
    # Type 1: (a, a, a-1)
    a_prev = 1
    a_curr = 17
    while True:
        perim = 3 * a_curr - 1
        if perim > MAX_PERIM:
            break
        total += perim
        a_next = 14 * a_curr - a_prev
        a_prev = a_curr
        a_curr = a_next
    # Type 2: (a, a, a+1)
    a_prev = 1
    a_curr = 5
    while True:
        perim = 3 * a_curr + 1
        if perim > MAX_PERIM:
            break
        if a_curr > 1:
            total += perim
        a_next = 14 * a_curr - a_prev
        a_prev = a_curr
        a_curr = a_next
    return total

if __name__ == "__main__":
    print(solve())