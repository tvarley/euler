// https://projecteuler.net/problem=35
//
// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
// How many circular primes are there below one million?
//
// Answer: 55

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

pub fn circular_primes() -> u64 {
    let mut count = 0;
    for n in 2..1_000_000 {
        if is_prime(n) {
            let s = format!("{}", n);
            let mut is_circular = true;
            for i in 0..s.len() {
                let rotated: String = s[i..].to_string() + &s[0..i];
                let r: u64 = rotated.parse().unwrap();
                if !is_prime(r) {
                    is_circular = false;
                    break;
                }
            }
            if is_circular {
                count += 1;
            }
        }
    }
    count
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_035() {
        assert_eq!(circular_primes(), 55);
    }
}