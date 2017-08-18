#pragma once
#include "Employee.h"
#include <vector>

using namespace std;

class TerminalInterface
{
public:
	TerminalInterface();
	~TerminalInterface();

	int StartMenu();
	int ProfileMenu();
	int ModMenu(vector <Employee*> listOfEmployees, int chosenEmployee);

};

