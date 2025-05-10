#include <iostream>
#include <windows.h>


using namespace std;

int getWindowSize() {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    
    int width = r.right - r.left;
    int height = r.bottom - r.top;
    
    cout << "Window width: " << width << endl;
    cout << "Window height: " << height << endl;

    return width, height;
}

bool isRunningAsAdmin() {

    int width = getWindowSize();
    if (width == 0) {
        return false;
    }

    return true;

}