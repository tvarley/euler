// Problem 70: Totient permutation

// Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n that are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
// The number 87109 has a special property; it is a permutation of 79180, the value of φ(87109). In other words, 87109 is a permutation of 79180.
// Find the value of n, 1 < n < 10^7, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.

// Answer: 8319823

// Execution time: ~1000ms on modern hardware

// Optimizations: Precompute primes, sieve for phi, check digit permutations
// Interesting notes: AI-generated solution using prime sieve and digit sorting for permutation check

pub fn totient_permutation() -> u64 {
    const LIMIT: usize = 10_000_000;
    let mut phi = vec![0usize; LIMIT];
    let mut primes = vec![];
    let mut is_prime = vec![true; LIMIT];
    is_prime[0] = false;
    is_prime[1] = false;
    for i in 2..LIMIT {
        if is_prime[i] {
            primes.push(i);
            phi[i] = i - 1;
        }
        for &p in &primes {
            if i * p >= LIMIT {
                break;
            }
            is_prime[i * p] = false;
            if i % p == 0 {
                phi[i * p] = phi[i] * p;
                break;
            } else {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
    let mut min_ratio = f64::INFINITY;
    let mut result = 0u64;
    for n in 2..LIMIT {
        let p = phi[n];
        if (n as f64) / (p as f64) < min_ratio && is_permutation(n, p) {
            min_ratio = n as f64 / p as f64;
            result = n as u64;
        }
    }
    result
}

fn is_permutation(a: usize, b: usize) -> bool {
    let mut a_digits: Vec<char> = a.to_string().chars().collect();
    let mut b_digits: Vec<char> = b.to_string().chars().collect();
    a_digits.sort();
    b_digits.sort();
    a_digits == b_digits
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_070() {
        assert_eq!(totient_permutation(), 8319823);
    }
}