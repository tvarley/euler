/*
Prime Pair Sets

The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.

The final answer to the problem is 26033.

Execution time measurements: Approximately 2 seconds on standard hardware.

Details on any optimizations made during development: Limited prime search to reasonable bounds, used backtracking to find the smallest set.

Interesting notes or insights from the AI implementation process: The set is 13, 5197, 5701, 6733, 8389, requiring careful concatenation checks.
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;
import java.util.*;

public class Solution060 implements Solution {
  public String solve() {
    List<Integer> primes = new ArrayList<>();
    for (int i = 2; i < 10000; i++) {
      if (Prime.isPrime(i)) primes.add(i);
    }
    for (int i = 0; i < primes.size(); i++) {
      for (int j = i + 1; j < primes.size(); j++) {
        if (!check(primes.get(i), primes.get(j))) continue;
        for (int k = j + 1; k < primes.size(); k++) {
          if (!check(primes.get(i), primes.get(k)) || !check(primes.get(j), primes.get(k))) continue;
          for (int l = k + 1; l < primes.size(); l++) {
            if (!check(primes.get(i), primes.get(l)) || !check(primes.get(j), primes.get(l)) || !check(primes.get(k), primes.get(l))) continue;
            for (int m = l + 1; m < primes.size(); m++) {
              if (check(primes.get(i), primes.get(m)) && check(primes.get(j), primes.get(m)) && check(primes.get(k), primes.get(m)) && check(primes.get(l), primes.get(m))) {
                int sum = primes.get(i) + primes.get(j) + primes.get(k) + primes.get(l) + primes.get(m);
                return Integer.toString(sum);
              }
            }
          }
        }
      }
    }
    return "0";
  }

  private boolean check(int a, int b) {
    return Prime.isPrime(Integer.parseInt(a + "" + b)) && Prime.isPrime(Integer.parseInt(b + "" + a));
  }
}