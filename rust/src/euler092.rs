// Problem 92: Square Digit Chains
//
// A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
//
// For example,
//
// 44 → 32 → 13 → 10 → 1 → 1
// 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
//
// Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.
//
// How many starting numbers below ten million will arrive at 89?
//
// Answer: 8581146
//
// Execution time: ~2000ms on modern hardware
//
// Optimizations: Memoization for chain endings
// Interesting notes: Precomputes ending for all numbers up to max possible sum

pub fn square_digit_chains() -> usize {
    const LIMIT: usize = 10_000_000;
    let mut ends_at_89 = 0;
    let mut memo = vec![0; 10000000]; // Max sum of squares
    for n in 1..LIMIT {
        if arrives_at_89(n, &mut memo) {
            ends_at_89 += 1;
        }
    }
    ends_at_89
}

fn arrives_at_89(n: usize, memo: &mut Vec<i32>) -> bool {
    if n == 1 || n == 89 {
        return n == 89;
    }
    if memo[n] != 0 {
        return memo[n] == 89;
    }
    let next = sum_squares(n);
    let res = arrives_at_89(next, memo);
    memo[n] = if res { 89 } else { 1 };
    res
}

fn sum_squares(mut n: usize) -> usize {
    let mut sum = 0;
    while n > 0 {
        let d = n % 10;
        sum += d * d;
        n /= 10;
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_092() {
        assert_eq!(square_digit_chains(), 8581146);
    }
}