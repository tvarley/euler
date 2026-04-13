// https://projecteuler.net/problem=89
// Roman Numerals
//
// For a number written in Roman numerals to be considered valid there are basic rules which must be followed. Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.
//
// For example, it would appear that there are at least six ways of writing the number sixteen:
//
// IIIIIIIIIIIIIIII
// VIIIIIIIIIII
// VVIIIIIII
// XIIIIII
// VVVI
// XVI
//
// However, according to the rules only XIIIIII and XVI are valid, and XIIIIII is not the "best" way of writing it, because it uses each symbol too many times.
//
// The "best" (shortest) way to write them, using the subtractive notation, is XVI.
//
// Find the number of characters saved by writing each of these in their minimal form.
//
// Note: You can assume that all the Roman numerals in the file contain no more than four consecutive identical units.
//
// Answer: 743
//
// Completed on: 2024-12-04
// Time: ~1ms
// Optimizations: Greedy parsing and building
// Notes: Used BufferedReader for file reading.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;

public class Solution089 implements Solution {
    private static final List<String[]> ROMAN_VALUES = Arrays.asList(
        new String[]{"M", "1000"}, new String[]{"CM", "900"}, new String[]{"D", "500"}, new String[]{"CD", "400"},
        new String[]{"C", "100"}, new String[]{"XC", "90"}, new String[]{"L", "50"}, new String[]{"XL", "40"},
        new String[]{"X", "10"}, new String[]{"IX", "9"}, new String[]{"V", "5"}, new String[]{"IV", "4"}, new String[]{"I", "1"}
    );

    public String solve() {
        long saved = 0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(
                getClass().getResourceAsStream("/p089_roman.txt")))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.isEmpty()) continue;
                int value = romanToInt(line);
                String minimal = intToRoman(value);
                saved += line.length() - minimal.length();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return Long.toString(saved);
    }

    private int romanToInt(String s) {
        int total = 0;
        int i = 0;
        while (i < s.length()) {
            boolean found = false;
            for (String[] p : ROMAN_VALUES) {
                String sym = p[0];
                int val = Integer.parseInt(p[1]);
                if (i + sym.length() <= s.length() && s.substring(i, i + sym.length()).equals(sym)) {
                    total += val;
                    i += sym.length();
                    found = true;
                    break;
                }
            }
            if (!found) i++;
        }
        return total;
    }

    private String intToRoman(int num) {
        StringBuilder result = new StringBuilder();
        for (String[] p : ROMAN_VALUES) {
            int val = Integer.parseInt(p[1]);
            String sym = p[0];
            while (num >= val) {
                result.append(sym);
                num -= val;
            }
        }
        return result.toString();
    }
}