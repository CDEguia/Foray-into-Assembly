#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.3 part I
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//
//----------------------------------------------------------
using namespace std;

void bitwise() {
	system("cls");
	cout << "---------- Bitwise ---------\n\n";
	cout << "\tA quick demo of bitwise opperators in c++ :\n\n";
	unsigned int a= 35, b = 17, c;
	cout << "\tThe & (\"AND\") opperator\n";
	c = a & b;
	cout << "a = 35 = | 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 1 |\n";
	cout << "b = 17 = | 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\n";
	cout << "\t&_____________________________________________________________\n";
	cout << "c = " << c << " = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\n\n";

	cout << "\tThe | (\"OR\") opperator\n";
	c = a | b;
	cout << "a = 35 = | 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 1 |\n";
	cout << "b = 17 = | 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\n";
	cout << "\t|_____________________________________________________________\n";
	cout << "c = " << c << " = | 0 |\t| 0 |\t| 1 |\t| 1 |\t| 0 |\t| 0 |\t| 1 |\t| 1 |\n\n";

	cout << "\tThe ~ (\"Compliment\") opperator\n";
	c = ~a;
	cout << "a = 35 = | 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 1 |\n";
	cout << "\t~_____________________________________________________________\n";
	cout << "c = " << c << " = | 1 |\t| 1 |\t| 0 |\t| 1 |\t| 1 |\t| 1 |\t| 0 |\t| 0 |\n\n";
	cout << "a in hex:\t\t" << hex << a << endl;
	cout << "~a in hex:\t" << c << endl;
	system("pause");
}