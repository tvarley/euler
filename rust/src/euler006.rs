// https://projecteuler.net/problem=6

// The sum of the squares of the first ten natural numbers is,
//
// 1^2 + 2^2 + ... + 10^2 = 385
// The square of the sum of the first ten natural numbers is,
//
// (1 + 2 + ... + 10)^2 = 55^2 = 3025
// Hence the difference between the sum of the squares of the first ten
// natural numbers and the square of the sum is 3025 − 385 = 2640.
//
// Find the difference between the sum of the squares of the first one
// hundred natural numbers and the square of the sum.

// Answer: 25164150

pub fn sum_squares(size: u32) -> u32
{
    let mut sum_square = 0;
    let mut square_sum = 0;

    for i in 1..size + 1 {
        sum_square += i * i;
        square_sum += i;
    }

    return (square_sum * square_sum) - sum_square;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_006() {
        assert_eq!(sum_squares(100), 25_164_150);
    }
}
