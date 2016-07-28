#pragma once
//-------------------------------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.9 part I
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//		Array, calculation of High Low Total & average
//-------------------------------------------------------------------------------
int loc, contains, number, maxA, minA, Tot, average;
char arrayName;

void ShowNumber() {
	std::cout << arrayName << "[" << loc << "] = " << contains << " | ";
}
void GetNumber() { std::cout << "\tEnter a number: "; cin >> number; }

void DisplayMax() { std::cout << "\tThe Highest number is: " << maxA << endl; }

void DisplayMin() { std::cout << "\tThe Lowest number is: " << minA << endl; }

void DisplayAvg() {	std::cout << "\tThe Average is: " << average << endl; }

void DisplayTot() { std::cout << "\tThe Total is: " << Tot << endl; }

void Pause() { cout << endl; system("pause"); }

void arrays() {
	system("cls");
	std::cout << "---------------- ARRAYS ---------------\n\n";
	int c[3], b[6], six = 6;
	_asm {
		mov ebx, 0;
		mov[c + ebx], 10;
		add ebx, 4;
		mov[c + ebx], 15; 
		add ebx, 4
		mov[c + ebx], 7;
		mov ebx, 0;
		mov loc, 0;
		mov arrayName, 'c';
		forLoop:
			mov ecx, [c + ebx]; //because memory can't be moved to memory
			mov contains, ecx;
			call ShowNumber;
			add ebx, 4;
			inc loc;
			cmp loc, 3;
			je Done;
			jmp forLoop;
		Done:
			call Pause;
;//---vvvvv--- User input and output ---vvvvv---
		mov ebx, 0;
		mov loc, 0;
	forLoopA:
		call GetNumber;
		mov ecx, number //because memory can't be moved to memory
		mov [b + ebx], ecx;
		add ebx, 4;
		inc loc;
		cmp loc, 6;
		je DisplayArray;
		jmp forLoopA;
	DisplayArray:
		mov arrayName, 'b';
		mov ebx, 0;
		mov loc, 0;
		DisplayLoop:
			mov ecx, [b + ebx]; //because memory can't be moved to memory
			mov contains, ecx;
			call ShowNumber;
			inc loc;
			add ebx, 4;
			cmp loc, 6;
			je DisplayDone;
			jmp DisplayLoop;
		DisplayDone:
;//---vvvvv--- Compute Heighest Number ---vvvvv---
		mov ecx, 0;
		mov loc, 0;
		mov ebx, 0;
	maxLoop:
		cmp[b + ebx], ecx ;
		jle lessThen;
		mov ecx, [b + ebx];
		lessThen:
			inc loc;
			add ebx, 4;
			cmp loc, 6;
			je maxEnd;
			jmp maxLoop;
		maxEnd:
			mov maxA, ecx;
			call DisplayMax;
;//---vvvvv--- Compute Lowest Number ---vvvvv---
		mov ecx, 9999;
		mov loc, 0;
		mov ebx, 0;
	minLoop:
		cmp[b + ebx], ecx;
		jge greaterThen;
		mov ecx, [b + ebx];
	greaterThen:
		inc loc;
		add ebx, 4;
		cmp loc, 6;
		je minEnd;
		jmp minLoop;
	minEnd:
		mov minA, ecx;
		call DisplayMin;
;//---vvvvv--- Compute Total Number ---vvvvv---
		mov ecx, 0;
		mov loc, 0;
		mov ebx, 0;
	totLoop:
		add ecx, [b + ebx];
		inc loc;
		add ebx, 4;
		cmp loc, 6;
		je totEnd;
		jmp totLoop;
	totEnd:
		mov eax, ecx;
		mov Tot, eax;		
		call DisplayTot;
;//---vvvvv--- Compute Average Number ---vvvvv---
		mov ecx, 0;
		mov loc, 0;
		mov ebx, 0;
	avgLoop:
		add ecx, [b + ebx];
		inc loc;
		add ebx, 4;
		cmp loc, 6;
		je avgEnd;
		jmp avgLoop;
	avgEnd:
		mov eax, ecx;
		cdq;
		idiv six;
		mov average, eax;
		call DisplayAvg;
		call Pause;
	}
}
/*--------------------------------Output-----------------------------------------
---------------- ARRAYS ---------------
c[0] = 10 | c[1] = 15 | c[2] = 7 |
Press any key to continue . . .
	Enter a number: 65
	Enter a number: 651
	Enter a number: 65
	Enter a number: 12
	Enter a number: 95
	Enter a number: 75
b[0] = 65 | b[1] = 651 | b[2] = 65 | b[3] = 12 | b[4] = 95 | b[5] = 75 |
The Highest number is: 651
        The Lowest number is: 12
        The Total is: 963
        The Average is: 160
Press any key to continue . . .
-------------------------------------------------------------------------------*/