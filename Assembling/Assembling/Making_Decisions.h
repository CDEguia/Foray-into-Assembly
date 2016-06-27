#pragma once
using namespace std;

void DisplayMr() {
	cout << "Hello Sir";
}
void DisplayMrs() {
	cout << "Hello Ma'am";
}
void NextLine() {
	cout << endl;
}
void DisplayPreeTeen() {
	cout << "You are a pree Teen";
}
void DisplayAdult() {
	cout << "You are an Adult";
}
void DisplayTeen() {
	cout << "You are a Teenager";
}
void decision() {
	system("cls");
	cout << "--------------- Decision ---------------\n\n";
	cout << "simple if statement\n\n";
	char gender;
	cout << "Enter m for male: "; cin >> gender;
	_asm {
		cmp gender, 'm'
		Jne else
		call DisplayMr
		Jmp cont
		else: call DisplayMrs
		cont:
		call NextLine
	}

	cout << "Enter f or F for female: "; cin >> gender;
	_asm {
		cmp gender, 'f'; compares gender to 'f'
		Jne TestForF; Jumps to TestForF if gender != 'f'
		call DisplayMrs
		Jmp contb; Jumps to lable contb
		TestForF : ; a lable
			cmp gender, 'F'; compares gender to 'F'
			Jne DisMr; Jumps to DisMr if gender != 'F'
			call DisplayMrs
			Jmp contb
		DisMr:
			call DisplayMr
		contb:
			call NextLine
	}

	short age;
	cout << "Using the ge(>=) and le(<=)\n";
	do {
		cout << "Enter your age or 0 to exit: "; cin >> age;
		if (age != 0) {
			_asm {
				cmp age, 12
				Jle preeTeen; Jump if age is less then or equal to(<=) 12
				//Jl could be use to jump if age is less then 13
				cmp age, 20
				Jge adult; Jump to if age is grater than or equal to(>=) 20
				call DisplayTeen
				Jmp contc
			adult:
				call DisplayAdult
				Jmp contc
			preeTeen:
				call DisplayPreeTeen			
			contc:
				call NextLine
			}
		}
	} while (age != 0);

	system("pause");
}