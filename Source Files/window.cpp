#include "../Header Files/window.h"
#include <iostream>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

LRESULT WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) 
    {
        case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            

            HBRUSH hBrush = CreateSolidBrush(RGB(8, 132, 132));
            FillRect(hdc, &ps.rcPaint, hBrush);
            DeleteObject(hBrush);

            SetTextColor(hdc, RGB(0, 0, 255));
            SetBkColor(hdc, RGB(255, 255, 255));
            SetBkMode(hdc, TRANSPARENT);

            TextOutW(hdc, 10, 10, L"Hello, World!", 13);




            EndPaint(hWnd, &ps);
        }
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


Window::Window()
    : m_hInstance(GetModuleHandle(nullptr))
{
    const wchar_t* CLASS_NAME = L"Window Class";

    WNDCLASSW wndClass = {};
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = m_hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpfnWndProc = WindowProc;

    RegisterClassW(&wndClass);

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

    int width = 640;
    int height = 480;

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;

    AdjustWindowRect(&rect, style, false);

    m_hWnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Desktop",
        style,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        m_hInstance,
        NULL
    );

    if (m_hWnd == NULL)
    {
        DWORD error = GetLastError();
        std::cout << error;
    }

    BOOL darkmode = TRUE;
    DwmSetWindowAttribute(m_hWnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &darkmode, sizeof(darkmode));

    ShowWindow(m_hWnd, SW_SHOWDEFAULT);
}

Window::~Window()
{
    const wchar_t* CLASS_NAME = L"Window Class";

    UnregisterClassW(CLASS_NAME, m_hInstance);
}

bool Window::processMessages()
{
    MSG msg = {};

    while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
    {

        if(msg.message == WM_QUIT)
        {
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return true;
}

