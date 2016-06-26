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
	cout << endl;
	cout << "\tThe << (\"left shift\") opperator\n";
	cout << "Using << 1 is the quickest way to multiply by 2.\n\n";
	a = 4;
	c = a << 1;
	cout << dec;
	cout << "a = 4 = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\n";
	cout << "   << 1 _____________________________________________________________\n";
	cout << "c = " << c << " = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\t| 0 |\n\n";
	
	cout << "\nUsing << 2 is the quickest way to multiply by 4.\n\n";
	c = a << 2;
	cout << "a = 4 = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\n";
	cout << "   << 2 _____________________________________________________________\n";
	cout << "c = " << c << " = | 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\n\n";

	cout << "\nSee it working with 5 = 0 1 0 1.\n\n";
	a = 5;
	c = a << 1;
	cout << "a = 5 = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 1 |\n";
	cout << "   << 1 _____________________________________________________________\n";
	cout << "c = " << c << " = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 1 |\t| 0 |\n\n";
	system("pause");
	
	cout << endl;
	cout << "\tThe >> (\"right shift\") opperator\n\n";
	cout << "Using >> is the quickest way to devide with the result rounded down.\n\n";
	a = 4;
	c = a >> 1;
	cout << dec;
	cout << "a = 4 = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 0 |\n";
	cout << "   >> 1 _____________________________________________________________\n";
	cout << "c = " << c << " = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\n\n";
	
	cout << "See it working with 5 = 0 1 0 1.\n\n";
	a = 5;
	c = a >> 1;
	cout << "a = 5 = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\t| 1 |\n";
	cout << "   >> 1 _____________________________________________________________\n";
	cout << "c = " << c << " = | 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 0 |\t| 1 |\t| 0 |\n\n";

	system("pause");
}