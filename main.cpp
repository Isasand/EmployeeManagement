#include "Employee.h"
#include <iostream>
#include <String>
#include <time.h>
#include <vector>
#include <Windows.h>

using namespace std;

int Menu();
int RandomNumOrChar();
string IDGenerator();
int ProfileMenu();
int Search(vector <Employee*> listOfEmployees, int index, int& option);
int ModMenu(vector <Employee*> listOfEmployees, int chosenEmployee);
void ModifyProfile(vector <Employee*> listOfEmployees, int chosenEmployee);
void ChangeInfo(vector <Employee*> listOfEmployees, int chosenEmployee, int option);

int main() {
	int choice;
	string ID;
	vector <Employee*>testEmployees;
	int hardCodedIndex = 4;
	int chosenEmployee, option;
	bool on = true;

	//adding database later
	Employee *hardCodedEmp[4];
	hardCodedEmp[0] = new Employee("Markus Svensson", "45Fk2%93", "Male", "1976:05:02", "CEO", "HR", 15000);
	hardCodedEmp[1] = new Employee("Johan Olsson", "42Dks=1A", "Male", "1953:04:22", "MD", "HR", 6400);
	hardCodedEmp[2] = new Employee("Markus Svensson", "Ks01!2lR", "Male", "1983:02:08", "SPV", "PRO", 3200);
	hardCodedEmp[3] = new Employee("Linda Skoge", "k#54uDl?", "Female", "1976:04:05", "GM", "HR", 7000);

	for (int i = 0; i < 4; i++)
		testEmployees.push_back(hardCodedEmp[i]);

	srand(time(0));
	while(on) {
		system("CLS");
		choice = Menu();
		if (choice == 5) { //5th menu option is closing the program
			on = false;
		}
		switch (choice) {
		case 1: {
			char searchAgain = 'Y';
			while (searchAgain == 'Y' || searchAgain == 'y') {
				chosenEmployee = Search(testEmployees, hardCodedIndex, option); //returned employee from search-function
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
							ModifyProfile(testEmployees, chosenEmployee);//modify the profile
						}
						else {
							break; //or go back to menu
						}

					}
					if (option == 2) {
						ModifyProfile(testEmployees, chosenEmployee); //option 2 = modify profile
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

int Menu() {
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

int ProfileMenu() {
	system("CLS");
	int choice;
	cout << "(1) View profile info" << endl;
	cout << "(2) Update employee info" << endl;
	cout << "(3) Delete employee profile" << endl;
	cout << "(4) Update salary and/or employment"<< endl;
	cout << "(5) Calculate salary" << endl;
	cout << "(6) Back to menu" << endl;
	cin >> choice;
	return choice;
}


int Search(vector <Employee*> listOfEmployees, int index, int& option) {
	string searchWord;
	vector <Employee*> foundEmployees; //vector to store all found employees
	int found = 0; //counter	
	vector <int> indexPosition; //store index from list (database) 
	int choice;

	option = ProfileMenu(); //get option from user
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

int ModMenu(vector <Employee*> listOfEmployees, int chosenEmployee) {
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
void ModifyProfile(vector <Employee*> listOfEmployees, int chosenEmployee) {
	int option;

	system("CLS");
	cout << "CHOOSE FIELD TO UPDATE" << endl;
	option = ModMenu(listOfEmployees, chosenEmployee);
	
	ChangeInfo(listOfEmployees, chosenEmployee, option);

}


void ChangeInfo(vector <Employee*> listOfEmployees, int chosenEmployee, int option) {
	string newInfo;

	switch (option) {
	case 1: {
		cout << "Enter new name: ";
		cin.ignore(1000, '\n');
		getline(cin, newInfo);
		listOfEmployees.at(chosenEmployee)->setName(newInfo);
		break;
	}
	case 2: {
		cout << "Enter new gender: ";
		getline(cin, newInfo);
		cin.ignore(1000, '\n');
		listOfEmployees.at(chosenEmployee)->setGender(newInfo);
		break;
	}
	case 3: {
		cout << "Enter new date of birth [YYYY-MM-DD]: "; 
		getline(cin, newInfo);
		cin.ignore(1000, '\n');
		listOfEmployees.at(chosenEmployee)->setDateOfBirth(newInfo);
		break;
	}
	case 4: {
		cout << "Enter new designation: ";
		getline(cin, newInfo);
		cin.ignore(1000, '\n');
		listOfEmployees.at(chosenEmployee)->setDesignation(newInfo);
		break;
	}
	case 5: {
		cout << "Enter new department: ";
		getline(cin, newInfo);
		cin.ignore(1000, '\n');
		listOfEmployees.at(chosenEmployee)->setDepartment(newInfo);
		break;
	}
	case 6: {
		cout << "Enter new date of joining [YYYY-MM-DD]: ";
		getline(cin, newInfo);
		cin.ignore(1000, '\n');
		listOfEmployees.at(chosenEmployee)->setDateOfJoining(newInfo);
		break;
	}
	case 7: {
		break;
	}
	}
}