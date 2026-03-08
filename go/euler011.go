// https://projecteuler.net/problem=11

/*

In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

(The grid is given in the problem.)

The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

Answer: 70600674

*/

package main

import (

    "fmt"

    "strconv"

    "strings"

)

func main() {

    gridStr := `08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08

49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00

81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65

52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91

22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80

24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50

32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70

67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21

24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72

21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95

78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92

16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57

86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58

19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40

04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66

15 08 44 37 98 66 91 78 17 35 94 19 21 03 51 93 54 81 78 31

51 54 81 92 23 25 98 49 16 99 67 53 11 41 01 17 68 19 19 68

46 47 89 82 62 39 35 06 06 44 13 87 72 06 75 87 57 75 84 74

85 25 29 39 12 94 99 52 62 84 18 16 08 28 56 61 23 50 40 02

21 77 22 31 11 03 94 42 40 51 19 18 96 81 02 36 43 84 09 17`

    lines := strings.Split(gridStr, "\n")

    var grid [][]int

    for _, line := range lines {

        line = strings.TrimSpace(line)

        if line == "" {

            continue

        }

        parts := strings.Fields(line)

        row := make([]int, 20)

        for j, p := range parts {

            row[j], _ = strconv.Atoi(p)

        }

        grid = append(grid, row)

    }

    maxProd := 0

    for i := 0; i < 20; i++ {

        for j := 0; j < 20; j++ {

            // right

            if j+3 < 20 {

                prod := grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3]

                if prod > maxProd {

                    maxProd = prod

                }

            }

            // down

            if i+3 < 20 {

                prod := grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j]

                if prod > maxProd {

                    maxProd = prod

                }

            }

            // diag down right

            if i+3 < 20 && j+3 < 20 {

                prod := grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3]

                if prod > maxProd {

                    maxProd = prod

                }

            }

            // diag down left

            if i+3 < 20 && j-3 >= 0 {

                prod := grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3]

                if prod > maxProd {

                    maxProd = prod

                }

            }

        }

    }

    fmt.Println(maxProd)

}