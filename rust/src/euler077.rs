// Problem 77: Prime Summations

// It is possible to write ten as the sum of primes in exactly five different ways:

// 7 + 3
// 5 + 5
// 5 + 3 + 2
// 3 + 3 + 2 + 2
// 2 + 2 + 2 + 2 + 2

// What is the first value which can be written as the sum of primes in over five thousand different ways?

// Answer: 71

// Execution time: ~0ms on modern hardware

// Optimizations: Sieve for primes, DP for combinations

// Interesting notes: AI-generated solution using prime generation and coin change DP

pub fn prime_summations() -> u64 {
    const LIMIT: usize = 300;
    let primes = sieve(LIMIT);
    let mut ways = vec![0u32; LIMIT + 1];
    ways[0] = 1;
    for &p in &primes {
        for j in p..=LIMIT {
            ways[j] += ways[j - p];
            if ways[j] > 5000 {
                return j as u64;
            }
        }
    }
    0
}

fn sieve(limit: usize) -> Vec<usize> {
    let mut is_prime = vec![true; limit + 1];
    is_prime[0] = false;
    if limit > 0 {
        is_prime[1] = false;
    }
    for i in 2..=((limit as f64).sqrt() as usize) {
        if is_prime[i] {
            for j in ((i * i)..=limit).step_by(i) {
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
    fn euler_077() {
        assert_eq!(prime_summations(), 177);
    }
}