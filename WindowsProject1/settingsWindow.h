#pragma once





int CALLBACK handleSettingsWindow(HWND hWnd) {

    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInst,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        MessageBox(
            hWnd,
            (LPCWSTR)L"Settings window creation failed.",
            (LPCWSTR)L"ERROR",
            MB_ICONERROR
        );

        return 0;
    }

    ShowWindow(hwnd, nCmdShowGlobal);




    return 1;
}


/*
void handleSettingsWindow(HWND hWnd) {

    //HINSTANCE hInstance;
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    HWND hSettingsWindow = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        hWnd,       // Parent window
        NULL,       // Menu
        hInst,  // Instance handle
        NULL        // Additional application data
    );

    //SetParent(hSettingsWindow, hWnd);

    if (hSettingsWindow == NULL)
    {
        MessageBox(
            hWnd,
            (LPCWSTR)L"Settings window creation failed.",
            (LPCWSTR)L"ERROR",
            MB_ICONERROR
        );
    }
}

*/

/*(LPCWSTR)L"Settings window creation failed."*/