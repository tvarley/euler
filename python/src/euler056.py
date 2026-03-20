# Problem 56: Powerful Digit Sum
# A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
# Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
# Answer: 972
# Execution time: Approximately 0.5 seconds
# Optimizations: Computed powers directly and summed digits from string representation, iterated over all possible a and b values.
# Notes: The maximum occurs for large a and b, requiring efficient digit summation.
def solve():
    max_sum = 0
    for a in range(1, 100):
        for b in range(1, 100):
            num_str = str(a ** b)
            digit_sum = sum(int(d) for d in num_str)
            if digit_sum > max_sum:
                max_sum = digit_sum
    return max_sum