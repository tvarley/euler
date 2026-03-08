/*
 * Solution for Euler problem 019
 *
 * Counting Sundays
 *
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution019 implements Solution {
  public String solve() {
    int dayOfWeek = 1; // 1 Jan 1900 was Monday (0=Sun, 1=Mon, ..., 6=Sat)
    int sundays = 0;

    // Advance to 1 Jan 1901
    dayOfWeek = (dayOfWeek + 365) % 7; // 1900 was not leap year

    for (int year = 1901; year <= 2000; year++) {
      for (int month = 1; month <= 12; month++) {
        if (dayOfWeek == 0) { // Sunday
          sundays++;
        }
        // Advance to next month
        dayOfWeek = (dayOfWeek + daysInMonth(month, year)) % 7;
      }
    }

    return Integer.toString(sundays);
  }

  private int daysInMonth(int month, int year) {
    switch (month) {
      case 4: case 6: case 9: case 11: return 30;
      case 2: return isLeapYear(year) ? 29 : 28;
      default: return 31;
    }
  }

  private boolean isLeapYear(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return year % 400 == 0;
  }
}