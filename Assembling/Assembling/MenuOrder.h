#pragma once
#include <iomanip>

using namespace std;

 //declare constants
 const short DRINK_PRICE = 2;
 const short CHIPS_PRICE = 1;

void Menu()
{
	system("cls");
	//declare identifiers
	short BillTotal;
	short DriNu, ChiNu;
	
		  //Display menu
	
	cout << setfill('-');
	  cout << "\t" << right << setw(22) << " K Store menu " << right << setw(7) << "-" << endl;
	  cout << setfill('.');
	  cout << left << setw(15) << "\t1. Drink" << right << setw(15) << DRINK_PRICE << endl;
	  cout << left << setw(15) << "\t2. Chips" << right << setw(15) << CHIPS_PRICE << endl;
	
		  //Get and store
	  cout << "\t\tHow many drinks? "; cin >> DriNu;
	  cout << "\t\tHow many chips? "; cin >> ChiNu;
	
		  //Calculate and store
	  _asm {
		  mov ax, DRINK_PRICE
		  imul DriNu
		  mov bx, ax
		  mov ax, CHIPS_PRICE
		  imul ChiNu
		  add ax, bx
		  mov BillTotal, ax
	  }
		 // BillTotal =  + (DRINK_PRICE*DriNu) + (CHIPS_PRICE*ChiNu);
	
		  // Display
		  cout << "\t\t\tYour total bill is " << BillTotal << endl;
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