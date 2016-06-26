#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.3 part III
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//		Int into Binary using C++ and some Assembly
//----------------------------------------------------------
using namespace std;

void intBase(unsigned int n) {
	unsigned int c = 1, x;
	_asm {
		mov cl, 31
		shl c, cl
	}
	for (int i = 1; i <= 32; i++) {
		_asm {
			mov eax, n
			and eax, c
			mov x, eax
		}
		if (x == 0) cout << "0";
		else cout << "1";
		if (i % 4 == 0) cout << " ";
		_asm {
			mov cl, 1
			shl n,cl
		}
	}
	cout << "\n\n";
}

void binary_asm() {
	system("cls");
	cout << "---------- Bianary ---------\n\n";
	cout << "\tOutput in bianary using bitwise opperators:\n\n";
	unsigned int a;
	do {
		cout << "Enter a positive integer or 0 to exit: "; cin >> a;
		if (a != 0) intBase(a);
	} while (a != 0);

	system("pause");
}