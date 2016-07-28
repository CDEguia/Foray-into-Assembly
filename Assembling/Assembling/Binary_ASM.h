#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.3 part III
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//		Int Base10 into another Base using C++ and some Assembly
//----------------------------------------------------------
using namespace std;
void Print1() {
	cout << "1";
}
void Print0() {
	cout << "0";
}
void PrintSpace() {
	cout << " ";
}
void intBase(unsigned int n) {
	unsigned int c = 1, x, b, i = 0;
	_asm {
		mov cl, 31
		shl c, cl
		Do:
				inc i;
				mov eax, n
				and eax, c
				mov x, eax
				cmp x, 0;
					je IsZero;
				call Print1;
				jmp SpaceCheck;
			IsZero:
				call Print0;
			SpaceCheck:
				mov eax, i;
				mov b, 4;
				cdq;
				idiv b;
				cmp edx, 0; //ebx = i%4
					jne NoSpace;
				call PrintSpace;
			NoSpace:
				mov cl, 1;
				shl n, cl;
		while:
			cmp i, 31;
				jle Do;
	}
	cout << "\n\n";
}

void binary_asm() {
	system("cls");
	cout << "---------- Bianary ---------\n\n";
	cout << "\tOutput in bianary using bitwise opperators:\n\n";
	unsigned int a;
	short b;
	do {
		cout << "Enter a positive integer or 0 to exit: "; cin >> a;
		cout << "Enter a Base to convert to: "; cin >> b;
		if (a != 0) intBase(a);
	} while (a != 0);

	system("pause");
}
/*------------------------------------------------------------------
---------- Bianary ---------

Output in bianary using bitwise opperators:

Enter a positive integer or 0 to exit: 5
0000 0000 0000 0000 0000 0000 0000 0101

Enter a positive integer or 0 to exit: 32
0000 0000 0000 0000 0000 0000 0010 0000

Enter a positive integer or 0 to exit: 33
0000 0000 0000 0000 0000 0000 0010 0001

Enter a positive integer or 0 to exit: 128
0000 0000 0000 0000 0000 0000 1000 0000

Enter a positive integer or 0 to exit: 563
0000 0000 0000 0000 0000 0010 0011 0011

Enter a positive integer or 0 to exit: 0
Press any key to continue . . .
------------------------------------------------------------------*/