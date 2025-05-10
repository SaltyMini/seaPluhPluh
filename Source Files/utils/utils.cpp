#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "../Header Files/utils.hpp"

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

bool vectorContains(const std::vector<std::string>& vec, const std::string& str) {
	for (const auto& item : vec) {
		if (item == str) {
			return true;
		}
	}
	return false;
}