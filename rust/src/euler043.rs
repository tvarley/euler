// https://projecteuler.net/problem=43
//
// The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
//
// Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
//
// d2d3d4=406 is divisible by 2
// d3d4d5=063 is divisible by 3
// d4d5d6=635 is divisible by 5
// d5d6d7=357 is divisible by 7
// d6d7d8=572 is divisible by 11
// d7d8d9=728 is divisible by 13
// d8d9d10=289 is divisible by 17
//
// Find the sum of all 0 to 9 pandigital numbers with this property.
//
// Answer: 16695334890

pub fn sub_string_divisibility() -> u64 {
    let digits = [0,1,2,3,4,5,6,7,8,9];
    let mut sum = 0u64;
    for perm in permutations(&digits) {
        if check_property(&perm) {
            sum += to_number(&perm);
        }
    }
    sum
}

fn check_property(digits: &[u8]) -> bool {
    let d2 = digits[1] as u64;
    let d3 = digits[2] as u64;
    let d4 = digits[3] as u64;
    let d5 = digits[4] as u64;
    let d6 = digits[5] as u64;
    let d7 = digits[6] as u64;
    let d8 = digits[7] as u64;
    let d9 = digits[8] as u64;
    let d10 = digits[9] as u64;

    (d2 * 100 + d3 * 10 + d4) % 2 == 0 &&
    (d3 * 100 + d4 * 10 + d5) % 3 == 0 &&
    (d4 * 100 + d5 * 10 + d6) % 5 == 0 &&
    (d5 * 100 + d6 * 10 + d7) % 7 == 0 &&
    (d6 * 100 + d7 * 10 + d8) % 11 == 0 &&
    (d7 * 100 + d8 * 10 + d9) % 13 == 0 &&
    (d8 * 100 + d9 * 10 + d10) % 17 == 0
}

fn permutations(arr: &[u8]) -> Vec<Vec<u8>> {
    let mut result = Vec::new();
    let mut arr = arr.to_vec();
    let len = arr.len();
    heap_permute(&mut arr, len, &mut result);
    result
}

fn heap_permute(arr: &mut [u8], n: usize, result: &mut Vec<Vec<u8>>) {
    if n == 1 {
        result.push(arr.to_vec());
        return;
    }
    for i in 0..n {
        heap_permute(arr, n - 1, result);
        if n % 2 == 1 {
            arr.swap(0, n - 1);
        } else {
            arr.swap(i, n - 1);
        }
    }
}

fn to_number(digits: &[u8]) -> u64 {
    let mut num = 0u64;
    for &d in digits {
        num = num * 10 + d as u64;
    }
    num
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_043() {
        assert_eq!(sub_string_divisibility(), 16695334890);
    }
}