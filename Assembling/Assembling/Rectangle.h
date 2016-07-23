#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-301
//		Project		No.3 part I
//		Due date	Feb 26, 2014
//		Professor	Ray Ahmadnia
//
//   This program displays:
//		the area and Perimeter of a rectangle
//----------------------------------------------------------
void rectangle()
{
	//Declare identifier
	short Width, L, Area, Perimeter;
	//Get data from the user and store
	cout << "For the following rectangle:" << endl;
	cout << "            ___________________" << endl;
	cout << "            |                 |" << endl;
	cout << "            |                 | width" << endl;
	cout << "            |                 |" << endl;
	cout << "            -------------------" << endl;
	cout << "                 length" << endl;
	cout << "Enter the measure of the width and length: ";
	cin >> Width >> L;
	//Calculate
	_asm {
		mov ax, Width
		imul L
		mov Area, ax
		mov ax, Width
		mov cx, 2
		imul cx; ax = ax * 2
		mov bx, ax
		mov ax, L
		imul cx
		add ax, bx
		mov Perimeter, ax
	}
	//Display All
	cout << "          Area = " << Area << endl;
	cout << "          Perimeter = " << Perimeter << endl;
	//Terminate Program
	system("pause");
}
/*----------------------Output------------------------------
For the following rectangle:
            ___________________
            |                 |
            |                 | width
            |                 |
            -------------------
                 length
Enter the measure of the width and length: 23 44
          Area = 1012
          Perimeter = 134
Press any key to continue . . .
----------------------------------------------------------*/