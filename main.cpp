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
void search(vector <Employee*> listOfEmployees, int index);
void ModifyProfile(vector <Employee*> listOfEmployees, int index, vector <int> indexPosition);

int main() {
	int choice;
	string ID;
	vector <Employee*>testEmployees;
	int hardCodedIndex = 4;
	//adding database later
	Employee *hardCodedEmp[4];
	hardCodedEmp[0] = new Employee("Markus Svensson", "45Fk2%93", "Male", "1976:05:02", "CEO", "HR", 15000);
	hardCodedEmp[1] = new Employee("Johan Olsson", "42Dks=1A", "Male", "1953:04:22", "MD", "HR", 6400);
	hardCodedEmp[2] = new Employee("Markus Svensson", "Ks01!2lR", "Male", "1983:02:08", "SPV", "PRO", 3200);
	hardCodedEmp[3] = new Employee("Linda Skoge", "k#54uDl?", "Female", "1976:04:05", "GM", "HR", 7000);

	for(int i=0; i <4; i++)
	testEmployees.push_back(hardCodedEmp[i]);

	srand(time(0));

	choice = Menu();
	switch (choice) {
	case 1: {
			search(testEmployees, hardCodedIndex);
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
	cin.get();
	cin.get();
}

int Menu() {
	int choice;

	cout << "-------" << endl;
	cout << "WELCOME" << endl;
	cout << "-------" << endl;
	cout << endl;

	cout << "1. SEARCH EMPLOYEE" << endl;
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

void search(vector <Employee*> listOfEmployees, int index) { 
	string searchWord;
	vector <Employee*> foundEmployees; //vector to store all found employees
	int found = 0; //counter	
	vector <int> indexPosition; //store index from list or database 
	char searchAgain = 'Y'; 
	int choice, mod;

	system("CLS");
	cout << "(1) View profile info" << endl;
	cout << "(2) Update employee profile" << endl;
	cout << "(3) Delete employee profile" << endl;
	cout << "(4) Promote employee" << endl;
	cout << "(5) Calculate salary" << endl;
	cin >> choice;


	while (searchAgain == 'Y' || searchAgain == 'y') {//mby you should be able to search by only first name or surname. later fix 
		cout << "Enter ID, name (forename surname), designation or department: ";
		cin.ignore();
		getline(cin, searchWord);
		for (int i = 0; i < index; i++) {
			if ((listOfEmployees.at(i)->getID()==searchWord) || (listOfEmployees.at(i)->getDesignation()==searchWord) || 
				(listOfEmployees.at(i)->getDepartment()==searchWord) || (listOfEmployees.at(i)->getName() == searchWord)){
				foundEmployees.push_back(listOfEmployees.at(i)); //push back found employees 
				indexPosition.push_back(i);
				found++; 
			}
		}
		
		if (found > 1) {
			cout << found << " employees found: " << endl << endl;
			for (int i = 0; i < found; i++) {
				foundEmployees.at(i)->getInfo();
			}
			if (choice == 2){
				cout << "Choose which profile to modify: ";
				cin >> mod;
				if (mod == 1) {
					ModifyProfile(listOfEmployees, index, indexPosition);
				}
			}
			else if (choice == 3) {
				cout << "Choose profile to delete: ";
			}
			else if (choice == 4) {
				cout << "Choose employee to promote: ";
			}
			else if (choice == 5) {
				cout << "Choose employee for salary calculation: ";
			}
		}

		else if (found == 0) {
			cout << "No employees found.";
		}

		else {
			foundEmployees.at(0)->getInfo();
		}
		cin.clear();
		cout << "Search again (Y/n)?";
		cin >> searchAgain;
	}
}

void ModifyProfile(vector <Employee*> listOfEmployees, int index, vector <int> indexPosition) {

}