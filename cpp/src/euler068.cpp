// https://projecteuler.net/problem=68
// Magic 5-gon ring

// Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.
//
// Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example), each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.
//
// It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.
//
// By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.
//
// Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. What is the maximum 16-digit string for a "magic" 5-gon ring?

// Answer: 6531031914842725

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string magic_5gon_ring()
{
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    std::string max_str = "";

    do {
        // internals 0-4, externals 5-9
        int sum = nums[5] + nums[0] + nums[1];
        bool valid = true;
        for(int i = 1; i < 5; ++i){
            int ext = nums[5+i];
            int in1 = nums[i];
            int in2 = nums[(i+1)%5];
            if(ext + in1 + in2 != sum){
                valid = false;
                break;
            }
        }
        if(valid){
            // find the starting external with smallest value
            int min_ext = *std::min_element(nums.begin()+5, nums.end());
            int start = -1;
            for(int i = 0; i < 5; ++i){
                if(nums[5+i] == min_ext){
                    start = i;
                    break;
                }
            }
            // now concatenate starting from start
            std::string s = "";
            for(int i = 0; i < 5; ++i){
                int idx = (start + i) % 5;
                int ext = nums[5+idx];
                int in1 = nums[idx];
                int in2 = nums[(idx+1)%5];
                s += std::to_string(ext) + std::to_string(in1) + std::to_string(in2);
            }
            // only consider 16-digit strings
            if(s.length() == 16 && s > max_str){
                max_str = s;
            }
        }
    } while(std::next_permutation(nums.begin(), nums.end()));

    return max_str;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << magic_5gon_ring() << std::endl;
}
#endif // #if ! defined UNITTEST_MODE