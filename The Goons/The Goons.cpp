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
    // this is the main menu
show_menu:
	io.clear();
	cout << "Welcome to The Goons" << endl;
	vector<string> options = {"Play", "Instructions", "About"};
	int choice = io.options(options);

	switch (choice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		io.titleAndContent("About 'The Goons'", "'The Goons' is a project that was created by Will Eccles and Jordan Duckstein for no reason other than that we like to have fun.");
		io.wait();
		goto show_menu;
		break;
	}

	system("pause");

    return 0;
}