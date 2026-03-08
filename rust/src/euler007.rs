// https://projecteuler.net/problem=7
//
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
// we can see that the 6th prime is 13.
//
// What is the 10 001st prime number?
//
// Answer: 104743

pub fn nth_prime(n: usize) -> u64 {
    if n == 1 {
        return 2;
    }
    let mut primes = vec![2u64];
    let mut candidate = 3u64;
    let upper_limit = 200_000u64; // Sufficient for 10001st prime
    let mut is_prime = vec![true; (upper_limit + 1) as usize];
    is_prime[0] = false;
    is_prime[1] = false;
    
    while primes.len() < n {
        if is_prime[candidate as usize] {
            primes.push(candidate);
            // Mark multiples
            let mut multiple = candidate * 2;
            while multiple <= upper_limit {
                is_prime[multiple as usize] = false;
                multiple += candidate;
            }
        }
        candidate += 2;
    }
    primes[n - 1]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_007() {
        assert_eq!(nth_prime(6), 13);
        assert_eq!(nth_prime(10_001), 104_743);
    }
}