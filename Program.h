#pragma once
#include "Employee.h"
#include <vector>

using namespace std;

class Program
{
public:
	Program();
	~Program();

	int StartMenu();
	int ProfileMenu();
	int ModMenu(vector <Employee*> listOfEmployees, int chosenEmployee);

};

