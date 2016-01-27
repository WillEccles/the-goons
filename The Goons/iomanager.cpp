#include "stdafx.h"
#include "iomanager.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <cstdio> // just in case I need to use printf or the like

#include "textcolors.h"

// see 'wait()', this must be fixed because of VS being stupid.
#undef max

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
vector<string> options;
int color;

void setColor(int colorCode) {
	SetConsoleTextAttribute(console, colorCode);
}

// because this is better than using 'system("cls")'
void iomanager::clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	SetConsoleCursorPosition(console, topLeft);
}

void iomanager::wait() {
	setColor(DARKWHITE);
	cout << "Press ENTER to continue...";
	// this is why i had to undef max, because windows defines it in some header file somewhere
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	setColor(WHITE);
}

void iomanager::wait(string message) {
	setColor(DARKWHITE);
	cout << message;
	// this is why i had to undef max, because windows defines it in some header file somewhere
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	setColor(WHITE);
}

/// show the user options and then return which one they choose
int iomanager::options(vector<string> options) {
	int number = 1;

	for (string item : options) {
		setColor(DARKGREY);
		cout << " [ " << number << " - ";
		setColor(WHITE);
		cout << item;
		setColor(DARKGREY);
		cout << " ]" << endl;
		setColor(WHITE);
		number++;
	}

	number--; // if there are three options, it is now 3
			  // this had to be set because at the end of the loop above it gained 1

	string input = "";
	int choice = 239847;

	while (choice > number || choice <= 0) {
		setColor(DARKGREY);
		cout << "> ";
		setColor(GREEN);
		input = "";
		choice = 234234;
		getline(cin, input);
		stringstream(input) >> choice;
	}

	setColor(WHITE);

	return choice;
}

void iomanager::titleAndContent(string title, string content) {
	// title
	clear();
	setColor(DARKWHITE);
	cout << title << endl;
	
	// content
	setColor(WHITE);
	cout << content << endl;
	
}