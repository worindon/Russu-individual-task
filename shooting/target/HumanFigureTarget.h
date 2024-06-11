#pragma once
#include "AbstractTarget.h"
class HumanFigureTarget : public AbstractTarget{
public:
    HumanFigureTarget(int w, int h) : AbstractTarget(w, h) {
        draw();
    }

    void draw() override {
        int headRadius = width / 8;
        int centerX = width / 2;
        int centerY = height / 4;

        // Голова
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (isInCircle(x, y, centerX, centerY, headRadius)) {
                    target[y][x] = '*';
                }
            }
        }

        // Тіло
        for (int y = centerY + headRadius; y < height; ++y) {
            for (int x = centerX - headRadius / 2; x <= centerX + headRadius / 2; ++x) {
                target[y][x] = '*';
            }
        }

        // Руки
        for (int y = centerY + headRadius; y < centerY + headRadius * 2; ++y) {
            for (int x = centerX - headRadius; x <= centerX + headRadius; ++x) {
                target[y][x] = '*';
            }
        }
    }

    std::pair<int, int> getCenterCoordinates() override {
        return {width / 2, height / 4};
    }

private:
    bool isInCircle(int x, int y, int centerX, int centerY, int radius) {
        int dx = x - centerX;
        int dy = y - centerY;
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};