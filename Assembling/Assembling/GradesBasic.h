#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.1 part III
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//	The mean, median, mode, and range of your grades
//----------------------------------------------------------
#include <algorithm>
//declare identifiers     A, B, C, D, F
short AllGrades[20], LetterGrades[5], grade, median, mean, range;
char mode;
void AskForGrades() {
	system("cls");
	cout << "------------------ Grades ------------------\n\n";
	cout << "Enter a string of grades (i.e. 92) ending with 999: ";
}
void readGrade() { cin >> grade; }
void displayGrades()
{
	cout << "\tA\tB\tC\tD\tF\n";
	cout << "\t" << LetterGrades[0] << "\t" << LetterGrades[1] << "\t" << LetterGrades[2] << "\t" << LetterGrades[3] << "\t" << LetterGrades[4] << endl;
	cout << "Average: " << mean << endl;
	cout << "You mostly get: " << mode << "'s" << endl;
	cout << "Your grades have a range of " << range << " points.\n";
	cout << "Your median score is: " << median << endl;
}
void sortarray() { sort(AllGrades, AllGrades + 20); }
void gradesbasic() {
	for(int i = 0; i < 20; i++)
	{
		if (i < 5) { LetterGrades[i] = 0; }
		AllGrades[i] = 0;
	}
	short  Gtotal = 0, min = 100, max = 0;
	cin.ignore();
	short gradeCount=0;
	_asm {
		call AskForGrades
	whileLoop :
		call readGrade;
		cmp grade, 999;
			Je outGrade;
		mov eax, 0; // Reset/Clear eax
		mov ax, gradeCount; // Set to the current number of grades
		cwd; // change the size of ax to eax
		mov bx, 2;
		imul bx; // eax = eax / 2
		mov bx, grade;
		mov [AllGrades + eax], bx;
		;// Find min and max grade to compute range
		mov ax, max;
		cmp grade, ax;
		jle Notgreater;
		mov ax, grade;
		mov max, ax;
	Notgreater:
		mov ax, min;
		cmp grade, ax;
		jge SetTotal;
		mov ax, grade;
		mov min, ax;
	SetTotal:
		inc gradeCount; // ++gradeCount
		mov ax, Gtotal;
		add ax, grade;
		mov Gtotal, ax;
		cmp grade, 90;
			Jge incA;
		cmp grade, 80;
			Jge incB;
		cmp grade, 70;
			Jge incC;
		cmp grade, 60;
			Jge incD;
		;// else grade = F
		inc [LetterGrades + 8];
		jmp cont;
	incD:
		inc [LetterGrades + 6];
		jmp cont;
	incC:
		inc [LetterGrades + 4];
		jmp cont;
	incB:
		inc[LetterGrades + 2];
		jmp cont;
	incA:
		inc [LetterGrades + 0];
		jmp cont;
	cont:
		jmp whileLoop;
	outGrade:
		;//Compute Median
		call sortarray;// low to high;
		mov ebx, 0;
		mov eax, 0;
		mov ebx, 20;
		mov cx, 2;
		mov ax, gradeCount;
		cwd;
		idiv cx;
		cmp dx, 1;
		jne NoMedian;
		add eax, 1;
		sub ebx, eax;
		imul ebx, 2;
		mov ax, [AllGrades + ebx];
		mov median, ax;
		jmp CompRange;
	NoMedian:
		mov median, 0;
	CompRange:
		;//Compute Range
		mov ax, max;
		sub ax, min;
		mov range, ax;
		;//Compute Mean
		mov ax, Gtotal;
		cwd;
		idiv gradeCount;
		mov mean, ax; // Set the mean
		;// Find Mode
		mov ebx, 0;
		mov cx, [LetterGrades + ebx];
		mov mode, 'A';
		mov dx, 1;
	modeLoop:
		cmp dx, 5;
		je endModeLoop;
		add ebx, 2;
		cmp[LetterGrades + ebx], cx;
		jle contModeLoop;
		mov cx, [LetterGrades + ebx];
		cmp dx, 1;
		je setGradeB;
		cmp dx, 2;
		je setGradeC;
		cmp dx, 3;
		je setGradeD;
		mov mode, 'F';
		jmp contModeLoop;
	setGradeD:
		mov mode, 'D';
		jmp contModeLoop;
	setGradeC:
		mov mode, 'C';
		jmp contModeLoop;
	setGradeB:
		mov mode, 'B';
	contModeLoop:
		inc dx;
		jmp modeLoop;
	endModeLoop:
		call displayGrades;
	}
	system("pause");
}
/*--------------------------------Output-----------------------------------------
------------------ Grades ------------------

Enter a string of grades (i.e. 92) ending with 999: 88 55 66 77 90 999
        A       B       C       D       F
        1       1       1       1       1
Average: 75
You mostly get: A's
Your grades have a range of 35 points.
Your median score is: 77
Press any key to continue . . .
-------------------------------------------------------------------------------*/