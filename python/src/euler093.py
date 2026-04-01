from itertools import combinations, permutations
# Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers, 1 to n, can be found.
# Answer: 1258
# Execution time: ~1000ms on modern hardware
# Optimizations: Recursive evaluation of all possible expressions
# Interesting notes: AI-generated solution using recursive expression evaluation

def evaluate_rec(nums):
    if len(nums) == 1:
        return {nums[0]}
    results = set()
    for i in range(1, len(nums)):
        left = nums[:i]
        right = nums[i:]
        left_vals = evaluate_rec(left)
        right_vals = evaluate_rec(right)
        for lv in left_vals:
            for rv in right_vals:
                results.add(lv + rv)
                results.add(lv - rv)
                results.add(lv * rv)
                if rv != 0:
                    results.add(lv / rv)
    return results

def evaluate(nums):
    doubles = evaluate_rec(nums)
    return {int(d) for d in doubles if d > 0 and d == int(d)}

def solve():
    digits = list(range(1, 10))
    max_n = 0
    best_set = ""
    for combo in combinations(digits, 4):
        values = set()
        for perm in permutations(combo):
            res = evaluate(perm)
            values.update(res)
        # find longest consecutive from 1
        n = 0
        while n + 1 in values:
            n += 1
        if n > max_n:
            max_n = n
            best_set = ''.join(map(str, sorted(combo)))
    return int(best_set)

if __name__ == "__main__":
    print(solve())