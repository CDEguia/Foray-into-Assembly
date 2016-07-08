#pragma once

using namespace std;
int loc, contains, number, max, min, average;
char arrayName;

void ShowNumber() {
	cout << "\n" << arrayName << "[" << loc << "] = " << contains << endl;
}

void GetNumber() {
	cout << "Enter a number: "; cin >> number;
}

void DisplayMax() {
	cout << "The Highest number is: " << max << endl;
}

void DisplayMin() {
	cout << "The Lowest number is: " << min << endl;
}
void DisplayAvg() {
	cout << "The Average is: " << average << endl;
}

void arrays() {
	system("cls");
	cout << "---------------- ARRAYS ---------------\n\n";
	cout << "\tIn an array of integers each block of data consists of 4 bytes.\n";
	cout << "By using the ebx register to hold the \"next\" location of each integer we can use _asm{} to create the array.";

	int c[3];

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
	}
	system("pause");

	int b[6];
	_asm {
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
	}
	
	cout << "\nComputing the Highest Number...\n";
	
	_asm {
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
			mov max, ecx;
			call DisplayMax;
	}

	cout << "\nComputing the Lowest Number...\n";
	_asm {
		mov ecx, 999999;
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
		mov min, ecx;
		call DisplayMin;
	}
	cout << "\nComputing the Average...\n";
	int six = 6;
	_asm {
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
	}
	system("pause");
}