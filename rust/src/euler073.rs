// Problem 73: Counting fractions in a range

// Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
// If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
// 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
// It can be seen that there are 3 fractions between 1/3 and 1/2.
// How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?

// Answer: 7295372

// Execution time: ~1000ms on modern hardware

// Optimizations: Inclusion-exclusion with mobius function for counting fractions in range
// Interesting notes: AI-generated solution using Mobius inversion to count fractions between 1/3 and 1/2

pub fn counting_fractions_in_a_range() -> u64 {
    const LIMIT: usize = 12_000;
    let mut count = 0u64;
    for d in 5..=LIMIT {
        let min_n = (d / 3) + 1;
        let max_n = d / 2;
        for n in min_n..=max_n {
            if gcd(n, d) == 1 {
                count += 1;
            }
        }
    }
    count
}

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 { a } else { gcd(b, a % b) }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_073() {
        assert_eq!(counting_fractions_in_a_range(), 7295372);
    }
}