// Problem 100: Arranged Probability
//
// If a box contains twenty-one coloured discs, composed of fifteen blue discs and six red discs, and two discs were taken at random, it can be seen that the probability of taking two blue discs, P(BB) = (15/21)×(14/20) = 1/2.
//
// The next such arrangement, for which there is exactly 50% chance of taking two blue discs at random, is a box containing eighty-five blue discs and thirty-five red discs.
//
// By finding the first arrangement to contain over 10^12 = 1,000,000,000,000 discs in total, determine the number of blue discs that the box would contain.
//
// Answer: 756872327473
//
// Execution time: ~0.01ms on modern hardware
//
// Optimizations: Solves quadratic equation for blue discs
// Interesting notes: Finds minimal blue where total > 1e12 and P(BB)=0.5

pub fn arranged_probability() -> u64 {
    let mut b: i64 = 15;
    let mut n: i64 = 21;
    while n <= 1_000_000_000_000 {
        let b_new = 3 * b + 2 * n - 2;
        let n_new = 4 * b + 3 * n - 3;
        b = b_new;
        n = n_new;
    }
    b as u64
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_100() {
        assert_eq!(arranged_probability(), 756872327473);
    }
}