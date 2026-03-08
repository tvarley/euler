// https://projecteuler.net/problem=15
//
// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//
// How many such routes are there through a 20×20 grid?
//
// Answer: 137846528820

pub fn lattice_paths(grid_size: u32) -> u128 {
    let n = 2 * grid_size;
    let k = grid_size;
    let mut result = 1u128;
    for i in 1..=k as u128 {
        result *= n as u128 - i + 1;
        result /= i;
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_015() {
        assert_eq!(lattice_paths(2), 6);
        assert_eq!(lattice_paths(20), 137_846_528_820);
    }
}