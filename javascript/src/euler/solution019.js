// https://projecteuler.net/problem=19

// You are given the following information, but you may prefer to do some
// research for yourself.
// 1 Jan 1900 was a Monday.
// Thirty days has September,
// April, June and November.
// All the rest have thirty-one,
// Saving February alone,
// Which has twenty-eight, rain or shine.
// And on leap years, twenty-nine.
// A leap year occurs on any year evenly divisible by 4, but not on a
// century unless it is divisible by 400.
// How many Sundays fell on the first of the month during the twentieth
// century (1 Jan 1901 to 31 Dec 2000)?
//
// Answer: 171

module.exports = {
  answer: () => {
    const daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let dayOfWeek = 1; // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
    let sundays = 0;

    // Start from 1900 to get the correct day alignment
    for (let year = 1900; year <= 2000; year++) {
      for (let month = 0; month < 12; month++) {
        // Skip 1900, only count from 1901-2000
        if (year >= 1901 && dayOfWeek === 0) {
          sundays++;
        }

        // Calculate days in this month
        let days = daysInMonth[month];
        if (month === 1 && ((year % 4 === 0 && year % 100 !== 0) || year % 400 === 0)) {
          days = 29; // February in leap year
        }

        // Move to first day of next month
        dayOfWeek = (dayOfWeek + days) % 7;
      }
    }

    return sundays;
  }
};