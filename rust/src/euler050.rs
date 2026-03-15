// https://projecteuler.net/problem=50
//
// The prime 41, can be written as the sum of six consecutive primes:
// 41 = 2 + 3 + 5 + 7 + 11 + 13.
// This is the longest sum of consecutive primes that adds to a prime below one-hundred.
// The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
// Which prime, below one-million, can be written as the sum of the most consecutive primes?
//
// Answer: 997651

pub fn consecutive_prime_sum() -> u64 {
    let primes = generate_primes(1000000);
    let mut max_len = 0;
    let mut max_prime = 0;
    for start in 0..primes.len() {
        let mut sum = 0u64;
        for end in start..primes.len() {
            sum += primes[end] as u64;
            if sum >= 1000000 { break; }
            let len = end - start + 1;
            if len > max_len && is_prime(sum as u32) {
                max_len = len;
                max_prime = sum;
            }
        }
    }
    max_prime
}

fn generate_primes(limit: u32) -> Vec<u32> {
    let mut sieve = vec![true; limit as usize + 1];
    sieve[0] = false;
    sieve[1] = false;
    for i in 2..=(limit as f64).sqrt() as usize {
        if sieve[i] {
            for j in ((i * i)..=limit as usize).step_by(i) {
                sieve[j] = false;
            }
        }
    }
    (2..=limit).filter(|&x| sieve[x as usize]).collect()
}

fn is_prime(n: u32) -> bool {
    if n < 2 { return false; }
    if n == 2 || n == 3 { return true; }
    if n % 2 == 0 || n % 3 == 0 { return false; }
    let mut i = 5u32;
    while (i as u64) * (i as u64) <= n as u64 {
        if n % i == 0 || n % (i + 2) == 0 { return false; }
        i += 6;
    }
    true
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_050() {
        assert_eq!(consecutive_prime_sum(), 997651);
    }
}