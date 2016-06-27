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
#include "Binary_ASM.h"
#include "Making_Decisions.h"
#include "AdvancedMenu.h"

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
		cout << "K. Making Decisions\n";
		cout << "L. Advanced Menu\n";
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
		case 'A':
			commandsAndMore();
			break;
		case 'B':
			assignment();
			break;
		case 'C':
			add_sub();
			break;
		case 'D':
			perimeter();
			break;
		case 'E':
			multiDiv();
			break;
		case 'F':
			Menu();
			break;
		case 'G':
			triangle();
			break;
		case 'H':
			bitwise();
			break;
		case 'I':
			binary();
			break;
		case 'J':
			binary_asm();
			break;
		case 'K':
			decision();
			break;
		case 'L':
			advancedMenu();
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