#pragma once
#include <string>
using namespace std;
int temp, I, total=0, mainChoice, howMany, shirtStock[3][4][5];
												/*	3 colors
														4 sizes
														    5 types */
char colorChoice, clothChoice, sizeChoice;

void ShopMenu() {
	system("cls");
	cout << "--------------- Shirt Shop -----------------\n";
	cout << "1. Update Inventory\n";
	cout << "2. Total Items in Inventory\n";
	cout << "3. Pick a cloth type to list\n";
	cout << "4. Pick a color to list\n";
	cout << "5. Pick a size to list\n";
	cout << "0. Exit\n";
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
	cout << "C. Cotton\n";
	cout << "P. Polyester\n";
	cout << "B. C. P. Blend\n";
	cout << "N. Nylon\n";
	cout << "O. C. P. N. Blend\n";
	cout << "E. Return to Main Menu\n";
	cout << "Enter a letter: ";
	cin >> clothChoice;
}
void color() {
	cout << "R. Red\n";
	cout << "G. Green\n";
	cout << "B. Blue\n";
	cout << "E. Return to Main Menu\n";
	cout << "Enter a letter: ";
	cin >> colorChoice;
}
void sizeGet() {
	cout << "S. Small\n";
	cout << "M. Medium\n";
	cout << "L. Large\n";
	cout << "X. Extra Large\n";
	cout << "E. Return to Main Menu\n";
	cout << "Enter a letter: ";
	cin >> sizeChoice;
}

void HowMany() {
	cout << "Enter a number (use -### to subtract from inventory): ";
	cin >> howMany;
}

void DisplayTotal() {
	cout << "There are " << total << " shirts in stock.\n";
	system("pause");
}

void DisplayTotalColor() {
	string thiscolor;
	if (colorChoice == 'r' || colorChoice == 'R') { 
		thiscolor = "Red"; 
	}else if(colorChoice == 'g' || colorChoice == 'G') {
		thiscolor = "Green";
	}
	else{ thiscolor = "Blue"; }
	
	cout << "There are " << total << " " << thiscolor << " shirts in stock.\n";
	system("pause");
}

void DisplayTotalSize() {
	string thisize;
	switch (sizeChoice) {
		case 's': case 'S':
			thisize = "Small"; break;
		case 'm': case 'M':
			thisize = "medium"; break;
		case 'l': case 'L':
			thisize = "large"; break;
		case 'x': case 'X':
			thisize = "Xlarge";
	}
	cout << "There are " << total << " " << thisize << " shirts in stock.\n";
	system("pause");
}

void DisplayTotalCloth() {
	cout << "There are " << total << " shirts in stock.\n";
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
		;// --^^^^-- End of array fill --^^^^--
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
	;// --^^^^-- End of Main Menu Logic --^^^^--
	;
	;//--vvvv-- Inventory Update logic --vvvv--
	;
		InventoryUpdate: 
			call updateMenu; // Header
			
			UIClothChoice:
				call cloth; // Cloth choice menu
				cmp clothChoice, 'a'; // Decide weather user input
				jge IULowerCaseCloth; // is upper or lower case.

				cmp clothChoice, 'C';
				je IUComputeCotten;
				cmp clothChoice, 'P';
				je IUComputePolly;
				cmp clothChoice, 'B';
				je IUComputeCP;
				cmp clothChoice, 'N';
				je IUComputeNylon;
				cmp clothChoice, 'O';
				je IUComputeCPN;
				cmp clothChoice, 'E';
				je ReLoop;
				jmp UIClothChoice; // if leter not found
			IULowerCaseCloth:
				cmp clothChoice, 'c';
				je IUComputeCotten;
				cmp clothChoice, 'p';
				je IUComputePolly;
				cmp clothChoice, 'b';
				je IUComputeCP;
				cmp clothChoice, 'n';
				je IUComputeNylon;
				cmp clothChoice, 'o';
				je IUComputeCPN;
				cmp clothChoice, 'e';
				je ReLoop;
				jmp UIClothChoice; // if leter not found

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
			
			IUColorChoice:
				call color; // Color choice menu
				cmp colorChoice, 'a';
				jge IULowerCase;

				cmp colorChoice, 'R';
				je IUComputeRed;
				cmp colorChoice, 'G';
				je IUComputeGreen;
				cmp colorChoice, 'B';
				je IUComputeBlue;
				cmp colorChoice, 'E';
				je ReLoop;
				jmp IUColorChoice // if leter not found

			IULowerCase:
				cmp colorChoice, 'r';
				je IUComputeRed;
				cmp colorChoice, 'g';
				je IUComputeGreen;
				cmp colorChoice, 'b';
				je IUComputeBlue;
				cmp colorChoice, 'e';
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

			
			IUSizeChoice:
				call sizeGet; // Size choice menu
				cmp sizeChoice, 'a';
				jge IULowerCaseSize;

				cmp sizeChoice, 'S';
				je IUComputeSmall;
				cmp sizeChoice, 'M';
				je IUComputeMedium;
				cmp sizeChoice, 'L';
				je IUComputeLarge;
				cmp sizeChoice, 'X';
				je IUComputeXL;
				cmp sizeChoice, 'E';
				je ReLoop;
				jmp IUSizeChoice // if leter not found

			IULowerCaseSize:
				cmp sizeChoice, 's';
				je IUComputeSmall;
				cmp sizeChoice, 'm';
				je IUComputeMedium;
				cmp sizeChoice, 'l';
				je IUComputeLarge;
				cmp sizeChoice, 'x';
				je IUComputeXL;
				cmp sizeChoice, 'e';
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
	;// --^^^^-- End of Inventory Update logic --^^^^--
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
	;// --^^^^-- End of Calculation --^^^^--
	;
	;//--vvvv-- Calculate # of shirts based on cloth type --vvvv--
	;
		PickCloth:
			call clothMenu;
			call cloth;
			mov total, 0;
			cmp clothChoice, 'a';
			jge LowerCaseCloth;

			cmp clothChoice, 'C';
			je ComputeCotten;
			cmp clothChoice, 'P';
			je ComputePolly;
			cmp clothChoice, 'B';
			je ComputeCP;
			cmp clothChoice, 'N';
			je ComputeNylon;
			cmp clothChoice, 'O';
			je ComputeCPN;
			cmp clothChoice, 'E';
			je ReLoop;
			jmp PickCloth;

			LowerCaseCloth:
				cmp clothChoice, 'c';
				je ComputeCotten;
				cmp clothChoice, 'p';
				je ComputePolly;
				cmp clothChoice, 'b';
				je ComputeCP;
				cmp clothChoice, 'n';
				je ComputeNylon;
				cmp clothChoice, 'o';
				je ComputeCPN;
				cmp clothChoice, 'e';
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
				call DisplayTotalCloth;
			jmp PickCloth; 
	;
	;// --^^^^-- End of Calculation --^^^^--
	;
	;//--vvvv-- Calculate # of shirts based on COLOR type --vvvv--
	;
		PickColor:
			call colorMenu;
			call color;
			cmp colorChoice, 'a';
			jge LowerCase;
			
			cmp colorChoice, 'R';
			je ComputeRed;
			cmp colorChoice, 'G';
			je ComputeGreen;
			cmp colorChoice, 'B';
			je ComputeBlue;
			cmp colorChoice, 'E';
			je ReLoop;
			jmp PickColor;
			
			LowerCase:
				cmp colorChoice, 'r';
				je ComputeRed;
				cmp colorChoice, 'g';
				je ComputeGreen;
				cmp colorChoice, 'b';
				je ComputeBlue;
				cmp colorChoice, 'e';
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
				call DisplayTotalColor;
			jmp PickColor;
	;
	;// --^^^^-- End of Calculation --^^^^--
	;
	;//--vvvv-- Calculate # of shirts based on SIZE --vvvv--
	;
		PickSize:
			call sizeMenu;
			call sizeGet;
			mov total, 0;
			cmp sizeChoice, 'a';
			jge LowerCaseSize;

			cmp sizeChoice, 'S';
			je ComputeSmall;
			cmp sizeChoice, 'M';
			je ComputeMedium;
			cmp sizeChoice, 'L';
			je ComputeLarge;
			cmp sizeChoice, 'X';
			je ComputeXL;
			cmp sizeChoice, 'E';
			je ReLoop;
			jmp PickSize;

			LowerCaseSize:
				cmp sizeChoice, 's';
				je ComputeSmall;
				cmp sizeChoice, 'm';
				je ComputeMedium;
				cmp sizeChoice, 'l';
				je ComputeLarge;
				cmp sizeChoice, 'x';
				je ComputeXL;
				cmp sizeChoice, 'e';
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
				call DisplayTotalSize;
			jmp PickSize;

		ReLoop:
			jmp MainLoop;
	End:
	}
}