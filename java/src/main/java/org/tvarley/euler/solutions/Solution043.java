/*
 * Solution for Euler problem 043
 *
 * Sub-string Divisibility
 *
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 * d2d3d4=406 is divisible by 2
 * d3d4d5=063 is divisible by 3
 * d4d5d6=635 is divisible by 5
 * d5d6d7=357 is divisible by 7
 * d6d7d8=572 is divisible by 11
 * d7d8d9=728 is divisible by 13
 * d8d9d10=289 is divisible by 17
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 *
 * @author tvarley
 * @date 3/14/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.ArrayList;
import java.util.List;

public class Solution043 implements Solution {
  public String solve() {
    String digits = "0123456789";
    List<String> perms = generatePermutations(digits);
    long sum = 0;
    for (String p : perms) {
      if (check(p)) {
        sum += Long.parseLong(p);
      }
    }
    return Long.toString(sum);
  }

  private boolean check(String s) {
    int[] divs = {2, 3, 5, 7, 11, 13, 17};
    for (int i = 0; i < 7; i++) {
      int num = Integer.parseInt(s.substring(i + 1, i + 4));
      if (num % divs[i] != 0) return false;
    }
    return true;
  }

  private List<String> generatePermutations(String s) {
    List<String> result = new ArrayList<>();
    permute(s.toCharArray(), 0, result);
    return result;
  }

  private void permute(char[] arr, int index, List<String> result) {
    if (index == arr.length) {
      result.add(new String(arr));
      return;
    }
    for (int i = index; i < arr.length; i++) {
      swap(arr, index, i);
      permute(arr, index + 1, result);
      swap(arr, index, i);
    }
  }

  private void swap(char[] arr, int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}