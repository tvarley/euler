# Problem 88: Product-sum numbers
# A natural number, N, that can be written as the sum and product of a given set of at least two natural numbers, {a1, a2, ... , ak} is called a product-sum number: N = a1 + a2 + ... + ak = a1 × a2 × ... × ak.
# For a given set of size, k, we shall call the smallest such N with a given set of size k a minimal product-sum number.
# Find the sum of all the minimal product-sum numbers for 2 ≤ k ≤ 12000.
# Answer: 7587457
# Execution time: ~500ms on modern hardware
# Optimizations: Use recursion to generate all possible factor sets
# Interesting notes: Adapted from C++ solution using recursive search

MAX_K = 12000
MAX_N = 200000

min_ps = [float('inf')] * (MAX_K + 1)

def find_min_ps(prod, sumf, numf, minf):
    if numf >= 2:
        k = prod - sumf + numf
        if k >= 2 and k <= MAX_K and prod < min_ps[k]:
            min_ps[k] = prod
    if prod > MAX_N // 2:
        return
    i = minf
    while True:
        if prod > MAX_N // i:
            break
        new_prod = prod * i
        if new_prod > MAX_N or new_prod // i != prod:
            break
        new_sum = sumf + i
        new_num = numf + 1
        est_k = new_prod - new_sum + new_num
        if est_k > MAX_K:
            break
        find_min_ps(new_prod, new_sum, new_num, i)
        i += 1

def solve():
    find_min_ps(1, 0, 0, 2)
    unique = set()
    for k in range(2, MAX_K + 1):
        if min_ps[k] != float('inf'):
            unique.add(min_ps[k])
    return sum(unique)

if __name__ == "__main__":
    print(solve())