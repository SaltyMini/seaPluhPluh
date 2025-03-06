#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <windows.h>
#include "../Header Files/window.h"

using namespace std;


static void helloWorld();
static void appStart();


int main()
{

    appStart();

    return 0;
}

static void appStart() 
{
    vector<string> apps = {"helloworld", "desktop"};

    string appSelection = "";
    cout << "Type Help for Help" << endl;
    cout << "Select app to start, ";
    cin >> appSelection;

    string appSelectionLower = "";
    for(char c : appSelection) {
        appSelectionLower += tolower(c);
    }
    
    if(appSelectionLower == "helloworld") {
        helloWorld();
    } else if (appSelectionLower == "help") 
    {
        cout << "Help";
        appStart();
    } else if (appSelectionLower == "desktop") {

        cout << "Creating Window" << endl;

        Window* pWindow = new Window();

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


    } else {
        cout << "Invalid Selection" << endl;
        appStart();
    }

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
    string nameLower = "";

    cout << "What is your name?" << endl;
    cin >> name;
    
    for(char c : name) {
        nameLower += tolower(c);
    }

    nameLower[0] = toupper(nameLower[0]);

    if(name == "zeb") {
        cout << "Fuck you";
    } else {
        cout << "Hello " << nameLower;
    }
    appStart();
}
