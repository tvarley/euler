# Problem 76: Counting Summations
# It is possible to write five as a sum in exactly six different ways:
# 4 + 1
# 3 + 2
# 3 + 1 + 1
# 2 + 2 + 1
# 2 + 1 + 1 + 1
# 1 + 1 + 1 + 1 + 1
# How many different ways can one hundred be written as a sum of at least two positive integers?
# Answer: 190569291
# Execution time: ~100ms on modern hardware
# Optimizations: Dynamic programming for partition function
# Interesting notes: AI-generated solution using DP to count partitions minus one

def solve():
    n = 100
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        for j in range(i, n + 1):
            dp[j] += dp[j - i]
    return dp[n] - 1

if __name__ == "__main__":
    print(solve())