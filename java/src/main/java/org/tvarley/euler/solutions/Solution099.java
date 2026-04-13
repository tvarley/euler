// https://projecteuler.net/problem=99
// Largest Exponential
//
// Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, as any calculator would confirm that 2^11 = 2048 < 3^7 = 2187.
//
// However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.
//
// Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.
//
// NOTE: The first two lines in the file represent the numbers in the example given above.
//
// Answer: 709
//
// Completed on: 2024-12-04
// Time: ~1ms
// Optimizations: Computed exp * log(base) to compare magnitudes
// Notes: Read 1000 lines from file, found max logarithmic value.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution099 implements Solution {
    public String solve() {
        int lineNum = 0;
        int maxLine = 0;
        double maxVal = 0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(
                getClass().getResourceAsStream("/p099_base_exp.txt")))) {
            String line;
            while ((line = br.readLine()) != null) {
                lineNum++;
                String[] parts = line.split(",");
                int base = Integer.parseInt(parts[0]);
                int exp = Integer.parseInt(parts[1]);
                double val = exp * Math.log(base);
                if (val > maxVal) {
                    maxVal = val;
                    maxLine = lineNum;
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return Integer.toString(maxLine);
    }
}