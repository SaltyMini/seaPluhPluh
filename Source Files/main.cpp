#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <windows.h>
#include "../Header Files/window.h"

#include "utils.cpp"

using namespace std;


static void helloWorld();
static void appStart();


int main()
{

    appStart();

    try {
		appStart2();
	}
	catch (exception) {
		cout << "Error: " << e.what() << endl;
	}

    return 0;
}

static bool appStart2()
{

    cout << "Type Help for Help" << endl;
    cout << "Select app to start, ";

    string input = "nothing";
	cin >> input;

	input = toLowerString(input);

    case(input) {
	case "helloworld":
		helloWorld();
		break;
	case "desktop":
		cout << "Creating Window" << endl;
		desktopStart();
		break;
	case "help":
		help();
		break;
	case "exit":
		cout << "Exiting" << endl;
		return true;
	default:
		cout << "Invalid Selection, type help for help" << endl;
		appStart2();
    }

}

static void desktopStart()
{
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
