// https://projecteuler.net/problem=22
// Names scores

// Using names.txt (right click and 'Save Link/Target As...'),
// a 46K text file containing over five-thousand first names,
// begin by sorting it into alphabetical order.
// Then working out the alphabetical value for each name, multiply this
// value by its alphabetical position in the list to obtain a name score.
//
// For example, when the list is sorted into alphabetical order,
// COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in
// the list. So, COLIN would obtain a score of 938 × 53 = 49714.
//
// What is the total of all the name scores in the file?

// Answer: 871198282

#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

// TODO: template to a non ascii version and optimize
int alphabet_score(std::string name)
{
  int score = 0;

  for( char& c : name ){
    if( std::isalpha(c)){ // Do not care about quotes
      score += toupper(c) - 'A'+1;
    }
  }

  return score;
}

int name_scores(const char* fname)
{
  typedef std::map<std::string,int> name_coll;
  name_coll names;

  std::cout << "Opening: " << fname << std::endl;
  std::ifstream fin(fname);

  if( !fin.is_open()){
    std::cerr << "Failed to open file: " << fname << std::endl;
  }

  for( std::string line ; std::getline(fin,line);){
    std::stringstream ss(line);
    std::string name;

    while (std::getline(ss,name,',')) {
      int score = alphabet_score(name);

      // std::cout << "Name: " << name << ':' << score << std::endl;

      name_coll::iterator n = names.find(name);
      if( n != names.end()){
        n->second += score; // Dupe name, just count again
      }else{
        names.insert( name_coll::value_type(name,score));
      }
    }
  }

  int total_score = 0;
  int pos = 1;
  for( name_coll::iterator itr = names.begin(); itr != names.end() ; itr++, pos++){
      // std::cout << "Name: " << pos << ':' << itr->first << ':' << itr->second << std::endl;
      total_score += (pos*itr->second);
  }

  return total_score;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
  std::cout << "Answer: " << name_scores("./src/p022_names.txt") << std::endl;
}
#endif //#if ! defined UNITTEST_MODE
