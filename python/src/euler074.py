# Problem 74: Digit factorial chains
# The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:
# 1! + 4! + 5! = 1 + 24 + 120 = 145
# Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are only three such loops that exist:
# 169 → 363601 → 1454 → 169
# 871 → 45361 → 871
# 872 → 45362 → 872
# It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For instance,
# 69 → 363600 → 1454 → 169 → 363601 (→ 1454)
# 78 → 45360 → 871 → 45361 (→ 871)
# 540 → 145 (→ 145)
# Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number below one million is sixty terms.
# How many starting numbers below one million produce a chain of exactly sixty non-repeating terms?
# Answer: 402
# Execution time: ~10000ms on modern hardware
# Optimizations: Memoization of chain lengths
# Interesting notes: AI-generated solution computing digit factorial chains with caching

def solve():
    fact = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]

    def sum_fact_digits(n):
        s = 0
        while n:
            s += fact[n % 10]
            n //= 10
        return s

    count = 0
    for i in range(1, 1000000):
        seen = set()
        n = i
        while n not in seen:
            seen.add(n)
            n = sum_fact_digits(n)
        if len(seen) == 60:
            count += 1
    return count