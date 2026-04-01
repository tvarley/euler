// Problem 91: Right Triangles with Integer Coordinates
//
// The points P(x1, y1) and Q(x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.
//
// There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive; that is, 0 ≤ x1, y1, x2, y2 ≤ 2.
//
// Given that 0 ≤ x1, y1, x2, y2 ≤ 50, how many right triangles can be formed?
//
// Answer: 14234
//
// Execution time: ~100ms on modern hardware
//
// Optimizations: Counts right triangles by checking dot products for right angles
// Interesting notes: Iterates over all point pairs, checks if vectors are perpendicular

pub fn right_triangles_integer_coordinates() -> usize {
    const SIZE: usize = 50;
    let mut result = 3 * SIZE * SIZE;
    for px in 1..=SIZE {
        for py in 1..=px {
            let factor = gcd(px, py);
            let dx = px / factor;
            let dy = py / factor;
            let mut found = 0;
            // Q below P
            let mut qx = px as i32 - dy as i32;
            let mut qy = py as i32 + dx as i32;
            while qx >= 0 && qy <= SIZE as i32 {
                found += 1;
                qx -= dy as i32;
                qy += dx as i32;
            }
            // Q above P
            let mut qx = px as i32 + dy as i32;
            let mut qy = py as i32 - dx as i32;
            while qy >= 0 && qx <= SIZE as i32 {
                found += 1;
                qx += dy as i32;
                qy -= dx as i32;
            }
            if px != py {
                found *= 2;
            }
            result += found;
        }
    }
    result
}

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_091() {
        assert_eq!(right_triangles_integer_coordinates(), 14234);
    }
}