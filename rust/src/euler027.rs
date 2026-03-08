// https://projecteuler.net/problem=27
//
// Euler discovered the remarkable quadratic formula: n² + n + 41
// It turns out that the formula n² − 79n + 1601 is remarkable: for n = 0 to 79 it
// produces 80 primes.
//
// Considering quadratics of the form: n² + an + b, where |a| < 1000 and |b| ≤ 1000,
// find the product of the coefficients, a and b, for the quadratic expression that
// produces the maximum number of primes for consecutive values of n, starting with n = 0.
//
// Answer: -59231

fn is_prime(n: i64) -> bool {
    if n < 2 {
        return false;
    }
    if n == 2 {
        return true;
    }
    if n % 2 == 0 {
        return false;
    }
    let mut i = 3i64;
    while i * i <= n {
        if n % i == 0 {
            return false;
        }
        i += 2;
    }
    true
}

pub fn quadratic_primes() -> i64 {
    let mut best_count = 0i64;
    let mut best_product = 0i64;
    for a in -999i64..1000 {
        for b in -1000i64..=1000 {
            let mut n = 0i64;
            while is_prime(n * n + a * n + b) {
                n += 1;
            }
            if n > best_count {
                best_count = n;
                best_product = a * b;
            }
        }
    }
    best_product
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_027() {
        assert_eq!(quadratic_primes(), -59231);
    }
}
