// https://projecteuler.net/problem=25
//
// The Fibonacci sequence is defined by the recurrence relation:
// F(n) = F(n−1) + F(n−2), where F(1) = 1 and F(2) = 1.
//
// The 12th term, F(12), is the first term to contain three digits.
// What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
//
// Answer: 4782

pub fn fibonacci_1000_digits(num_digits: usize) -> usize {
    let mut a = vec![1u32]; // F(1)
    let mut b = vec![1u32]; // F(2)
    let mut index = 2;

    fn add_vecs(x: &[u32], y: &[u32]) -> Vec<u32> {
        let len = x.len().max(y.len());
        let mut result = Vec::with_capacity(len + 1);
        let mut carry = 0u32;
        for i in 0..len {
            let xi = if i < x.len() { x[i] } else { 0 };
            let yi = if i < y.len() { y[i] } else { 0 };
            let sum = xi + yi + carry;
            result.push(sum % 10);
            carry = sum / 10;
        }
        if carry > 0 {
            result.push(carry);
        }
        result
    }

    loop {
        let c = add_vecs(&a, &b);
        index += 1;
        if c.len() >= num_digits {
            return index;
        }
        a = b;
        b = c;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_025() {
        assert_eq!(fibonacci_1000_digits(3), 12);
        assert_eq!(fibonacci_1000_digits(1000), 4782);
    }
}
