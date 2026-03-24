// Problem 64: Odd Period Square Roots

// All square roots are periodic when written as continued fractions and can be written in the form:
// √N=a0 + 1 / (a1 + 1 / (a2 + 1 / (a3 + ...)))
// For example, let us consider √23:
// √23 = 4 + √23-4=4 + 1 / (1 / (√23-4)) = 4+1 / (1 + (√23-3)/7)
// If we continue we would get the following expansion:
// √23=4 + 1 / (1 + 1 / (3+ 1 / (1 + 1 / (8+ ...))))
// The process can be summarised as follows:
// a0 = 4, 1/(√23-4)= (√23+4)/7=1 + (√23-3)/7
// a1 = 1, 7/(√23-3)=7(√23+3)/14=3 + (√23-3)/2
// a2 = 3, 2/(√23-3)=2(√23+3)/14=1 + (√23-4)/7
// a3 = 1, 7/(√23-4)=7(√23+4)/7=8+√23-4
// a4 = 8, 1/(√23-4)= (√23+4)/7=1 + (√23-3)/7
// a5 = 1, 7/(√23-3)=7(√23+3)/14=3 + (√23-3)/2
// a6 = 3, 2/(√23-3)=2(√23+3)/14=1 + (√23-4)/7
// a7 = 1, 7/(√23-4)=7(√23+4)/7=8+√23-4
// It can be seen that the sequence is repeating. For conciseness, we use the notation √23=[4;(1,3,1,8)], to indicate that the block (1,3,1,8) repeats indefinitely.
// The first ten continued fraction representations of (irrational) square roots are:
// √2=[1;(2)], period=1
// √3=[1;(1,2)], period=2
// √5=[2;(4)], period=1
// √6=[2;(2,4)], period=2
// √7=[2;(1,1,1,4)], period=4
// √8=[2;(1,4)], period=2
// √10=[3;(6)], period=1
// √11=[3;(3,6)], period=2
// √12=[3;(2,6)], period=2
// √13=[3;(1,1,1,1,6)], period=5
// Exactly four continued fractions, for N ≤ 13, have an odd period.
// How many continued fractions for N ≤ 10000 have an odd period?

// Answer: 1322

// Execution time: ~50ms on modern hardware

// Optimizations: Efficient continued fraction period calculation using integer arithmetic
// Interesting notes: AI-generated solution implementing the standard continued fraction algorithm for square roots

use std::collections::HashSet;

pub fn odd_period_square_roots() -> u32 {
    let mut count = 0;
    for n in 2..=10000 {
        let sqrt_n = (n as f64).sqrt() as i64;
        if sqrt_n * sqrt_n == n as i64 {
            continue;
        }
        let mut period = 0;
        let mut a = sqrt_n;
        let mut m = 0i64;
        let mut d = 1i64;
        let mut seen = HashSet::new();
        loop {
            let next_m = d * a - m;
            let next_d = (n as i64 - next_m * next_m) / d;
            let next_a = (sqrt_n + next_m) / next_d;
            period += 1;
            let state = (next_m, next_d, next_a);
            if seen.contains(&state) {
                break;
            }
            seen.insert(state);
            m = next_m;
            d = next_d;
            a = next_a;
        }
        if (period - 1) % 2 == 1 {
            count += 1;
        }
    }
    count
}