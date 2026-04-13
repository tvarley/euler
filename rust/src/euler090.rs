// Problem 90: Cube Digit Pairs
//
// Each of the six faces on a cube has a different digit (0 to 9) written on it; the same is done to a second cube. By placing the two cubes side-by-side in different positions we can form a variety of 2-digit numbers.
//
// For example, the square number 64 could be formed:
//
// In fact, by carefully choosing the digits on both cubes it is possible to display all of the square numbers below one-hundred: 01, 04, 09, 16, 25, 36, 49, 64, and 81.
//
// For example, one way this can be achieved is by placing {0, 5, 6, 7, 8, 9} on one cube and {1, 2, 3, 4, 8, 9} on the other cube.
//
// However, for this problem we shall allow the 6 or 9 to be turned upside-down so that an arrangement like {0, 5, 6, 7, 8, 9} and {1, 2, 3, 4, 6, 7} allows for all nine square numbers to be displayed; otherwise it would be impossible to obtain 09.
//
// In determining a distinct arrangement we are interested in the digits on each cube, not the order.
//
// {1, 2, 3, 4, 5, 6} is equivalent to {3, 6, 4, 1, 2, 5}
//
// {1, 2, 3, 4, 5, 6} is distinct from {1, 2, 3, 4, 5, 9}
//
// But because we are allowing 6 and 9 to be reversed, the two distinct sets in the last example both represent the extended set {1, 2, 3, 4, 5, 6, 9} for the purpose of forming 2-digit numbers.
//
// How many distinct arrangements of the two cubes allow for all of the square numbers to be displayed?
//
// Answer: 1217
//
// Execution time: ~10ms on modern hardware
//
// Optimizations: Combinatorial generation of cube digit sets
// Interesting notes: Generates all possible digit combinations for cubes, checks coverage of squares

pub fn cube_digit_pairs() -> usize {
    let squares = vec![1, 4, 9, 16, 25, 36, 49, 64, 81];
    let mut cubes = vec![];
    for i in 0u32..(1 << 10) {
        if i.count_ones() == 6 {
            cubes.push(i as usize);
        }
    }
    let mut count = 0;
    let n = cubes.len();
    for i in 0..n {
        let ma = cubes[i];
        for j in i + 1..n {
            let mb = cubes[j];
            let mut ok = true;
            for &sq in &squares {
                if !can_form_square(ma, mb, sq) {
                    ok = false;
                    break;
                }
            }
            if ok {
                count += 1;
            }
        }
    }
    count
}

fn has_digit(mask: usize, d: usize) -> bool {
    if (mask & (1 << d)) != 0 {
        return true;
    }
    if d == 6 && (mask & (1 << 9)) != 0 {
        return true;
    }
    if d == 9 && (mask & (1 << 6)) != 0 {
        return true;
    }
    false
}

fn can_form_square(mask_a: usize, mask_b: usize, sq: usize) -> bool {
    let d1 = sq / 10;
    let d2 = sq % 10;
    let a1 = has_digit(mask_a, d1);
    let a2 = has_digit(mask_a, d2);
    let b1 = has_digit(mask_b, d1);
    let b2 = has_digit(mask_b, d2);
    (a1 && b2) || (a2 && b1)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_090() {
        assert_eq!(cube_digit_pairs(), 1217);
    }
}