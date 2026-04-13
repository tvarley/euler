// Problem 97: Large Non-Mersenne Prime
//
// The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593 - 1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p - 1, have been found which contain more digits.
//
// However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433 × 2^7830457 + 1.
//
// Find the last ten digits of this prime number.
//
// Answer: 8739992577
//
// Execution time: ~0.01ms on modern hardware
//
// Optimizations: Modular arithmetic for large exponentiation
// Interesting notes: Computes (28433 * 2^7830457 + 1) mod 10^10

use num_bigint::BigUint;

pub fn large_non_mersenne_prime() -> String {
    let base: BigUint = 28433u64.into();
    let exp: u32 = 7830457;
    let modulus: BigUint = 10_000_000_000u64.into();
    let two: BigUint = 2u64.into();
    let pow = two.modpow(&exp.into(), &modulus);
    let result = (base * pow + 1u64) % modulus;
    format!("{:010}", result)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_097() {
        assert_eq!(large_non_mersenne_prime(), "8739992577");
    }
}