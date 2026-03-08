// https://projecteuler.net/problem=14
//
// The following iterative sequence is defined for the set of positive integers:
//
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following sequence:
//
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?
//
// NOTE: Once the chain starts the terms are allowed to go above one million.
//
// Answer: 837799

use std::collections::HashMap;

pub fn longest_collatz_sequence(limit: usize) -> usize {
    let mut memo = HashMap::new();
    memo.insert(1, 1u64);
    let mut max_length = 0;
    let mut max_start = 1;
    for start in 1..limit {
        let mut n = start as u64;
        let mut path = vec![];
        while !memo.contains_key(&n) {
            path.push(n);
            if n % 2 == 0 {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
        }
        let mut length = memo[&n];
        for &p in path.iter().rev() {
            length += 1;
            memo.insert(p, length);
        }
        if length > max_length {
            max_length = length;
            max_start = start;
        }
    }
    max_start
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_014() {
        assert_eq!(longest_collatz_sequence(1_000_000), 837_799);
    }
}