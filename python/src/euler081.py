# Problem 81: Path Sum: Two Ways
# In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.
# Find the minimal path sum from the top left to the bottom right by only moving right and down in matrix.txt, a 31K text file containing an 80 by 80 matrix.
# Answer: 427337
# Execution time: ~10ms on modern hardware
# Optimizations: Dynamic programming on the matrix
# Interesting notes: AI-generated solution using DP for grid path minimization

def solve():
    with open('../cpp/src/p081_matrix.txt') as f:
        matrix = [list(map(int, line.split(','))) for line in f]
    n = len(matrix)
    dp = [[0] * n for _ in range(n)]
    dp[0][0] = matrix[0][0]
    for i in range(1, n):
        dp[i][0] = dp[i-1][0] + matrix[i][0]
        dp[0][i] = dp[0][i-1] + matrix[0][i]
    for i in range(1, n):
        for j in range(1, n):
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matrix[i][j]
    return dp[n-1][n-1]