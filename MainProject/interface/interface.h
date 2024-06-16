#pragma once
#include "../../Source/console_source/ConsoleControl.h"
#include <iostream>
#include "../shooting/target/AbstractTarget.h"
#include <conio.h>

#include <iostream>
#include <conio.h>







void swap_black_to_green(char ch) {
    console::saveCursorPosition();
    console::setFoneColor("green");
    std::cout << ch;
    console::restoreCursorPosition();
    console::setFoneColor("black");
}

void swap_green_to_black(char ch) {
    if (ch == 'X') {
        console::saveCursorPosition();
        console::setFoneColor("red");
        std::cout << ch;
        console::restoreCursorPosition();
        console::setFoneColor("green");
    }
    else {
        console::saveCursorPosition();
        console::setFoneColor("black");
        std::cout << ch;
        console::restoreCursorPosition();
        console::setFoneColor("green");
    }
}



const int Arrow_Up = 72;
const int Arrow_Down = 80;
const int Arrow_Left = 75;
const int Arrow_Right = 77;
const int Escape_but = 27;
const int Enter = 13;




std::pair<int, int> scope(const AbstractTarget& targ, const std::pair<int, int>& startpos) {
    std::pair<int, int> size = targ.size();

    int x = startpos.first; int y = startpos.second;


    console::setCursorAbsolutePosition(size.first / 2 + 1, size.second / 2 + 1);
    swap_black_to_green(targ.at(startpos.first, startpos.second));
    while (true) {
        char ch = _getch();

        if (ch == 0 || ch == -32) {
            ch = _getch(); // ѕолучаем второй байт специальной клавиши

            switch (ch) {
            case 72:
                if (y > 0) {
                    swap_green_to_black(targ.at(x, y));
                    console::setCursorPositionShiftUp(1);
                    swap_black_to_green(targ.at(x, --y));
                }
                break;
            case 80:
                if (y < size.second - 1) {
                    swap_green_to_black(targ.at(x, y));
                    console::setCursorPositionShiftDown(1);
                    swap_black_to_green(targ.at(x, ++y));
                }
                break;
            case 75:
                if (x > 0) {
                    swap_green_to_black(targ.at(x, y));
                    console::setCursorPositionShiftLeft(1);
                    swap_black_to_green(targ.at(--x, y));
                    
                }
                break;
            case 77:
                if (x < size.first - 1) {
                    swap_green_to_black(targ.at(x, y));
                    console::setCursorPositionShiftRight(1);
                    swap_black_to_green(targ.at(++x, y));
                }
                break;
            }
            Sleep(50);
        }
        else {
            // ѕроверка нажати€ обычных клавиш
            switch (ch) {
            case 27: 
                return { -1, -1 };
            case 13:
                return { x ,y };
            }
        }
       

    }
    return startpos;
}



