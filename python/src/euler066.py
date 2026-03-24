# Problem 66: Diophantine equation
# Consider quadratic Diophantine equations of the form:
# x² – D y² = 1
# For example, when D=13, the minimal solution in x is 649² – 13×180² = 1.
# It can be assumed that there are no solutions in positive integers when D is square.
# By finding minimal solutions in x for D ≤ 1000, find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.
# Answer: 661
# Execution time: ~100ms on modern hardware
# Optimizations: Continued fraction algorithm with big integer arithmetic
# Interesting notes: AI-generated solution using continued fraction convergents to solve Pell equations

def solve():
    import math
    def minimal_solution(d):
        if int(math.sqrt(d))**2 == d:
            return 0, 0
        a0 = int(math.sqrt(d))
        m = 0
        dv = 1
        a = a0
        h = a0
        k = 1
        if h*h - d*k*k == 1:
            return h, k
        hm2 = 1
        hm1 = a0
        km2 = 0
        km1 = 1
        while True:
            m = dv * a - m
            dv = (d - m*m) // dv
            a = (a0 + m) // dv
            hh = a * hm1 + hm2
            kk = a * km1 + km2
            if hh*hh - d*kk*kk == 1:
                return hh, kk
            hm2 = hm1
            hm1 = hh
            km2 = km1
            km1 = kk
    max_x = 0
    max_d = 0
    for d in range(2, 1001):
        x, _ = minimal_solution(d)
        if x > max_x:
            max_x = x
            max_d = d
    return max_d