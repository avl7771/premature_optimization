#include "optimization_tasks.hpp"

#include <vector>
#include <fstream>

int CalculateSecretNumber(const std::string& content) {
  std::vector<int> list;

  size_t foundpos;
  std::string haystack = content;
  while ((foundpos = haystack.find_first_of(
      std::string("0123456789otfsenOTFSEN"))) != std::string::npos) {
    haystack = haystack.substr(foundpos);

    if (haystack[0] >= '0' && haystack[0] <= '9') {
      size_t newpos;
      list.push_back(std::stoi(haystack, &newpos));
      haystack = haystack.substr(newpos);
    } else {
      if (haystack.substr(0, 3) == "one" ||
          haystack.substr(0, 3) == "One") {
        list.push_back(1);
        haystack = haystack.substr(3);
      } else if (haystack.substr(0, 3) == "two" ||
                 haystack.substr(0, 3) == "Two") {
        list.push_back(2);
        haystack = haystack.substr(3);
      } else if (haystack.substr(0, 5) == "three" ||
                 haystack.substr(0, 5) == "Three") {
        list.push_back(3);
        haystack = haystack.substr(5);
      } else if (haystack.substr(0, 4) == "four" ||
                 haystack.substr(0, 4) == "Four") {
        list.push_back(4);
        haystack = haystack.substr(4);
      } else if (haystack.substr(0, 4) == "five" ||
                 haystack.substr(0, 4) == "Five") {
        list.push_back(5);
        haystack = haystack.substr(4);
      } else if (haystack.substr(0, 3) == "six" ||
                 haystack.substr(0, 3) == "Six") {
        list.push_back(6);
        haystack = haystack.substr(3);
      } else if (haystack.substr(0, 5) == "seven" ||
                 haystack.substr(0, 5) == "Seven") {
        list.push_back(7);
        haystack = haystack.substr(5);
      } else if (haystack.substr(0, 5) == "eight" ||
                 haystack.substr(0, 5) == "Eight") {
        list.push_back(8);
        haystack = haystack.substr(5);
      } else if (haystack.substr(0, 4) == "nine" ||
                 haystack.substr(0, 4) == "Nine") {
        list.push_back(9);
        haystack = haystack.substr(4);
      } else if (haystack.substr(0, 3) == "ten" ||
                 haystack.substr(0, 3) == "Ten") {
        list.push_back(10);
        haystack = haystack.substr(3);
      } else if (haystack.substr(0, 6) == "eleven" ||
                 haystack.substr(0, 6) == "Eleven") {
        list.push_back(11);
        haystack = haystack.substr(6);
      } else if (haystack.substr(0, 6) == "twelve" ||
                 haystack.substr(0, 6) == "Twelve") {
        list.push_back(12);
        haystack = haystack.substr(6);
      } else {
        haystack = haystack.substr(1);
      }
    }
  }

  std::sort(list.begin(), list.end());

  int result = 0;
  for (size_t i = 0; i < list.size(); ++i) {
    if (i % 2 == 0)
      result += list[i];
    else
      result -= list[i];
  }

  return result;
}

std::string ReadFile(const char* path) {
  std::ifstream stream(path);
  std::string output((std::istreambuf_iterator<char>(stream)),
                      std::istreambuf_iterator<char>());

  return output;
}
