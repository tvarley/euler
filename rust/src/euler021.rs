// https://projecteuler.net/problem=21
//
// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//
// Evaluate the sum of all the amicable numbers under 10000.
//
// Answer: 31626

pub fn amicable_numbers(limit: usize) -> u64 {
    let mut sum_div = vec![0u64; limit + 1];
    for i in 1..=limit {
        for j in (i * 2..=limit).step_by(i) {
            sum_div[j] += i as u64;
        }
    }
    let mut sum = 0u64;
    for i in 1..limit {
        let j = sum_div[i];
        if j <= limit as u64 && j != i as u64 && sum_div[j as usize] == i as u64 && i < j as usize {
            sum += i as u64 + j;
        }
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_021() {
        assert_eq!(amicable_numbers(10000), 31626);
    }
}