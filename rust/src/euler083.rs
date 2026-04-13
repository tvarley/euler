// Problem 83: Path Sum: Four Ways
//
// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down, is indicated in bold red and is equal to 2297.
//
// 131	673	234	103	18
// 201	96	342	965	150
// 630	803	746	422	111
// 537	699	497	121	956
// 805	732	524	37	331
//
// Find the minimal path sum from the top left to the bottom right by moving left, right, up, and down in matrix.txt, a 31K text file containing an 80 by 80 matrix.
//
// Answer: 425185
//
// Execution time: ~50ms on modern hardware
//
// Optimizations: Dijkstra's algorithm for shortest path in undirected grid
// Interesting notes: Similar to problem 82 but allows all directions

pub fn path_sum_four_ways() -> u64 {
    let content = std::fs::read_to_string("../cpp/src/p081_matrix.txt").unwrap();
    let mut matrix: Vec<Vec<u64>> = vec![];
    for line in content.lines() {
        let row: Vec<u64> = line.split(',').map(|s| s.trim().parse().unwrap()).collect();
        matrix.push(row);
    }
    let rows = matrix.len();
    let cols = matrix[0].len();
    let mut dist = vec![vec![u64::MAX; cols]; rows];
    let mut pq = std::collections::BinaryHeap::new();
    use std::cmp::Reverse;
    dist[0][0] = matrix[0][0];
    pq.push(Reverse((dist[0][0], 0, 0)));
    let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    while let Some(Reverse((cost, x, y))) = pq.pop() {
        if cost > dist[x][y] {
            continue;
        }
        for &(dx, dy) in &dirs {
            let nx = x as i32 + dx;
            let ny = y as i32 + dy;
            if nx >= 0 && nx < rows as i32 && ny >= 0 && ny < cols as i32 {
                let nx = nx as usize;
                let ny = ny as usize;
                let nc = cost + matrix[nx][ny];
                if nc < dist[nx][ny] {
                    dist[nx][ny] = nc;
                    pq.push(Reverse((nc, nx, ny)));
                }
            }
        }
    }
    dist[rows - 1][cols - 1]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_083() {
        assert_eq!(path_sum_four_ways(), 425185);
    }
}