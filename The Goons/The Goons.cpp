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
	//this is a test 
	cout << "Welcome to apeture science" << endl;
	vector<string> options = {"allahu", "akbar", "jihad"};
	int choice = io.options(options);

	cout << "You chose '" << options[choice - 1] << "'" << endl;
	system("pause");

    return 0;
}