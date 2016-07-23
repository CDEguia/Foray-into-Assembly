#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.1 part III
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//	Find the perimeter
//----------------------------------------------------------
short assemble(short a2, short b2, short c2, short d2) {
	short p2;
	_asm {
		mov ax, a2
		add ax, b2
		add ax, c2
		add ax, d2
		mov p2, ax
	}
	return p2;
}

void perimeter() {
	system("cls");
	cout << "---------- Perimeter ---------\n";
	short a, b, c, d, total;
	cout << "\t\ta\n";
	cout << "     ---------------------\n";
	cout << "    /                      \\\n";
	cout << " b /                        \\ c\n";
	cout << "  /                          \\\n";
	cout << " /                            \\\n";
	cout << " ------------------------------\n";
	cout << " \t\td\n";
	cout << "Enter the values of a, b, c, d:"; 
	cin >> a >> b >> c >> d;
	
	total = assemble(a, b, c, d);
	cout << "\t The perimeter is : " << endl;
	cout << a << " + " << b << " + " << c << " + " << d << " = " << total << endl;
	system("pause");
}
/*--------------------Output-----------------------------------------------------
---------- Perimeter ---------
                a
     ---------------------
    /                      \
 b /                        \ c
  /                          \
 /                            \
 ------------------------------
                d
Enter the values of a, b, c, d:1 2 3 4
         The perimeter is :
1 + 2 + 3 + 4 = 10
Press any key to continue . . .
-------------------------------------------------------------------------------*/