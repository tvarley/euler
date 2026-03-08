// https://projecteuler.net/problem=30
//
// Surprisingly there are only three numbers that can be written as the sum of fourth
// powers of their digits:
// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
// (1 = 1^4 is not a sum, so is not included.)
//
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//
// Find the sum of all the numbers that can be written as the sum of fifth powers of
// their digits.
//
// Answer: 443839

pub fn digit_fifth_powers() -> u64 {
    // Upper bound: a 7-digit number max is 9999999, but 7 * 9^5 = 413343 < 1000000
    // so no 7-digit number can equal the sum of its fifth powers. Use 6 * 9^5 = 354294.
    let upper = 6 * 9u64.pow(5) + 1;
    let mut sum = 0u64;
    for n in 2..=upper {
        let digit_sum: u64 = {
            let mut tmp = n;
            let mut s = 0u64;
            while tmp > 0 {
                s += (tmp % 10).pow(5);
                tmp /= 10;
            }
            s
        };
        if digit_sum == n {
            sum += n;
        }
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_030() {
        assert_eq!(digit_fifth_powers(), 443_839);
    }
}
