// Hotkey.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>

#define B_KEY (UINT)'B'

int main()
{
    if (RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, B_KEY))
    {
        wprintf(L"Hotkey 'alt+b' registered, using MOD_NOREPEAT flag\n");
    }

    MSG msg;
    int x = 0;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (msg.message == WM_HOTKEY)
        {
            x++;
            wprintf(L"WM_HOTKEY received, %d\n", x);
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
