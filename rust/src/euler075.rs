// Problem 75: Singular integer right triangles

// It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.
// 12 cm: (3,4,5)
// 24 cm: (6,8,10)
// 30 cm: (5,12,13)
// 36 cm: (9,12,15)
// 40 cm: (8,15,16)
// 48 cm: (12,16,20)
// In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.
// 120 cm: (30,40,50), (20,48,52), (24,45,51)
// Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?

// Answer: 161667

// Execution time: ~10000ms on modern hardware

// Optimizations: Generate primitive Pythagorean triples and multiples, count perimeters
// Interesting notes: AI-generated solution using triple generation with Euclid's formula

pub fn singular_integer_right_triangles() -> u32 {
    const LIMIT: usize = 1_500_000;
    let mut count = vec![0u32; LIMIT + 1];
    let mut m = 2;
    while m * m * 2 <= LIMIT {
        for n in 1..m {
            if (m - n) % 2 == 1 && gcd(m, n) == 1 {
                let a = m * m - n * n;
                let b = 2 * m * n;
                let c = m * m + n * n;
                let perimeter = a + b + c;
                let mut k = 1;
                while k * perimeter <= LIMIT {
                    count[k * perimeter] += 1;
                    k += 1;
                }
            }
        }
        m += 1;
    }
    count.iter().filter(|&&x| x == 1).count() as u32
}

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 { a } else { gcd(b, a % b) }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_075() {
        assert_eq!(singular_integer_right_triangles(), 161667);
    }
}