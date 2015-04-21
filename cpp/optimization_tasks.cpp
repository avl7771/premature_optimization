#include "optimization_tasks.hpp"

#include <vector>
#include <fstream>

std::vector<int> FindDigits(std::string content) {
  std::vector<int> list;
  for (auto pos = content.find_first_of("0123456789"); pos != std::string::npos;
       pos = content.find_first_of("0123456789")) {
    content = content.substr(pos);
    size_t newpos;
    list.push_back(std::stoi(content, &newpos));
    content = content.substr(newpos);
  }

  return list;
}

unsigned FindWrittenNumberOccurrences(
    std::string content, const std::string& to_search) {
  unsigned count = 0;

  for (auto pos = content.find(to_search); pos != std::string::npos;
       pos = content.find(to_search)) {
    ++count;
    content = content.substr(pos + to_search.length());
  }

  return count;
}

std::vector<int> AccumulateNumbers(
    const std::string& content, const std::string& written, int number) {
  std::vector<int> list;
  unsigned count = FindWrittenNumberOccurrences(content, written);
  for (unsigned i = 0; i < count; ++i)
    list.push_back(number);

  return list;
}

std::vector<int> FindAllNumbers(const std::string& content) {
  std::vector<int> list;
  std::vector<int> result;

  list = AccumulateNumbers(content, "one", 1);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "One", 1);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "two", 2);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Two", 2);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "three", 3);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Three", 3);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "four", 4);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Four", 4);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "five", 5);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Five", 5);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "six", 6);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Six", 6);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "seven", 7);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Seven", 7);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "eight", 8);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Eight", 8);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "nine", 9);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Nine", 9);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "ten", 10);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Ten", 10);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "eleven", 11);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Eleven", 11);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "twelve", 12);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = AccumulateNumbers(content, "Twelve", 12);
  std::copy(list.begin(), list.end(), std::back_inserter(result));
  list = FindDigits(content);
  std::copy(list.begin(), list.end(), std::back_inserter(result));

  return result;
}

int CalculateSecretNumber(const std::string& content) {
  std::vector<int> list = FindAllNumbers(content);

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
