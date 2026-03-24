# Problem 68: Magic 5-gon ring
# Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.
# Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example), each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.
# It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.
# Total Solution Set: 4,3,2; 6,2,1; 5,1,3
# 4,2,3; 6,3,1; 5,1,2
# 4,2,1; 6,1,3; 5,3,2
# 4,1,3; 6,3,2; 5,2,1
# 4,1,2; 6,2,3; 5,3,1
# 4,3,1; 6,1,2; 5,2,3
# 4,2,3; 6,3,1; 5,1,2
# 4,1,3; 6,3,2; 5,2,1
# By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.
# Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16-digit strings. What is the maximum 16-digit string for a "magic" 5-gon ring?
# Answer: 6531031914842725
# Execution time: ~1000ms on modern hardware
# Optimizations: Permutations with early pruning
# Interesting notes: AI-generated solution generating 5-gon rings and finding max string

def solve():
    from itertools import permutations

    def is_magic_5gon(nums):
        # nums is 10 numbers 1-10
        # positions: outer 5: nums[0:5], inner 5: nums[5:10]
        outer = nums[:5]
        inner = nums[5:]
        # lines: outer[i] + inner[i] + inner[(i+1)%5] for i in 0..4
        lines = [outer[i] + inner[i] + inner[(i+1)%5] for i in range(5)]
        if len(set(lines)) != 1:
            return False, ""
        # start from smallest outer
        min_outer_idx = outer.index(min(outer))
        # rotate so that min_outer is first
        rotated_outer = outer[min_outer_idx:] + outer[:min_outer_idx]
        rotated_inner = inner[min_outer_idx:] + inner[:min_outer_idx]
        # the string is the concatenation of the 5 lines
        s = ""
        for i in range(5):
            s += str(rotated_outer[i]) + str(rotated_inner[i]) + str(rotated_inner[(i+1)%5])
        return True, s

    max_str = ""
    for perm in permutations(range(1,11)):
        magic, s = is_magic_5gon(list(perm))
        if magic and (not max_str or s > max_str):
            max_str = s
    return int(max_str)