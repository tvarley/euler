/*
Convergents of e

The square root of 2 can be written as an infinite continued fraction.
√2 = 1 + 1/(2 + 1/(2 + 1/(2 + ...)))
The infinite continued fraction can be written, √2 = [1;(2)], (2) indicates that 2 repeats ad infinitum.
In a similar way, √23 = [4; (1,3,1,8)].
It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations.
Let us consider the convergents for √2.
1 + 1/2 = 3/2
1 + 1/(2 + 1/2) = 7/5
1 + 1/(2 + 1/(2 + 1/2)) = 17/12
1 + 1/(2 + 1/(2 + 1/2)) = 41/29
Hence the sequence of the first ten convergents for √2 are:
1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...
What is most surprising is that the important mathematical constant,
e = [2; 1, 2, 1, 1, 4, 1, 1, 6, 1, ..., 1, 2k, 1, ...]
The first ten terms in the sequence of convergents for e are:
2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.

The final answer to the problem is 272.

Execution time measurements: Approximately 0 ms on standard hardware.

Details on any optimizations made during development: Simple big integer arithmetic using strings for numerator calculation
Interesting notes or insights from the AI implementation process: AI-generated solution implementing continued fraction convergents with string-based big integers
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.*;

public class Solution065 implements Solution {
  private static String addBig(String a, String b) {
    StringBuilder result = new StringBuilder();
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
      int sum = carry;
      if (i >= 0) sum += a.charAt(i--) - '0';
      if (j >= 0) sum += b.charAt(j--) - '0';
      carry = sum / 10;
      result.append(sum % 10);
    }
    return result.reverse().toString();
  }

  private static String multiplyBig(String a, int b) {
    StringBuilder result = new StringBuilder();
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
      int prod = (a.charAt(i) - '0') * b + carry;
      carry = prod / 10;
      result.append(prod % 10);
    }
    while (carry > 0) {
      result.append(carry % 10);
      carry /= 10;
    }
    return result.reverse().toString();
  }

  private static int sumDigitsBig(String s) {
    int sum = 0;
    for (char c : s.toCharArray()) sum += c - '0';
    return sum;
  }

  public String solve() {
    List<Integer> terms = new ArrayList<>();
    terms.add(2);
    for (int k = 1; ; k++) {
      terms.add(1);
      terms.add(2 * k);
      terms.add(1);
      if (terms.size() >= 101) break;
    }
    String hPrev2 = "0";
    String hPrev1 = "1";
    String kPrev2 = "1";
    String kPrev1 = "0";
    for (int i = 0; i < 100; i++) {
      String h = addBig(multiplyBig(hPrev1, terms.get(i)), hPrev2);
      String k = addBig(multiplyBig(kPrev1, terms.get(i)), kPrev2);
      hPrev2 = hPrev1;
      hPrev1 = h;
      kPrev2 = kPrev1;
      kPrev1 = k;
    }
    return String.valueOf(sumDigitsBig(hPrev1));
  }
}