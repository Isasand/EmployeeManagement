#include <iostream>
#include <String>

using namespace std;

int Menu();
int RandomNumOrChar();
string IDGenerator();

int main() {
	int choice;
	string ID = " ";

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
	cout << "3. ALL EMPLOYEES (PRESENT)" << endl;
	cout << "4. ALL EMPLOYEES (PRESENT & PAST)" << endl;
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

	for (int i = 0; i < 9; i++) {
		ID += RandomNumOrChar();
	}
	cout << ID;
	return ID;
}