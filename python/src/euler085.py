# Problem 85: Counting Rectangles
# By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:
# Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
# Answer: 2772
# Execution time: ~1ms on modern hardware
# Optimizations: Brute force search over possible dimensions
# Interesting notes: AI-generated solution finding grid area with rectangle count closest to 2 million

def solve():
    target = 2000000
    min_diff = float('inf')
    best_area = 0
    for m in range(1, 100):
        for n in range(1, 100):
            rects = m * (m + 1) * n * (n + 1) // 4
            diff = abs(rects - target)
            if diff < min_diff:
                min_diff = diff
                best_area = m * n
    return best_area