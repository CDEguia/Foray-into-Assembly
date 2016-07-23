#pragma once
#include "Rectangle.h"
using namespace std;
void h1() {
	cout << "------------ Multiply and Devide --------------\n";
}
void pause() {
	cout << "Press [Enter] to continue...";
	cin.ignore();
	cin.get();
	system("cls");
}
void multiDiv() {
	system("cls");
	h1();
	cout << "First we will look at incrementation and deincrementation.\n";
	cout << "Assembly uses the key words inc and dec to increment and deincrement a variable.\n";
	short l, h;
	cout << "low = 10\n";	
	cout << "high = 20\n";
	_asm {
		mov ax, 10
		mov bx, 20
		dec ax
		inc bx
		mov l, ax
		mov h, bx
	}
	cout << "low-- = " << l << endl;
	cout << "high++ = " << h << endl;
	
	pause();
	
	h1();
	cout << "\t** Translating C++ into Assembly **\n";
	cout << "short a = 5, b = -3, c;\nc = a++ + --b;";
	short a = 5, b = -3, c;
	cout << "_asm {\n\tdec b; b--\n\tmov ax, a; ax = a\n\tadd ax, b; ax += b\n\tmov c, ax\n\tinc a; a++\n}\n";
	_asm {
		dec b; b--
		mov ax, a; ax = a
		add ax, b; ax += b
		mov c, ax
		inc a; a++
	}
	cout << "5++ + --(-3) = " << c << endl;
	cout << "a= " << a << "\tb= " << b << endl;

	pause();
	h1();
	cout << "\t** Multiplication **\n";
	cout << "Compute c = a * b\na, b, c are short\na is 16 bits\nb is 16 bits\n--------------\nc is 32 bits\n";
//	short a, b, c;

	_asm {
		mov a, 256
		mov b, 255
		mov ax, a; ax = a
		imul b; ax:dx = ax * b
		mov c, ax; c = a*b
	}
	cout << a << " * " << b << " = " << c << endl;
	cout << "If c is declared as a short (16bit) it's highest value would be 65535\n";
	pause();
	h1();
	cout << "\t** More Examples **\n";
	rectangle();
	pause();

}