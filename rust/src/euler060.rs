// https://projecteuler.net/problem=60
//
// The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.
// Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
//
// Answer: 26033

pub fn prime_pair_sets() -> u32 {
    let primes = generate_primes(10000);
    for &p1 in &primes {
        for &p2 in &primes {
            if p2 <= p1 || !check_pair(p1, p2) { continue; }
            for &p3 in &primes {
                if p3 <= p2 || !check_pair(p1, p3) || !check_pair(p2, p3) { continue; }
                for &p4 in &primes {
                    if p4 <= p3 || !check_pair(p1, p4) || !check_pair(p2, p4) || !check_pair(p3, p4) { continue; }
                    for &p5 in &primes {
                        if p5 <= p4 || !check_pair(p1, p5) || !check_pair(p2, p5) || !check_pair(p3, p5) || !check_pair(p4, p5) { continue; }
                        return p1 + p2 + p3 + p4 + p5;
                    }
                }
            }
        }
    }
    0
}

fn check_pair(a: u32, b: u32) -> bool {
    let ab = format!("{}{}", a, b).parse::<u64>().unwrap();
    let ba = format!("{}{}", b, a).parse::<u64>().unwrap();
    is_prime(ab as u32) && is_prime(ba as u32)
}

fn generate_primes(limit: u32) -> Vec<u32> {
    let mut sieve = vec![true; limit as usize + 1];
    sieve[0] = false;
    sieve[1] = false;
    for i in 2..=(limit as f64).sqrt() as usize {
        if sieve[i] {
            for j in ((i * i)..=limit as usize).step_by(i) {
                sieve[j] = false;
            }
        }
    }
    (2..=limit).filter(|&x| sieve[x as usize]).collect()
}

fn is_prime(n: u32) -> bool {
    if n < 2 { return false; }
    if n == 2 || n == 3 { return true; }
    if n % 2 == 0 || n % 3 == 0 { return false; }
    let mut i = 5u32;
    while (i as u64) * (i as u64) <= n as u64 {
        if n % i == 0 || n % (i + 2) == 0 { return false; }
        i += 6;
    }
    true
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_060() {
        assert_eq!(prime_pair_sets(), 26033);
    }
}