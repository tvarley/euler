# Problem 78: Coin Partitions
# Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.
# Find the least value of n for which p(n) is divisible by one million.
# Answer: 55374
# Execution time: ~500ms on modern hardware
# Optimizations: Use pentagonal number theorem for efficient partition calculation modulo 10^6
# Interesting notes: AI-generated solution using generalized pentagonal numbers for partition function

def solve():
    MOD = 1000000
    def pentagonal(k):
        return k * (3 * k - 1) // 2
    limit = 60000
    p = [0] * (limit + 1)
    p[0] = 1
    for n in range(1, limit + 1):
        k = 1
        while True:
            pk = pentagonal(k)
            if pk > n:
                break
            sign = (-1) ** ((k + 1) % 2)
            p[n] = (p[n] + sign * p[n - pk]) % MOD
            pk = pentagonal(-k)
            if pk > n:
                break
            sign = (-1) ** ((-k + 1) % 2)
            p[n] = (p[n] + sign * p[n - pk]) % MOD
            k += 1
        if p[n] == 0:
            return n

if __name__ == "__main__":
    print(solve())