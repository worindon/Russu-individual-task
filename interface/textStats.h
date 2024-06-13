#pragma once
#include "../console_source/ConsoleControl.h"
#include <iostream>
#include <iomanip>
#include "../shooting/shooter/Shooter.h"
namespace textStats {

    void outpadStatistikElement(int a, int x, int y) {
        console::setCursorAbsolutePosition(x, y);
        console::saveCursorPosition();
        std::cout << "   ";
        console::restoreCursorPosition();
        cout << a + 1;
    }

    void outpadShooterStats(int x, int y, Shooter& shooter) {
        console::setCursorAbsolutePosition(x, y);
        console::saveCursorPosition();
        cout << shooter.get_shoots() << " shoots";
        console::restoreCursorPosition();
        console::setCursorPositionShiftDown(2);
        cout << shooter.get_hits() << " hits";
        console::restoreCursorPosition();
        console::setCursorPositionShiftDown(4);
        console::saveCursorPosition();
        cout << "           ";
        console::restoreCursorPosition();
        cout <<fixed<<setprecision(2)<< shooter.get_fidelity() << " % ";
    }

    bool messageHitOrMiss(int x, int y, bool fl) {
        console::setCursorAbsolutePosition(x, y);
        console::saveCursorPosition();
        std::cout << "    ";
        console::restoreCursorPosition();
        if (fl) {std::cout << "HIT";}
        else {std::cout << "MISS";}
        return fl;
    }
}