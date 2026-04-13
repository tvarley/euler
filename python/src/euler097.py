# Problem 97: Large non-Mersenne prime
# Find the last ten digits of 28433×2^7830457+1.
# Answer: 8739992577
# Execution time: ~1ms on modern hardware
# Optimizations: Modular exponentiation
# Interesting notes: AI-generated solution using fast exponentiation

def solve():
    base = 28433
    exp = 7830457
    mod = 10**10
    result = pow(2, exp, mod) * base % mod + 1
    return result

if __name__ == "__main__":
    print(solve())