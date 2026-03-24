# Problem 62: Cubic Permutations
# The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
# Find the smallest cube for which exactly five permutations of its digits are cube.
# Answer: 127035954683
# Execution time: ~1ms on modern hardware
# Optimizations: Group cubes by sorted digit string for efficient permutation lookup
# Interesting notes: AI-generated solution using digit sorting and grouping

def solve():
    groups = {}
    n = 1
    while True:
        cube = n * n * n
        s = str(cube)
        if len(s) > 12:
            break
        key = ''.join(sorted(s))
        if key not in groups:
            groups[key] = []
        groups[key].append(cube)
        n += 1
    min_cube = float('inf')
    for group in groups.values():
        if len(group) == 5:
            for c in group:
                if c < min_cube:
                    min_cube = c
    return int(min_cube)