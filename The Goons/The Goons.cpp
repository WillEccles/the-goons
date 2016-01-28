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
	vector<string> options = {"Play", "Instructions", "About", "Quit"};
	int choice = io.options(options);

	switch (choice) {
	case 1:
		break;
	case 2:
		io.titleAndContent("Instructions", "If you havent figured it out already, you type a number that corresponds with your choice and then hit ENTER. ");
		io.wait("\nPress ENTER to return to the main menu.");
		goto show_menu;
		break;
	case 3:
		io.titleAndContent("About 'The Goons'", "'The Goons' is a project that was created by Will Eccles and Jordan Duckstein for no reason other than that we like to have fun.");
		io.wait("Press ENTER to return to the main menu.");
		goto show_menu;
		break;
	case 4:
		return 0;
	}

	io.wait();

    return 0;
}