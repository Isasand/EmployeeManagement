#include "Employee.h"
#include "TerminalInterface.h"
#include <iostream>
#include <String>
#include <time.h>
#include <vector>
#include <Windows.h>

using namespace std;

int RandomNumOrChar();
string IDGenerator();
int Search(vector <Employee*> listOfEmployees, int index);
void ModifyProfile(TerminalInterface *show, vector <Employee*> listOfEmployees, int chosenEmployee);
void ChangeInfo(vector <Employee*> listOfEmployees, int chosenEmployee, int option);


int main() {
	TerminalInterface *show = new TerminalInterface();

	int choice;
	string ID;
	vector <Employee*>testEmployees;
	int hardCodedIndex = 4;
	int count = 0;
	int chosenEmployee, option;
	bool on = true;

	//adding database later
	Employee *hardCodedEmp[4];

	hardCodedEmp[0] = new Employee("Markus Svensson", "Male", "45Fk2%93", "1976:05:02", "VD", "HR", 15000);
	hardCodedEmp[1] = new Employee("Johan Olsson",  "Male", "42Dks=1A", "1953:04:22", "MD", "HR", 6400);
	hardCodedEmp[2] = new Employee("Markus Svensson", "Male", "Ks01!2lR", "1983:02:08", "SPV", "PRO", 3200);
	hardCodedEmp[3] = new Employee("Linda Skoge",  "Female", "k#54uDl?", "1976:04:05", "GM", "HR", 7000);

	for (int i = 0; i < 4; i++)
		testEmployees.push_back(hardCodedEmp[i]);

	srand(time(0));
	while (on) {
		system("CLS");
		choice = show->StartMenu(); //show startmenu
		if (choice == 5) { //5th menu option is closing the program
			on = false;
		}
		switch (choice) {
		case 1: {
			char searchAgain = 'Y';
			while (searchAgain == 'Y' || searchAgain == 'y') {
				chosenEmployee = Search(testEmployees, hardCodedIndex); //returned employee from search-function
				
				system("CLS");
				testEmployees.at(chosenEmployee)->getInfo();//view profile of chosen employee
				option = show->ProfileMenu();//choose what to do with it 

				if (option == 5) { //option 5 is back to startmenu
					break;
				}
				try {
					switch (option) {
					case 1: { //modify
						ModifyProfile(show, testEmployees, chosenEmployee);//modify the profile
						break;
					}
					case 2: { //delete
					
						break;
					}
					case 3: {//update salary/employment
						break;
					}
					case 4: {//calculate salary, TODO make function that takes parameters employment and salary
						break;
					}
					}

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


int Search(vector <Employee*> listOfEmployees, int index/*, int& option*/) {
	string searchWord;
	vector <Employee*> foundEmployees; //vector to store all found employees
	int found = 0; //counter	
	vector <int> indexPosition; //store index from list (database) 
	int choice;
	bool wrongInput = true;

	system("CLS");
	cout << "Enter ID, name (forename surname), designation or department: ";

	cin.ignore();
	getline(cin, searchWord);
	for (int i = 0; i < index; i++) {
		if ((listOfEmployees.at(i)->getID() == searchWord) || (listOfEmployees.at(i)->getDesignation() == searchWord) ||
			(listOfEmployees.at(i)->getDepartment() == searchWord) || (listOfEmployees.at(i)->getName() == searchWord)) { //comparing the employees and the searchword
			foundEmployees.push_back(listOfEmployees.at(i)); //push back found employees 
			indexPosition.push_back(i); //push back index position from list of all employees (later data base)
			found++; //counter for found employees
		}
	}

	if (found > 1) { //if more than one employee is found
		system("CLS"); //clear screen
		cout << found << " employees found: " << endl;

		for (int i = 0; i < found; i++) {
			cout << endl << foundEmployees.at(i)->getName() << "(" << i + 1 << ") "; //print 
		}
		cout << endl << endl << "Choose Employee for preview: ";
		cin >> choice;
		return indexPosition.at(choice - 1); //return chosen employee index
	}

	else if (found == 0) {
		return -1; //if nothing was found
	}

	else { //if just one match is found
		return indexPosition.front(); //send the only element in the index-vector
	}
}

void ModifyProfile(TerminalInterface *show, vector <Employee*> listOfEmployees, int chosenEmployee) {
	int option;

	system("CLS");
	cout << "CHOOSE FIELD TO UPDATE" << endl;
	option = show->ModMenu(listOfEmployees, chosenEmployee);

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
		cin.clear();
		break;
	}
	case 2: {
		cout << "Enter new gender: ";
		cin.ignore(1000, '\n');
		getline(cin, newInfo);
		listOfEmployees.at(chosenEmployee)->setGender(newInfo);
		cin.clear();
		break;
	}
	case 3: {
		cout << "Enter new date of birth: ";
		cin.ignore(1000, '\n');
		getline(cin, newInfo);
		listOfEmployees.at(chosenEmployee)->setDateOfBirth(newInfo);
		cin.clear();
		break;
	}
	case 4: {
		cout << "Enter new designation: ";
		cin.ignore(1000, '\n');
		getline(cin, newInfo);
		listOfEmployees.at(chosenEmployee)->setDesignation(newInfo);
		cin.clear();
		break;
	}
	case 5: {
		cout << "Enter new department: ";
		cin.ignore(1000, '\n');
		getline(cin, newInfo);
		listOfEmployees.at(chosenEmployee)->setDepartment(newInfo);
		cin.clear();
		break;
	}
	case 6: {
		cout << "Enter new date of joining: ";
		cin.ignore(1000, '\n');
		getline(cin, newInfo);
		listOfEmployees.at(chosenEmployee)->setDateOfJoining(newInfo);
		cin.clear();
		break;
	}
	case 7: {
		break;
	}
	}
}