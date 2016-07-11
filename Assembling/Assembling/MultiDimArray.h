#pragma once
using namespace std;
int temp, I, total=0, mainChoice, howMany, shirtStock[3][4][5];
/*													3 colors
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
void sizeA() {
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

void multidimarray() {
	_asm {

		mov ebx, 0;
		mov I, 1;
		mov eax, 0;
	fillArray:
		cmp I, 61;
		Je endFillArray;
		mov ecx, I;
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
			call sizeA;
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
			jmp ReLoop;
		
		PickColor:
			call colorMenu;
			call color;
			jmp ReLoop;

		PickSize:
			call sizeMenu;
			call sizeA;

		ReLoop:
			jmp MainLoop;
	End:
	}
}