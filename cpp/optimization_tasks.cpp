#include "optimization_tasks.hpp"

#include <algorithm>
#include <fstream>
#include <vector>

#include "written_numbers.hpp"

std::vector<int> FindDigits(std::string content) {
    std::vector<int> list;
    for (auto pos = content.find_first_of("0123456789");
         pos != std::string::npos;
         pos = content.find_first_of("0123456789")) {
        content = content.substr(pos);
        size_t newpos;
        list.push_back(std::stoi(content, &newpos));
        content = content.substr(newpos);
    }

    return list;
}

std::vector<int> FindWrittenNumbers(std::string content) {
    std::vector<int> list;
    while (!content.empty()) {
        int number;
        size_t length;
        GetWrittenNumber(content, &number, &length);
        if (number > 0) {
            list.push_back(number);
            content = content.substr(length);
        } else {
            content = content.substr(1);
        }
    }

    return list;
}

std::vector<int> FindAllNumbers(const std::string& content) {
    std::vector<int> list;
    std::vector<int> result;

    list = FindWrittenNumbers(content);
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
