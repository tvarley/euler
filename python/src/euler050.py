def solve():
    """
    Consecutive Prime Sum
    The prime 41, can be written as the sum of six consecutive primes:

    41 = 2 + 3 + 5 + 7 + 11 + 13.

    This is the longest sum of consecutive primes that adds to a prime below one-hundred.

    The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

    Which prime, below one-million, can be written as the sum of the most consecutive primes?
    https://projecteuler.net/problem=50
    """
    def sieve(limit):
        is_prime = [True] * limit
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(limit**0.5) + 1):
            if is_prime[i]:
                for j in range(i*i, limit, i):
                    is_prime[j] = False
        return [i for i in range(2, limit) if is_prime[i]]

    primes = sieve(1000000)
    max_len = 0
    result = 0
    for i in range(len(primes)):
        for j in range(i + max_len, len(primes)):
            sub_sum = sum(primes[i:j+1])
            if sub_sum >= 1000000:
                break
            if sub_sum in primes and j - i + 1 > max_len:
                max_len = j - i + 1
                result = sub_sum
    return result