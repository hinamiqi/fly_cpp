#define UNICODE

#include <iostream>
using namespace std;

#include <tchar.h>
#include <Windows.h>

// wstring sprites[4];
int nFieldWidth = 10;
int nFieldHeight = 10;
unsigned char *pField = nullptr;

int nScreenWidth = 80; // Console screen size X
int nScreenHeight = 25; // Console screen size Y

int nFieldOffsetX = 2; // Offset of game field on the console screen
int nFieldOffsetY = 1;

int nPlayerX = nFieldWidth / 2;
int nPlayerY = nFieldHeight / 2;

int nExitX = nFieldWidth - 2;
int nExitY = nFieldHeight - 2;

int main () {
    // Create screen buffer
    wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
    for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    pField = new unsigned char[nFieldWidth*nFieldHeight];
    for (int x = 0; x < nFieldWidth; x++)
        for (int y = 0; y < nFieldHeight; y++) {
            pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == 0 || y == nFieldHeight - 1) ? 1 : 0;
            if (x == nPlayerX && y == nPlayerY) pField[y*nFieldWidth + x] = 2;
            if (x == nExitX && y == nExitY) pField[y*nFieldWidth + x] = 3;
        }

    // Main loop
    bool bGameOver = false;

    while (!bGameOver) {

        // TIMING =============================

        // INPUT ==============================

        // GAME LOGIC =========================

        // RENDER OUTPUT ======================

        // Draw Field
        for (int x = 0; x < nFieldWidth; x++)
            for (int y = 0; y < nFieldHeight; y++)
                // screen[(y + 2)*nScreeWidth + (x + 2)] = L".#@O"[pField[y*nFieldWidth + x]];
                screen[(y + nFieldOffsetY)*nScreenWidth + (x + nFieldOffsetX)] = L".#@O"[pField[y*nFieldWidth + x]];
                // screen[y*nScreenWidth + x] = L'.';

        // Display Frame
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
    }

    return 0;
}
