#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include "../Header Files/breakoutUtils.hpp"
#include "../Header Files/breakout.hpp"

using namespace std;

void configWindow();

Breakout::Breakout() : isRunning(false) {
    // Initialize other members here
}

Breakout::~Breakout() {
    // Cleanup code here
}

void Breakout::startGame() {
    cout << "Starting Breakout Game..." << endl;


    if(isRunning) {
        cout << "Game is already running!" << endl;
        return;
    }
    configWindow();
    this->isRunning = true;
}

void configWindow() {
    HWND console = GetConsoleWindow();
    cout << "Configuring Window..." << endl;
    Sleep(4000);
    // Set the window size to 800x600
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Get the current console info
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    
    // First make window smaller than buffer
    SMALL_RECT tempWindowSize = {0, 0, 60, 30};
    SetConsoleWindowInfo(hConsole, TRUE, &tempWindowSize);
    
    // Set new buffer size
    COORD bufferSize = {100, 50};
    if (!SetConsoleScreenBufferSize(hConsole, bufferSize)) {
        cout << "Failed to set buffer size. Error: " << GetLastError() << endl;
        return;
    }
    
    // Now set the final window size
    SMALL_RECT windowSize = {0, 0, 99, 49};
    if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize)) {
        cout << "Failed to set window size. Error: " << GetLastError() << endl;
        return;
    }
    
    
}