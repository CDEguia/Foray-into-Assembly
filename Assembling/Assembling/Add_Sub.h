#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.1 part II
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//	add and subtract
//----------------------------------------------------------
using namespace std;

void display(int a0, int b0, int c0, char s0[]) {
	cout << "\t" << dec << a0 << s0 << b0 << " = " << c0 << endl;
}
void addition(int d, int e ){
	int c;
	_asm {
		mov eax, d; place d into eax
		add eax, e; place eax + e into eax
		mov c, eax; place eax into c
	}
	display(d, e, c, " + ");
}
void subtraction(int d, int e) {
	int c;
	_asm {
		//compute c = a-b
		mov ebx, d //place a into eax
		sub ebx, e //place ebx-b into ebx
		mov c, ebx //place ebx into c
	}
	display(d, e, c, " - ");
}
void aNegative(int d, int e) {
	int c;
	_asm {
		//compute c = -a + b
		mov eax, d
		neg eax //convert eax into a negetive number
		mov d, eax //place -eax into a
		add eax, e //place -eax + b into eax
		mov c, eax
	}
	display(d, e, c, " + ");
}
void NegAsubtractB(int d, int e) {
	int c;
	_asm {
		//compute c = -a - b
		mov eax, d
		neg eax //convert eax into a negetive number
		mov d, eax //place -eax into a
		sub eax, e //place -eax + b into eax
		mov c, eax
	}
	display(d, e, c, " - ");
}

void add_sub() {
	int a, b;
	system("cls");
	cout << "---------- Addition and Subtraction ----------\n";
	_asm {
		mov a, 12; // set a to 12
		mov b, 15; // set b to 15
	}
	cout << "a = 12\tb = 15\n";
	addition(a, b);
	subtraction(a, b);
	aNegative(a, b);
	NegAsubtractB(a, b);
	
	bool again;
	do {
		again = false;
		cout << "Enter two positive integers (i.e.: 1 3 ): ";
		if (!(cin >> a >> b)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Sorry I didn't recognize that.\n";
			again = true;
		}
	} while (again);
	addition(a, b);
	subtraction(a, b);
	aNegative(a, b);
	NegAsubtractB(a, b);

	system("pause");
}
/*-------------------------------------------------------
---------- Addition and Subtraction ----------
a = 12  b = 15
        12 + 15 = 27
        12 - 15 = -3
        -12 + 15 = 3
        -12 - 15 = -27
Enter two positive integers (i.e.: 1 3 ): 65 84
        65 + 84 = 149
        65 - 84 = -19
        -65 + 84 = 19
        -65 - 84 = -149
Press any key to continue . . .
---------------------------------------------------------*/