// https://projecteuler.net/problem=48

// The series, 1¹ + 2² + 3³ + … + 10¹⁰ = 10405071317.
// Find the last ten digits of the series, 1¹ + 2² + 3³ + … + 1000¹⁰⁰⁰.

// Answer: 9110846700

module.exports = {
  answer: () => {
    const MOD = 10000000000n;
    let sum = 0n;
    for (let i = 1n; i <= 1000n; i++) {
      let pow = 1n;
      for (let j = 0n; j < i; j++) {
        pow = (pow * i) % MOD;
      }
      sum = (sum + pow) % MOD;
    }
    return Number(sum);
  }
};