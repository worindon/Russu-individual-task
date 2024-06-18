#include <iostream>
#include <string>
#include "shooting/shooter/Shooter.h"
#include "shooting/target/CircularTarget.h"

#include "../Source/console_source/ConsoleControl.h"
#include "../Source/consoleconfig/setings.h"
#include "../Source/console_source/consolewindow/mainwindow.h"
#include "game/game.h"
#include "interface/interface.h"

#include "interface/OutputClasses/Field.h"

#include "interface/textStats.h"
#include "sounds/sounds.h"

    const int TargetSize = 31;
    const int CharSize = 16;
    const bool sound_on = true;
    const  std::wstring exePath = L"mess.exe";


    const std::string firsmessage("Hi, it`s my individual task");
    const std::string secondmessage("press any key to continue");


    const std::string info("you can use arrows, esc and enter");
    const std::string modeselectmenu("Chose mode");
    const std::string circularmode(" Round target");
    const std::string humanmode(" Target in the form of a human figure");
    const std::string statsmode(" Show stats");

    const int consoleWidth = 800;
    const int consoleHeight = 600;


int main() {
    setlocale(LC_ALL, "ru");
    settings::mySetings(consoleWidth, consoleHeight, CharSize, CharSize);

    std::cout << "\033[?25l";   //делает курсор невидимым


    MainConsoleApp mainApp(exePath);
    console::clearConsoleScreen();
    CircularTarget circ(TargetSize);
    HumanFigureTarget hum(TargetSize, TargetSize);


    field(10, 10, firsmessage.length()).print(firsmessage);
    field(11, 10, info.length()).print(info);
    field(13, 10, secondmessage.length()).print(secondmessage);

    field(20, 20, 25).print("created by Russu Yaroslav");
    cin.get();
    console::clearConsoleScreen();
    field(12, 12, 35).print(" Enter your name");

    console::setCursorAbsolutePosition(13, 13);
    std::string name;
    console::setConsoleTextColor("green");
    cin >> name;
    console::setConsoleTextColor("white");
    console::clearConsoleScreen();
    Shooter shooter(name);



    std::pair<int, int> coord1 = hum.getCenterCoordinates();
    std::pair<int, int> coord2 = circ.getCenterCoordinates();
        while (true) {

            field(12, 10, 35).print(" Chose mode");
            field(13, 10, circularmode.length()).print(circularmode);
            field(14, 10, humanmode.length()).print(humanmode);
            field(15, 10, statsmode.length()).print(statsmode);
            field(16, 10, 10).print(" Exit");



            int mode = console::actionIndicatorForMenu(13, 4, 10);
            std::cout << "\033[?25l";
            console::clearConsoleScreen();
            if (mode == 4) break;
            switch (mode)
            {
            case 1:
                game(TargetSize, sound_on, circ, shooter, mainApp);
                break;
            case 2:
                game(TargetSize, sound_on, hum, shooter, mainApp);
                break;
            case  3:
                printShooterStat(shooter);
                _getch();
                break;
            }
            console::clearConsoleScreen();
        }

    return 0;
}
