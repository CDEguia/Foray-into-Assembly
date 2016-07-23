#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.2 part II
//		Due date	June 20, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//	the area of a triangle
//----------------------------------------------------------
using namespace std;

void triangle() {
	system("cls");
	cout << "---------- Division ---------\n\n";
	int h, b, area;
	cout << "\t     ^\n";
	cout << "\t    / \\\n";
	cout << "\t   / | \\ h\n";
	cout << "\t  /  |  \\\n";
	cout << "\t /   |   \\\n";
	cout << "\t-----------\n";
	cout << "\t     b\n";

	cout << "Enter the height: "; 
	cin >> h;
	cout << "Enter the base: ";
	cin >> b;

	_asm {
		mov ebx, 2; ebx = 2
		mov eax, h; eax = h
		imul b; eax = h * b
		idiv ebx; eax = eax / 2
		mov area, eax; area = (h * b) / 2
	}
	cout << "\t The area is: " << area << endl;

	system("pause");
}
/*--------------------------------Output-----------------------------------------
---------- Division ---------

             ^
            / \
           / | \ h
          /  |  \
         /   |   \
        -----------
             b
Enter the height: 8
Enter the base: 32
         The area is: 128
Press any key to continue . . .
-------------------------------------------------------------------------------*/