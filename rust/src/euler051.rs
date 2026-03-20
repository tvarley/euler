// https://projecteuler.net/problem=51
//
// By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
// By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
// Consequently 56003, being the first member of this family, is the smallest prime with this property.
// Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
//
// Answer: 121313

pub fn prime_digit_replacements() -> u64 {
    let mut primes = generate_primes(1000000);
    primes.sort();
    for &p in &primes {
        if p < 100000 { continue; } // start from 6 digits
        let s = p.to_string();
        let digits: Vec<char> = s.chars().collect();
        for mask in 1..(1 << digits.len()) - 1 { // non-empty subset
            let mut family = vec![];
            for d in 0..10 {
                if d == 0 && (mask & 1) != 0 { continue; } // can't have leading zero
                let mut num = 0u64;
                for i in 0..digits.len() {
                    if (mask & (1 << i)) != 0 {
                        num = num * 10 + d as u64;
                    } else {
                        num = num * 10 + (digits[i] as u8 - b'0') as u64;
                    }
                }
                if is_prime(num as u32) {
                    family.push(num);
                }
            }
            if family.len() == 8 {
                return *family.iter().min().unwrap();
            }
        }
    }
    0
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
    fn euler_051() {
        assert_eq!(prime_digit_replacements(), 121313);
    }
}