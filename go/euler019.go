// https://projecteuler.net/problem=19

/*

You are given the following information, but you may prefer to do some research for additional details.

- The Gregorian calendar was adopted on 15 October 1582.

- 1 January 1900 was a Monday.

- Thirty days has September, April, June and November. All the rest have thirty-one, Saving February alone, Which has twenty-eight, rain or shine. And on leap years, twenty-nine.

- A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Answer: 171

*/

package main

import "fmt"

func daysInMonth(year, month int) int {

    days := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

    if month == 2 && isLeap(year) {

        return 29

    }

    return days[month-1]

}

func isLeap(year int) bool {

    return year%4 == 0 && (year%100 != 0 || year%400 == 0)

}

func main() {

    count := 0

    day := 2 // 1901-01-01 is Tuesday (1900-01-01 Monday, 365 days later Tuesday)

    for year := 1901; year <= 2000; year++ {

        for month := 1; month <= 12; month++ {

            if day == 0 {

                count++

            }

            days := daysInMonth(year, month)

            day = (day + days) % 7

        }

    }

    fmt.Println(count)

}