// Problem 85: Counting Rectangles
//
// By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:
//
// Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
//
// Answer: 2772
//
// Execution time: ~1ms on modern hardware
//
// Optimizations: Mathematical formula for rectangle count per grid size
// Interesting notes: Brute force search for closest to 2e6 rectangles

pub fn counting_rectangles() -> u64 {
    const TARGET: u64 = 2_000_000;
    let mut min_diff = u64::MAX;
    let mut best_area = 0;
    for w in 1..100 {
        for h in 1..100 {
            let rects = (w * (w + 1) * h * (h + 1)) / 4;
            let diff = (rects as i64 - TARGET as i64).abs() as u64;
            if diff < min_diff {
                min_diff = diff;
                best_area = w * h;
            }
        }
    }
    best_area
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_085() {
        assert_eq!(counting_rectangles(), 2772);
    }
}