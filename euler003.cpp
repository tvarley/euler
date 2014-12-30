// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?
  #include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

// Size window (in bytes, not flags)
// i.e. 1000 chars can store 8000 flags
static const int ARRAY_INCREMENT = 1000;

#if ! defined BYTE
typedef unsigned char BYTE;
#endif

string base_convert(unsigned long v, long base)
{
  string digits = "0123456789abcdef";
  string result;
  if((base < 2) || (base > 16))
  {
    result = "Error: base out of range.";
  }
  else
  {
    do
    {
      result = digits[v % base] + result;
      v /= base;
    }
    while(v);
  }
  return result;
}

/*
 * Bit based flag vector
 */
class Cflags
{
public:
  Cflags(uint64_t a_reserve = 0) : m_flags(0), m_current_size(0), m_buffer_size(0)
  {
    m_current_size = 0;
    resize(a_reserve/8);
  }

  virtual ~Cflags()
  {
    delete [] m_flags;
  }

  bool set(uint64_t idx)
  {
    if( idx > m_current_size )
    {
      throw "Index out of range";
    }

    uint64_t short_idx = (floor(((float)idx / 8)));

    cout << "A:" << idx
          << " B:" <<  short_idx
          << " C:" <<  (0xFF - idx % 8)
          << endl;

    // 00000000 00000000 00000000

    // 1000000  0
    // 0100000  1
    // 0010000  2


    BYTE x = m_flags[short_idx];// && (idx%8);

    cout << "F: " <<  base_convert(x,2) << endl;// && (idx%8);
    x = x | (idx%8);
    cout << "F2: " <<  base_convert(x,2)<< endl;// && (idx%8);

    m_flags[short_idx] = m_flags[short_idx] | (idx%8);

    return x;
  }

  bool get(uint64_t idx)
  {
    uint64_t short_idx = (floor(((float)idx / 8)));
    return m_flags[short_idx] && (idx%8);
  }

  uint64_t size()
  {
      return m_current_size;
  }

  uint64_t real_size()
  {
    return m_buffer_size;
  }

protected:
private:

  uint64_t m_current_size;  // In Bytes
  uint64_t m_buffer_size;

  BYTE* m_flags;

  void resize(
              uint64_t new_size // < In flags
                )
  {
    if( 0 == m_flags ||
        new_size != m_current_size )
    {
      if( new_size > m_current_size )
      {
        uint64_t real_size = ceil((float)(new_size*8)/ARRAY_INCREMENT)* ARRAY_INCREMENT;
        BYTE* new_array = new BYTE(real_size);
        if( 0 != m_flags )
        {
          memcpy( new_array , m_flags , m_current_size);
          delete [] m_flags;
        }
        m_flags = new_array;
        m_buffer_size = real_size;
      }
      m_current_size = new_size;
    }
  }
};

int main( int argc , char* argv[]  )
{
  uint64_t test = 600851475143;

  try
  {
    // TODO: Sieve of Erosthanes
    // http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

    /*
    * For this problem we have a few issues
    * 1. We want the algorithm to be performant, so a 'is this prime' approach
    * would be too slow.  An efficient method for locating primes is the
    * Sieve of Erosthanes (documented above.)
    * 2. If were to use the Sieve, it would normally lead to an array of bools
    * but as the test number is so large we would end up with a very large array.
    * We could use std collections and remove non primes (flags) as identified
    * but that would add additional memory manipulation (remove from list)
    * What I am going to do is:
    *   1/ Ignore evens off the bat, reducing the array footprint and # of checks
    *   2/ See if I can use a bit based flag array (footprint / 8)
    */

    class Cflags* flags = new Cflags(600851475143);

    // flags->set(4);
    // flags->set(14);
    // flags->set(15);
    flags->set(16);


    // cout << flags->get(4) << endl;
    // cout << flags->get(14) << endl;
    // cout << flags->get(15) << endl;
    cout << flags->get(16) << endl;

    bool check = flags->get(1000);

    // cout << flags->size() << endl;
    // cout << flags->real_size() << endl;
    // cout << check << endl;
  }
  catch( char* e )
  {
    cerr << "Exception thrown: "
      << e
      << endl;
  }



}
