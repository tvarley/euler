/*
Combinatoric Selections

There are exactly ten ways of selecting three from five, 12345: 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
In combinatorics, we use the notation, \binom 5 3 = 10.
In general, \binom n r = \dfrac{n!}{r!(n-r)!}, where r \le n, n! = n \times (n-1) \times ... \times 3 \times 2 \times 1, and 0! = 1.
It is not until n = 23, that a value exceeds one-million: \binom {23} {10} = 1144066.
How many, not necessarily distinct, values of \binom n r for 1 \le n \le 100, are greater than one-million?

Answer: 4075

*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;

public class Solution053 implements Solution {
  public String solve() {
    int count = 0;
    BigInteger limit = BigInteger.valueOf(1000000);
    for (int n = 1; n <= 100; n++) {
      for (int r = 0; r <= n; r++) {
        if (binomial(n, r).compareTo(limit) > 0) {
          count++;
        }
      }
    }
    return Integer.toString(count);
  }

  private BigInteger binomial(int n, int k) {
    if (k > n - k) k = n - k;
    BigInteger res = BigInteger.ONE;
    for (int i = 0; i < k; i++) {
      res = res.multiply(BigInteger.valueOf(n - i));
      res = res.divide(BigInteger.valueOf(i + 1));
    }
    return res;
  }
}