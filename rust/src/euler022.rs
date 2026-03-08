// https://projecteuler.net/problem=22
//
// Using a 46K text file containing over five-thousand first names, begin by sorting it
// into alphabetical order. Then working out the alphabetical value for each name,
// multiply this value by its alphabetical position in the list to obtain a name score.
//
// For example, when the list is sorted into alphabetical order, COLIN, which is worth
// 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain
// a score of 938 × 53 = 49714.
//
// What is the total of all the name scores in the file?
//
// Answer: 871198282

const NAMES_DATA: &str = include_str!("../../cpp/src/p022_names.txt");

pub fn names_scores() -> u64 {
    let mut names: Vec<&str> = NAMES_DATA
        .split(',')
        .map(|s| s.trim_matches('"'))
        .collect();
    names.sort_unstable();
    names
        .iter()
        .enumerate()
        .map(|(i, name)| {
            let alpha_val: u64 = name.bytes().map(|b| (b - b'A' + 1) as u64).sum();
            (i as u64 + 1) * alpha_val
        })
        .sum()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_022() {
        assert_eq!(names_scores(), 871_198_282);
    }
}
