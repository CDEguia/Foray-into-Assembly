#pragma once
#include <string>
using namespace std;
int temp, I, total=0, mainChoice, howMany, shirtStock[3][4][5];
												/*	3 colors
														4 sizes
														    5 types */
char colorChoice, clothChoice, sizeChoice;
void tempDisplay() {
	cout << "number: " << temp;
}
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
	cout << "Enter a letter: ";
	cin >> clothChoice;
}
void color() {
	cout << "R. Red\n";
	cout << "G. Green\n";
	cout << "B. Blue\n";
	cout << "Enter a letter: ";
	cin >> colorChoice;
}
void sizeGet() {
	cout << "S. Small\n";
	cout << "M. Medium\n";
	cout << "L. Large\n";
	cout << "X. Extra Large\n";
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
	case 's':
	case 'S':
		thisize = "Small";
		break;
	case 'm':
	case 'M':
		thisize = "medium";
		break;
	case 'l':
	case 'L':
		thisize = "large";		
		break;
	case 'x':
	case 'X':
		thisize = "Xlarge";
	}

	cout << "There are " << total << " " << thisize << " shirts in stock.\n";
	system("pause");
}

void multidimarray() {
	_asm {

		mov ebx, 0;
		mov I, 0;
		mov eax, 0;
	fillArray:
		cmp I, 60;
		Je endFillArray;
		cmp I, 20;
		jge above20;
		mov ecx, 1;
		jmp setarray;
		above20:
			cmp I, 40;
			jge above40;
			mov ecx, 2;
			jmp setarray;
		above40:
			mov ecx, 3;
		setarray:
			mov [shirtStock + ebx], ecx;
			inc I;
			add ebx, 4;
			Jmp fillArray;
	endFillArray:

	MainLoop:
		call ShopMenu; //display the main menu
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
		jmp End;

		InventoryUpdate:
			call updateMenu;
			call cloth;
			call color;
			call sizeGet;
			call HowMany;

			jmp ReLoop;

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
			jmp PickSize;

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
				jmp PickSize;
				;//vvvvvvvvv Section Needs updated to the Cloth choice types vvvvvvvvvv
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
				cmp I, 15;
				je endSizeLoop;
				cmp I, 5;
				je NextColor;
				cmp I, 10;
				je NextColor;
				add ebx, 4;
				jmp SizeLoop;
			NextColor:
				add ebx, 64;
				jmp SizeLoop;
			endSizeLoop:
				mov total, ecx;
				call DisplayTotalSize;
				jmp ReLoop;
				;//^^^^^^^^^^^ Section Needs updated to the Cloth choice types ^^^^^^^^^^

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
			jmp PickColor;
			
			LowerCase:
				cmp colorChoice, 'r';
				je ComputeRed;
				cmp colorChoice, 'g';
				je ComputeGreen;
				cmp colorChoice, 'b';
				je ComputeBlue;
				jmp PickColor;

			ComputeRed:
				mov ebx, 0;
				jmp ComputeColor;
			ComputeGreen:
				mov ebx, 20;
				jmp ComputeColor;
			ComputeBlue:
				mov ebx, 40;
				jmp ComputeColor;

			ComputeColor:
				mov ecx, 0;
				mov I, 0;
			ColorLoop:
				add ecx, [shirtStock + ebx];
				inc I;
				add ebx, 4;
				cmp I, 20;
				je endColorLoop;
				jmp ColorLoop;
			endColorLoop:
				mov total, ecx;
				call DisplayTotalColor;
			jmp ReLoop;

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
				cmp I, 15;
				je endSizeLoop;
				cmp I, 5;
				je NextColor;
				cmp I, 10;
				je NextColor;
				add ebx, 4;
				jmp SizeLoop;
				NextColor:
					add ebx, 64;
				jmp SizeLoop;
			endSizeLoop:
				mov total, ecx;
				call DisplayTotalSize;

		ReLoop:
			jmp MainLoop;
	End:
	}
}