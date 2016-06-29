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
	bool done = false;
	bool retry;
	while (!done) {
		int menuChoice;
		system("cls");
		cout << "---------- MENU ----------\n";
		cout << "1. Genral notation and commands\n";
		cout << "2. Assigning Values\n";
		cout << "3. Adding and subtracting\n";
		cout << "4. Perimeter example\n";
		cout << "5. Multiply and Divide\n";
		cout << "6. Menu Ordering\n";
		cout << "7. Triangle(Division)\n";
		cout << "8. Bitwise Opperators\n";
		cout << "9. Binary output\n";
		cout << "10. Binary output using Assembly(\"mostly\")\n";
		cout << "11. Making Decisions\n";
		cout << "12. Advanced Menu\n";
		cout << "0. Exit\n";
		cout << "Enter a choice: ";
		do {
			retry = false;
			cout << "\tPlease, make a selection: ";
			if (!(cin >> menuChoice)) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Sorry I didn't recognize that.\n";
				retry = true;
			}
		} while (retry);

		switch (toupper(menuChoice))
		{
		case 0:
			cin.ignore();
			cout << "Enter 0 again to exit: ";
			if (cin.get() == '0') {
				done = true;
			}
			break;
		case 1:
			commandsAndMore();
			break;
		case 2:
			assignment();
			break;
		case 3:
			add_sub();
			break;
		case 4:
			perimeter();
			break;
		case 5:
			multiDiv();
			break;
		case 6:
			Menu();
			break;
		case 7:
			triangle();
			break;
		case 8:
			bitwise();
			break;
		case 9:
			binary();
			break;
		case 10:
			binary_asm();
			break;
		case 11:
			decision();
			break;
		case 12:
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