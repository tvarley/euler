/*
Prime Digit Replacements

By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
Consequently 56003, being the first member of this family, is the smallest prime with this property.
Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

Answer: 121313

*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;
import java.util.*;

public class Solution051 implements Solution {
  public String solve() {
    List<Integer> primes = new ArrayList<>();
    for (int i = 2; i < 1000000; i++) {
      if (Prime.isPrime(i)) primes.add(i);
    }
    for (int p : primes) {
      if (p < 100000) continue;
      String s = Integer.toString(p);
      char[] digits = s.toCharArray();
      for (int mask = 1; mask < (1 << digits.length) - 1; mask++) {
        List<Integer> family = new ArrayList<>();
        for (int d = 0; d < 10; d++) {
          if (d == 0 && (mask & 1) != 0) continue;
          int num = 0;
          for (int i = 0; i < digits.length; i++) {
            if ((mask & (1 << i)) != 0) {
              num = num * 10 + d;
            } else {
              num = num * 10 + (digits[i] - '0');
            }
          }
          if (Prime.isPrime(num)) {
            family.add(num);
          }
        }
        if (family.size() == 8) {
          return Integer.toString(Collections.min(family));
        }
      }
    }
    return "0";
  }
}