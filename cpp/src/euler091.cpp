// Problem 91: Right triangles with integer coordinates
// https://projecteuler.net/problem=91
// Count right-angled triangles with vertices on integer coords in 0..50 grid (right angle anywhere).
// Cases: origin, x-axis, y-axis (3*size²). Interior: GCD-reduced steps for Q from P (dot product=0),
// symmetry (py<=px, *2 for mirror). O(N²) with small constants.

#include <iostream>

unsigned int gcd(unsigned int a, unsigned int b) {
    while (a != 0) {
        unsigned int c = a;
        a = b % a;
        b = c;
    }
    return b;
}

long long right_triangles() {
    const unsigned int size = 50;
    long long result = 3LL * size * size;  // origin + x-axis + y-axis

    // right angle at interior point P(px, py); uses GCD to step through valid Q points where PO·PQ = 0
    // only iterates bottom triangle (py <= px) and doubles count for symmetry (except diagonal)
    for (unsigned int px = 1; px <= size; ++px) {
        for (unsigned int py = 1; py <= px; ++py) {
            unsigned int factor = gcd(px, py);
            unsigned int dx = px / factor;
            unsigned int dy = py / factor;

            unsigned int found = 0;

            // Q below P
            int qx = static_cast<int>(px) - dy;
            int qy = static_cast<int>(py) + dx;
            while (qx >= 0 && qy <= static_cast<int>(size)) {
                ++found;
                qx -= dy;
                qy += dx;
            }

            // Q above P
            qx = static_cast<int>(px) + dy;
            qy = static_cast<int>(py) - dx;
            while (qy >= 0 && qx <= static_cast<int>(size)) {
                ++found;
                qx += dy;
                qy -= dx;
            }

            if (px != py) found *= 2;
            result += found;
        }
    }
    return result;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << right_triangles() << std::endl;
    return 0;
}
#endif