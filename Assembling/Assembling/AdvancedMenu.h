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
short NumberOfDrinks, NumberOfDinners;
char KindOfDrink, KindOfDinner, ans;

void AskForDrinks(){
	bool again;
	do {
		again = false;
		cout << "\t\tHow many drinks would you all like? ";
		if (!(cin >> NumberOfDrinks)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Sorry I didn't recognize that.\n";
			again = true;
		}
	} while (again);
}
void AskKindOfDrink(){
cout << "\t\tWhat kind of drink(s/w/b)? "; cin >> KindOfDrink;
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
void GiveTurkey() {
	cout << "\tOne TURKEY DINNER coming up...\n";
}
void GiveRoast() {
	cout << "\tOne ROAST BEEF DINNER coming up...\n";
}
void GivePrime() {
	cout << "\tOne PRIME RIB DINNER coming up...\n";
}
void DontHave() {
	cout << "\tSorry we don't have that...\n";
}
void AskNumberOfDinners() {
	bool again;
	do {
		again = false;
		cout << "\t\tHow many dinners would you all like? ";
		if (!(cin >> NumberOfDinners)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Sorry I didn't recognize that.\n";
			again = true;
		}
	} while (again);
}
void AskKindOfDinner() {
	cout << "\t\tWhat kind of dinner(t/r/p)? "; cin >> KindOfDinner;
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
void ConDinner() {
	cout << "Are you sure no one wants dinner (y/n)? ";
	cin >> ans;
}

void advancedMenu()
{
	_asm {
		call menu;
	Drinks:;
		call AskForDrinks;
		
		cmp NumberOfDrinks, 0;
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
				mov cx, NumberOfDrinks;
				cmp i, cx;
				Jg done;
				
				call AskKindOfDrink;
				
				cmp KindOfDrink, 's';
					jne testForSWB;
				//compute soda price
				Jmp SodaCost;

				testForSWB:;
				cmp KindOfDrink, 'S';
				Jne testForWB;
					//compute soda price
					Jmp SodaCost;
					
				testForWB:;
					cmp KindOfDrink, 'w';
					Jne testForW;
					Jmp WaterCost;
					
				testForW:;
					cmp KindOfDrink, 'W';
					Jne testBeer;
					Jmp WaterCost;
					
				testBeer:;
					cmp KindOfDrink, 'b';
					Jne testForB;
					Jmp BeerCost;
				testForB:;
					cmp KindOfDrink, 'B';
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
				call AskNumberOfDinners;

				cmp NumberOfDinners, 0;
				Je ConfirmDinner;
				Jmp GetDinners;

			ConfirmDinner:;
				call ConDinner;
				cmp ans, 'y';
				Jne TestForYD;
				Jmp Total;
			TestForYD:;
				cmp ans, 'Y';
				Jne Dinners;
				Jmp Total;
			GetDinners:;
				mov i, 1;
				forLoopD:
					mov cx, NumberOfDinners;
					cmp i, cx;
					Jg Total;

					call AskKindOfDinner;

					cmp KindOfDinner, 't';
					jne testForTRP;
					//compute soda price
					Jmp TurkeyCost;

					testForTRP:;
						cmp KindOfDinner, 'T';
						Jne testForRP;
						//compute soda price
						Jmp TurkeyCost;

					testForRP:;
						cmp KindOfDinner, 'r';
						Jne testForR;
						Jmp RoastCost;

					testForR:;
						cmp KindOfDinner, 'R';
						Jne testPrime;
						Jmp RoastCost;

					testPrime:;
						cmp KindOfDinner, 'p';
						Jne testForP;
						Jmp PrimeCost;
					testForP:;
						cmp KindOfDinner, 'P';
						Jne NotFoundD;

					PrimeCost:;
						mov dx, PRIME_PRICE
						add BillTotal, dx;
						call GivePrime;
						Jmp BottomOfLoopD;
					RoastCost:;
						mov dx, ROAST_PRICE;
						add BillTotal, dx;
						call GiveRoast;
						Jmp BottomOfLoopD;
					TurkeyCost:;
						mov dx, TURKEY_PRICE;
						add BillTotal, dx;
						call GiveTurkey;
						Jmp BottomOfLoopD;
					NotFoundD:;
						call DontHave;
						Jmp forLoopD;

					BottomOfLoopD:
						inc i;
						Jmp forLoopD;
		Total:
			call displayTotal;
	}

	//terminate program
	system("pause");
}
/*--------------------Output----------------------------------------------------------

------------------------------------------------------------------------------------*/