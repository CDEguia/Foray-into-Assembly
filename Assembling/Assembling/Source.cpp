#include <iostream>
#include "Add_Sub.h"

using namespace std;

int main() {
	bool again = true;
	int menuChoice;
	while (again) {
		system("cls");
		cout << "---------- MENU ----------\n";
		cout << "\t1. Adding and subtracting\n";
		cout << "\t0. Exit\n";
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