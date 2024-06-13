#include <iostream>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>



#include "shooting/shooter/Shooter.h"
#include "shooting/target/CircularTarget.h"

#include "console_source/ConsoleControl.h"
#include "consoleconfig/setings.h"

#include "interface/textStats.h"
#include "sounds/sounds.h"




int main() {
    setlocale(LC_ALL, ("ru"));


    //setings
    settings::mySetings(800, 600, 16, 16);
    string name("Ivan");
    CircularTarget circ(31);
    HumanFigureTarget hum(31, 31);
    char ch;
    cerr << "\033[?25l";  //invisible cursor
    console::setCursorAbsolutePosition(0, 0);
    circ.print();
    ch = _getch();

    int n, b;

    Shooter shooter(name);

    while (true)
    {
        ch = _getch();
        std::thread soundThread(play::playMP3, "sounds/2.mp3", 1250);
        soundThread.detach();
        if (ch == 27) break; 
        n = rand() % 31;
        b = rand() % 31;

        if(textStats::messageHitOrMiss(2, circ.getCenterCoordinates().first * 2+5, shooter.fire(circ, n, b))){
            std::thread soundThread(play::playMP3, "sounds/2.mp3", 1250);
            soundThread.detach();
        }
        textStats::outpadStatistikElement(n, 1, circ.getCenterCoordinates().first * 2 + 5);
        textStats::outpadStatistikElement(b, 1, circ.getCenterCoordinates().first * 2 + 8);
            
        textStats::outpadShooterStats(5, circ.getCenterCoordinates().first * 2 + 5, shooter);

        


        console::setCursorAbsolutePosition(0, 0);
        circ.print();
        
        Sleep(50);
    }
    play::playMP3("sounds/4.mp3", 1500);
    std::cout << "Программа завершена. Нажмите любую клавишу для выхода..." << std::endl;
    std::cin.get();
    return 0;
}
