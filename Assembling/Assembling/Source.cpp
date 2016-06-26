#include <iostream>
#include "Add_Sub.h"
#include "Assignment.h"
#include "Perimeter.h"
#include "CommandsAndMore.h"
#include "Multiply_Divide.h"
#include "MenuOrder.h"
#include "theTriangle.h"
#include "Bitwise.h"
#include "Bianary.h"

using namespace std;


int main() {
	bool again = true;
	
	while (again) {
		char menuChoice;
		system("cls");
		cout << "---------- MENU ----------\n";
		cout << "A. Genral notation and commands\n";
		cout << "B. Assigning Values\n";
		cout << "C. Adding and subtracting\n";
		cout << "D. Perimeter example\n";
		cout << "E. Multiply and Divide\n";
		cout << "F. Menu Ordering\n";
		cout << "G. Triangle(Division)\n";
		cout << "H. Bitwise Opperators\n";
		cout << "I. Binary output\n";
		cout << "J. Binary output using Assembly(\"mostly\")\n";
		cout << "0. Exit\n";
		cout << "Enter a choice: ";
		cin >> menuChoice;

		switch (toupper(menuChoice))
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
		case '8':
			bitwise();
			break;
		case '9':
			binary();
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