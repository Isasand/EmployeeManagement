#include "Employee.h"
#include <iostream>
#include <String>
#include <time.h>
#include <vector>

using namespace std;

int Menu();
int RandomNumOrChar();
string IDGenerator();

int main() {
	int choice;
	string ID;
	//adding database later
	vector <Employee*>testEmployees;

	Employee *hardCodedEmp[4];
	hardCodedEmp[0] = new Employee("Markus Svensson", "45Fk2%93", "Male", "1976:05:02", "CEO", "HR", 15000);
	hardCodedEmp[1] = new Employee("Johan Olsson", "42Dks=1A", "Male", "1953:04:22", "MD", "HR", 6400);
	hardCodedEmp[2] = new Employee("Karl Magnusson", "Ks01!2lR", "Male", "1983:02:08", "SPV", "PRO", 3200);
	hardCodedEmp[3] = new Employee("Linda Skoge", "k#54uDl?", "Female", "1976:04:05", "GM", "HR", 7000);

	for(int i=0; i <4; i++)
	testEmployees.push_back(hardCodedEmp[i]);

	srand(time(0));

	choice = Menu();
	switch (choice) {
	case 1: {

		break;
	}
	case 2: {

		break;
	}
	case 3: {

		break;
	}
	case 4: {


		break;
	}
	case 5: {

		break;
	}

	default: {
		cout << "Enter a valid option";
			break;
	}
	}
}

int Menu() {
	int choice;

	cout << "-------" << endl;
	cout << "WELCOME" << endl;
	cout << "-------" << endl;
	cout << endl;

	cout << "1. SEARCH EMPLOYEE (By name, ID or designation)" << endl;
	cout << "2. ADD EMPLOYEE" << endl;
	cout << "3. ALL EMPLOYEES (Present)" << endl;
	cout << "4. ALL EMPLOYEES (Present & past)" << endl;
	cout << "5. CLOSE PROGRAM" << endl;

	cin >> choice;
	return choice;
}

int RandomNumOrChar() {
	static const char alphanum[] =
		"0123456789"
		"!@#$%^&*"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	int Length = sizeof(alphanum) - 1;

	return alphanum[rand() % Length];
}

string IDGenerator() {
	string ID;

	for (int i = 0; i < 8; i++) {
		ID += RandomNumOrChar();
	}
	return ID;
}