// https://projecteuler.net/problem=9
//
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a² + b² = c²
//
// For example, 3² + 4² = 9 + 16 = 25 = 5².
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
//
// Answer: 31875000

pub fn special_pythagorean_triplet(sum: u64) -> u64 {
    for a in 1..sum/3 {
        for b in a+1..(sum-a)/2 {
            let c = sum - a - b;
            if a*a + b*b == c*c {
                return a * b * c;
            }
        }
    }
    0
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_009() {
        assert_eq!(special_pythagorean_triplet(1000), 31_875_000);
    }
}