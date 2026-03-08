// https://projecteuler.net/problem=19
//
// You are given the following information, but you do not need to use it for your calculation:
//
// During the twentieth century (1 Jan 1901 to 31 Dec 2000), how many Sundays fell on the first of the month?
//
// Answer: 171

pub fn counting_sundays() -> usize {
    let days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let mut day_counter = 2; // 1901-01-01 is Tuesday (0=Sunday, 1=Monday, 2=Tuesday)
    let mut count = 0;
    for year in 1901..=2000 {
        for month in 0..12 {
            if day_counter % 7 == 0 {
                count += 1;
            }
            let mut days = days_in_month[month];
            if month == 1 && is_leap(year) {
                days = 29;
            }
            day_counter += days;
        }
    }
    count
}

fn is_leap(year: u32) -> bool {
    year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_019() {
        assert_eq!(counting_sundays(), 171);
    }
}