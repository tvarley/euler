/*
 * Solution for Euler problem 032
 *
 * Pandigital Products
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 * Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.*;

public class Solution032 implements Solution {
  public String solve() {
    Set<Integer> products = new HashSet<>();
    String digits = "123456789";
    permute(digits, 0, products);
    int sum = 0;
    for (int p : products) sum += p;
    return Integer.toString(sum);
  }

  private void permute(String s, int start, Set<Integer> products) {
    if (start == s.length()) {
      checkProducts(s, products);
      return;
    }
    for (int i = start; i < s.length(); i++) {
      s = swap(s, start, i);
      permute(s, start + 1, products);
      s = swap(s, start, i);
    }
  }

  private String swap(String s, int i, int j) {
    char[] arr = s.toCharArray();
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return new String(arr);
  }

  private void checkProducts(String perm, Set<Integer> products) {
    for (int i = 1; i < perm.length(); i++) {
      for (int j = i + 1; j < perm.length(); j++) {
        String a = perm.substring(0, i);
        String b = perm.substring(i, j);
        String c = perm.substring(j);
        if (a.charAt(0) == '0' || b.charAt(0) == '0' || c.charAt(0) == '0') continue;
        int numA = Integer.parseInt(a);
        int numB = Integer.parseInt(b);
        int numC = Integer.parseInt(c);
        if (numA * numB == numC) {
          products.add(numC);
        }
      }
    }
  }
}