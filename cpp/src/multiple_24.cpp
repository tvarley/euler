#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

class CSieveOfEratosthenes
{
public:
  CSieveOfEratosthenes(int a_upper = 0) : m_upper(a_upper), m_primes(nullptr)
  {
    init();
  }

  virtual ~CSieveOfEratosthenes()
  {
    delete m_primes;
  }

  int get_nth(int a_pos)
  {
    int value = 0;
    size_t i = 0;
    for ( i = 0; i < m_primes->size() && a_pos ; i++) {
      if( true == (*m_primes)[i] ){
        value = i;
        a_pos--;
      }
    }

    if( a_pos == 0 ){
      return value;
    }else{
      return 0;
    }
  }

protected:
  void init()
  {
    delete m_primes;

    if( m_upper <= 0 ){
      return;
    }

    int sqrtupper = (int)floor(sqrt(m_upper));

    m_primes = new std::vector<bool>(m_upper,true);

    (*m_primes)[0] = false;
    (*m_primes)[1] = false;

    for (size_t i = 2; i <= sqrtupper ; i++ ) {
      // cout << "O:" << i << endl;
      if( true == (*m_primes)[i]){
        for (size_t j = (i*i); j < m_upper; j += i ) {
          // cout << "    I:" << j << endl;
          (*m_primes)[j] = false;
        }
      }
    }
  }

private:
  int m_upper;
  std::vector<bool>*  m_primes;
};

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
  auto sieve = new CSieveOfEratosthenes(2000000);
  for( int i = 2 ; i < 100000; i++ ) {
    uint64_t prime = sieve->get_nth(i);
    auto test = (prime * prime) - 1;
    if( 0 != (test % 24)) {
      std::cout << i << ") Prime: " << prime << " Test: " << test << " Mod: " << (test % 24) << std::endl;
    }
  }
}
#endif // #if ! defined UNITTEST_MODE
