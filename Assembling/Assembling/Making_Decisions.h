#pragma once

void DisplayMr() {
	std::cout << "Hello Sir";
}
void DisplayMrs() {
	std::cout << "Hello Ma'am";
}
void NextLine() {
	std::cout << endl;
}
void DisplayPreeTeen() {
	std::cout << "You are a pree Teen";
}
void DisplayAdult() {
	std::cout << "You are an Adult";
}
void DisplayTeen() {
	std::cout << "You are a Teenager";
}
void decision() {
	system("cls");
	std::cout << "--------------- Decision ---------------\n\n";
	std::cout << "simple if statement\n\n";
	char gender;
	std::cout << "Enter m for male: "; std::cin >> gender;
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
			call NextLine
	}

	std::cout << "Enter f or F for female: "; std::cin >> gender;
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
	std::cout << "Using the ge(>=) and le(<=)\n";
	do {
		std::cout << "Enter your age or 0 to exit: "; std::cin >> age;
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