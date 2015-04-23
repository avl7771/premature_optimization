#include "written_numbers.hpp"

bool GetSpecificNumber(const std::string& written,
                       const std::string& written_number,
                       int number,
                       int* found_number, size_t* found_length) {
    if (written.substr(0, written_number.length()) == written_number) {
        *found_number = number;
        *found_length = written_number.length();
        return true;
    }

    return false;
}


void GetWrittenNumber(const std::string& written,
                      int* found_number, size_t* found_length) {
    if (!GetSpecificNumber(written, "one", 1, found_number, found_length) &&
        !GetSpecificNumber(written, "One", 1, found_number, found_length) &&
        !GetSpecificNumber(written, "two", 2, found_number, found_length) &&
        !GetSpecificNumber(written, "Two", 2, found_number, found_length) &&
        !GetSpecificNumber(written, "three", 3, found_number, found_length) &&
        !GetSpecificNumber(written, "Three", 3, found_number, found_length) &&
        !GetSpecificNumber(written, "four", 4, found_number, found_length) &&
        !GetSpecificNumber(written, "Four", 4, found_number, found_length) &&
        !GetSpecificNumber(written, "five", 5, found_number, found_length) &&
        !GetSpecificNumber(written, "Five", 5, found_number, found_length) &&
        !GetSpecificNumber(written, "six", 6, found_number, found_length) &&
        !GetSpecificNumber(written, "Six", 6, found_number, found_length) &&
        !GetSpecificNumber(written, "seven", 7, found_number, found_length) &&
        !GetSpecificNumber(written, "Seven", 7, found_number, found_length) &&
        !GetSpecificNumber(written, "eight", 8, found_number, found_length) &&
        !GetSpecificNumber(written, "Eight", 8, found_number, found_length) &&
        !GetSpecificNumber(written, "nine", 9, found_number, found_length) &&
        !GetSpecificNumber(written, "Nine", 9, found_number, found_length) &&
        !GetSpecificNumber(written, "ten", 10, found_number, found_length) &&
        !GetSpecificNumber(written, "Ten", 10, found_number, found_length) &&
        !GetSpecificNumber(written, "eleven", 11, found_number, found_length) &&
        !GetSpecificNumber(written, "Eleven", 11, found_number, found_length) &&
        !GetSpecificNumber(written, "twelve", 12, found_number, found_length) &&
        !GetSpecificNumber(written, "Twelve", 12, found_number, found_length)) {
        *found_number = 0;
        *found_length = 0;
    }
}


