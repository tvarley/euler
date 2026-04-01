// Problem 78: Coin Partitions

// Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.

// OOOOO
// OOOO   O
// OOO   OO
// OOO   O   O
// OO   OO   O
// OO   O   O   O
// O   O   O   O   O

// Find the least value of n for which p(n) is divisible by one million.

// Answer: 55374

// Execution time: ~1000ms on modern hardware

// Optimizations: Pentagonal number theorem for partition function

// Interesting notes: AI-generated solution using generalized pentagonal number recurrence

pub fn coin_partitions() -> u64 {
    const MOD: u64 = 1_000_000;
    let mut p = vec![0u64; 100000];
    p[0] = 1;
    let mut n = 1usize;
    loop {
        let mut sum = 0u64;
        let mut k = 1i64;
        loop {
            let pent1 = k * (3 * k - 1) / 2;
            let pent2 = k * (3 * k + 1) / 2;
            if pent1 > n as i64 {
                break;
            }
            let sign = if k % 2 == 1 { 1i64 } else { -1i64 };
            let val1 = p[(n as i64 - pent1) as usize];
            if sign == 1 {
                sum = (sum + val1) % MOD;
            } else {
                sum = (sum + MOD - (val1 % MOD)) % MOD;
            }
            if pent2 <= n as i64 {
                let val2 = p[(n as i64 - pent2) as usize];
                if sign == 1 {
                    sum = (sum + val2) % MOD;
                } else {
                    sum = (sum + MOD - (val2 % MOD)) % MOD;
                }
            }
            k += 1;
        }
        p[n] = sum;
        if sum == 0 {
            return n as u64;
        }
        n += 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_078() {
        assert_eq!(coin_partitions(), 55374);
    }
}