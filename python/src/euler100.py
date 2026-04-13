# Problem 100: Arranged probability
# If a box contains twenty-one coloured discs, composed of fifteen blue discs and six red discs, and two discs were taken at random, it can be seen that the probability of taking two blue discs, P(BB) = (15/21)×(14/20) = 1/2.
# The next such arrangement, for which there is exactly 50% chance of taking two blue discs at random, is a box containing eighty-five blue discs and thirty-five red discs.
# By finding the first arrangement to contain over 10^12 discs in total, determine the number of blue discs that the box would contain.
# Answer: 756872327473
# Execution time: ~1ms on modern hardware
# Optimizations: Use the recurrence relation for efficiency
# Interesting notes: The total number of discs follows the recurrence t_{n+1} = 4*t_n + 3*t_{n-1} - 3, blue b_{n+1} = 3*b_n + 2*t_n - 2

def solve():
    b = 15
    n = 21
    while True:
        b_new = 3 * b + 2 * n - 2
        n_new = 4 * b + 3 * n - 3
        if n_new > 1000000000000:
            return b_new
        b = b_new
        n = n_new

if __name__ == "__main__":
    print(solve())