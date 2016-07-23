#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.5 part II
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//	Simple menu
//----------------------------------------------------------
#include <iomanip>
using namespace std;
short CalcBill(short itemPrice, short numberOfItems) {
	short subtotal;
	//Calculate and store
	_asm {
		mov ax, itemPrice;
		imul numberOfItems;
		mov subtotal, ax;
	}
	return subtotal;
}
void Menu()
{
	system("cls");
//declare constants
	const short DRINK_PRICE = 2;
	const short CHIPS_PRICE = 1;
//declare identifiers
	short BillTotal, number;
//Display menu
	cout << setfill('-') << showpoint << fixed << setprecision(2);
	cout << "\t" << right << setw(22) << " K Store menu " << right << setw(7) << "-" << endl;
	cout << setfill('.');
	cout << left << setw(11) << "\t1. Drink" << right << setw(15) << " $" << (float)DRINK_PRICE << endl;
	cout << left << setw(11) << "\t2. Chips" << right << setw(15) << " $" << (float)CHIPS_PRICE << endl;
//Get and store
	cout << "\t\tHow many drinks? "; cin >> number;
	BillTotal = CalcBill(DRINK_PRICE, number);
	cout << "\t\tHow many chips? "; cin >> number;
	BillTotal += CalcBill(CHIPS_PRICE, number);
// BillTotal =  + (DRINK_PRICE*DriNu) + (CHIPS_PRICE*ChiNu);
	cout << "\t\t\tYour total bill is $" << (float)BillTotal << endl;
	system("pause");
}
/*--------------------Output-----------------------------------------------------
        -------- K Store menu -------
        1. Drink............... $2.00
        2. Chips............... $1.00
                How many drinks? 5
                How many chips? 3
                        Your total bill is $13.00
Press any key to continue . . .
-------------------------------------------------------------------------------*/