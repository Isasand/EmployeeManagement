#include "TerminalInterface.h"
#include "Employee.h"
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

TerminalInterface::TerminalInterface()
{
}


TerminalInterface::~TerminalInterface()
{
}

int TerminalInterface::StartMenu() { 
	int choice;

		system("CLS");
		cout << "WELCOME" << endl << endl;

		cout << "(1) SEARCH EMPLOYEE" << endl;
		cout << "(2) ADD EMPLOYEE" << endl;
		cout << "(3) ALL EMPLOYEES (Present)" << endl;
		cout << "(4) ALL EMPLOYEES (Present & past)" << endl;
		cout << "(5) CLOSE PROGRAM" << endl;

		cin >> choice;
		
	return choice;
}

int TerminalInterface::ProfileMenu() {
	int choice;
	cout << "(1) Update info" << endl;
	cout << "(2) Delete profile" << endl;
	cout << "(3) Update salary and/ or employment" << endl;
	cout << "(4) Calculate salary" << endl;
	cout << "(5) Back to menu" << endl;
	cin >> choice;
	return choice;
}

int TerminalInterface::ModMenu(vector <Employee*> listOfEmployees, int chosenEmployee) {
	int option;
	cout << "(1) Name: " << listOfEmployees.at(chosenEmployee)->getName() << endl;
	cout << "(2) Gender: " << listOfEmployees.at(chosenEmployee)->getGender() << endl;
	cout << "(3) Date of birth: " << listOfEmployees.at(chosenEmployee)->getDateOfBirth() << endl;
	cout << "(4) Designation: " << listOfEmployees.at(chosenEmployee)->getDesignation() << endl;
	cout << "(5) Department: " << listOfEmployees.at(chosenEmployee)->getDepartment() << endl;
	cout << "(6) Date of joining: " << listOfEmployees.at(chosenEmployee)->getDateOfJoining() << endl << endl << endl;

	cout << "-Back to menu (7)-" << endl << endl;
	cin >> option;
	return option;
}