// Problem 81: Path Sum: Two Ways
//
// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving right and down, is indicated in bold red and is equal to 2427.
//
// 131	673	234	103	18
// 201	96	342	965	150
// 630	803	746	422	111
// 537	699	497	121	956
// 805	732	524	37	331
//
// Find the minimal path sum from the top left to the bottom right by only moving right and down in matrix.txt, a 31K text file containing an 80 by 80 matrix.
//
// Answer: 427337
//
// Execution time: ~1ms on modern hardware
//
// Optimizations: Dynamic programming on grid
// Interesting notes: Reads matrix from file, uses DP to compute min path

pub fn path_sum_two_ways() -> u64 {
    let content = std::fs::read_to_string("../cpp/src/p081_matrix.txt").unwrap();
    let matrix: Vec<Vec<u64>> = content.lines().map(|line| {
        line.split(',').map(|s| s.trim().parse().unwrap()).collect()
    }).collect();
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut dp = matrix.clone();
    for i in 0..rows {
        for j in 0..cols {
            if i == 0 && j == 0 {
                continue;
            }
            let mut min = u64::MAX;
            if i > 0 {
                min = min.min(dp[i-1][j]);
            }
            if j > 0 {
                min = min.min(dp[i][j-1]);
            }
            dp[i][j] += min;
        }
    }
    dp[rows-1][cols-1]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_081() {
        assert_eq!(path_sum_two_ways(), 427337);
    }
}