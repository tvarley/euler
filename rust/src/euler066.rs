// Problem 66: Diophantine equation

// Consider quadratic Diophantine equations of the form:
// x² – D y² = 1
// For example, when D=13, the minimal solution in x is 649² – 13×180² = 1.
// It can be assumed that there are no solutions in positive integers when D is square.
// By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:
// 3² – 2×2² = 1
// 2² – 3×1² = 1
// 9² – 5×4² = 1
// 5² – 6×2² = 1
// 8² – 7×3² = 1
// Hence the largest x is 9.
// Find the value of D ≤ 1000 in minimal solutions of x² – D y² = 1 that gives the maximal x.

// Answer: 661

// Execution time: ~10ms on modern hardware

// Optimizations: Continued fraction algorithm for solving Pell equations efficiently
// Interesting notes: AI-generated solution using continued fraction convergents to find minimal solutions

use num_bigint::BigInt;
use num_traits::Zero;

fn is_square(n: u64) -> bool {
    let sqrt = (n as f64).sqrt() as u64;
    sqrt * sqrt == n
}

fn continued_fraction_sqrt(d: u64) -> (BigInt, BigInt) {
    if is_square(d) {
        return (BigInt::zero(), BigInt::zero());
    }
    let a0 = (d as f64).sqrt() as u64;
    let mut m = 0u64;
    let mut d_val = 1u64;
    let mut a = a0;
    let mut h_prev2 = BigInt::from(1u64);
    let mut h_prev1 = BigInt::from(a0);
    let mut k_prev2 = BigInt::zero();
    let mut k_prev1 = BigInt::from(1u64);
    let mut h = BigInt::from(a0);
    let mut k = BigInt::from(1u64);
    if &h * &h - BigInt::from(d) * &k * &k == BigInt::from(1) {
        return (h, k);
    }
    loop {
        m = d_val * a - m;
        d_val = (d - m * m) / d_val;
        a = (a0 + m) / d_val;
        let term = BigInt::from(a);
        h = &h_prev1 * &term + &h_prev2;
        k = &k_prev1 * &term + &k_prev2;
        if &h * &h - BigInt::from(d) * &k * &k == BigInt::from(1) {
            return (h, k);
        }
        h_prev2 = h_prev1.clone();
        h_prev1 = h.clone();
        k_prev2 = k_prev1.clone();
        k_prev1 = k.clone();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_066() {
        assert_eq!(diophantine_equation(), 661);
    }
}

pub fn diophantine_equation() -> u64 {
    let mut max_x = BigInt::zero();
    let mut max_d = 0;
    for d in 2..=1000 {
        if is_square(d) {
            continue;
        }
        let (x, _) = continued_fraction_sqrt(d);
        if x > max_x {
            max_x = x;
            max_d = d;
        }
    }
    max_d
}