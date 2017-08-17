#include "Program.h"
#include "Employee.h"
#include <iostream>
#include <vector>

using namespace std;

Program::Program()
{
}


Program::~Program()
{
}

int Program::StartMenu() { 
	int choice;

	cout << "WELCOME" << endl << endl;

	cout << "(1) SEARCH EMPLOYEE" << endl;
	cout << "(2) ADD EMPLOYEE" << endl;
	cout << "(3) ALL EMPLOYEES (Present)" << endl;
	cout << "(4) ALL EMPLOYEES (Present & past)" << endl;
	cout << "(5) CLOSE PROGRAM" << endl;

	cin >> choice;
	return choice;
}

int Program::ProfileMenu() {
	system("CLS");
	int choice;
	cout << "(1) View profile info" << endl;
	cout << "(2) Update employee info" << endl;
	cout << "(3) Delete employee profile" << endl;
	cout << "(4) Update salary and/or employment" << endl;
	cout << "(5) Calculate salary" << endl;
	cout << "(6) Back to menu" << endl;
	cin >> choice;
	return choice;
}

int Program::ModMenu(vector <Employee*> listOfEmployees, int chosenEmployee) {
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