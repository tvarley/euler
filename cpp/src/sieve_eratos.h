#if ! defined SIEVE_ERATOS_INCLUDED
#define SIEVE_ERATOS_INCLUDED

#include <vector>
#include <cmath>

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
      // cout << "O: " << i << endl;
      if( true == (*m_primes)[i] ){
        // cout << "    **" << endl;
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

  u_int64_t sum(size_t a_max)
  {
    u_int64_t total = 0;
    size_t i;
    for( i = 0; i < a_max ; i++){
      if( true == (*m_primes)[i]){
        total += i;
      }
    }
    return total;
  }

  void dump(void);

  bool is_prime(unsigned long n) const {
    if (n >= m_upper || n < 2) return false;
    return (*m_primes)[n];
  }

protected:
  void init()
  {
    delete m_primes;

    if( m_upper <= 0 ){
      return;
    }

    size_t sqrtupper = (int)floor(sqrt(m_upper));

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
  size_t m_upper;
  std::vector<bool>*  m_primes;
};


#endif // SIEVE_ERATOS_INCLUDED
