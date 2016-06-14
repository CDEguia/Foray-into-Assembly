#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-301
//		Project		No.3 part I
//		Due date	Feb 26, 2014
//		Professor	Ray Ahmadnia
//
//   This program displays:
//For the following rectangle:
//            ___________________
//            |                 |
//            |                 | width
//            |                 |
//            -------------------
//                 length
//Enter the measure of the width: 23.90
//Enter the measure of the length: 44.01
//          Area = 1051.84
//          Perimeter = 135.82
//----------------------------------------------------------
#include <math.h>

using namespace std;

void rectangle()
{
	//Declare identifier
	short Width, Length, Area, Perimeter;

	//Get data from the user and store
	cout << "For the following rectangle:" << endl;
	cout << "            ___________________" << endl;
	cout << "            |                 |" << endl;
	cout << "            |                 | width" << endl;
	cout << "            |                 |" << endl;
	cout << "            -------------------" << endl;
	cout << "                 length" << endl;
	cout << "Enter the measure of the width: ";
	cin >> Width;
	cout << "Enter the measure of the length: ";
	cin >> Length;
	short l = Length;
	//Calculate
	_asm {
		mov ax, Width
		imul l
		mov Area, ax
		mov ax, Width
		mov cx, 2
		imul cx; ax = ax * 2
		mov bx, ax
		mov ax, l
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
------------ Multiply and Devide --------------
        ** More Examples **
For the following rectangle:
            ___________________
            |                 |
            |                 | width
            |                 |
            -------------------
                 length
Enter the measure of the width: 23
Enter the measure of the length: 44
          Area = 1012
          Perimeter = 134
Press any key to continue . . .
----------------------------------------------------------*/