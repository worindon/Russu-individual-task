#pragma once
#include "AbstractTarget.h"
class CircularTarget : public AbstractTarget {
public:
    CircularTarget(int size) : AbstractTarget(size, size) {
        draw();
    }

    CircularTarget() : AbstractTarget(31, 31) {
        draw();
    }


    void draw() override {
        int centerX = width / 2;
        int centerY = height / 2;
        int radius = width / 2;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
            if (isInCircle(x, y, centerX, centerY, radius)) {
            target[y][x] = '*';
            }
            }
        }
    }

    std::pair<int, int> getCenterCoordinates() override {
        return { width / 2, height / 2 };
    }

private:
    bool isInCircle(int x, int y, int centerX, int centerY, int radius) {
        int dx = x - centerX;
        int dy = y - centerY;
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};