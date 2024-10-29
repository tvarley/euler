// https://projecteuler.net/problem=1

// If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
// 
// Answer: 233168

pub fn sum_natural_35(upper:u32) -> u32
{
    let mut sum = 0;
    for i in 1..upper {
        if 0 == i % 3 || 0 == i % 5 {
            sum += i;
        }
    }
    return sum;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_001() {
        assert_eq!(sum_natural_35(1000), 233_168);
    }
}
