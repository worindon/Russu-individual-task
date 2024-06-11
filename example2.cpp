
#include <iostream>
#include <windows.h>
#include "shooting/target/CircularTarget.h"
#include "console_source/ConsoleControl.h"
#include <algorithm>



int main()
{

	console::SetConsoleFont(16, 16);

	// Set console buffer size to a reasonable size (ensure it matches the desired window size)
	console::SetConsoleBufferSize(80, 30);

	// Set console window size to 600x600 pixels
	console::SetConsoleSize(800, 600);
	console::DisableScrollAndResize();


	CircularTarget circ(31);
	int n = 15, b = 15;
	while (true)
	{
		console::setCursorAbsolutePosition(0, 0);
		circ.print();
		console::setCursorAbsolutePosition(1, circ.getCenterCoordinates().first * 2 + 5);
		console::saveCursorPosition();
		std::cout << "       ";
		console::restoreCursorPosition();
		std::cin >> n;
		console::setCursorAbsolutePosition(2, circ.getCenterCoordinates().first * 2 + 5);
		console::saveCursorPosition();
		std::cout << "       ";
		console::restoreCursorPosition();
		std::cin >> b;
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

	}
}
