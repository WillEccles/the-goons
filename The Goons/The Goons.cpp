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
	// this is a test
    // this is an interesting test you have done
	cout << "Welcome to apeture science" << endl;
	vector<string> options = {"allahu", "akbar", "jihad"};
	int choice = io.options(options);

	cout << "You chose '" << options[choice - 1] << "'" << endl;
	// this is also a comment
	system("pause");
	// I am a comment
    return 0;
}