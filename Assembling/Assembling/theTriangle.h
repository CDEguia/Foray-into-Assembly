#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.2 part II
//		Due date	June 20, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//For the following Triangle:
//                   ^
//					/ \
//                 / | \
//                /  |  \ height
//               /   |   \
//              -----------
//                 base
//Enter the height: 10
//Enter the base: 20
//		Area = 100
//      Perimeter = 135
//----------------------------------------------------------
using namespace std;

void triangle() {
	system("cls");
	cout << "---------- Division ---------\n\n";
	int h, b, area, perim;
	cout << "\t     ^\n";
	cout << "\t   / | \\\n";
	cout << "\t  /  |  \\ h\n";
	cout << "\t /   |   \\\n";
	cout << "\t/    |    \\\n";
	cout << "\t-----------\n";
	cout << "\t     b\n";

	cout << "Enter the values of h, b: ";
	cin >> h >> b;

	_asm {
		mov ebx, 2; ebx = 2
		mov eax, h; eax = h
		imul b; eax = h * b
		idiv ebx; eax = eax / 2
		mov area, eax; area = eax
		mov eax, h; eax = h
		imul ebx; eax = h * 2
		add eax, b; eax = (h * 2) + b
		mov perim, eax; perim = eax
	}
	cout << "\t The area is: " << area << endl;
	cout << "\t The perimeter is: " << perim << endl;

	system("pause");
}