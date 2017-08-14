#include <iostream>

using namespace std;

int Menu();

int main() {
	int choice;

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