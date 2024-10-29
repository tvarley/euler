// https://projecteuler.net/problem=4

// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

// Answer: 906609

fn palindrome_test(test_me: u64) -> bool
{
    let mut reversed = 0;
    let mut original = test_me;

    while 0 < original {
        reversed = reversed * 10 + (original % 10);
        original /= 10;
    }

    return test_me == reversed;
}

pub fn prob004_brute_force() -> u64
{
    let mut max_pali = 0;
    for i in (100..999).rev() {
        for j in (100..999).rev() {
            let t = i * j;
            if palindrome_test(t) {
                if t > max_pali {
                    max_pali = t;
                }
            }
        }
    }
    return max_pali;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_004() {
        assert_eq!(prob004_brute_force(), 906_609 );
    }
}
