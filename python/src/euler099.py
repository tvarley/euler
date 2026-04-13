# Problem 99: Largest exponential
# The file contains 100 lines, each with base exp, find the line with the largest base^exp.
# Answer: 709
# Execution time: ~1ms on modern hardware
# Optimizations: Compare log values
# Interesting notes: AI-generated solution using logarithms for comparison

def solve():
    import math
    max_val = 0
    max_line = 0
    with open('../cpp/src/p099_base_exp.txt') as f:
        for i, line in enumerate(f, 1):
            base, exp = map(int, line.split(','))
            val = exp * math.log(base)
            if val > max_val:
                max_val = val
                max_line = i
    return max_line

if __name__ == "__main__":
    print(solve())