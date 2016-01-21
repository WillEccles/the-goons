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
	cout << "HERRO pls pick an optionnnnn" << endl;
	vector<string> options = {"Hello", "World", "Hi"};
	int choice = io.options(options);

	cout << "You chose '" << options[choice - 1] << "'" << endl;
	system("pause");

    return 0;
}