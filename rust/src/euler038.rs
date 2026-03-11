// https://projecteuler.net/problem=38
//
// Take the number 192 and multiply it by each of 1, 2, and 3:
// 192 × 1 = 192
// 192 × 2 = 384
// 192 × 3 = 576
// By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3).
// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
// What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, … ,n) where n > 1?
//
// Answer: 932718654

pub fn pandigital_multiples() -> u64 {
    let mut max = 0;
    for n in (1..10000).rev() {
        let mut s = String::new();
        let mut k = 1;
        while s.len() < 9 {
            s += &format!("{}", n * k);
            k += 1;
        }
        if s.len() == 9 {
            let mut digits = [0; 10];
            let mut ok = true;
            for c in s.chars() {
                let d = c.to_digit(10).unwrap() as usize;
                if d == 0 || digits[d] > 0 {
                    ok = false;
                    break;
                }
                digits[d] = 1;
            }
            if ok {
                let num: u64 = s.parse().unwrap();
                if num > max {
                    max = num;
                }
            }
        }
    }
    max
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_038() {
        assert_eq!(pandigital_multiples(), 932718654);
    }
}