// https://projecteuler.net/problem=39

// If p is the perimeter of a right angle triangle with integral length sides, {a, b, c}, there are exactly three solutions for p = 120.

// {20,48,52}, {24,45,51}, {30,40,50}

// For which value of p ≤ 1000, is the number of solutions maximised?

// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 <crush@charm.land>

#include <iostream>
#include <vector>
#include <string>

int integer_right_triangles() {
    int max_count = 0;
    int best_p = 0;
    for(int p=12; p<=1000; p++) {
        int count = 0;
        for(int a=1; a<p; a++) {
            for(int b=a; b<p-a; b++) {
                int c = p - a - b;
                if(a*a + b*b == c*c) count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            best_p = p;
        }
    }
    return best_p;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << integer_right_triangles() << std::endl;
}
#endif // UNITTEST_MODE