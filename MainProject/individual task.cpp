#include <iostream>
#include <windows.h>
#include <string>
#include <thread>  // Для работы с потоками
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


int main() {
    const int TargetSize = 31;
    const int CharSize = 16;
    const bool sound_on = true;
    const  std::wstring exePath = L"mess.exe";
    //setlocale(LC_ALL, "ru");
    std::cout << "\033[?25l";

    /*Field field1(15, 15, 10);
    field1.print("rwewerwrer");
    cout << endl;
    system("pause")*/;


    settings::mySetings(800, 600, CharSize, CharSize);
    MainConsoleApp mainApp(exePath);
    console::clearConsoleScreen();


    CircularTarget circ(TargetSize);
    HumanFigureTarget hum(TargetSize, TargetSize);

    std::string name("Ivan");

    Shooter shooter(name);
    //shooter.fire(circ, 14, 12);
    circ.print();
    std::pair<int, int> coord = circ.getCenterCoordinates();
    game(TargetSize, sound_on, circ, shooter, mainApp);



   // play::playMP3("sounds/4.mp3", 1500);
    std::cin.get();

    return 0;
}
