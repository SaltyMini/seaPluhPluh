#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::string toLowerString(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        c = std::tolower(c);
    }
    return result;
}

std::string toUpperString(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        c = std::toupper(c);
    }
    return result;
}