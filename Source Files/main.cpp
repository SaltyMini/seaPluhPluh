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

static int getWindowSize();

int helpExplain = 0;


int main()
{
    SetConsoleTitleW(L"Hello World"); 
    Sleep(100);
    

    //check if running as admin
    int width = getWindowSize();
    if (width == 0) {
        setConsoleColor(ConsoleColor::BRIGHT_RED);
        cout << "Starting in defualt mode" << endl;
        cout << "Run as admin for enchanced user experience" << endl;
        resetConsoleColor();
        Sleep(3000)
        system("cls");
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

    vector<string> options = {"helloworld", "desktop", "breakout", "help", "exit"};

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
                // Call the function to start the Breakout game here
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

}

static int getWindowSize() {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    
    int width = r.right - r.left;
    int height = r.bottom - r.top;
    
    cout << "Window width: " << width << endl;
    cout << "Window height: " << height << endl;

    return width;
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