#pragma once

#include"mySample.h"
#include <ShObjIdl.h>

#define BUTTON_ID_OK 0
#define ID_FILE_MENU 1
#define ID_EXIT_MENU 0x1df
#define ID_TOOLS_MENU 0x2f0
#define ID_ABOUT_MENU 0x100
#define ID_OPEN_MENU 0x011

HMENU hMenu;



void handleOpenMenu(HWND hWnd) {
    
    OPENFILENAME ofn;

    LPWSTR fileName[100];

    ZeroMemory(&ofn, sizeof(OPENFILENAME));

    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFile = (LPWSTR)fileName;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = 100;
    ofn.lpstrFilter = (LPWSTR)L"Text Files\0*.txt*\0";
    ofn.nFilterIndex = 1;

    GetOpenFileName(&ofn);

    MessageBox(
        hWnd,
        ofn.lpstrFile,
        (LPCWSTR)L"Path",
        MB_OK
    );

}




void handleAbout(HWND hWnd) {
    OutputDebugStringW((LPCWSTR)L"handleAbout called.");
    
    int msgboxID = MessageBox(
        hWnd,
        (LPCWSTR)L"Developed by M.Salman Altaf",
        (LPCWSTR)L"About",
        MB_OK
    );
    
}



void handleMainMenu(HWND hWnd, HMENU hMenuMain) {
    hMenuMain = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    HMENU hSubFileMenu = CreateMenu();
    HMENU hHelpMenu = CreateMenu();
    
    
    AppendMenu(hMenuMain, MF_POPUP, (UINT_PTR)hFileMenu, (LPCWSTR)L"File");
    AppendMenu(hMenuMain, MF_POPUP, (UINT_PTR)hHelpMenu, (LPCWSTR)L"Help");
    AppendMenu(hHelpMenu, MF_POPUP, ID_ABOUT_MENU, (LPCWSTR)L"About");
    AppendMenu(hSubFileMenu, MF_STRING, NULL, (LPCWSTR)L"Sub menu   F5");

    AppendMenu(hFileMenu, MF_STRING, NULL, (LPCWSTR)L"New");
    AppendMenu(hFileMenu, MF_STRING, ID_OPEN_MENU, (LPCWSTR)L"Open");
    AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hSubFileMenu, (LPCWSTR)L"Tools");
    AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
    AppendMenu(hFileMenu, MF_STRING, ID_EXIT_MENU, (LPCWSTR)L"Exit");

    SetMenu(hWnd, hMenuMain);
}



void handleManu(HWND hWnd) {
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();

    AppendMenu(hFileMenu, MF_STRING, ID_EXIT_MENU, (LPCWSTR)L"Exit");

    AppendMenu(hMenu, MF_STRING, (UINT_PTR)hFileMenu, (LPCWSTR)L"File");

    SetMenu(hWnd, hMenu);
}

void showManuDistructionFailed() {
    MessageBox(
        NULL,
        (LPCWSTR)L"Manu Distruction Failed.",
        (LPCWSTR)L"distruction info.",
        MB_ICONWARNING
    );
}

void handleDistroyManu() {
    if (hMenu) {
        int manuDestroyed = DestroyMenu(hMenu);
        if (!manuDestroyed) showManuDistructionFailed();
    }
    
}










void handleNewWidow(HWND hWnd) {

}


































//cetering window
void handleCenterWindow(HWND hWnd) {
    int centerd = CenterWindow(hWnd);
    if (!centerd) DisplayWindowCannotMoveMessageBox(hWnd);
}


void handleButton(HWND hWnd) {
    //button
    HWND hwndButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"OK",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles 
        10,         // x position 
        10,         // y position 
        100,        // Button width
        30,        // Button height
        hWnd,     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.


    if (!hwndButton)
    {
        MessageBox(NULL,
            _T("Call to CreateButton failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);
    }
}


