// https://projecteuler.net/problem=24
//
// A permutation is an ordered arrangement of objects. For example, 3124 is one possible
// permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed
// numerically or alphabetically, we call it lexicographic order.
//
// The lexicographic permutations of 0, 1 and 2 are:
// 012   021   102   120   201   210
//
// What is the millionth lexicographic permutation of the digits 0-9?
//
// Answer: 2783915460

pub fn lexicographic_permutation(mut n: usize) -> String {
    let mut digits = vec![0usize, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    let mut result = String::new();
    n -= 1; // convert to 0-indexed
    let mut factorials = [1usize; 10];
    for i in 1..10 {
        factorials[i] = factorials[i - 1] * i;
    }
    for i in (0..10).rev() {
        let idx = n / factorials[i];
        result.push((b'0' + digits[idx] as u8) as char);
        digits.remove(idx);
        n %= factorials[i];
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_024() {
        assert_eq!(lexicographic_permutation(1_000_000), "2783915460");
    }
}
