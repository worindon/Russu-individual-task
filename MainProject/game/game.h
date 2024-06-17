#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <thread>  // Для работы с потоками
#include "../shooting/shooter/Shooter.h"
#include "../shooting/target/CircularTarget.h"

#include "../../Source/console_source/ConsoleControl.h"
#include "../../Source/consoleconfig/setings.h"
#include "../../Source/console_source/consolewindow/mainwindow.h"
#include "../interface/interface.h"

#include "../interface/OutputClasses/Field.h"

#include "../interface/textStats.h"
#include "../sounds/sounds.h"




    void game(int TargetSize, bool sound_on, AbstractTarget& target, Shooter& shooter, MainConsoleApp& mainApp, bool loop = false) {
        console::clearConsoleScreen();
        field pressanykey(13, 15, 25);
        pressanykey.print("press any key to start");
        char ch = _getch();
        console::clearConsoleScreen();
        textStats::outpadShooterStats(5, target.getCenterCoordinates().first * 2 + 5, shooter);

        // Отправка сообщения в консоль для ошибок
        mainApp.sendMessageToErrorConsole("coordinates = " + std::to_string(0) + "  and " + std::to_string(0));
        mainApp.sendMessageToErrorConsole(to_string(shooter.get_shoots()) + " shoots and " + to_string(shooter.get_hits()) + " hits");
        mainApp.sendMessageToErrorConsole(" ");


        console::setCursorAbsolutePosition(0, 0);
        target.print();




        //ch = _getch();

        console::setCursorAbsolutePosition(0, 0);
        target.print();
        std::pair<int, int> lastpos(target.getCenterCoordinates());

        while (true) {
            if (ch == 27) break;
            std::pair<int, int> coordinats = scope(target, lastpos);
            int n = coordinats.first;
            int b = coordinats.second;
            if (n==-1 or b == -1) return;

            
            


            // Воспроизведение звука (если включено)
            if (sound_on) {
                std::thread soundThread(play::playMP3, "2.mp3", 1250);
                soundThread.detach();
            }

            // Выстрел и проверка попадания
            if (textStats::messageHitOrMiss(2, target.getCenterCoordinates().first * 2 + 5, shooter.fire(target, n, b))) {
                if (sound_on) {
                    std::thread soundThread(play::playMP3, "2.mp3", 200);
                    soundThread.detach();
                }
            }

            // Вывод статистики и информации о стрелке
            //textStats::outpadStatistikElement(n, 1, target.getCenterCoordinates().first * 2 + 5);
            //textStats::outpadStatistikElement(b, 1, target.getCenterCoordinates().first * 2 + 8);
            textStats::outpadShooterStats(5, target.getCenterCoordinates().first * 2 + 5, shooter);

            // Отправка сообщения в консоль для ошибок
            mainApp.sendMessageToErrorConsole("coordinates = " + std::to_string(n + 1) + "  and " + std::to_string(b + 1));
            mainApp.sendMessageToErrorConsole(to_string(shooter.get_shoots()) + " shoots and " + to_string(shooter.get_hits()) + " hits");
            mainApp.sendMessageToErrorConsole(" ");


            console::setCursorAbsolutePosition(0, 0);
            target.print();

        }
    }

