#include <iostream>
#include <chrono>
#include <algorithm>

typedef std::chrono::high_resolution_clock my_clock;
typedef std::chrono::milliseconds timer_res;

int main( int argc , char* argv[] )
{
  // double duration;
  int m = 100;
  int a[100];
  static const int ITER = 1000000;

  auto p1 = my_clock::now();
  for( int i = 0 ; i < ITER ; i++ )
  {
    std::for_each(a,a+m,[](int& a){a = 5;});
  }
  auto p2 = my_clock::now();
  auto a1 = p2-p1;
  std::cout << "Duration lamba: " << std::chrono::duration_cast<timer_res>(a1).count() << std::endl;

  p1 = my_clock::now();
  for( int j = 0 ; j < ITER ; j++ )
  {
    for(int i = (m+1) ; --i ;  ){
      a[i-1] = 6;
    }
  }
  p2 = my_clock::now();
  a1 = p2-p1;
  std::cout << "backward loop: " << std::chrono::duration_cast<timer_res>(a1).count() << std::endl;

  p1 = my_clock::now();
  for( int j = 0 ; j < ITER ; j++ )
  {
    for(int i = m ; i-- ;  ){
      a[i] = 6;
    }
  }
  p2 = my_clock::now();
  a1 = p2-p1;
  std::cout << "forward loop: " << std::chrono::duration_cast<timer_res>(a1).count() << std::endl;
}
