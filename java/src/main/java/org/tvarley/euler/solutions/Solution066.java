/*
Diophantine equation

Consider quadratic Diophantine equations of the form:

x² – D y² = 1

For example, when D=13, the minimal solution in x is 649² – 13×180² = 1.

It can be assumed that there are no solutions in positive integers when D is square.

By finding minimal solutions in x for D ≤ 1000, find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

The final answer to the problem is 661.

Execution time measurements: Approximately 100 ms on standard hardware.

Details on any optimizations made during development: Continued fraction algorithm with BigInteger arithmetic
Interesting notes or insights from the AI implementation process: AI-generated solution using continued fraction convergents to solve Pell equations
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;
import java.util.*;

public class Solution066 implements Solution {
  private static BigInteger pellMinimalX(int d) {
    int a0 = (int) Math.sqrt(d);
    if (a0 * a0 == d) return BigInteger.ZERO;
    BigInteger h = BigInteger.valueOf(a0);
    BigInteger k = BigInteger.ONE;
    BigInteger dd = BigInteger.valueOf(d);
    BigInteger one = BigInteger.ONE;
    if (h.multiply(h).subtract(dd.multiply(k.multiply(k))).equals(one)) {
      return h;
    }
    int m = 0;
    int dv = 1;
    int a = a0;
    BigInteger hm2 = BigInteger.ONE;
    BigInteger hm1 = BigInteger.valueOf(a0);
    BigInteger km2 = BigInteger.ZERO;
    BigInteger km1 = BigInteger.ONE;
    while (true) {
      m = dv * a - m;
      dv = (d - m * m) / dv;
      a = (a0 + m) / dv;
      BigInteger tt = BigInteger.valueOf(a);
      BigInteger hh = tt.multiply(hm1).add(hm2);
      BigInteger kk = tt.multiply(km1).add(km2);
      if (hh.multiply(hh).subtract(dd.multiply(kk.multiply(kk))).equals(one)) {
        return hh;
      }
      hm2 = hm1;
      hm1 = hh;
      km2 = km1;
      km1 = kk;
    }
  }

  public String solve() {
    BigInteger maxX = BigInteger.ZERO;
    int maxD = 0;
    for (int d = 2; d <= 1000; d++) {
      BigInteger x = pellMinimalX(d);
      if (x.compareTo(maxX) > 0) {
        maxX = x;
        maxD = d;
      }
    }
    return String.valueOf(maxD);
  }
}