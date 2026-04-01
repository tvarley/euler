# Problem 92: Square digit chains
# A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
# For example, 44 → 32 → 13 → 10 → 1 → 1
# 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
# For a number to end up at 89, it must be in a chain that includes 89.
# How many starting numbers below ten million will arrive at 89?
# Answer: 8581146
# Execution time: ~5000ms on modern hardware
# Optimizations: Memoization for chain endings
# Interesting notes: AI-generated solution using DP for chain analysis

MAX_SUM = 568
memo = [0] * MAX_SUM

def sum_square_digits(n):
    total = 0
    while n > 0:
        d = n % 10
        total += d * d
        n //= 10
    return total

def get_chain_end(n):
    if n == 1:
        return 1
    if n == 89:
        return 2
    if memo[n] != 0:
        return memo[n]
    s = sum_square_digits(n)
    memo[n] = get_chain_end(s)
    return memo[n]

def solve():
    count = 0
    for n in range(1, 10000000):
        s = sum_square_digits(n)
        if get_chain_end(s) == 2:
            count += 1
    return count

if __name__ == "__main__":
    print(solve())