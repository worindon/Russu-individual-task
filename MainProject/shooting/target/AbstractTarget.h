#pragma once
#include <vector>
#include <iostream>
#include "../../../Source/console_source/ConsoleControl.h"
class AbstractTarget {
protected:
    int width, height;
    std::vector<std::vector<char>> target;

public:
    AbstractTarget(int w, int h) : width(w), height(h), target(h, std::vector<char>(w, ' ')) {}

    virtual void draw() = 0;

    virtual bool shoot(int x, int y) {
        if (x < 0 or x >= width or y < 0 or y >= height or target[y][x] ==' ') {
            return false;
        }        
            target[y][x] = 'X';
            return true;       
        
    }

    virtual std::pair<int, int> getCenterCoordinates() = 0;

    void print() const {
        for (const auto& row : target) {
            for (const auto& ell : row) {
                if (ell == 'X') console::setFoneColor("red");
                std::cout << ell;
                console::setFoneColor("black");
            }
            std::cout << std::endl;
        }
    }

    char at(int x, int y) const {
        return target[y][x];
    }

    std::pair <int, int> size() const {
        return std::make_pair(width, height);
    }


    void erasetarget() { draw(); }
};