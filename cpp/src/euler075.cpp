// https://projecteuler.net/problem=75
// Singular integer right triangles

// It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.

// 12 cm: (3,4,5)
// 24 cm: (6,8,10)
// 30 cm: (5,12,13)
// 36 cm: (9,12,15)
// 40 cm: (8,15,17)
// 48 cm: (12,16,20)

// In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.

// 120 cm: (30,40,50), (20,48,52), (24,45,51)

// Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?

// Answer: 161667

#include <iostream>
#include <vector>
#include <numeric>

int singular_integer_right_triangles()
{
    const int MAXL = 1500000;
    std::vector<int> count(MAXL+1, 0);

    for(int m=2; ; m++){
        bool stop = false;
        for(int n=1; n<m; n++){
            if((m-n) % 2 == 1 && std::gcd(m, n) == 1){
                long long a = (long long)m*m - n*n;
                long long b = 2LL * m * n;
                long long c = (long long)m*m + n*n;
                long long L = a + b + c;
                for(long long k=1; ; k++){
                    long long LL = k * L;
                    if(LL > MAXL){
                        break;
                    }
                    count[LL]++;
                }
            }
        }
        if((long long)m*m + (m-1)*(m-1) > MAXL) break;
    }

    int ans = 0;
    for(int i=1; i<=MAXL; i++){
        if(count[i] == 1){
            ans++;
        }
    }
    return ans;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << singular_integer_right_triangles() << std::endl;
}
#endif // #if ! defined UNITTEST_MODE