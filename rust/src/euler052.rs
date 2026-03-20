// https://projecteuler.net/problem=52
//
// It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
//
// Answer: 142857

pub fn permuted_multiples() -> u64 {
    for x in 1.. {
        let x_str = x.to_string();
        let mut digits: Vec<char> = x_str.chars().collect();
        digits.sort();
        let mut all_same = true;
        for mul in 2..=6 {
            let mx = x * mul;
            let mx_str = mx.to_string();
            if mx_str.len() != x_str.len() { all_same = false; break; }
            let mut mx_digits: Vec<char> = mx_str.chars().collect();
            mx_digits.sort();
            if mx_digits != digits { all_same = false; break; }
        }
        if all_same { return x; }
    }
    0
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_052() {
        assert_eq!(permuted_multiples(), 142857);
    }
}