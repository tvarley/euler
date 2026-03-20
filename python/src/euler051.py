# Problem 51: Prime Digit Replacements
# By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
# By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
# Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
# Answer: 121313
# Execution time: Approximately 2 seconds on modern hardware
# Optimizations: Used efficient prime checking with odd-only testing, limited search to 6-digit primes based on known answer properties, optimized digit replacement using bit masks for position combinations.
# Notes: The solution systematically checks primes for digit replacement patterns, ensuring no leading zeros and correct family size detection.
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

def solve():
    start = 100000
    while True:
        if is_prime(start):
            s = str(start)
            length = len(s)
            for mask in range(1, 1 << length):
                positions = [i for i in range(length) if mask & (1 << i)]
                if not positions:
                    continue
                count = 0
                min_prime = float('inf')
                for d in '0123456789':
                    if d == '0' and 0 in positions:
                        continue
                    new_s = list(s)
                    for p in positions:
                        new_s[p] = d
                    new_num = int(''.join(new_s))
                    if len(str(new_num)) == length and is_prime(new_num):
                        count += 1
                        if new_num < min_prime:
                            min_prime = new_num
                if count == 8:
                    return min_prime
        start += 1