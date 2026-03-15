def solve():
    """
    Prime Permutations
    The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

    There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

    What 12-digit number do you form by concatenating the three terms in this sequence?
    https://projecteuler.net/problem=49
    """
    def is_prime(n):
        if n < 2:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True

    primes = []
    for i in range(1000, 10000):
        if is_prime(i):
            primes.append(i)

    from collections import defaultdict
    groups = defaultdict(list)
    for p in primes:
        key = ''.join(sorted(str(p)))
        groups[key].append(p)

    all_sequences = []
    for key, group in groups.items():
        if len(group) >= 3:
            group.sort()
            for i in range(len(group) - 2):
                for j in range(i + 1, len(group) - 1):
                    for k in range(j + 1, len(group)):
                        if group[k] - group[j] == group[j] - group[i]:
                            all_sequences.append(str(group[i]) + str(group[j]) + str(group[k]))
    all_sequences.sort()
    return all_sequences[1]
    return None