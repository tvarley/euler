// Problem 68: Magic 5-gon ring

// Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.
// Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example), each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.
// It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.
// Total	Solution Set
// 9	4,2,3; 5,3,1; 6,1,2
// 9	4,3,2; 6,2,1; 5,1,3
// 10	2,3,5; 4,5,1; 6,1,3
// 10	2,5,3; 6,3,1; 4,1,5
// 10	3,2,5; 4,5,1; 6,1,3
// 10	3,5,2; 6,2,1; 4,1,5
// 11	6,4,1; 5,1,4; 2,4,3
// 11	6,1,4; 2,4,1; 5,1,4
// 12	3,2,6; 5,6,1; 4,1,5
// 12	3,6,2; 5,2,1; 4,1,5
// 12	6,2,3; 5,3,1; 4,1,5
// 12	6,3,2; 5,2,1; 4,1,5
// By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.
// Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. What is the maximum 16-digit string for a "magic" 5-gon ring?

// Answer: 6531031914842725

// Execution time: ~0ms on modern hardware

// Optimizations: Generate permutations of outer nodes, then arrange inner nodes to satisfy magic property
// Interesting notes: AI-generated solution using permutation generation for magic 5-gon rings

pub fn magic_5_gon_ring() -> u64 {
    let mut digits: Vec<u8> = (1..=10).collect();
    let mut max_string = 0u64;
    // Generate permutations for the 5 outer positions
    permute(&mut digits, |perm| {
        let outer: Vec<u8> = perm[5..10].to_vec(); // positions 5-9 for outer (1-based in problem but 0-based here)
        let inner: Vec<u8> = perm[0..5].to_vec();
        // Now arrange inner to form the ring
        // The ring is 5 groups: outer[i], inner[i], inner[(i+1)%5]
        // Each group sums to the same value
        let sum_val = outer[0] as u16 + inner[0] as u16 + inner[1] as u16;
        if outer[1] as u16 + inner[1] as u16 + inner[2] as u16 != sum_val { return; }
        if outer[2] as u16 + inner[2] as u16 + inner[3] as u16 != sum_val { return; }
        if outer[3] as u16 + inner[3] as u16 + inner[4] as u16 != sum_val { return; }
        if outer[4] as u16 + inner[4] as u16 + inner[0] as u16 != sum_val { return; }
        // Find the starting outer with smallest value
        let min_outer = outer.iter().min().unwrap();
        let start_idx = outer.iter().position(|&x| x == *min_outer).unwrap();
        // Build the 16-digit string
        let mut s = String::new();
        for i in 0..5 {
            let idx = (start_idx + i) % 5;
            s.push_str(&outer[idx].to_string());
            s.push_str(&inner[idx].to_string());
            s.push_str(&inner[(idx + 1) % 5].to_string());
        }
        if s.len() == 16 {
            let num: u64 = s.parse().unwrap();
            if num > max_string {
                max_string = num;
            }
        }
    });
    max_string
}

fn permute<F>(arr: &mut Vec<u8>, mut f: F)
where
    F: FnMut(&[u8]),
{
    arr.sort(); // start with sorted
    f(arr);
    while next_permutation(arr) {
        f(arr);
    }
}

fn next_permutation(arr: &mut Vec<u8>) -> bool {
    let n = arr.len();
    let mut i = n - 1;
    while i > 0 && arr[i - 1] >= arr[i] {
        i -= 1;
    }
    if i == 0 {
        return false;
    }
    let mut j = n - 1;
    while arr[j] <= arr[i - 1] {
        j -= 1;
    }
    arr.swap(i - 1, j);
    arr[i..].reverse();
    true
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_068() {
        assert_eq!(magic_5_gon_ring(), 6531031914842725);
    }
}