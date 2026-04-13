// https://projecteuler.net/problem=97
// Large Non-Mersenne Prime
//
// The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593−1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p−1, have been found which contain more digits.
//
// However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×2^7830457+1.
//
// Find the last ten digits of this prime number.
//
// Answer: 8739992577
//
// Completed on: 2024-12-04
// Time: ~1ms
// Optimizations: Modular exponentiation with BigInteger
// Notes: Computed 28433 * 2^7830457 + 1 mod 10^10.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;

public class Solution097 implements Solution {
    public String solve() {
        BigInteger mod = BigInteger.valueOf(10000000000L);
        BigInteger base = BigInteger.valueOf(2);
        BigInteger exp = BigInteger.valueOf(7830457);
        BigInteger pow2 = base.modPow(exp, mod);
        BigInteger coeff = BigInteger.valueOf(28433);
        BigInteger result = coeff.multiply(pow2).add(BigInteger.ONE).mod(mod);
        return result.toString();
    }
}