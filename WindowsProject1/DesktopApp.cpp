// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include<iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
using namespace std;

#define MAINWIN_WIDTH 500
#define MAINWIN_HEIGHT 400
HINSTANCE hInst;
int nCmdShowGlobal;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //declaration of the window procedures method.
// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Untitled - Text-Editor");



#include"windowStuff.h"




#define processCallCount 0




HMENU hMenuMain;


// Global variables





// Forward declarations of functions included in this code module:


int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = (HICON)LoadImage( // returns a HANDLE so we have to cast to HICON
        NULL,             // hInstance must be NULL when loading from a file
        L"editor-png-open-2000.ico",   // the icon file name
        IMAGE_ICON,       // specifies that the file is an icon
        0,                // width of the image (we'll specify default later on)
        0,                // height of the image
        LR_LOADFROMFILE |  // we want to load a file (as opposed to a resource)
        LR_DEFAULTSIZE |   // default metrics based on the type (IMAGE_ICON, 32x32)
        LR_SHARED         // let the system release the handle when it's no longer used
    );
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    //store ncmdshow in out gloabal vairalble
    nCmdShowGlobal = nCmdShow;

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        MAINWIN_WIDTH, MAINWIN_HEIGHT,
        NULL,
        hMenuMain,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);




    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    
    //handleOtherWindows(_In_ HINSTANCE hInstance, )

    return (int)msg.wParam;
    
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Hello, Windows desktop!");
    wchar_t msg[50];


    switch (message)
    {
    case WM_CREATE:
        OutputDebugStringW((LPCWSTR)L"WM_CREATE called....");
        handleCenterWindow(hWnd);
        //handleButton(hWnd);
        //handleNewWidow(hWnd);
        //handleManu(hWnd);
        handleMainMenu(hWnd, hMenuMain);
        handleEdit(hWnd, lParam);
        break;

    case WM_COMMAND:
        //DisplayResourceNAMessageBox(hWnd);

        switch (wParam)
        {
        case ID_EXIT_MENU:
            handleDistroyManu();
            PostQuitMessage(0);
            break;
        case ID_ABOUT_MENU:
            handleAbout(hWnd);
            break;
        case ID_OPEN_MENU:
            handleOpenMenu(hWnd);
            break;
        case ID_NEW_MENU:
            hanleNewWidow(hWnd);
            break;
        case ID_SAVE_MENU:
            hanleSaveText(hWnd);
            break;
        case ID_SAVEAS_MENU:
            hanleSaveAsText(hWnd);
            break;
        case ID_SETTINGS_MENU:
            handleSettingsWindow(hWnd);
            break;
        case ID_SETTINGS_DIALOG_MENU:
            handleSettingsDialogBoxWindow(hWnd);
            break;
            
        default:
            break;
        }

        //OutputDebugStringW((LPCWSTR)L"command called.");

        break;

    case WM_INITDIALOG:
        OutputDebugStringW((LPCWSTR)L"WM_INITDIALOG called....");
        break;

    case WM_SETFOCUS:
        SetFocus(hwndEdit);
        break;

    case WM_SIZE:
        MoveWindow(hwndEdit,
            0, 0,                  // starting x- and y-coordinates 
            LOWORD(lParam),        // width of client area 
            HIWORD(lParam),        // height of client area 
            TRUE);                 // repaint window 
        break;
    case WM_GETMINMAXINFO:
        MINMAXINFO MMI;
        MMI.ptMaxSize.x = 600;
        MMI.ptMaxSize.y = 600;
        break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        /*
        PAINTSTRUCT ps;
        HDC hdc;
        hdc = BeginPaint(hWnd, &ps);

        // Here your application is laid out.
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 5));
        // End application-specific layout section.

        EndPaint(hWnd, &ps);
        */
        break;
    case WM_DESTROY:
        handleDistroyManu();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }


    return 0;
}
