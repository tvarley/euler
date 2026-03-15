// https://projecteuler.net/problem=41
//
// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
//
// What is the largest n-digit pandigital prime that exists?
//
// Answer: 7652413

pub fn pandigital_prime() -> u64 {
    // n=7 is the largest possible, since n=8 and n=9 sums are divisible by 3
    let digits = [1,2,3,4,5,6,7];
        let mut max_prime = 0u64;
    for perm in permutations(&digits) {
        let num = to_number(&perm);
        if is_prime(num) && num > max_prime {
            max_prime = num;
        }
    }
    max_prime
}

fn is_prime(n: u64) -> bool {
    if n < 2 { return false; }
    if n == 2 || n == 3 { return true; }
    if n % 2 == 0 || n % 3 == 0 { return false; }
    let mut i = 5;
    while i * i <= n {
        if n % i == 0 || n % (i + 2) == 0 { return false; }
        i += 6;
    }
    true
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
    fn euler_041() {
        assert_eq!(pandigital_prime(), 7652413);
    }
}