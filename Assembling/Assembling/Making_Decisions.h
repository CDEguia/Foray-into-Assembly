#pragma once
using namespace std;

void DisplayMr() {
	cout << "Hello Sir";
}
void DisplayMrs() {
	cout << "Hello Ma'am";
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
	}

	system("pause");
}