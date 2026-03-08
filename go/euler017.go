// https://projecteuler.net/problem=17

/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters, and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

Answer: 21124

*/

package main

import (

    "fmt"

    "strings"

)

func numberToWords(n int) string {

    if n == 1000 {

        return "one thousand"

    }

    if n == 0 {

        return ""

    }

    units := []string{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}

    teens := []string{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}

    tens := []string{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}

    var words []string

    hundreds := n / 100

    if hundreds > 0 {

        words = append(words, units[hundreds], "hundred")

        n %= 100

        if n > 0 {

            words = append(words, "and")

        }

    }

    if n >= 20 {

        ten := n / 10

        words = append(words, tens[ten])

        n %= 10

        if n > 0 {

            words = append(words, units[n])

        }

    } else if n >= 10 {

        words = append(words, teens[n-10])

    } else if n > 0 {

        words = append(words, units[n])

    }

    return strings.Join(words, " ")

}

func main() {

    total := 0

    for i := 1; i <= 1000; i++ {

        words := numberToWords(i)

        for _, c := range words {

            if c != ' ' && c != '-' {

                total++

            }

        }

    }

    fmt.Println(total)

}