#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include "../Header Files/window.h"

#include "../Source Files/utils/utils.cpp"

using namespace std;

Window* pWindow = 0;

static void helloWorld();
static bool appStart();
static void desktopStart();
static void help();
static void shutdown();

int main()
{

    bool sucsess = appStart();

    if(!sucsess)
    {
        //app failed
        shutdown();
    }


    return 0;
}

static bool appStart()
{

    cout << "Type Help for Help" << endl;
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
    cout << "Help Menu" << endl;
	cout << "helloworld - Starts the Hello World app" << endl;
	cout << "desktop - Starts the Desktop app" << endl;
	cout << "help - Shows this help menu" << endl;
	cout << "exit - Exits the program" << endl;
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