#pragma once
#include "../../../Source/console_source/ConsoleControl.h"
#include <string>


class field
{
public:
	field(int x, int y, int length, bool erase = false);


    void print(const std::string& str) {
        console::saveCursorPosition();
        console::setCursorAbsolutePosition(x, y);

        int strLength = str.length();

        for (int i = 0; i < this->length; ++i) {
            if (i < strLength) {
                std::cout << str[i];
            }
            else {
                std::cout << ' ';
            }
        }
        console::restoreCursorPosition();
    }


    void erase() {
        console::saveCursorPosition();
        console::setCursorAbsolutePosition(x, y);
        for (int i = 0; i < this->length; ++i) {
        std::cout << ' ';       
        }
        console::restoreCursorPosition();
    }

    ~field(){if (_erase) {erase();}}

private:

	int x = 0;
	int y = 0;
	int length;
    bool _erase;
    
};

field::field(int x, int y, int length, bool erase) {
	this->x = x;
	this->y = y;
	this->length = length;
    this->_erase = erase;
}
