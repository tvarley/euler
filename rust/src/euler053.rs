// https://projecteuler.net/problem=53
//
// There are exactly ten ways of selecting three from five, 12345: 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
// In combinatorics, we use the notation, \binom 5 3 = 10.
// In general, \binom n r = \dfrac{n!}{r!(n-r)!}, where r \le n, n! = n \times (n-1) \times ... \times 3 \times 2 \times 1, and 0! = 1.
// It is not until n = 23, that a value exceeds one-million: \binom {23} {10} = 1144066.
// How many, not necessarily distinct, values of \binom n r for 1 \le n \le 100, are greater than one-million?
//
// Answer: 4075

pub fn combinatoric_selections() -> u64 {
    let mut count = 0;
    for n in 1..=100 {
        for r in 0..=n {
            if binomial(n, r) > 1000000 {
                count += 1;
            }
        }
    }
    count
}

fn binomial(n: u64, k: u64) -> u64 {
    if k > n { return 0; }
    let k = k.min(n - k);
    let mut res = 1u64;
    for i in 0..k {
        res = res.saturating_mul(n - i);
        res = res / (i + 1);
    }
    res
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_053() {
        assert_eq!(combinatoric_selections(), 4075);
    }
}