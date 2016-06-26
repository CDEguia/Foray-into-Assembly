#include <iostream>
#include "Add_Sub.h"
#include "Assignment.h"
#include "Perimeter.h"
#include "CommandsAndMore.h"
#include "Multiply_Divide.h"
#include "MenuOrder.h"
#include "theTriangle.h"


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
		cout << "5. Multiply and Divide\n";
		cout << "6. Menu Ordering\n";
		cout << "7. Triangle(Division)\n";
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
			commandsAndMore();
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
		case '5':
			multiDiv();
			break;
		case '6':
			Menu();
			break;
		case '7':
			triangle();
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