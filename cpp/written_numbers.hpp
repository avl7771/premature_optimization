#ifndef WRITTEN_NUMBERS_HPP
#define WRITTEN_NUMBERS_HPP

#include <string>

bool GetSpecificNumber(const std::string& written,
                       const std::string& written_number,
                       int number,
                       int* found_number, size_t* found_length);

void GetWrittenNumber(const std::string& written,
                      int* found_number, size_t* found_length);

#endif // WRITTEN_NUMBERS_HPP
