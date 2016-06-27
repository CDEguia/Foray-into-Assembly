#pragma once
#include <iomanip>

using namespace std;

//declare constants
const short WATER_PRICE = 1;
const short SODA_PRICE = 2;
const short BEER_PRICE = 3;
const short TURKEY_PRICE = 4;
const short ROAST_PRICE = 5;
const short PRIME_PRICE = 6;

//declare identifiers
short BillTotal = 0, i;
short DriNum, DinNum;
char DriKind, DinKind, ans;

void AskDrinks(){
	bool again;
	do {
		again = false;
		cout << "\t\tHow many drinks would you all like? ";
		if (!(cin >> DriNum)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Bad Input, Please re-enter\n";
			again = true;
		}
	} while (again);
}
void AskDrinkKind(){
cout << "\t\tWhat kind of drink(s/w/b)? "; cin >> DriKind;
}
void GiveWater() {
	cout << "\tOne WATER coming up...\n";
}
void GiveBeer() {
	cout << "\tOne BEER coming up...\n";
}
void GiveSoda() {
	cout << "\tOne SODA coming up...\n";
}
void DontHave() {
	cout << "\tSorry we don't have that...\n";
}
void AskDinners() {
	bool again;
	do {
		again = false;
		cout << "\t\tHow many dinners would you all like? ";
		if (!(cin >> DinNum)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Sorry I didn't recognize that.\n";
			again = true;
		}
	} while (again);
}
void AskDinnerKind() {
	cout << "\t\tWhat kind of drink(t/r/p)? "; cin >> DinKind;
}
void displayTotal(){
cout << showpoint << fixed << setprecision(2);
cout << "\t\t\tTotal Bill = $" << (float)BillTotal << endl;
}
void menu() { //Display menu
	system("cls");
	cout << setfill('-') << showpoint << fixed << setprecision(2);
	cout << "\t|" << right << setw(25) << " (K) Store menu " << right << setw(10) << "|" << endl;
	cout << setfill(' ');
	cout << left << setw(15) << "\t| Drinks:" << right << setw(22) << "|" << endl;
	cout << setfill('.');
	cout << left << setw(15) << "\t|\t Water (w)" << right << setw(10) << "$" << (float)WATER_PRICE << " |" << endl;
	cout << left << setw(15) << "\t|\t Soda (s)" << right << setw(10) << "$" << (float)SODA_PRICE << " |" << endl;
	cout << left << setw(15) << "\t|\t Beer (b)" << right << setw(10) << "$" << (float)BEER_PRICE << " |" << endl;
	cout << setfill(' ');
	cout << left << setw(15) << "\t| Dinners: " << right << setw(22) << "|" << endl;
	cout << setfill('.');
	cout << left << setw(15) << "\t|\t Turkey (t)" << right << setw(10) << "$" << (float)TURKEY_PRICE << " |" << endl;
	cout << left << setw(15) << "\t|\t Roast Beef (r)" << right << setw(7) << "$" << (float)ROAST_PRICE << " |" << endl;
	cout << left << setw(15) << "\t|\t Prime Rib (p)" << right << setw(8) << "$" << (float)PRIME_PRICE << " |" << endl;
	cout << endl;
}
void ConDrink() {
	cout << "Are you sure no one wants a drink (y/n)? ";
	cin >> ans;
}

void advancedMenu()
{
	_asm {
		call menu;
	Drinks:;
		call AskDrinks;
		
		cmp DriNum, 0;
			Je ConfirmDrink;
		Jmp GetDrinks;
		
		ConfirmDrink:;
			call ConDrink;
			cmp ans, 'y';
			Jne TestForY;
			Jmp Dinners;
		TestForY:;
			cmp ans, 'Y';
			Jne Drinks;
			Jmp Dinners;
		GetDrinks:;
			mov i, 1;
			forLoop:
				mov cx, DriNum;
				cmp i, cx;
				Jg done;
				
				call AskDrinkKind;
				
				cmp DriKind, 's';
					jne testForSWB;
				//compute soda price
				Jmp SodaCost;

				testForSWB:;
				cmp DriKind, 'S';
				Jne testForWB;
					//compute soda price
					Jmp SodaCost;
					
				testForWB:;
					cmp DriKind, 'w';
					Jne testForW;
					Jmp WaterCost;
					
				testForW:;
					cmp DriKind, 'W';
					Jne testBeer;
					Jmp WaterCost;
					
				testBeer:;
					cmp DriKind, 'b';
					Jne testForB;
					Jmp BeerCost;
				testForB:;
					cmp DriKind, 'B';
					Jne NotFound;
				
				BeerCost:;
					mov dx, BEER_PRICE
					add BillTotal, dx;
					call GiveBeer;
					Jmp BottomOfLoop;
				WaterCost:;
					mov dx, WATER_PRICE;
					add BillTotal, dx;
					call GiveWater;
					Jmp BottomOfLoop;
				SodaCost:;
					mov dx, SODA_PRICE;
					add BillTotal, dx;
					call GiveSoda;
					Jmp BottomOfLoop;
				NotFound:;
					call DontHave;
					Jmp forLoop;

				BottomOfLoop:
					inc i;
					Jmp forLoop;
			done:
				call displayTotal;
		Dinners:;
	}

	//terminate program
	system("pause");
}
/*--------------------Output----------------------------------------------------------
-------- K Store menu -------
1. Drink....................2
2. Chips....................1
How many drinks? 35
How many chips? 2
Your total bill is 72
Press any key to continue . . .
------------------------------------------------------------------------------------*/