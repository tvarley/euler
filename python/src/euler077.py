# Problem 77: Prime Summations
# It is possible to write ten as the sum of primes in exactly five different ways:
# 7 + 3
# 5 + 5
# 5 + 3 + 2
# 3 + 3 + 2 + 2
# 2 + 2 + 2 + 2 + 2
# What is the first value which can be written as the sum of primes in over five thousand different ways?
# Answer: 71
# Execution time: ~10ms on modern hardware
# Optimizations: Sieve for primes, DP for prime partitions
# Interesting notes: AI-generated solution finding the smallest n with more than 5000 prime partitions

def solve():
    import math
    def sieve(n):
        is_prime = [True] * (n + 1)
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(math.sqrt(n)) + 1):
            if is_prime[i]:
                for j in range(i*i, n+1, i):
                    is_prime[j] = False
        return [i for i in range(2, n+1) if is_prime[i]]
    limit = 1000
    primes = sieve(limit)
    dp = [0] * (limit + 1)
    dp[0] = 1
    for p in primes:
        for j in range(p, limit + 1):
            dp[j] += dp[j - p]
    for n in range(2, limit + 1):
        if dp[n] > 5000:
            return n

if __name__ == "__main__":
    print(solve())