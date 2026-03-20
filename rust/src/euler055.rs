// https://projecteuler.net/problem=55
//
// If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
// Not all numbers produce palindromes so quickly. For example, 349 took three iterations.
// Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome.
// A number that never forms a palindrome through the reverse and add process is called a Lychrel number.
// Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise.
// In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome.
// In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
// Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
// How many Lychrel numbers are there below ten-thousand?
// NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
//
// Answer: 249

use num_bigint::BigUint;
use num_traits::{Zero, One};

pub fn lychrel_numbers() -> u32 {
    let mut count = 0;
    for n in 1..10000 {
        if is_lychrel(n) {
            count += 1;
        }
    }
    count
}

fn is_lychrel(n: u64) -> bool {
    let mut num = BigUint::from(n);
    for _ in 0..50 {
        let rev = reverse_big(&num);
        num += &rev;
        if is_palindrome(&num) {
            return false;
        }
    }
    true
}

fn reverse_big(n: &BigUint) -> BigUint {
    let s = n.to_string();
    let rev_s: String = s.chars().rev().collect();
    BigUint::parse_bytes(rev_s.as_bytes(), 10).unwrap()
}

fn is_palindrome(n: &BigUint) -> bool {
    let s = n.to_string();
    s == s.chars().rev().collect::<String>()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_055() {
        assert_eq!(lychrel_numbers(), 249);
    }
}