# Problem 60: Prime Pair Sets
# The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.
# Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
# Answer: 26033
# Execution time: About 10 seconds
# Optimizations: Limited prime generation to under 10000, used early termination in nested loops when concatenation fails.
# Notes: Required checking all pairwise concatenations for primality, which is computationally intensive but feasible for small primes.
def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

def concat_prime(a, b):
    return is_prime(int(str(a) + str(b))) and is_prime(int(str(b) + str(a)))

def solve():
    primes = [p for p in range(2, 10000) if is_prime(p)]
    for i in range(len(primes)):
        p1 = primes[i]
        for j in range(i + 1, len(primes)):
            p2 = primes[j]
            if not concat_prime(p1, p2):
                continue
            for k in range(j + 1, len(primes)):
                p3 = primes[k]
                if not (concat_prime(p1, p3) and concat_prime(p2, p3)):
                    continue
                for l in range(k + 1, len(primes)):
                    p4 = primes[l]
                    if not all(concat_prime(x, p4) for x in [p1, p2, p3]):
                        continue
                    for m in range(l + 1, len(primes)):
                        p5 = primes[m]
                        if all(concat_prime(x, p5) for x in [p1, p2, p3, p4]):
                            return p1 + p2 + p3 + p4 + p5