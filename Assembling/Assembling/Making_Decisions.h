#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.5 part I
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//	Detect age and Gender
//----------------------------------------------------------
void DisplayMr() { std::cout << "Hello Sir"; }

void DisplayMrs() {	std::cout << "Hello Ma'am"; }

void DisplayLine() { std::cout << endl; }

void DisplayPreeTeen() { std::cout << "You are a pree Teen"; }

void DisplayAdult() { std::cout << "You are an Adult"; }

void DisplayTeen() { std::cout << "You are a Teenager"; }

void decision() {
	system("cls");
	std::cout << "--------------- Decisions ---------------\n\n";
	char gender;
	std::cout << "\tEnter m for male: "; std::cin >> gender;
	_asm {
		cmp gender, 'm';
		Jne else;
		call DisplayMr;
		Jmp cont;
		else: 
			cmp gender, 'M';
			je DispMr;
			call DisplayMrs;
			Jmp cont;
		DispMr:
			call DisplayMr;
		cont:
			call DisplayLine
	}

	std::cout << "\tEnter f or F for female: "; std::cin >> gender;
	_asm {
		cmp gender, 'f'; //compares gender to 'f'
		Jne TestForF; //Jumps to TestForF if gender != 'f'
		call DisplayMrs;
		Jmp contb; //Jumps to lable contb
		TestForF : ; //a lable
			cmp gender, 'F';// compares gender to 'F'
			Jne DisMr; //Jumps to DisMr if gender != 'F'
			call DisplayMrs;
			Jmp contb;
		DisMr:;
			call DisplayMr;
		contb:;
			call DisplayLine;
	}

	short age;
	std::cout << "\tUsing the ge(>=) and le(<=)\n";
	do {
		std::cout << "\tEnter your age or 0 to exit: "; std::cin >> age;
		if (age != 0) {
			_asm {
				cmp age, 12;
				Jle preeTeen; //Jump if age is less then or equal to(<=) 12
				//Jl could be use to jump if age is less then 13
				cmp age, 20;
				Jge adult; //Jump to if age is grater than or equal to(>=) 20
				call DisplayTeen;
				Jmp contc;
			adult:
				call DisplayAdult;
				Jmp contc;
			preeTeen:
				call DisplayPreeTeen;
			contc:
				call DisplayLine;
			}
		}
	} while (age != 0);

	system("pause");
}
/*--------------------------------------------------------------------------
--------------- Decisions ---------------

	Enter m for male: m
Hello Sir
	Enter f or F for female: F
Hello Ma'am
	Using the ge(>=) and le(<=)
	Enter your age or 0 to exit: 65
You are an Adult
	Enter your age or 0 to exit: 12
You are a pree Teen
	Enter your age or 0 to exit: 13
You are a Teenager
	Enter your age or 0 to exit: 15
You are a Teenager
	Enter your age or 0 to exit: 19
You are a Teenager
	Enter your age or 0 to exit: 20
You are an Adult
	Enter your age or 0 to exit: 0
Press any key to continue . . .
--------------------------------------------------------------------------*/