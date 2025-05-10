#pragma once
#include <windows.h>
#include <string>

enum class ConsoleColor {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    YELLOW = 6,
    WHITE = 7,
    BRIGHT_BLUE = 9,
    BRIGHT_GREEN = 10,
    BRIGHT_CYAN = 11,
    BRIGHT_RED = 12,
    BRIGHT_MAGENTA = 13,
    BRIGHT_YELLOW = 14,
    BRIGHT_WHITE = 15
};

void setConsoleColor(ConsoleColor textColor, ConsoleColor backgroundColor = ConsoleColor::BLACK);
void resetConsoleColor();
void printWithColor(const std::string& text, ConsoleColor textColor, ConsoleColor backgroundColor = ConsoleColor::BLACK);