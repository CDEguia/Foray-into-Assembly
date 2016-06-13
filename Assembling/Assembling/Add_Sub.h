#pragma once

void add_sub() {
	int a, b, c;
	system("cls");
	std::cout << "---------- Addition and Subtraction ----------\n";
	_asm {
		mov a, 12
		mov b, 17

		////compute c = a+b
		mov eax, a //place a into eax
		add eax, b //place eax+b into eax
		mov c, eax //place eax into c
	}

	std::cout << a << " + " << b << " = " << c << std::endl;

	_asm {
		//compute c = a-b
		mov ebx, a //place a into eax
		sub ebx, b //place ebx-b into ebx
		mov c, ebx //place ebx into c
	}
	std::cout << a << " - " << b << " = " << c << std::endl;

	_asm {
		//compute c = -a + b
		mov eax, a
		neg eax //convert eax into a negetive number
		mov a, eax //place -eax into a
		add eax, b //place -eax + b into eax
		mov c, eax
	}
	std::cout << a << " + " << b << " = " << c << std::endl;

	system("pause");
}