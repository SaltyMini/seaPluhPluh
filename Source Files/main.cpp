#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include "../Header Files/window.h"
#include "../Header Files/consoleColourUtil.h"
#include "../Header Files/utils.hpp"

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

    string input = "";
    cout << "generate new window? (y/n)" << endl;
    cin >> input;
    input = toLowerString(input);
    if (input == "y") {
        cout << "Creating new window" << endl;
        //TODO: Create new window
    } else {
        cout << "Not creating new window" << endl;
    }

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

    if (input == "helloworld") {
        helloWorld();
    } else if (input == "desktop") {
        cout << "Creating Window" << endl;
        desktopStart();
    } else if (input == "help") {
        help();
        appStart();
    } else if (input == "exit") {
        cout << "Exiting" << endl;
        shutdown();
        return true;
    } else {
        cout << "Invalid Selection, type help for help" << endl;
        appStart();
    }

    return true;

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

    if(name == "zeb") {
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