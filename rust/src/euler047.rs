// https://projecteuler.net/problem=47
//
// The first two consecutive numbers to have two distinct prime factors are:
// 14 = 2 × 7
// 15 = 3 × 5.
// The first three consecutive numbers to have three distinct prime factors are:
// 644 = 2² × 7 × 23
// 645 = 3 × 5 × 43
// 646 = 2 × 17 × 19.
// Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
//
// Answer: 134043

pub fn distinct_primes_factors() -> u64 {
    let mut n = 2;
    loop {
        if count_distinct_prime_factors(n) == 4 &&
           count_distinct_prime_factors(n + 1) == 4 &&
           count_distinct_prime_factors(n + 2) == 4 &&
           count_distinct_prime_factors(n + 3) == 4 {
            return n;
        }
        n += 1;
    }
}

fn count_distinct_prime_factors(mut n: u64) -> usize {
    let mut count = 0;
    if n % 2 == 0 {
        count += 1;
        while n % 2 == 0 {
            n /= 2;
        }
    }
    let mut i = 3;
    while i * i <= n {
        if n % i == 0 {
            count += 1;
            while n % i == 0 {
                n /= i;
            }
        }
        i += 2;
    }
    if n > 1 {
        count += 1;
    }
    count
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_047() {
        assert_eq!(distinct_primes_factors(), 134043);
    }
}