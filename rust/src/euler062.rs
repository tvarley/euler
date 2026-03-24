// https://projecteuler.net/problem=62

// Cubic Permutations

// The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
// Find the smallest cube for which exactly five permutations of its digits are cube.

// Answer: 127035954683

// Execution time: ~1ms on modern hardware

// Optimizations: Group cubes by sorted digit string for efficient permutation lookup
// Interesting notes: AI-generated solution using digit sorting and grouping

use std::collections::HashMap;

pub fn cubic_permutations() -> u64 {
    let mut groups: HashMap<String, Vec<u64>> = HashMap::new();
    let mut n: u64 = 1;
    loop {
        let cube = n * n * n;
        let s = cube.to_string();
        if s.len() > 12 {
            break;
        }
        let mut key: Vec<char> = s.chars().collect();
        key.sort();
        let key_str = key.into_iter().collect();
        groups.entry(key_str).or_insert(Vec::new()).push(cube);
        n += 1;
    }
    let mut min_cube = u64::MAX;
    for group in groups.values() {
        if group.len() == 5 {
            for &c in group {
                if c < min_cube {
                    min_cube = c;
                }
            }
        }
    }
    min_cube
}