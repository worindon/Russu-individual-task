#include <windows.h>
#include <iostream>
#include <conio.h>
#include "console_source/ConsoleControl.h"

void DrawBar(HANDLE hConsole, int x, int y, int length) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    DWORD written;
    FillConsoleOutputCharacter(hConsole, '*', length + 1, pos, &written);
}

void DrawSlider(HANDLE hConsole, int x, int y) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    DWORD written;
    FillConsoleOutputCharacter(hConsole, 'X', 1, pos, &written);
}

int main() {
    console::SetConsoleFont(16, 16);

    // Set console buffer size to a reasonable size (ensure it matches the desired window size)
    console::SetConsoleBufferSize(80, 30);

    // Set console window size to 600x600 pixels
    console::SetConsoleSize(300, 200);
    console::DisableScrollAndResize();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int max_x = csbi.dwMaximumWindowSize.X;
    int max_y = csbi.dwMaximumWindowSize.Y;

    int bar_length = 15;
    int bar_x = 0;//(max_x - bar_length) / 2;
    int bar_y = 0;//max_y / 2;

    int slider_x = bar_x;
    int slider_y = bar_y;

    bool moveRight = true;

    while (true) {
        // Очищаем консоль
        system("cls");

        // Отрисовываем полосу
        DrawBar(hConsole, bar_x, bar_y, bar_length);

        // Отрисовываем ползунок
        DrawSlider(hConsole, slider_x, slider_y);

        // Перемещаем ползунок
        if (moveRight) {
            slider_x++;
            // Если ползунок достигает конца полосы, меняем направление движения
            if (slider_x >= bar_x + bar_length)
                moveRight = false;
        }
        else {
            slider_x--;
            // Если ползунок достигает начала полосы, меняем направление движения
            if (slider_x <= bar_x)
                moveRight = true;
        }

        // Задержка перед следующим обновлением
        Sleep(100);

        // Если нажата клавиша Enter, выходим из цикла
        if (_kbhit()) {
            int ch = _getch();
            if (ch == 13) // Enter key
                break;
        }
    }

    return 0;
}
