# Problem 57: Square Root Convergents
# It is possible to show that the square root of two can be expressed as an infinite continued fraction.
# √2 =1+ 1/(2+ 1/(2 +1/(2+ ...)))
# By expanding this for the first four iterations, we get:
# 1 + 1/2 = 3/2 = 1.5
# 1 + 1/(2 + 1/2) = 7/5 = 1.4
# 1 + 1/(2 + 1/(2+1/2)) = 17/12 = 1.41666...
# 1 + 1/(2 + 1/(2+1/(2+1/2))) = 41/29 = 1.41379...
# The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
# In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?
# Answer: 153
# Execution time: Instantaneous
# Optimizations: Used recurrence relations for numerator and denominator to generate convergents efficiently without fraction arithmetic.
# Notes: The convergent fractions follow a specific pattern that can be computed iteratively.
def solve():
    count = 0
    h = [1, 3]
    k = [1, 2]
    for i in range(2, 1001):
        h.append(h[i-1] * 2 + h[i-2])
        k.append(k[i-1] * 2 + k[i-2])
        if len(str(h[i])) > len(str(k[i])):
            count += 1
    return count