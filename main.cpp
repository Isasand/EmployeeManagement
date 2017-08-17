#include "Employee.h"
#include "Program.h"
#include <iostream>
#include <String>
#include <time.h>
#include <vector>
#include <Windows.h>

using namespace std;

void AddEmployeeInfo(vector <Employee*> listOfEmployees, string argDesignation, string argDepartment, int argSalary, int &count);
int RandomNumOrChar();
string IDGenerator();
int Search(Program *program, vector <Employee*> listOfEmployees, int index, int& option);
void ModifyProfile(Program *program, vector <Employee*> listOfEmployees, int chosenEmployee);
void Change(string infoToChange, vector <Employee*> listOfEmployees, int chosenEmployee);
void ChangeInfo(vector <Employee*> listOfEmployees, int chosenEmployee, int option);

int main() {
	Program *program = new Program();

	int choice;
	string ID;
	vector <Employee*>testEmployees;
	int hardCodedIndex = 4;
	int count = 0;
	int chosenEmployee, option;
	bool on = true;

	//adding database later
	Employee *hardCodedEmp[4];

	hardCodedEmp[0] = new Employee("Markus Svensson", "45Fk2%93", "Male", "1976:05:02");
	hardCodedEmp[1] = new Employee("Johan Olsson", "42Dks=1A", "Male", "1953:04:22");
	hardCodedEmp[2] = new Employee("Markus Svensson", "Ks01!2lR", "Male", "1983:02:08");
	hardCodedEmp[3] = new Employee("Linda Skoge", "k#54uDl?", "Female", "1976:04:05");


	for (int i = 0; i < 4; i++)
		testEmployees.push_back(hardCodedEmp[i]);

	AddEmployeeInfo(testEmployees, "VD", "HR", 15000, count);
	AddEmployeeInfo(testEmployees, "MD", "HR", 6400, count);
	AddEmployeeInfo(testEmployees, "SPV", "PRO", 3200, count);
	AddEmployeeInfo(testEmployees, "GM", "HR", 7000, count);

	srand(time(0));
	while(on) {
		system("CLS");
		choice = program->StartMenu();
		if (choice == 5) { //5th menu option is closing the program
			on = false;
		}
		switch (choice) {
		case 1: {
			char searchAgain = 'Y';
			while (searchAgain == 'Y' || searchAgain == 'y') {
				chosenEmployee = Search(program, testEmployees, hardCodedIndex, option); //returned employee from search-function
				//option is passed as a referense to know what to do with the returned object
				if (chosenEmployee == -2) { //back to menu option in searchfunction
					break;
				}

				try {
					if (option == 1) {//option 1 = view profile
						int ans;
						system("CLS");
						cout << "Back to menu (1)" << endl;
						cout << "Modify Profile (2)" << endl<< endl;
						testEmployees.at(chosenEmployee)->getInfo(); //view employee profile
						cin >> ans;
						if (ans == 2) {
							ModifyProfile(program, testEmployees, chosenEmployee);//modify the profile
						}
						else {
							break; //or go back to menu
						}

					}
					if (option == 2) {
						ModifyProfile(program, testEmployees, chosenEmployee); //option 2 = modify profile
					}
					if (option == 3) { //option 3 = delete profile

					}
					if (option == 4) { // change salary or employment

					}

					cout << testEmployees.at(chosenEmployee)->getName() << "<- returned from function" << endl;//testing
					cout << endl << option << " <- option chosen" << endl;
				}
				catch (...) { //if function returns -1 
					system("CLS");
					cout << "No employees found." << endl;
				}
				cin.clear();
				cout << "Search again (Y/n)?";
				cin >> searchAgain;
			}
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

		}
	}
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



int Search(Program *program, vector <Employee*> listOfEmployees, int index, int& option) {
	string searchWord;
	vector <Employee*> foundEmployees; //vector to store all found employees
	int found = 0; //counter	
	vector <int> indexPosition; //store index from list (database) 
	int choice;

	option = program->ProfileMenu(); //get option from user
	if (option == 6) {
		return -2;
	}
	//mby you should be able to search by only first name or surname. later fix 
	system("CLS");
	cout << "Enter ID, name (forename surname), designation or department: ";
	cin.ignore();
	getline(cin, searchWord);
	
	for (int i = 0; i < index; i++) {
		if ((listOfEmployees.at(i)->getID() == searchWord) || (listOfEmployees.at(i)->getDesignation() == searchWord) ||
				(listOfEmployees.at(i)->getDepartment() == searchWord) || (listOfEmployees.at(i)->getName() == searchWord)) {
			foundEmployees.push_back(listOfEmployees.at(i)); //push back found employees 
			indexPosition.push_back(i);
			found++;
		}
	}

	if (found > 1) {
		cout << found << " employees found: " << endl << endl;

		switch (option) {
		case 1: {
			cout << "Choose which profile to preview";
			break;
		}
		case 2: {
			cout << "Choose which profile to modify";
			break;
		}
		case 3: {
			cout << "Choose which profile to delete";
			break;
		}
		case 4: {
			cout << "Choose an employee to change salary/ employment";
			break;
		}
		case 5: {
			cout << "Choose employee for salary calculation";
			break;
		}
		}

		for (int i = 0; i < found; i++) {
			cout << endl << foundEmployees.at(i)->getName() << "(" << i + 1 << ") "; //print 
		}
		cin >> choice;
		return indexPosition.at(choice - 1); //return chosen employee
	}

	else if (found == 0) {
		return -1; //if nothing was found
	}

	else { //if just one match is found
		return indexPosition.front(); //send the only element in the index-vector
	}
}

void ModifyProfile(Program *program, vector <Employee*> listOfEmployees, int chosenEmployee) {
	int option;

	system("CLS");
	cout << "CHOOSE FIELD TO UPDATE" << endl;
	option = program->ModMenu(listOfEmployees, chosenEmployee);
	
	ChangeInfo(listOfEmployees, chosenEmployee, option);

}

void Change(string infoToChange, vector <Employee*> listOfEmployees, int chosenEmployee) {
	string info;
	
	cout << "Enter new " << infoToChange << ": ";
	cin.ignore(1000, '\n');
	getline(cin, info);
	listOfEmployees.at(chosenEmployee)->setName(info);
}

void ChangeInfo(vector <Employee*> listOfEmployees, int chosenEmployee, int option) {
	string newInfo;

	switch (option) {
	case 1: {
		Change("name", listOfEmployees, chosenEmployee);
		break;
	}
	case 2: {
		Change("gender", listOfEmployees, chosenEmployee);
		break;
	}
	case 3: {
		Change("date of birth [YYYY-MM-DD]", listOfEmployees, chosenEmployee);
		break;
	}
	case 4: {
		Change("designation", listOfEmployees, chosenEmployee);
		break;
	}
	case 5: {
		Change("department", listOfEmployees, chosenEmployee);
		break;
	}
	case 6: {
		Change("date of joining [YYYY-MM-DD]", listOfEmployees, chosenEmployee);
		break;
	}
	case 7: {
		break;
	}
	}
}

void AddEmployeeInfo(vector <Employee*> listOfEmployees, string argDesignation, string argDepartment, int argSalary, int &count) {
	listOfEmployees.at(count)->setDesignation(argDesignation);
	listOfEmployees.at(count)->setDepartment(argDepartment);
	listOfEmployees.at(count)->setSalary(argSalary);
	count++;
}