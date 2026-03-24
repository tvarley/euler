# Problem 67: Maximum path sum II
# By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
# 3
# 7 4
# 2 4 6
# 8 5 9 3
# That is, 3 + 7 + 4 + 9 = 23.
# Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
# Answer: 7273
# Execution time: ~10ms on modern hardware
# Optimizations: Dynamic programming bottom-up approach
# Interesting notes: AI-generated solution reading triangle data and computing max path sum

def solve():
    with open('data/euler_67_data.txt', 'r') as f:
        triangle = []
        for line in f:
            triangle.append([int(x) for x in line.split()])

    for i in range(len(triangle) - 2, -1, -1):
        for j in range(len(triangle[i])):
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1])

    return triangle[0][0]