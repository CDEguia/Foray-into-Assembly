#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.16 part I
//		Due date	July 18, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//		Calculate total using Floating point numbers
//----------------------------------------------------------
#include <iomanip>
#include <string>
using namespace std;

//declare constants
const float fpWATER_PRICE = 1.25;
const float fpSODA_PRICE = 2.50;
const float fpBEER_PRICE = 3.75;
const float fpTURKEY_PRICE = 4.25;
const float fpROAST_PRICE = 5.50;
const float fpPRIME_PRICE = 6.75;

//declare identifiers
float fpBillTotal = 0, fpHowMany;
char fpKindOfDrink, fpKindOfDinner, fpAns;
short place;
string orderItem, orderItems[6] = { "Soda's","Water's","Beer's", "Turkey", "Roast", "Prime" };

void fpAskKindOfDrink() {
	cout << "\t\tWhat kind of drink would you like (s/w/b)? "; cin >> fpKindOfDrink;
}
void fpMoreDrinks() {
	cout << "\t\tWould any one else like a drink (y/n)? "; cin >> fpAns;
}
void fpMoreDinners() {
	cout << "\t\tWould any one else like a dinner (y/n)? "; cin >> fpAns;
}
void fpAskHowMany() {
	bool again;
	do {
		again = false;
		cout << "\t\tHow many " << orderItems[place] << " would you like? ";
		if (!(cin >> fpHowMany)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Sorry I didn't recognize that.\n";
			again = true;
		}
	} while (again);
}
void fpRepeatOrder() {
	cout << noshowpoint << fixed << setprecision(0);
	cout << "\t" << fpHowMany << " " << orderItems[place] << " coming up...\n";
}
void fpDontHave() {
	cout << "\tSorry we don't have that...\n";
}
void fpAskKindOfDinner() {
	cout << "\t\tWhat kind of dinner(t/r/p)? "; cin >> fpKindOfDinner;
}
void fpdisplayTotal() {
	cout << showpoint << fixed << setprecision(2);
	cout << "\t\t\tTotal Bill = $" << fpBillTotal << endl;
}
void fpmenu() { //Display menu
	system("cls");
	cout << setfill('-') << showpoint << fixed << setprecision(2);
	cout << "\t|" << right << setw(25) << " (K) Store menu " << right << setw(10) << "|" << endl;
	cout << setfill(' ');
	cout << left << setw(15) << "\t| Drinks:" << right << setw(22) << "|" << endl;
	cout << setfill('.');
	cout << left << setw(15) << "\t|\t Water (w)" << right << setw(10) << "$" << fpWATER_PRICE << " |" << endl;
	cout << left << setw(15) << "\t|\t Soda (s)" << right << setw(10) << "$" << fpSODA_PRICE << " |" << endl;
	cout << left << setw(15) << "\t|\t Beer (b)" << right << setw(10) << "$" << fpBEER_PRICE << " |" << endl;
	cout << setfill(' ');
	cout << left << setw(15) << "\t| Dinners: " << right << setw(22) << "|" << endl;
	cout << setfill('.');
	cout << left << setw(15) << "\t|\t Turkey (t)" << right << setw(10) << "$" << fpTURKEY_PRICE << " |" << endl;
	cout << left << setw(15) << "\t|\t Roast Beef (r)" << right << setw(7) << "$" << fpROAST_PRICE << " |" << endl;
	cout << left << setw(15) << "\t|\t Prime Rib (p)" << right << setw(8) << "$" << fpPRIME_PRICE << " |" << endl;
	cout << endl;
}
void fpConfirm() {
	cout << "Are you sure no one wants a " << orderItem << " (y/n)? ";
	cin >> fpAns;
}

void floatingPointMenu()
{
	_asm {
		call fpmenu;
	fpDrinks:;
		call fpAskKindOfDrink; // Get drink type
		cmp fpKindOfDrink, 'a'; // answer is lower or upper case
		jge fpLowerCase;
		//else answer is upper case
			cmp fpKindOfDrink, 'S';
			je fpSodaCost;
			cmp fpKindOfDrink, 'W';
			je fpWaterCost;
			cmp fpKindOfDrink, 'B';
			je fpBeerCost;
			jmp fpNotFound; // if not found

		fpLowerCase:
			cmp fpKindOfDrink, 's';
			je fpSodaCost;
			cmp fpKindOfDrink, 'w';
			je fpWaterCost;
			cmp fpKindOfDrink, 'b';
			je fpBeerCost;
			jmp fpNotFound; // if not found
		
		fpBeerCost:;
			fld fpBEER_PRICE;
			mov place, 2;
			jmp fpGetandCalculate;
		fpWaterCost:;
			fld fpWATER_PRICE;
			mov place, 1;
			jmp fpGetandCalculate;
		fpSodaCost:;
			fld fpSODA_PRICE;
			mov place, 0;
			jmp fpGetandCalculate;
		fpNotFound:;
			call fpDontHave;
			Jmp fpDrinks;
		fpGetandCalculate:
			call fpAskHowMany; // Get number of a drink type
			fld fpHowMany;
			fmul;
			fld fpBillTotal;
			fadd;
			fstp fpBillTotal;
			call fpRepeatOrder;
		fpBottomOfLoop:
			call fpMoreDrinks;
			cmp fpAns, 'Y';
			je fpDrinks;
			cmp fpAns, 'y';
			je fpDrinks;
		done:
			call fpdisplayTotal;
		fpDinners:;
			call fpAskKindOfDinner; // Get drink type
			cmp fpKindOfDinner, 'a'; // answer is lower or upper case
			jge fpLowerCaseDin;
			//else answer is upper case
			cmp fpKindOfDinner, 'P';
			je fpPrimCost;
			cmp fpKindOfDinner, 'R';
			je fpRoastCost;
			cmp fpKindOfDinner, 'T';
			je fpTurkCost;
			jmp fpNotFoundDin; // if not found

		fpLowerCaseDin:
			cmp fpKindOfDinner, 'p';
			je fpPrimCost;
			cmp fpKindOfDinner, 'r';
			je fpRoastCost;
			cmp fpKindOfDinner, 't';
			je fpTurkCost;
			jmp fpNotFoundDin; // if not found

		fpTurkCost:;
			fld fpTURKEY_PRICE;
			mov place, 5;
			jmp fpGetandCalculateDin;
		fpRoastCost:;
			fld fpROAST_PRICE;
			mov place, 4;
			jmp fpGetandCalculateDin;
		fpPrimCost:;
			fld fpPRIME_PRICE;
			mov place, 3;
			jmp fpGetandCalculateDin;
		fpNotFoundDin:;
			call fpDontHave;
			Jmp fpDinners;
		fpGetandCalculateDin:
			call fpAskHowMany; // Get number of a drink type
			fld fpHowMany;
			fmul;
			fld fpBillTotal;
			fadd;
			fstp fpBillTotal;
			call fpRepeatOrder;
		fpBottomOfLoopDin:
			call fpMoreDinners;
			cmp fpAns, 'Y';
			je fpDinners;
			cmp fpAns, 'y';
			je fpDinners;
		fpdone:
			call fpdisplayTotal;
	}

	//terminate program
	system("pause");
}
/*--------------------Output----------------------------------------------------------
        |--------- (K) Store menu ---------|
        | Drinks:                          |
        |        Water (w)...........$1.25 |
        |        Soda (s)............$2.50 |
        |        Beer (b)............$3.75 |
        | Dinners:                         |
        |        Turkey (t)..........$4.25 |
        |        Roast Beef (r)......$5.50 |
        |        Prime Rib (p).......$6.75 |

                What kind of drink would you like (s/w/b)? s
                How many Soda's would you like? 2
        2 Soda's coming up...
                Would any one else like a drink (y/n)? n
                        Total Bill = $5.00
                What kind of dinner(t/r/p)? R
                How many Roast would you like? 2
        2 Roast coming up...
                Would any one else like a dinner (y/n)? n
                        Total Bill = $16.00
Press any key to continue . . .
------------------------------------------------------------------------------------*/