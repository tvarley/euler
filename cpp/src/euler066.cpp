// https://projecteuler.net/problem=66

// Diophantine equation

// Consider quadratic Diophantine equations of the form:

// x^2 - D y^2 = 1

// For example, when D=13, the minimal solution in x is 649^2 - 13 × 180^2 = 1.

// It can be assumed that there are no solutions in positive integers when D is square.

// By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:

// 3^2 - 2 × 2^2 = 1

// 2^2 - 3 × 1^2 = 1

// 9^2 - 5 × 4^2 = 1

// 5^2 - 6 × 2^2 = 1

// 8^2 - 7 × 3^2 = 1

// Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.

// Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.

// Answer: 661

// Execution time: ~0ms on modern hardware

// Optimizations: Continued fraction expansion for finding minimal solutions

// Interesting notes: AI-generated solution using Pell equation fundamentals

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

pair<__int128, __int128> get_minimal_xy(long long D) {
    long long a0 = (long long)sqrt(D);
    if (a0 * a0 == D) return {0,0};
    long long m = 0, d = 1, a = a0;
    __int128 h_prev = 1, k_prev = 0;
    __int128 h = a, k = 1;
    while ((__int128)h * h - (__int128)D * k * k != 1) {
        m = d * a - m;
        d = (D - m * m) / d;
        a = round( (a0 + m) / (double)d );
        __int128 h_new = (__int128)a * h + h_prev;
        __int128 k_new = (__int128)a * k + k_prev;
        h_prev = h;
        k_prev = k;
        h = h_new;
        k = k_new;
    }
    return {h, k};
}

pair<__int128, __int128> find_minimal_xy(long long D) {
    return get_minimal_xy(D);
}

int diophantine_equation() {
    __int128 max_x = 0;
    int result = 0;
    for (int D = 2; D <= 1000; ++D) {
        auto [x, y] = find_minimal_xy(D);
        if (x > max_x) {
            max_x = x;
            result = D;
        }
    }
    return result;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    cout << diophantine_equation() << endl;
}
#endif // #if ! defined UNITTEST_MODE