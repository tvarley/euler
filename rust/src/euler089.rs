// Problem 89: Roman Numerals
//
// For a number written in Roman numerals to be considered valid there are basic rules which must be followed. Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.
//
// For example, it would appear that there are at least six ways of writing the number sixteen:
//
// IIIIIIIIIIIIIIII
// VIIIIIIIIIII
// VVIIIIII
// XIIIIII
// VVVI
// XVI
//
// However, according to the rules only XIIIIII and XVI are valid, and the last example is considered to be the most efficient, as it uses the least number of numerals.
//
// The 11K text file, roman.txt, contains one thousand numbers written in valid, but not necessarily minimal, Roman numerals; see About... Roman Numerals for the definitive rules for this problem.
//
// Find the number of characters saved by writing each of these in their minimal form.
//
// Answer: 743
//
// Execution time: ~1ms on modern hardware
//
// Optimizations: Roman numeral parsing and optimization
// Interesting notes: Converts each roman to int, then back to minimal roman, counts savings

pub fn roman_numerals() -> usize {
    let content = std::fs::read_to_string("../cpp/src/p089_roman.txt").unwrap();
    let mut saved = 0;
    for line in content.lines() {
        if line.is_empty() {
            continue;
        }
        let value = roman_to_int(line);
        let minimal = int_to_roman(value);
        saved += line.len() - minimal.len();
    }
    saved
}

fn roman_to_int(s: &str) -> u32 {
    let values = vec![
        ("M", 1000), ("CM", 900), ("D", 500), ("CD", 400),
        ("C", 100), ("XC", 90), ("L", 50), ("XL", 40),
        ("X", 10), ("IX", 9), ("V", 5), ("IV", 4), ("I", 1)
    ];
    let mut total = 0;
    let mut i = 0;
    let chars: Vec<char> = s.chars().collect();
    while i < chars.len() {
        let mut found = false;
        for &(rom, val) in &values {
            let rom_chars: Vec<char> = rom.chars().collect();
            if i + rom_chars.len() <= chars.len() && chars[i..i + rom_chars.len()] == rom_chars {
                total += val;
                i += rom_chars.len();
                found = true;
                break;
            }
        }
        if !found {
            i += 1;
        }
    }
    total
}

fn int_to_roman(mut num: u32) -> String {
    let values = vec![
        (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
        (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
        (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
    ];
    let mut result = String::new();
    for &(val, rom) in &values {
        while num >= val {
            result.push_str(rom);
            num -= val;
        }
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_089() {
        assert_eq!(roman_numerals(), 743);
    }
}