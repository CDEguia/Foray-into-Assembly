#include <iostream>
#include "Add_Sub.h"
#include "Assignment.h"
using namespace std;


int main() {
	bool again = true;
	int menuChoice;
	while (again) {
		system("cls");
		cout << "---------- MENU ----------\n";
		cout << "1. Assigning Values\n";
		cout << "2. Adding and subtracting\n";
		cout << "0. Exit\n";
		cout << "Enter a number: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 0:
			cin.ignore();
			cout << "Enter 0 again to exit: ";
			if (cin.get() == '0') {
				again = false;
			}
			break;
		case 1:
			assignment();
			break;
		case 2:
			add_sub();
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