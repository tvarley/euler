// https://projecteuler.net/problem=67
// Maximum path sum II

// By starting at the top of the triangle below and moving to adjacent numbers
// on the row below, the maximum total from top to bottom is 23.
//
//    3
//   7 4
//  2 4 6
// 8 5 9 3
//
// That is, 3 + 7 + 4 + 9 = 23.
//
// Find the maximum total from top to bottom in triangle.txt (right click and
// 'Save Link/Target As...'), a 15K text file containing a triangle with
// one-hundred rows.
//
// NOTE: This is a much more difficult version of Problem 18. It is not possible
// to try every route to solve this problem, as there are 2^99 altogether! If
// you could check one trillion (10^12) routes every second it would take over
// twenty billion years to check them all. There is an efficient algorithm to
// solve it. ;o)

// Answer: 7273

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

static const char* test_data_fname_67 = "./src/euler_67_data.txt";

int maximum_path_sum_2(const char* fname)
{
  std::ifstream fin(fname);

  if( !fin.is_open()){
    std::cerr << "Failed to open input file: " << fname << std::endl;
    return -1;
  }

  std::vector<std::vector<int> > lines;

  for( std::string line ; std::getline(fin,line);){
    std::stringstream ss(line);
    std::string number;
    std::vector<int> inner;

    while (std::getline(ss,number,' ')) {
      inner.push_back(std::stoi(number));
    }
    lines.push_back(inner);
  }

  for( int i = lines.size()-1; i > 0 ; --i){
    for( int j = 0 ; j < i; j++){
      if( lines[i][j] > lines[i][j+1] ){
        lines[i-1][j] += lines[i][j];
      }else{
        lines[i-1][j] += lines[i][j+1];
      }
    }
  }

  return lines[0][0];
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << "Answer: " << maximum_path_sum_2(test_data_fname_67) << std::endl;
}
#endif // #if ! defined UNITTEST_MODE