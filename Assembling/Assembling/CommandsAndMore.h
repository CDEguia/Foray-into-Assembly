#pragma once
using namespace std;

void commandsAndMore() {
	system("cls");
	cout << "---------- Registers ----------\n";
	cout << " 8 bit registers: ah , al  bh , bl  ch , cl  dh , dl\n";
	cout << endl;
	cout << " 16 bit registers: ax \t bx \t cx \t dx \n";
	cout << endl;
	cout << " 32 bit regiters: eax \t ebx \t ecx \t edx \n";
	cout << endl;
	cout << "Registarts eax, ax, ah, and al use the same set of bits:\n";
	cout << "                            eax\n";
	cout << "  __________________________/\\___________________________\n";
	cout << " /                                                       \\\n";
	cout << " 31 - 27 - 23 - 19 - 16 15 - 13 - 11 - 9 8 7 6 5 4 3 2 1 0\n";
	cout << "                        \\_______  _______/ \\______  _____/\n";
	cout << "                                \\/                \\/\n";
	cout << "                                ah                al\n";
	cout << "                        \\________________  ______________/\n";
	cout << "                                         \\/\n";
	cout << "                                         ax\n";
	cout << endl;
	cout << "The 8 bit registers can hold one char each.\n";
	cout << "The 16 bit registers can hold one short each.\n";
	cout << "the 32 bit registers can hold one int each";

	cout << "Press [Enter] to continue...";
	cin.ignore();
	cin.get();

	cout << "mov ax, x\t ; ax = x\n";
	cout << "dec x\t ; lowers the value of x by 1\n";
	cout << "inc x\t ; raises the value of x by 1\n";
	cout << "imul x\t ; multiplys the value in ax or eax by x\n";
}