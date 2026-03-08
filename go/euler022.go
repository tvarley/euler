// https://projecteuler.net/problem=22

/*

Using names.txt, a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out the alphabetical
value for each name, multiply this value by its alphabetical position in the
list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is
worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

Answer: 871198282

*/

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strings"
)

func nameScore(name string) int {
    score := 0
    for _, c := range name {
        score += int(c-'A') + 1
    }
    return score
}

func main() {
    f, err := os.Open("p022_names.txt")
    if err != nil {
        fmt.Fprintln(os.Stderr, "Error opening p022_names.txt:", err)
        os.Exit(1)
    }
    defer f.Close()

    scanner := bufio.NewScanner(f)
    scanner.Buffer(make([]byte, 1024*1024), 1024*1024)
    var names []string
    for scanner.Scan() {
        line := scanner.Text()
        for _, part := range strings.Split(line, ",") {
            name := strings.Trim(part, "\"")
            if name != "" {
                names = append(names, name)
            }
        }
    }

    sort.Strings(names)

    total := 0
    for i, name := range names {
        total += (i + 1) * nameScore(name)
    }

    fmt.Println(total)
}
