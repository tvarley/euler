// https://projecteuler.net/problem=5

// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?

// Answer: 232792560

pub fn prob005_brute_force(max: u32) -> u32
{
    let mut test = max;
    let mut check = false;

    while !check {
        check = true;
        for i in 1..max {
            check = 0 == (test % i);
            if !check {
                break;
            };
        }
        if !check {
            test += 20;
        }
    }
    test
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_005() {
        assert_eq!(prob005_brute_force(20), 232_792_560);
    }
}
