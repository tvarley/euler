// https://projecteuler.net/problem=26
//
// A unit fraction contains 1 in the numerator. The decimal representation of the unit
// fractions with denominators 2 to 10 are given:
// 1/6 = 0.1(6), where the cycle length is 1.
// 1/7 = 0.(142857), where the cycle length is 6.
//
// Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its
// decimal fraction part.
//
// Answer: 983

fn cycle_length(d: u32) -> usize {
    let mut remainders = vec![0usize; d as usize];
    let mut r = 1usize;
    let mut pos = 0usize;
    loop {
        r %= d as usize;
        if r == 0 {
            return 0;
        }
        if remainders[r] != 0 {
            return pos - remainders[r] + 1;
        }
        remainders[r] = pos + 1;
        r *= 10;
        pos += 1;
    }
}

pub fn longest_recurring_cycle(limit: u32) -> u32 {
    let mut best_d = 0u32;
    let mut best_len = 0usize;
    for d in 2..limit {
        let len = cycle_length(d);
        if len > best_len {
            best_len = len;
            best_d = d;
        }
    }
    best_d
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_026() {
        assert_eq!(longest_recurring_cycle(1000), 983);
    }
}
