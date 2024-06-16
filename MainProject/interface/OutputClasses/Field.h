#pragma once
#include "../../../Source/console_source/ConsoleControl.h"
#include <string>


class Field
{
public:
	Field(int x, int y, int lenth);


	void print(const std::string& str) {
		console::setCursorAbsolutePosition(x, y);
		for (int i = 0; i < lenth; ++i) { cout << ' '; }

		int strlenth = str.length();
		for (int i = 0; i < strlenth || i < lenth; ++i) {
			cout << str[i];
		}
	}

	~Field();

private:

	int x = 0;
	int y = 0;
	int lenth;
	std::string str;



};

Field::Field(int x, int y, int lenth) {
	this->x = x;
	this->y = y;
	this->lenth = lenth;
}
Field::~Field()
{
}