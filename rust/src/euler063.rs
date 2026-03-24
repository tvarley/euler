// Problem 63: Powerful Digit Counts

// The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
// How many n-digit positive integers exist which are also an nth power?

// Answer: 49

// Execution time: ~0ms on modern hardware

// Optimizations: Mathematical logarithmic approach using log10 to compute exact count without power calculations

pub fn powerful_digit_counts() -> u32 {
    let mut count = 0;
    for a in 1..=9 {
        let log_a = (a as f64).log10();
        let max_n = (1.0 / (1.0 - log_a)) as u32;
        count += max_n;
    }
    count
}