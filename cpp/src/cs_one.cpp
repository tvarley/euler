#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>

int main() {
  std::cout << "Hello world" << std::endl;
  Json::Value root;
  Json::Reader reader;
  if( !reader.parse("./json_example_one.json", root)) {
    std::cout << "Failed to parse json file" << std::endl 
              << reader.getFormatedErrorMessages() << std::endl;
  }
  return 0;
}
