#pragma once
#include <windows.h>
#include <iostream>
#include <thread>
#include <conio.h>
#include <cstdlib>
#include <ctime>

#pragma comment(lib, "winmm.lib")

namespace play {
    void playMP3(const std::string& filePath, int durationMs) {
        std::string command = "open \"" + filePath + "\" type mpegvideo alias mp3";
        if (mciSendStringA(command.c_str(), NULL, 0, NULL) != 0) {
         //   std::cerr << "Не удалось открыть файл: " << filePath << std::endl;
            return;
        }
        if (mciSendStringA("play mp3", NULL, 0, NULL) != 0) {
    //        std::cerr << "Не удалось воспроизвести файл: " << filePath << std::endl;
            mciSendStringA("close mp3", NULL, 0, NULL);
            return;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(durationMs));
        mciSendStringA("stop mp3", NULL, 0, NULL);
        mciSendStringA("close mp3", NULL, 0, NULL);
    }
}
