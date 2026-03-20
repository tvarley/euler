// https://projecteuler.net/problem=10
//
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.
//
// Answer: 142913828922

pub fn sum_primes_below(limit: usize) -> u64 {
    let mut is_prime = vec![true; limit + 1];
    is_prime[0] = false;
    if limit > 0 {
        is_prime[1] = false;
    }
    for i in 2..((limit as f64).sqrt() as usize + 1) {
        if is_prime[i] {
            for multiple in ((i*i)..=limit).step_by(i) {
                is_prime[multiple] = false;
            }
        }
    }
    let mut sum = 0u64;
    for (i, &prime) in is_prime.iter().enumerate().skip(2).take(limit - 1) {
        if prime {
            sum += i as u64;
        }
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_010() {
        assert_eq!(sum_primes_below(10), 17);
        assert_eq!(sum_primes_below(2_000_000), 142_913_828_922);
    }
}