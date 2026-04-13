// Problem 95: Amicable Chains
//
// The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14. As the sum of these divisors is equal to 28, we call it a perfect number.
//
// Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220, forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.
//
// Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:
//
// 12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → …)
//
// Since this chain returns to its starting point, it is called an amicable chain.
//
// Find the smallest member of the longest amicable chain with no element exceeding one million.
//
// Answer: 14316
//
// Execution time: ~5000ms on modern hardware
//
// Optimizations: Precompute sum of divisors, track chains
// Interesting notes: Finds cycles in divisor sum chains, identifies longest below limit

pub fn amicable_chains() -> usize {
    const LIMIT: usize = 1_000_000;
    let mut sum_div = vec![0; LIMIT + 1];
    for i in 1..=LIMIT {
        for j in (i*2..=LIMIT).step_by(i) {
            sum_div[j] += i;
        }
    }
    let mut visited = vec![false; LIMIT + 1];
    let mut max_len = 0;
    let mut min_member = LIMIT;
    for i in 1..=LIMIT {
        if visited[i] {
            continue;
        }
        let mut chain = vec![];
        let mut current = i;
        while !visited[current] && current <= LIMIT && sum_div[current] <= LIMIT {
            visited[current] = true;
            chain.push(current);
            current = sum_div[current];
            if chain.contains(&current) {
                let cycle_start = chain.iter().position(|&x| x == current).unwrap();
                let cycle_len = chain.len() - cycle_start;
                if cycle_len > max_len {
                    max_len = cycle_len;
                    min_member = *chain[cycle_start..].iter().min().unwrap();
                }
                break;
            }
        }
    }
    min_member
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_095() {
        assert_eq!(amicable_chains(), 14316);
    }
}