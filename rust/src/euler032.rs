// https://projecteuler.net/problem=32
//
// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
// The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
// Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
// HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
//
// Answer: 45228

use std::collections::HashSet;

pub fn pandigital_products() -> u64 {
    let mut products = HashSet::new();
    let digits: Vec<char> = "123456789".chars().collect();
    let mut perms = vec![];
    permute(&digits, 0, &mut perms);
    for perm in perms {
        let s: String = perm.into_iter().collect();
        for i in 1..=4 {
            for j in (i + 1)..=5 {
                let a_str = &s[0..i];
                let b_str = &s[i..j];
                let c_str = &s[j..9];
                if c_str.is_empty() {
                    continue;
                }
                let a: u64 = a_str.parse().unwrap();
                let b: u64 = b_str.parse().unwrap();
                let c: u64 = c_str.parse().unwrap();
                if a * b == c {
                    products.insert(c);
                }
            }
        }
    }
    products.iter().sum()
}

fn permute(digits: &Vec<char>, start: usize, result: &mut Vec<Vec<char>>) {
    if start == digits.len() {
        result.push(digits.clone());
        return;
    }
    let mut digits = digits.clone();
    for i in start..digits.len() {
        digits.swap(start, i);
        permute(&digits, start + 1, result);
        digits.swap(start, i);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_032() {
        assert_eq!(pandigital_products(), 45228);
    }
}