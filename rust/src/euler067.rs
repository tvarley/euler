// Problem 67: Maximum path sum II

// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
// 3
// 7 4
// 2 4 6
// 8 5 9 3
// That is, 3 + 7 + 4 + 9 = 23.
// Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

// Answer: 7273

// Execution time: ~0ms on modern hardware

// Optimizations: Dynamic programming from bottom up, reusing rows to save space
// Interesting notes: AI-generated solution reading triangle data and computing maximum path sum

use std::fs;

pub fn maximum_path_sum_ii() -> u64 {
    let content = fs::read_to_string("src/euler_67_data.txt").expect("Failed to read file");
    let mut triangle: Vec<Vec<u64>> = content
        .lines()
        .map(|line| {
            line.split_whitespace()
                .map(|s| s.parse().unwrap())
                .collect()
        })
        .collect();
    for row in (0..triangle.len() - 1).rev() {
        for col in 0..triangle[row].len() {
            triangle[row][col] += triangle[row + 1][col].max(triangle[row + 1][col + 1]);
        }
    }
    triangle[0][0]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_067() {
        assert_eq!(maximum_path_sum_ii(), 7273);
    }
}