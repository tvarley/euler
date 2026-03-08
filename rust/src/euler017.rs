// https://projecteuler.net/problem=17
//
// If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
//
// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
//
// Answer: 21124

const UNITS: &[&str] = &["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
const TEENS: &[&str] = &["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"];
const TENS: &[&str] = &["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"];

fn letter_count(n: usize) -> usize {
    if n == 1000 {
        return "onethousand".len();
    }
    let mut count = 0;
    let hundreds = n / 100;
    let remainder = n % 100;
    if hundreds > 0 {
        count += UNITS[hundreds].len() + "hundred".len();
        if remainder > 0 {
            count += "and".len();
        }
    }
    if remainder >= 20 {
        let ten = remainder / 10;
        let unit = remainder % 10;
        count += TENS[ten].len();
        if unit > 0 {
            count += UNITS[unit].len();
        }
    } else if remainder >= 10 {
        count += TEENS[remainder - 10].len();
    } else if remainder > 0 {
        count += UNITS[remainder].len();
    }
    count
}

pub fn number_letter_counts(limit: usize) -> usize {
    (1..=limit).map(letter_count).sum()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_017() {
        assert_eq!(number_letter_counts(5), 19);
        assert_eq!(number_letter_counts(1000), 21124);
    }
}