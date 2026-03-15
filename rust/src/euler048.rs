// https://projecteuler.net/problem=48
//
// The series, 1¹ + 2² + 3³ + … + 10¹⁰ = 10405071317.
// Find the last ten digits of the series, 1¹ + 2² + 3³ + … + 1000¹⁰⁰⁰.
//
// Answer: 9110846700

use num_bigint::BigUint;

pub fn self_powers() -> String {
    let mut sum = BigUint::from(0u32);
    let modulus = BigUint::from(10u32).pow(10);
    for n in 1..=1000 {
        let mut power = BigUint::from(n as u32);
        power = power.modpow(&BigUint::from(n as u32), &modulus);
        sum = (sum + power) % &modulus;
    }
    format!("{:010}", sum)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_048() {
        assert_eq!(self_powers(), "9110846700");
    }
}