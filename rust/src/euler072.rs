// Problem 72: Counting fractions

// Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
// If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
// 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
// It can be seen that there are 21 elements in this set.
// How many elements would be contained in the set of reduced proper fractions for d ≤ 1,000,000?

// Answer: 303963552391

// Execution time: ~1000ms on modern hardware

// Optimizations: Euler's totient function sieve to count fractions
// Interesting notes: AI-generated solution using phi function to count coprime pairs

pub fn counting_fractions() -> u64 {
    const LIMIT: usize = 1_000_000;
    let mut phi = vec![0u64; LIMIT + 1];
    for i in 0..=LIMIT {
        phi[i] = i as u64;
    }
    for i in 2..=LIMIT {
        if phi[i] == i as u64 { // i is prime
            for j in (i..=LIMIT).step_by(i) {
                phi[j] = phi[j] / i as u64 * (i as u64 - 1);
            }
        }
    }
    phi.iter().skip(2).sum()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_072() {
        assert_eq!(counting_fractions(), 303963552391);
    }
}