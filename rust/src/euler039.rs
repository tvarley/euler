// https://projecteuler.net/problem=39
//
// If p is the perimeter of a right angle triangle with integral length sides, {a, b, c}, there are exactly three solutions for p = 120.
// {20,48,52}, {24,45,51}, {30,40,50}
// For which value of p ≤ 1000, is the number of solutions maximised?
//
// Answer: 840

pub fn integer_right_triangles() -> u64 {
    let mut max_count = 0;
    let mut max_p = 0;
    for p in 1..=1000 {
        let mut count = 0;
        for a in 1..p / 2 {
            for b in a..(p - a) / 2 {
                let c = p - a - b;
                if a * a + b * b == c * c {
                    count += 1;
                }
            }
        }
        if count > max_count {
            max_count = count;
            max_p = p;
        }
    }
    max_p
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_039() {
        assert_eq!(integer_right_triangles(), 840);
    }
}