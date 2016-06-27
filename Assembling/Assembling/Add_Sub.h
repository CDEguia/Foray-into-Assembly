#pragma once
using namespace std;

void display(int a0, int b0, int c0, char s0[]) {
	cout << dec << a0 << s0 << b0 << " = " << c0 << endl;
}

void add_sub() {
	int a, b, c, d, e;
	system("cls");
	cout << "---------- Addition and Subtraction ----------\n";
	_asm {
		mov a, 12
		mov b, 15

		; compute c = a + b
		mov eax, a; place a into eax
		add eax, b; place eax + b into eax
		mov c, eax; place eax into c
	}
	cout << "_asm\t\tcomment\n";
	cout << "mov a, 12\t; a = 12\n";
	cout << "mov eax, a\t; eax = the contents of: a\n";
	cout << "add eax, b\t; eax = eax + b\n";
	cout << "mov c, eax\t; c = the contents of: eax" << endl;
	display(a, b, c, " + ");

	//cout << "Enter two positive integers (i.e.: 1 3 ): ";
	//cin >> d >> e;
	bool again;
	do {
		again = false;
		cout << "Enter two positive integers (i.e.: 1 3 ): ";
		if (!(cin >> d >> e)) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Sorry I didn't recognize that.\n";
			again = true;
		}
	} while (again);
	
	_asm {
		mov eax, d; place d into eax
		add eax, e; place eax + e into eax
		mov c, eax; place eax into c
	}
	display(d, e, c, " + ");

	_asm {
		//compute c = a-b
		mov ebx, a //place a into eax
		sub ebx, b //place ebx-b into ebx
		mov c, ebx //place ebx into c
	}
	display(a, b, c, " - ");

	_asm {
		//compute c = -a + b
		mov eax, a
		neg eax //convert eax into a negetive number
		mov a, eax //place -eax into a
		add eax, b //place -eax + b into eax
		mov c, eax
	}
	display(a, b, c, " + ");

	_asm {
		//compute c = -a - b
		mov eax, a
		neg eax //convert eax into a negetive number
		mov a, eax //place -eax into a
		sub eax, b //place -eax + b into eax
		mov c, eax
	}
	display(a, b, c, " - ");

	system("pause");
}