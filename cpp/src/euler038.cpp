// https://projecteuler.net/problem=38

// Take the number 192 and multiply it by each of 1, 2, and 3:

// 192 × 1 = 192

// 192 × 2 = 384

// 192 × 3 = 576

// By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3).

// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

// What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, …, n) where n > 1?

// Answer: 932718654

// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 <crush@charm.land>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

long long pandigital_multiples() {
    long long max_pandigital = 0;
    for(int x=1; x<10000; x++) {
        std::string concat = "";
        for(int k=1; ; k++) {
            concat += std::to_string(x * k);
            if(concat.size() > 9) break;
            if(concat.size() == 9) {
                std::string check = "123456789";
                std::string sorted = concat;
                std::sort(sorted.begin(), sorted.end());
                if(sorted == check) {
                    long long num = std::stoll(concat);
                    if(num > max_pandigital) max_pandigital = num;
                }
                break;
            }
        }
    }
    return max_pandigital;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << pandigital_multiples() << std::endl;
}
#endif // UNITTEST_MODE