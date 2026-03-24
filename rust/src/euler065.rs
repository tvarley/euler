// Problem 65: Convergents of e

// The square root of 2 can be written as an infinite continued fraction.
// √2 = 1 + 1/(2 + 1/(2 + 1/(2 + ...)))
// The infinite continued fraction can be written, √2 = [1;(2)], (2) indicates that 2 repeats ad infinitum.
// In a similar way, √23 = [4; (1,3,1,8)].
// It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations.
// Let us consider the convergents for √2.
// 1 + 1/2 = 3/2
// 1 + 1/(2 + 1/2) = 7/5
// 1 + 1/(2 + 1/(2 + 1/2)) = 17/12
// 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29
// Hence the sequence of the first ten convergents for √2 are:
// 1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...
// What is most surprising is that the important mathematical constant,
// e = [2; 1, 2, 1, 1, 4, 1, ..., 1, 2k, 1, ...]
// The first ten terms in the sequence of convergents for e are:
// 2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
// The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
// Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.

// Answer: 272

// Execution time: ~0ms on modern hardware

// Optimizations: Simple big integer arithmetic using strings for numerator calculation
// Interesting notes: AI-generated solution implementing continued fraction convergents with string-based big integers

use num_bigint::BigInt;
use num_traits::Zero;

pub fn convergents_of_e() -> u32 {
    let mut terms = vec![2];
    let mut k = 1;
    while terms.len() < 101 {
        terms.push(1);
        terms.push(2 * k);
        terms.push(1);
        k += 1;
    }
    let mut h_prev2 = BigInt::zero();
    let mut h_prev1 = BigInt::from(1);
    let mut k_prev2 = BigInt::from(1);
    let mut k_prev1 = BigInt::zero();
    for i in 0..100 {
        let h = &h_prev1 * terms[i] + &h_prev2;
        let k = &k_prev1 * terms[i] + &k_prev2;
        h_prev2 = h_prev1.clone();
        h_prev1 = h;
        k_prev2 = k_prev1.clone();
        k_prev1 = k;
    }
    h_prev1.to_string().chars().map(|c| c.to_digit(10).unwrap()).sum()
}