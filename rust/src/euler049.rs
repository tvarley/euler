// https://projecteuler.net/problem=49
//
// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
// What 12-digit number do you form by concatenating the three terms in this sequence?
//
// Answer: 296962999629

pub fn prime_permutations() -> String {
    let mut primes = vec![];
    for n in 1000..10000 {
        if is_prime(n) {
            primes.push(n);
        }
    }
    for &p in &primes {
        if p == 1487 { continue; } // skip the known sequence
        let perms = get_permutations(p);
        for &q in &perms {
            if q <= p || !primes.contains(&q) { continue; }
            let diff = q - p;
            let r = q + diff;
            if r < 10000 && primes.contains(&r) && perms.contains(&r) {
                return format!("{}{}{}", p, q, r);
            }
        }
    }
    "".to_string()
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

fn get_permutations(n: u32) -> Vec<u32> {
    let s: String = format!("{}", n);
    let mut chars: Vec<char> = s.chars().collect();
    let mut result = std::collections::HashSet::new();
    let len = chars.len();
    heap_permute(&mut chars, len, &mut result);
    result.into_iter().filter(|&x| x != n).collect()
}

fn heap_permute(chars: &mut Vec<char>, n: usize, result: &mut std::collections::HashSet<u32>) {
    if n == 1 {
        let num: String = chars.iter().collect();
        if let Ok(num) = num.parse::<u32>() {
            result.insert(num);
        }
        return;
    }
    for i in 0..n {
        heap_permute(chars, n - 1, result);
        if n % 2 == 1 {
            chars.swap(0, n - 1);
        } else {
            chars.swap(i, n - 1);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_049() {
        assert_eq!(prime_permutations(), "296962999629");
    }
}