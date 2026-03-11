// https://projecteuler.net/problem=34
//
// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
// Find the sum of all numbers which are equal to the sum of the factorial of their digits.
// Note: As 1! = 1 and 2! = 2 are not sums they are not included.
//
// Answer: 40730

pub fn digit_factorials() -> u64 {
    let fact = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880];
    let mut sum = 0;
    for n in 10..(362880 * 7) {
        let mut s = 0;
        let mut m = n;
        while m > 0 {
            s += fact[(m % 10) as usize];
            m /= 10;
        }
        if s == n {
            sum += n as u64;
        }
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_034() {
        assert_eq!(digit_factorials(), 40730);
    }
}