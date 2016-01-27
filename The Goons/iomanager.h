#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class iomanager
{
public:
	void clear();
	void wait();
	int options(vector<string> options);
	void titleAndContent(string title, string content);
};

