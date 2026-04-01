// Problem 86: Cuboid route
// https://projecteuler.net/problem=86
// Find the least value of M such that the number of cuboids with integer dimensions,
// up to M by M by M, with shortest path integer, first exceeds one million.

#include <iostream>
#include <algorithm>
#include <cmath>

long long cuboid_route() {
    long long count = 0;
    int M = 0;
    const long long TARGET = 1000000;
    while (count <= TARGET) {
        M++;
        long long current_count = 0;
        for (int a = 1; a <= M; ++a) {
            for (int b = a; b <= M; ++b) {
                int c = M;
                long long p1 = (long long)(a + b) * (a + b) + (long long)c * c;
                long long p2 = (long long)(a + c) * (a + c) + (long long)b * b;
                long long p3 = (long long)(b + c) * (b + c) + (long long)a * a;
                long long min_p = std::min({p1, p2, p3});
                int root = (int)(std::sqrt(min_p) + 0.5);
                if ((long long)root * root == min_p) {
                    current_count++;
                }
            }
        }
        count += current_count;
    }
    return M;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << cuboid_route() << std::endl;
    return 0;
}
#endif