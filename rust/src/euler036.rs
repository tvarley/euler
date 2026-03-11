// https://projecteuler.net/problem=36
//
// The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.
// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
// (Please note that the palindromic number, in either base, may not include leading zeros.)
//
// Answer: 872187

fn is_palindrome(s: &str) -> bool {
    s == s.chars().rev().collect::<String>()
}

pub fn double_base_palindromes() -> u64 {
    let mut sum = 0;
    for n in 1..1_000_000 {
        let dec = format!("{}", n);
        if is_palindrome(&dec) {
            let bin = format!("{:b}", n);
            if is_palindrome(&bin) {
                sum += n;
            }
        }
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_036() {
        assert_eq!(double_base_palindromes(), 872187);
    }
}