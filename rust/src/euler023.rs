// https://projecteuler.net/problem=23
//
// A perfect number is a number for which the sum of its proper divisors is exactly equal
// to the number. A number n is called deficient if the sum of its proper divisors is less
// than n and it is called abundant if this sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number
// that can be written as the sum of two abundant numbers is 24.
// By mathematical analysis, it can be shown that all integers greater than 28123 can be
// written as the sum of two abundant numbers.
//
// Find the sum of all the positive integers which cannot be written as the sum of two
// abundant numbers.
//
// Answer: 4179871

const LIMIT: usize = 28124;

fn sum_proper_divisors(n: usize) -> usize {
    if n <= 1 {
        return 0;
    }
    let mut sum = 1;
    let mut i = 2;
    while i * i <= n {
        if n % i == 0 {
            sum += i;
            if i != n / i {
                sum += n / i;
            }
        }
        i += 1;
    }
    sum
}

pub fn non_abundant_sums() -> u64 {
    let abundants: Vec<usize> = (1..LIMIT)
        .filter(|&n| sum_proper_divisors(n) > n)
        .collect();

    let mut is_sum = vec![false; LIMIT];
    'outer: for i in 0..abundants.len() {
        for j in i..abundants.len() {
            let s = abundants[i] + abundants[j];
            if s >= LIMIT {
                continue 'outer;
            }
            is_sum[s] = true;
        }
    }

    (1..LIMIT)
        .filter(|&n| !is_sum[n])
        .map(|n| n as u64)
        .sum()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_023() {
        assert_eq!(non_abundant_sums(), 4_179_871);
    }
}
