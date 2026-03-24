# Problem 69: Totient maximum
# Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
# n Relatively Prime φ(n) n/φ(n)
# 2 1 1 2
# 3 1,2 2 1.5
# 4 1,3 2 2
# 5 1,2,3,4 4 1.25
# 6 1,5 2 3
# 7 1,2,3,4,5,6 6 1.1666...
# 8 1,3,5,7 4 2
# 9 1,2,4,5,7,8 6 1.5
# 10 1,3,7,9 4 2.5
# It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.
# Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
# Answer: 510510
# Execution time: ~1000ms on modern hardware
# Optimizations: Sieve to compute totient for all n up to limit
# Interesting notes: AI-generated solution using Euler's totient sieve

def solve():
    limit = 1000000
    phi = list(range(limit + 1))
    for i in range(2, limit + 1):
        if phi[i] == i:  # i is prime
            for j in range(i, limit + 1, i):
                phi[j] = phi[j] // i * (i - 1)
    max_ratio = 0
    max_n = 0
    for n in range(2, limit + 1):
        ratio = n / phi[n]
        if ratio > max_ratio:
            max_ratio = ratio
            max_n = n
    return max_n