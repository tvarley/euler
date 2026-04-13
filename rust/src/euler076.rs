// Problem 76: Counting Summations

// It is possible to write five as a sum in exactly six different ways:

// 4 + 1
// 3 + 2
// 3 + 1 + 1
// 2 + 2 + 1
// 2 + 1 + 1 + 1
// 1 + 1 + 1 + 1 + 1

// How many different ways can one hundred be written as a sum of at least two positive integers?

// Answer: 190569291

// Execution time: ~0ms on modern hardware

// Optimizations: Dynamic programming for partition function

// Interesting notes: AI-generated solution using standard DP approach

pub fn counting_summations() -> u64 {
    const N: usize = 100;
    let mut ways = vec![0u64; N + 1];
    ways[0] = 1;
    for i in 1..=N {
        for j in i..=N {
            ways[j] += ways[j - i];
        }
    }
    ways[N] - 1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_076() {
        assert_eq!(counting_summations(), 190569291);
    }
}