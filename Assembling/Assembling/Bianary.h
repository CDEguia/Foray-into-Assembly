#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.3 part II
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//		Int into Bianary using C++
//----------------------------------------------------------
using namespace std;

void intBase2(unsigned int n) {
	unsigned int c = 1 << 31, x;
	for (int i = 1; i <= 32; i++) {
		x = n&c;
		if (x == 0) cout << "0";
		else cout << "1";
		if (i % 4 == 0) cout << " ";
		n = n << 1;
	}
	cout << endl;
}

void bianary() {
	system("cls");
	cout << "---------- Bianary ---------\n\n";
	cout << "\tOutput in bianary using bitwise opperators:\n\n";
	unsigned int a;
	do {
		cout << "Enter a positive integer or 0 to exit: "; cin >> a;
		if (a != 0) intBase2(a);
	} while (a != 0);

	system("pause");
}