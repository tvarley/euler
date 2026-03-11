// https://projecteuler.net/problem=37
//
// The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
//
// Answer: 748317

fn is_prime(n: u64) -> bool {
    if n < 2 {
        return false;
    }
    if n == 2 || n == 3 {
        return true;
    }
    if n % 2 == 0 || n % 3 == 0 {
        return false;
    }
    let mut i = 5;
    while i * i <= n {
        if n % i == 0 || n % (i + 2) == 0 {
            return false;
        }
        i += 6;
    }
    true
}

pub fn truncatable_primes() -> u64 {
    let mut sum = 0;
    let mut count = 0;
    let mut n = 11;
    while count < 11 {
        if is_prime(n) {
            let s = format!("{}", n);
            let mut left_ok = true;
            let mut right_ok = true;
            for i in 1..s.len() {
                let trunc: u64 = s[i..].parse().unwrap();
                if !is_prime(trunc) {
                    left_ok = false;
                    break;
                }
            }
            for i in (1..s.len()).rev() {
                let trunc: u64 = s[0..i].parse().unwrap();
                if !is_prime(trunc) {
                    right_ok = false;
                    break;
                }
            }
            if left_ok && right_ok {
                sum += n;
                count += 1;
            }
        }
        n += 2;
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_037() {
        assert_eq!(truncatable_primes(), 748317);
    }
}