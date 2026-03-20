// https://projecteuler.net/problem=58
//
// Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
// [diagram]
// It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.
// If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed.
// If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
//
// Answer: 26241

pub fn spiral_primes() -> u32 {
    let mut side = 1;
    let mut primes = 0;
    let mut total = 1;
    let mut current = 1;
    loop {
        side += 2;
        for _ in 0..4 {
            current += side - 1;
            total += 1;
            if is_prime(current) {
                primes += 1;
            }
        }
        if primes * 10 < total {
            return side;
        }
    }
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
    fn euler_058() {
        assert_eq!(spiral_primes(), 26241);
    }
}