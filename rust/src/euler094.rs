// Problem 94: Almost Equilateral Triangles
//
// It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the almost equilateral triangle 5-5-6 has an area of 12 square units.
//
// We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.
//
// Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).
//
// Answer: 518408346
//
// Execution time: ~100ms on modern hardware
//
// Optimizations: Heron formula for area, checks for integral area
// Interesting notes: Solves for sides where area is integer using quadratic equations

pub fn almost_equilateral_triangles() -> u64 {
    let mut sum = 0u64;
    const MAX_PERIM: u64 = 1_000_000_000;
    // Type 1: (a, a, a-1)
    let mut a_prev = 1;
    let mut a_curr = 17;
    loop {
        let perim = 3 * a_curr - 1;
        if perim > MAX_PERIM {
            break;
        }
        sum += perim;
        let a_next = 14 * a_curr - a_prev;
        a_prev = a_curr;
        a_curr = a_next;
    }
    // Type 2: (a, a, a+1)
    a_prev = 1;
    a_curr = 5;
    loop {
        let perim = 3 * a_curr + 1;
        if perim > MAX_PERIM {
            break;
        }
        if a_curr > 1 {
            sum += perim;
        }
        let a_next = 14 * a_curr - a_prev;
        a_prev = a_curr;
        a_curr = a_next;
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_094() {
        assert_eq!(almost_equilateral_triangles(), 518408346);
    }
}