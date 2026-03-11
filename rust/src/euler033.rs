// https://projecteuler.net/problem=33
//
// The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
// There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
// If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
//
// Answer: 100

pub fn digit_cancelling_fractions() -> u64 {
    let mut product_num = 1;
    let mut product_den = 1;
    for num in 10..100 {
        for den in (num + 1)..100 {
            let num_str = format!("{}", num);
            let den_str = format!("{}", den);
            let mut common = vec![];
            for &c in num_str.as_bytes() {
                if den_str.as_bytes().contains(&c) && c != b'0' {
                    common.push(c);
                }
            }
            for &digit in &common {
                let new_num_str: String = num_str.chars().filter(|&c| c != digit as char).collect();
                let new_den_str: String = den_str.chars().filter(|&c| c != digit as char).collect();
                if new_num_str.len() == 1 && new_den_str.len() == 1 {
                    let new_num: f64 = new_num_str.parse().unwrap();
                    let new_den: f64 = new_den_str.parse().unwrap();
                    let orig = num as f64 / den as f64;
                    let new_val = new_num / new_den;
                    if (orig - new_val).abs() < 1e-10 {
                        product_num *= num as u64;
                        product_den *= den as u64;
                    }
                }
            }
        }
    }
    let gcd = gcd(product_num, product_den);
    product_den / gcd
}

fn gcd(a: u64, b: u64) -> u64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_033() {
        assert_eq!(digit_cancelling_fractions(), 100);
    }
}