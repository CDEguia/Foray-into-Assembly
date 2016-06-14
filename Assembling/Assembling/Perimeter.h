#pragma once

using namespace std;

int assemble(short a2, short b2, short c2, short d2) {
	short p2;
	_asm {
		mov ax, a2
		add ax, b2
		add ax, c2
		add ax, d2
		mov p2, ax
	}
	return p2;
}

void perimeter() {
	system("cls");
	cout << "---------- Perimeter ---------\n";
	short a, b, c, d;
	cout << "\t\ta\n";
	cout << "     ---------------------\n";
	cout << "    /                      \\\n";
	cout << " b /                        \\ c\n";
	cout << "  /                          \\\n";
	cout << " /                            \\\n";
	cout << " ------------------------------\n";
	cout << " \t\td\n";

	cout << "Enter the values of a, b, c, d:";
	cin >> a >> b >> c >> d;

	cout << "\t The perimeter is : " << assemble(a, b, c, d) << endl;
	cout << "_asm\t\tcomment\n";
	cout << "mov ax, a \t ; ax = the contents of a. a is unchanged.\n";
	cout << "add ax, b \t ; ax = ax + b\n";
	cout << "add ax, c\n";
	cout << "add ax, d\n";
	cout << "mov p2, ax \t ; p2 = ax allowing 2p to be used elsewhere in the program.\n";

	system("pause");
}