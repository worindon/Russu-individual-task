
#include <iostream>
#include <windows.h>
#include "shooting/target/CircularTarget.h"
#include "console_source/ConsoleControl.h"
#include <algorithm>
#include <time.h> 
#include <conio.h>



int main(){

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hConsole, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING; // Устанавливаем флаг для включения поддержки ANSI Escape-кодов
	SetConsoleMode(hConsole, mode);

	console::SetConsoleFont(16, 16);

	// Set console buffer size to a reasonable size (ensure it matches the desired window size)
	console::SetConsoleBufferSize(80, 30);

	// Set console window size to 600x600 pixels
	console::SetConsoleSize(800, 600);
	console::DisableScrollAndResize();
	srand(time(NULL));
	
		CircularTarget circ(31);
	char ch;

	console::setCursorAbsolutePosition(0, 0);
	circ.print();
	ch = _getch();

	int n = 15, b = 15;
	cerr << "\033[?25l";  //invisible cursore
	while (true)
	{
		n = rand() % 31;
		b = rand() % 31;
		console::setCursorAbsolutePosition(0, 0);

		console::setCursorAbsolutePosition(1, circ.getCenterCoordinates().first * 2 + 5);
		console::saveCursorPosition();
		std::cout << "       ";
		console::restoreCursorPosition();
		cout << n+1;
		//std::cin >> n;
		console::setCursorAbsolutePosition(2, circ.getCenterCoordinates().first * 2 + 5);
		console::saveCursorPosition();
		std::cout << "       ";
		console::restoreCursorPosition();
		cout << b+1;
		//std::cin >> b;
		if (circ.shoot(n, b)) {
			console::setCursorAbsolutePosition(3, circ.getCenterCoordinates().first * 2 + 5);
			console::saveCursorPosition();
			std::cout << "       ";
			console::restoreCursorPosition();
			std::cout << "HIT";
		}
		else
		{
			console::setCursorAbsolutePosition(3, circ.getCenterCoordinates().first * 2 + 5);
			console::saveCursorPosition();
			std::cout << "       ";
			console::restoreCursorPosition();
			std::cout << "MISS";
		}
		console::setCursorAbsolutePosition(0, 0);
		circ.print();

		ch = _getch();
	}
}
