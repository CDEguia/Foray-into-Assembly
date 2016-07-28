#pragma once
//-------------------------------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.9 part II
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//		Multi Dimentional Array, add subtract and get numbers
//-------------------------------------------------------------------------------
#include <string>
using namespace std;
int temp, I, total=0, mainChoice, howMany, shirtStock[3][4][5];
													//	3 colors 4 sizes 5 types
char UserChoice;

void ShopMenu() {
	system("cls");
	cout << "--------------- Shirt Shop -----------------\n";
	cout << "\t1. Update Inventory\n";
	cout << "\t2. Total Items in Inventory\n";
	cout << "\t3. Pick a cloth type to list\n";
	cout << "\t4. Pick a color to list\n";
	cout << "\t5. Pick a size to list\n";
	cout << "\t0. Exit\n";
	cout << "Enter a number: ";
	cin >> mainChoice;
}
void clothMenu() {
	system("cls");
	cout << "--------------- Cloth Menu -----------------\n";
}
void colorMenu() {
	system("cls");
	cout << "--------------- Color Menu -----------------\n";
}
void sizeMenu() {
	system("cls");
	cout << "--------------- Size Menu -----------------\n";
}
void updateMenu() {
	system("cls");
	cout << "--------------- Update Inventory -----------------\n";
}
void cloth() {
	cout << "\tC. Cotton\n";
	cout << "\tP. Polyester\n";
	cout << "\tB. Cotton Poly Blend\n";
	cout << "\tN. Nylon\n";
	cout << "\tO. Full Blend\n";
	cout << "\tE. Return to Main Menu\n";
}
void color() {
	cout << "\tR. Red\n";
	cout << "\tG. Green\n";
	cout << "\tB. Blue\n";
	cout << "\tE. Return to Main Menu\n";
}
void sizeGet() {
	cout << "\tS. Small\n";
	cout << "\tM. Medium\n";
	cout << "\tL. Large\n";
	cout << "\tX. Extra Large\n";
	cout << "\tE. Return to Main Menu\n";
}
void getInput() { 
	cout << "Enter a letter: ";
	cin >> UserChoice; 
}
void HowMany() {
	cout << "Enter a number (-### to subtract): ";
	cin >> howMany;
}
void DisplayTotal() {
	cout << "There are " << total << " shirts in stock.\n";
	system("pause");
}
void DisplayIndividualTotal() {
	cout << "There are " << total << " " << UserChoice << " shirts in stock.\n";
	system("pause");
}
void multidimarray() {
	_asm {
		;//--vvvv-- fill the multi dim array --vvvv-- 
		mov ebx, 0;
		mov I, 0;
	fillArray:
		cmp I, 60;
		Je MainLoop;
		mov [shirtStock + ebx], 1;
		inc I;
		add ebx, 4;
		Jmp fillArray;
		;
		;//--vvvv-- Menu display and logic --vvvv-- 
		;
	MainLoop: 
		call ShopMenu; //display the main menu
		cmp mainChoice, 0;
		je End;
		cmp mainChoice, 1; //compare user input
		je InventoryUpdate; //jump to if equal
		cmp mainChoice, 2;
		je ListAll;
		cmp mainChoice, 3;
		je PickCloth;
		cmp mainChoice, 4;
		je PickColor;
		cmp mainChoice, 5;
		je PickSize;
		jmp MainLoop; // Display menu again if user input dosent match
	;
	;//--vvvv-- Inventory Update logic --vvvv--
	;
		InventoryUpdate: 
			call updateMenu; // Header
	;//--vvvv-- Get cloth input --vvvv--
		IUClothChoice:
				call cloth; // Cloth choice menu
				call getInput;
				cmp UserChoice, 'a'; // Decide weather user input
				jge IULowerCaseCloth; // is upper or lower case.
				cmp UserChoice, 'C';
				je IUComputeCotten;
				cmp UserChoice, 'P';
				je IUComputePolly;
				cmp UserChoice, 'B';
				je IUComputeCP;
				cmp UserChoice, 'N';
				je IUComputeNylon;
				cmp UserChoice, 'O';
				je IUComputeCPN;
				cmp UserChoice, 'E';
				je ReLoop;
				jmp IUClothChoice; // if leter not found
			IULowerCaseCloth:
				cmp UserChoice, 'c';
				je IUComputeCotten;
				cmp UserChoice, 'p';
				je IUComputePolly;
				cmp UserChoice, 'b';
				je IUComputeCP;
				cmp UserChoice, 'n';
				je IUComputeNylon;
				cmp UserChoice, 'o';
				je IUComputeCPN;
				cmp UserChoice, 'e';
				je ReLoop;
				jmp IUClothChoice; // if leter not found
			IUComputeCotten:
				mov ebx, 0;
				jmp IUColorChoice;
			IUComputePolly:
				mov ebx, 4;
				jmp IUColorChoice;
			IUComputeCP:
				mov ebx, 8;
				jmp IUColorChoice;
			IUComputeNylon:
				mov ebx, 12;
				jmp IUColorChoice;
			IUComputeCPN:
				mov ebx, 16;
	;//--vvvv-- Get Color input --vvvv--
			IUColorChoice:
				call color; // Color choice menu
				call getInput;
				cmp UserChoice, 'a';
				jge IULowerCase;
				cmp UserChoice, 'R';
				je IUComputeRed;
				cmp UserChoice, 'G';
				je IUComputeGreen;
				cmp UserChoice, 'B';
				je IUComputeBlue;
				cmp UserChoice, 'E';
				je ReLoop;
				jmp IUColorChoice // if leter not found
			IULowerCase:
				cmp UserChoice, 'r';
				je IUComputeRed;
				cmp UserChoice, 'g';
				je IUComputeGreen;
				cmp UserChoice, 'b';
				je IUComputeBlue;
				cmp UserChoice, 'e';
				je ReLoop;
				jmp IUColorChoice // if leter not found
			IUComputeRed:
				add ebx, 0;
				jmp IUSizeChoice;
			IUComputeGreen:
				add ebx, 80;
				jmp IUSizeChoice;
			IUComputeBlue:
				add ebx, 160;
	;//--vvvv-- Get size input --vvvv--
			IUSizeChoice:
				call sizeGet; // Size choice menu
				call getInput;
				cmp UserChoice, 'a';
				jge IULowerCaseSize;
				cmp UserChoice, 'S';
				je IUComputeSmall;
				cmp UserChoice, 'M';
				je IUComputeMedium;
				cmp UserChoice, 'L';
				je IUComputeLarge;
				cmp UserChoice, 'X';
				je IUComputeXL;
				cmp UserChoice, 'E';
				je ReLoop;
				jmp IUSizeChoice // if leter not found
			IULowerCaseSize:
				cmp UserChoice, 's';
				je IUComputeSmall;
				cmp UserChoice, 'm';
				je IUComputeMedium;
				cmp UserChoice, 'l';
				je IUComputeLarge;
				cmp UserChoice, 'x';
				je IUComputeXL;
				cmp UserChoice, 'e';
				je ReLoop;
				jmp IUSizeChoice // if leter not found
			IUComputeSmall:
				add ebx, 0;
				jmp IUpdate;
			IUComputeMedium:
				add ebx, 20;
				jmp IUpdate;
			IUComputeLarge:
				add ebx, 40;
				jmp IUpdate;
			IUComputeXL:
				add ebx, 60;
			IUpdate:
				call HowMany; // Number to add
				mov eax, howMany
				add [shirtStock + ebx], eax
			jmp Reloop; // Dipsplay the main menu
	;
	;//--vvvv-- Calculates all shirts in stock --vvvv--
	;
		ListAll:
			mov ecx, 0;
			mov I, 0;
			mov ebx, 0;
			AllLoop:
				add ecx, [shirtStock + ebx];
				inc I;
				add ebx, 4;
				cmp I, 60;
				je endAllLoop;
				jmp AllLoop;
			endAllLoop:
				mov total, ecx;
				call DisplayTotal;
			jmp ReLoop;
	;
	;//--vvvv-- Calculate # of shirts based on cloth type --vvvv--
	;
		PickCloth:
			call clothMenu;
			call cloth;
			call getInput;
			mov total, 0;
			cmp UserChoice, 'a';
				jge LowerCaseCloth;
			cmp UserChoice, 'C';
				je ComputeCotten;
			cmp UserChoice, 'P';
				je ComputePolly;
			cmp UserChoice, 'B';
				je ComputeCP;
			cmp UserChoice, 'N';
				je ComputeNylon;
			cmp UserChoice, 'O';
				je ComputeCPN;
			cmp UserChoice, 'E';
				je ReLoop;
			jmp PickCloth;
			LowerCaseCloth:
				cmp UserChoice, 'c';
					je ComputeCotten;
				cmp UserChoice, 'p';
					je ComputePolly;
				cmp UserChoice, 'b';
					je ComputeCP;
				cmp UserChoice, 'n';
					je ComputeNylon;
				cmp UserChoice, 'o';
					je ComputeCPN;
				cmp UserChoice, 'e';
					je ReLoop;
				jmp PickCloth;
			ComputeCotten:
				mov ebx, 0;
				jmp ComputeCloth;
			ComputePolly:
				mov ebx, 4;
				jmp ComputeCloth;
			ComputeCP:
				mov ebx, 8;
				jmp ComputeCloth;
			ComputeNylon:
				mov ebx, 12;
				jmp ComputeCloth;
			ComputeCPN:
				mov ebx, 16;
				
			ComputeCloth:
				mov ecx, 0;
				mov I, 0;
			ClothDoLoop:
				add ecx, [shirtStock + ebx];
				inc I;
				cmp I, 12;
				je endClothDoLoop;
				add ebx, 20;
				jmp ClothDoLoop;
			endClothDoLoop:
				mov total, ecx;
				call DisplayIndividualTotal;
			jmp PickCloth; 
	;
	;//--vvvv-- Calculate # of shirts based on COLOR type --vvvv--
	;
		PickColor:
			call colorMenu;
			call color;
			call getInput;
				cmp UserChoice, 'a';
				jge LowerCase;
				cmp UserChoice, 'R';
				je ComputeRed;
				cmp UserChoice, 'G';
				je ComputeGreen;
				cmp UserChoice, 'B';
				je ComputeBlue;
				cmp UserChoice, 'E';
				je ReLoop;
			jmp PickColor;
			LowerCase:
				cmp UserChoice, 'r';
				je ComputeRed;
				cmp UserChoice, 'g';
				je ComputeGreen;
				cmp UserChoice, 'b';
				je ComputeBlue;
				cmp UserChoice, 'e';
				je ReLoop;
				jmp PickColor;
			ComputeRed:
				mov ebx, 0;	// Location of the first Red shirt
				jmp ComputeColor;
			ComputeGreen:
				mov ebx, 20; // Location of the first Green shirt
				jmp ComputeColor;
			ComputeBlue:
				mov ebx, 40; // Location of the first Blue shirt
				jmp ComputeColor;
			ComputeColor:
				mov ecx, 0;
				mov I, 0;
			ColorLoop:
				add ecx, [shirtStock + ebx];
				inc I;
				cmp I, 20;
				je endColorLoop;
				add ebx, 4;
				jmp ColorLoop;
			endColorLoop:
				mov total, ecx;
				call DisplayIndividualTotal;
			jmp PickColor;
	;
	;//--vvvv-- Calculate # of shirts based on SIZE --vvvv--
	;
		PickSize:
			call sizeMenu;
			call sizeGet;
			call getInput;
			mov total, 0;
			cmp UserChoice, 'a';
			jge LowerCaseSize;
				cmp UserChoice, 'S';
				je ComputeSmall;
				cmp UserChoice, 'M';
				je ComputeMedium;
				cmp UserChoice, 'L';
				je ComputeLarge;
				cmp UserChoice, 'X';
				je ComputeXL;
				cmp UserChoice, 'E';
				je ReLoop;
			jmp PickSize;
			LowerCaseSize:
				cmp UserChoice, 's';
				je ComputeSmall;
				cmp UserChoice, 'm';
				je ComputeMedium;
				cmp UserChoice, 'l';
				je ComputeLarge;
				cmp UserChoice, 'x';
				je ComputeXL;
				cmp UserChoice, 'e';
				je ReLoop;
				jmp PickSize;
			ComputeSmall:
				mov ebx, 0;
				jmp ComputeSize;
			ComputeMedium:
				mov ebx, 20;
				jmp ComputeSize;
			ComputeLarge:
				mov ebx, 40;
				jmp ComputeSize;
			ComputeXL:
				mov ebx, 60;
			ComputeSize:
				mov ecx, 0;
				mov I, 0;
			SizeLoop:
				add ecx, [shirtStock + ebx];
				inc I;
				cmp I, 15;		// Jump to end once all shirts...
				je endSizeLoop; // of the same size have been added.
				cmp I, 5;		
				je NextColor;	// move to the next COLOR
				cmp I, 10;
				je NextColor;	// move to the next COLOR
				add ebx, 4;		// move to the next cloth type
				jmp SizeLoop;
				NextColor:
					add ebx, 64;
				jmp SizeLoop;
			endSizeLoop:
				mov total, ecx;
				call DisplayIndividualTotal;
			jmp PickSize;
		ReLoop:
			jmp MainLoop;
	End:
	}
}
/*--------------------------------Output-----------------------------------------
--------------- Shirt Shop -----------------
	1. Update Inventory
	2. Total Items in Inventory
	3. Pick a cloth type to list
	4. Pick a color to list
	5. Pick a size to list
	0. Exit
Enter a number: 1
--------------- Update Inventory -----------------
	C. Cotton
	P. Polyester
	B. Cotton Poly Blend
	N. Nylon
	O. Full Blend
	E. Return to Main Menu
Enter a letter: B
	R. Red
	G. Green
	B. Blue
	E. Return to Main Menu
Enter a letter: G
	S. Small
	M. Medium
	L. Large
	X. Extra Large
	E. Return to Main Menu
Enter a letter: l
Enter a number (-### to subtract): 32
--------------- Cloth Menu -----------------
	C. Cotton
	P. Polyester
	B. Cotton Poly Blend
	N. Nylon
	O. Full Blend
	E. Return to Main Menu
Enter a letter: B
There are 44 B shirts in stock.
Press any key to continue . . .
--------------- Color Menu -----------------
	R. Red
	G. Green
	B. Blue
	E. Return to Main Menu
Enter a letter: B
There are 20 B shirts in stock.
Press any key to continue . . .
--------------- Size Menu -----------------
	S. Small
	M. Medium
	L. Large
	X. Extra Large
	E. Return to Main Menu
Enter a letter: L
There are 47 L shirts in stock.
Press any key to continue . . .
-------------------------------------------------------------------------------*/