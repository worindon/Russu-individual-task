#pragma once
#include "AbstractTarget.h"
class HumanFigureTarget : public AbstractTarget{
public:
    HumanFigureTarget(int w, int h) : AbstractTarget(w, h) {
        draw();
    }
    HumanFigureTarget() : AbstractTarget(0 , 0) {
        draw();
    }
    void draw() override {
        int size = 31;

    // Initialize the matrix with spaces
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            target[i][j] = ' ';
        }
    }

    // Head
    int headRadius = 3;
    int headCenterX = size / 2;
    int headCenterY = 5;
    for (int y = -headRadius; y <= headRadius; ++y) {
        for (int x = -headRadius; x <= headRadius; ++x) {
            if (x * x + y * y <= headRadius * headRadius) {
                target[headCenterY + y][headCenterX + x] = '*';
            }
        }
    }

    // Body
    for (int y = headCenterY + headRadius + 1; y <= headCenterY + headRadius + 10; ++y) {
        target[y][headCenterX] = '*';
    }

    // Arms
    for (int x = headCenterX - 5; x <= headCenterX + 5; ++x) {
        target[headCenterY + headRadius + 3][x] = '*';
    }

    // Legs
    int legStartY = headCenterY + headRadius + 11;
    for (int y = legStartY; y < legStartY + 10; ++y) {
        target[y][headCenterX - 2] = '*';
        target[y][headCenterX + 2] = '*';
    }

    // Feet
    for (int x = headCenterX - 3; x <= headCenterX - 1; ++x) {
        target[legStartY + 10][x] = '*';
    }
    for (int x = headCenterX + 1; x <= headCenterX + 3; ++x) {
        target[legStartY + 10][x] = '*';
    }
}

void printMatrix(const char matrix[31][31]) {
    for (int i = 0; i < 31; ++i) {
        for (int j = 0; j < 31; ++j) {
            std::cout << target[i][j];
        }
        std::cout << std::endl;
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