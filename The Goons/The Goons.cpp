// The Goons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "iomanager.h"
#include <vector>

using namespace std;

iomanager io;

int main()
{
	// 
    // this is the main menu
	cout << "Welcome to The Goons" << endl;
	vector<string> options = {"Play", "Instructions", "About"};
	int choice = io.options(options);

	cout << "You chose '" << options[choice - 1] << "'" << endl;
	system("pause");

    return 0;
}