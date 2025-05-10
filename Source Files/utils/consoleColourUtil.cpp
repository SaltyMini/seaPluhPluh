#include "../../Header Files/consoleColourUtil.h"
#include <iostream>

void setConsoleColor(ConsoleColor textColor, ConsoleColor backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 
        static_cast<WORD>(textColor) | (static_cast<WORD>(backgroundColor) << 4));
}

void resetConsoleColor() {
    setConsoleColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
}

void printWithColor(const std::string& text, ConsoleColor textColor, ConsoleColor backgroundColor) {
    setConsoleColor(textColor, backgroundColor);
    std::cout << text;
    resetConsoleColor();
}