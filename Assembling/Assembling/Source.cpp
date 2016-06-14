#include <iostream>
#include "Add_Sub.h"
#include "Assignment.h"
#include "Perimeter.h"
using namespace std;


int main() {
	bool again = true;
	
	while (again) {
		char menuChoice;
		system("cls");
		cout << "---------- MENU ----------\n";
		cout << "1. Genral notation and commands\n";
		cout << "2. Assigning Values\n";
		cout << "3. Adding and subtracting\n";
		cout << "\t4. Perimeter example\n";
		cout << "0. Exit\n";
		cout << "Enter a choice: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case '0':
			cin.ignore();
			cout << "Enter 0 again to exit: ";
			if (cin.get() == '0') {
				again = false;
			}
			break;
		case '1':
			//genralNotation();
			break;
		case '2':
			assignment();
			break;
		case '3':
			add_sub();
			break;
		case '4':
			perimeter();
			break;
		default:
			cout << "\nChoice not found.\n\n";
			cout << "Press [Enter] to continue...";
			cin.ignore();
			cin.get();
		}
	}
	return 0;
}