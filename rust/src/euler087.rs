// Problem 87: Prime Power Triples
//
// The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28.
//
// In fact, there are exactly four numbers below fifty that can be expressed in such a way:
//
// 28 = 2^2 + 2^3 + 2^4
// 33 = 3^2 + 2^3 + 2^4
// 49 = 5^2 + 2^3 + 2^4
// 47 = 2^2 + 3^3 + 2^4
//
// How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
//
// Answer: 1097343
//
// Execution time: ~100ms on modern hardware
//
// Optimizations: Generate primes, use sets for unique sums
// Interesting notes: Precomputes primes and finds all unique sums below limit

use std::collections::HashSet;

pub fn prime_power_triples() -> usize {
    const LIMIT: usize = 50_000_000;
    let primes = sieve((LIMIT as f64).sqrt() as usize + 1);
    let mut sums = HashSet::new();
    for &p2 in &primes {
        let sq = p2 * p2;
        if sq >= LIMIT { break; }
        for &p3 in &primes {
            let cb = p3 * p3 * p3;
            if sq + cb >= LIMIT { break; }
            for &p4 in &primes {
                let fq = p4 * p4 * p4 * p4;
                let sum = sq + cb + fq;
                if sum >= LIMIT { break; }
                sums.insert(sum);
            }
        }
    }
    sums.len()
}

fn sieve(limit: usize) -> Vec<usize> {
    let mut is_prime = vec![true; limit + 1];
    is_prime[0] = false;
    if limit > 0 {
        is_prime[1] = false;
    }
    for i in 2..=((limit as f64).sqrt() as usize) {
        if is_prime[i] {
            for j in (i * i..=limit).step_by(i) {
                is_prime[j] = false;
            }
        }
    }
    (2..=limit).filter(|&x| is_prime[x]).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_087() {
        assert_eq!(prime_power_triples(), 1097343);
    }
}