// https://projecteuler.net/problem=28
//
// Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5
// spiral is formed as follows:
//
// 43 44 45 46 47 48 49
// 42 21 22 23 24 25 26
// 41 20  7  8  9 10 27
// 40 19  6  1  2 11 28
// 39 18  5  4  3 12 29
// 38 17 16 15 14 13 30
// 37 36 35 34 33 32 31
//
// It can be verified that the sum of the numbers on the diagonals is 101.
//
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in
// the same way?
//
// Answer: 669171001

pub fn spiral_diagonals(size: u64) -> u64 {
    let mut sum = 1u64;
    let mut n = 1u64;
    let mut step = 2u64;
    while step < size {
        for _ in 0..4 {
            n += step;
            sum += n;
        }
        step += 2;
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_028() {
        assert_eq!(spiral_diagonals(5), 101);
        assert_eq!(spiral_diagonals(1001), 669_171_001);
    }
}
