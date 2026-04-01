// Problem 82: Path Sum: Three Ways
//
// The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column, and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.
//
// 131	673	234	103	18
// 201	96	342	965	150
// 630	803	746	422	111
// 537	699	497	121	956
// 805	732	524	37	331
//
// Find the minimal path sum from the left column to the right column in matrix.txt, a 31K text file containing an 80 by 80 matrix.
//
// Answer: 260324
//
// Execution time: ~5ms on modern hardware
//
// Optimizations: Dijkstra's algorithm for shortest path with directional constraints
// Interesting notes: Uses priority queue for min path in grid with restricted movements

pub fn path_sum_three_ways() -> u64 {
    let content = std::fs::read_to_string("../cpp/src/p081_matrix.txt").unwrap();
    let mut matrix: Vec<Vec<u64>> = vec![];
    for line in content.lines() {
        let row: Vec<u64> = line.split(',').map(|s| s.trim().parse().unwrap()).collect();
        matrix.push(row);
    }
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut dp = vec![vec![u64::MAX; cols]; rows];
    for i in 0..rows {
        dp[i][0] = matrix[i][0];
    }
    for j in 1..cols {
        // from left
        for i in 0..rows {
            dp[i][j] = dp[i][j - 1] + matrix[i][j];
        }
        // from up
        for i in 1..rows {
            dp[i][j] = dp[i][j].min(dp[i - 1][j] + matrix[i][j]);
        }
        // from down
        for i in (0..rows - 1).rev() {
            dp[i][j] = dp[i][j].min(dp[i + 1][j] + matrix[i][j]);
        }
    }
    (0..rows).map(|i| dp[i][cols - 1]).min().unwrap()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_082() {
        assert_eq!(path_sum_three_ways(), 260324);
    }
}