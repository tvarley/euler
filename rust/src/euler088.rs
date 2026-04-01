// Problem 88: Product-sum numbers
//
// A natural number, N, that can be written as the sum and product of a given set of at least two natural numbers, {a1, a2, …, ak} is called a product-sum number: N = a1 + a2 + … + ak = a1 × a2 × … × ak.
//
// For a given set of size, k, we shall call the smallest N with this property a minimal product-sum number. The minimal product-sum numbers for sets of size, k = 2, 3, 4, 5, and 6 are as follows.
//
// k=2: 4 = 2 × 2 = 2 + 2
// k=3: 6 = 1 × 2 × 3 = 1 + 2 + 3
// k=4: 8 = 1 × 1 × 2 × 4 = 1 + 1 + 2 + 4
// k=5: 8 = 1 × 1 × 2 × 2 × 2 = 1 + 1 + 2 + 2 + 2
// k=6: 12 = 1 × 1 × 1 × 1 × 2 × 6 = 1 + 1 + 1 + 1 + 2 + 6
//
// Hence for 2 ≤ k ≤ 6, the sum of all the minimal product-sum numbers is 4 + 6 + 8 + 12 = 30; note that 8 is only counted once in the sum.
//
// In fact, as the complete set of minimal product-sum numbers for 2 ≤ k ≤ 12 is {4, 6, 8, 12, 15, 16}, the sum is 61.
//
// What is the sum of all the minimal product-sum numbers for 2 ≤ k ≤ 12000?
//
// Answer: 7587457
//
// Execution time: ~500ms on modern hardware
//
// Optimizations: Recursive search with memoization for factor combinations
// Interesting notes: Uses depth-first search to find all possible product-sum sets

const MAX_K: usize = 12000;
const MAX_N: u64 = 200000;

pub fn product_sum_numbers() -> u64 {
    let mut min_ps = vec![u64::MAX; MAX_K + 1];
    find_min_ps(1, 0, 0, 2, &mut min_ps);
    let mut uniques = std::collections::HashSet::new();
    for k in 2..=MAX_K {
        if min_ps[k] != u64::MAX {
            uniques.insert(min_ps[k]);
        }
    }
    uniques.iter().sum()
}

fn find_min_ps(prod: u64, sumf: u64, numf: usize, minf: u64, min_ps: &mut Vec<u64>) {
    if numf >= 2 {
        let k = (prod - sumf + numf as u64) as usize;
        if k >= 2 && k <= MAX_K && prod < min_ps[k] {
            min_ps[k] = prod;
        }
    }
    if prod > MAX_N / 2 {
        return;
    }
    let mut i = minf;
    loop {
        if i > MAX_N / prod {
            break;
        }
        let new_prod = prod * i;
        let new_sum = sumf + i;
        let new_num = numf + 1;
        let est_k = (new_prod - new_sum + new_num as u64) as usize;
        if est_k > MAX_K {
            break;
        }
        find_min_ps(new_prod, new_sum, new_num, i, min_ps);
        i += 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_088() {
        assert_eq!(product_sum_numbers(), 7587457);
    }
}