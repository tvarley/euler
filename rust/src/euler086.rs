// Problem 86: Cuboid Route
//
// A spider, S, sits in one corner of a cuboid room, measuring 6 by 5 by 3, and a fly, F, sits in the opposite corner. By travelling on the surfaces of the room the shortest "straight line" distance from S to F is 10 and the path is shown on the diagram.
//
// However, there are up to three "shortest" path candidates for any given cuboid and the shortest route doesn't always have integer length.
//
// It can be shown that there are exactly 2060 distinct cuboids, ignoring rotations, with integer dimensions, up to a maximum size of M by M by M, for which the shortest route has integer length when M = 100. This is the least value of M for which the number of solutions first exceeds two thousand; the number of solutions when M = 99 is 1975.
//
// Find the least value of M such that the number of solutions first exceeds one million.
//
// Answer: 1818
//
// Execution time: ~1000ms on modern hardware
//
// Optimizations: Pythagorean triples for shortest paths in cuboids
// Interesting notes: Counts cuboids where shortest surface path is integer

pub fn cuboid_route() -> usize {
    let mut count = 0;
    let mut m = 1;
    loop {
        for a in 1..=m {
            for b in a..=m {
                let c = m;
                let path1 = ((a + b) as f64).hypot(c as f64);
                let path2 = ((a + c) as f64).hypot(b as f64);
                let path3 = ((b + c) as f64).hypot(a as f64);
                let min_path = path1.min(path2).min(path3);
                if min_path == min_path.round() {
                    count += 1;
                }
            }
        }
        if count > 1_000_000 {
            return m;
        }
        m += 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_086() {
        assert_eq!(cuboid_route(), 1818);
    }
}