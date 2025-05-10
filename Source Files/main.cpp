#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include "../Header Files/window.h"
#include "../Header Files/consoleColourUtil.h"
#include "../Header Files/utils.hpp"
#include "../Header Files/breakout.hpp"
#include "../Header Files/breakoutUtils.hpp"

using namespace std;

Window* pWindow = 0;

static void helloWorld();
static bool appStart();
static void desktopStart();
static void help();
static void shutdown();

int helpExplain = 0;


int main()
{
    SetConsoleTitleW(L"Hello World"); 
    Sleep(100);

    bool sucsess = appStart();
    
    return 0;
}

static bool appStart()
{
    
    if(helpExplain == 0) {
        cout << "Type Help for Help" << endl;
    }
    helpExplain = 1;

    cout << "Select app to start, ";
    
    string input = "nothing";
    cin >> input;

    input = toLowerString(input);

    vector<string> options = {"helloworld", "desktop", "breakout", "help", "exit"};
    Breakout breakout;

    auto it = find(options.begin(), options.end(), input);
    if(it != options.end()) {
        int index = it - options.begin();
        switch (index) {
            case 0:
                cout << "Starting Hello World" << endl;
                helloWorld();
                break;
            case 1:
                cout << "Starting Desktop" << endl;
                desktopStart();
                break;
            case 2:
                cout << "Starting Breakout" << endl;
                if(!isRunningAsAdmin()) {
                    cout << "Please run as admin" << endl;
                    appStart();
                }
                breakout.startGame();
                break;
            case 3:
                cout << "Starting Help" << endl;
                help();
                appStart();
                break;
            case 4:
                cout << "Exiting" << endl;
                shutdown();
                return true;
                break;
        }

    } else {
        cout << "Invalid Selection, type help for help" << endl;
        appStart();
    }
    return false;
}

static void desktopStart()
{
    cout << "Creating Window" << endl;

    pWindow = new Window();

    bool running = true;
    while (running)
    {
        if (!pWindow->processMessages())
        {
            cout << "Closing Window" << endl;
        }

        //render

        Sleep(10);
    }
    delete pWindow;

}

static void help() {
    setConsoleColor(ConsoleColor::BRIGHT_CYAN);
    cout << "Help Menu" << endl;
    setConsoleColor(ConsoleColor::CYAN);
    cout << "helloworld - Starts the Hello World app" << endl;
    cout << "desktop - Starts the Desktop app" << endl;
    cout << "breakout - Starts the Breakout game" << endl;
    cout << "help - Shows this help menu" << endl;
    cout << "exit - Exits the program" << endl;
    resetConsoleColor();
}

static void helloWorld() 
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl; 

    string name = "";

    cout << "What is your name?" << endl;
    cin >> name;
    
    name = toLowerString(name);
    name[0] = toupper(name[0]);

    if(name == "Zeb") {
        cout << "Fuck you";
    } else {
        cout << "Hello " << name;
    }
    cout << endl;
    appStart();
}

static void shutdown()
{

    if(pWindow == 0)
    {
        delete pWindow;
    }

    cout << "\nPress any key to exit...";
    _getch();  // Wait for any key press
    exit(0);

}



//Break out game down here,