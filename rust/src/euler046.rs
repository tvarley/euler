// https://projecteuler.net/problem=46
//
// It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
// 9 = 7 + 2×1²
// 15 = 7 + 2×2²
// 21 = 3 + 2×3²
// 25 = 7 + 2×3²
// 27 = 19 + 2×2²
// 33 = 31 + 2×1²
// It turns out that the conjecture was false.
// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
//
// Answer: 5777

pub fn goldbachs_other_conjecture() -> u64 {
    let mut n = 9;
    loop {
        if !is_prime(n) && n % 2 == 1 && !can_write_as_prime_plus_twice_square(n) {
            return n;
        }
        n += 2;
    }
}

fn is_prime(n: u64) -> bool {
    if n < 2 { return false; }
    if n == 2 || n == 3 { return true; }
    if n % 2 == 0 || n % 3 == 0 { return false; }
    let mut i = 5;
    while i * i <= n {
        if n % i == 0 || n % (i + 2) == 0 { return false; }
        i += 6;
    }
    true
}

fn can_write_as_prime_plus_twice_square(n: u64) -> bool {
    let mut p = 2;
    while p < n {
        if is_prime(p) {
            let diff = n - p;
            if diff % 2 == 0 {
                let sq = diff / 2;
                let root = (sq as f64).sqrt() as u64;
                if root * root == sq {
                    return true;
                }
            }
        }
        p += 1;
    }
    false
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_046() {
        assert_eq!(goldbachs_other_conjecture(), 5777);
    }
}