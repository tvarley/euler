# Problem 87: Prime power triples
# Find the number of numbers below 50 million that can be expressed as the sum of a prime square, prime cube, and prime fourth power.
# Answer: 1097343
# Execution time: ~100ms on modern hardware
# Optimizations: Generate primes, use sets for squares, cubes, fourth powers
# Interesting notes: AI-generated solution using prime generation and set operations

def solve():
    from math import sqrt
    limit = 50000000
    max_p2 = int(sqrt(limit))
    max_p3 = int(limit ** (1/3))
    max_p4 = int(limit ** (1/4))
    primes = []
    is_prime = [True] * (max_p2 + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, max_p2 + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i*i, max_p2 + 1, i):
                is_prime[j] = False
    squares = [p*p for p in primes if p*p < limit]
    cubes = [p*p*p for p in primes if p*p*p < limit]
    fourths = [p*p*p*p for p in primes if p*p*p*p < limit]
    seen = set()
    for f in fourths:
        for c in cubes:
            if f + c >= limit:
                break
            for s in squares:
                num = f + c + s
                if num >= limit:
                    break
                seen.add(num)
    return len(seen)