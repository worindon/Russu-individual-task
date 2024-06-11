#pragma once
#include <iostream>
#include <string.h>
#include <windows.h>


using namespace std;

namespace console {

	void SetConsoleSize(int width, int height);
	void SetConsoleFont(int fontWidth, int fontHeight);
	void SetConsoleBufferSize(int columns, int rows);
	void DisableScrollAndResize();




	void restoreCursorPosition();
	void saveCursorPosition();


	void setCursorAbsolutePosition(int row, int col);
	void setCursorPositionInLine(int col);
	void setCursorPositionShiftUp(int row);
	void setCursorPositionShiftDown(int row);
	void setCursorPositionShiftRight(int offset);
	void setCursorShiftUpOneLine();
	void clearOurAllLine();
	void clearConsoleScreen();
	void setConsoleTextColor(const char color[]);
	void setFoneColor(const char color[]);
	void resetConsoleColor();
	void moveCursorDown();
	void indicator_on(const char sumbol[] = "  ");
	void indicator_off();
}