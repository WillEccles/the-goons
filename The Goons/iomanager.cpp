#include "stdafx.h"
#include "iomanager.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "textcolors.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
vector<string> options;
int color;

void setColor(int colorCode) {
	SetConsoleTextAttribute(console, colorCode);
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