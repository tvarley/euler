// https://projecteuler.net/problem=40
//
// An irrational decimal fraction is created by concatenating the positive integers:
// 0.123456789101112131415161718192021…
// It can be seen that the 12th digit of the fractional part is 1.
// If dn represents the nth digit of the fractional part, find the value of the following expression.
// d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
//
// Answer: 210

pub fn champernownes_constant() -> u64 {
    let mut s = String::new();
    let mut n = 1;
    while s.len() < 1_000_000 {
        s += &format!("{}", n);
        n += 1;
    }
    let d1 = s.chars().next().unwrap().to_digit(10).unwrap() as u64;
    let d10 = s.chars().nth(9).unwrap().to_digit(10).unwrap() as u64;
    let d100 = s.chars().nth(99).unwrap().to_digit(10).unwrap() as u64;
    let d1000 = s.chars().nth(999).unwrap().to_digit(10).unwrap() as u64;
    let d10000 = s.chars().nth(9999).unwrap().to_digit(10).unwrap() as u64;
    let d100000 = s.chars().nth(99999).unwrap().to_digit(10).unwrap() as u64;
    let d1000000 = s.chars().nth(999999).unwrap().to_digit(10).unwrap() as u64;
    d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_040() {
        assert_eq!(champernownes_constant(), 210);
    }
}