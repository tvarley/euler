// Problem 79: Passcode Derivation

// A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 73162890, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 316.

// The text file, keylog.txt, contains fifty successful login attempts.

// Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.

// Answer: 73162890

// Execution time: ~0ms on modern hardware

// Optimizations: Topological sort from order constraints

// Interesting notes: AI-generated solution using graph construction from triples

pub fn passcode_derivation() -> u64 {
    let triples = vec![
        "319", "680", "180", "690", "129", "620", "762", "689", "762", "318",
        "368", "710", "720", "710", "629", "168", "160", "689", "716", "731",
        "736", "729", "316", "729", "729", "710", "769", "290", "719", "680",
        "318", "389", "162", "289", "162", "718", "729", "319", "790", "680",
        "890", "362", "319", "760", "316", "729", "380", "319", "728", "716"
    ];
    let mut graph: std::collections::HashMap<char, Vec<char>> = std::collections::HashMap::new();
    let mut indegree: std::collections::HashMap<char, i32> = std::collections::HashMap::new();
    for triple in &triples {
        let chars: Vec<char> = triple.chars().collect();
        let a = chars[0];
        let b = chars[1];
        let c = chars[2];
        graph.entry(a).or_insert(vec![]).push(b);
        graph.entry(b).or_insert(vec![]).push(c);
        *indegree.entry(a).or_insert(0) += 0;
        *indegree.entry(b).or_insert(0) += 1;
        *indegree.entry(c).or_insert(0) += 1;
    }
    let mut all_digits: std::collections::HashSet<char> = std::collections::HashSet::new();
    for triple in &triples {
        for c in triple.chars() {
            all_digits.insert(c);
        }
    }
    let mut queue: std::collections::VecDeque<char> = std::collections::VecDeque::new();
    for &d in &all_digits {
        if *indegree.get(&d).unwrap_or(&0) == 0 {
            queue.push_back(d);
        }
    }
    let mut result = String::new();
    while let Some(d) = queue.pop_front() {
        result.push(d);
        if let Some(neighbors) = graph.get(&d) {
            for &n in neighbors {
                *indegree.get_mut(&n).unwrap() -= 1;
                if *indegree.get(&n).unwrap() == 0 {
                    queue.push_back(n);
                }
            }
        }
    }
    result.parse().unwrap()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_079() {
        assert_eq!(passcode_derivation(), 73162890);
    }
}