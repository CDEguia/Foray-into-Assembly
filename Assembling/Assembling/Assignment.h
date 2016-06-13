#pragma once
using namespace std;

void assignment() {
	system("cls");
	char c; //1 byte
	short s; //2 bytes
	int I; //4 bytes
	_asm {
		mov c, 'a'; assign 'a' to variable c
		mov s, 123; assign s = 123
		mov I, 997; assign I = 997
	}
	cout << "Values can assigned with 'mov' in a variaty of ways.\n";
	cout << "\tnote: ; is used to insert comments in _asm{} code.\n";
	cout << "mov c, 'a' ;assign's c = 'a'\n";
	cout << "c= " << c << "\n\n"; //a
	cout << "mov s, 123; assign s = 123\n";
	cout << "s= " << s << "\n\n"; //123
	cout << "mov I, 997; assign I = 997\n";
	cout << "i= " << I << "\n\n"; //123

	cout << "The following uses cout << oct & hex to change how I is displayed.\n";
	cout << "i= " << oct << I << endl; //this prints the value in base 8
	cout << "i= " << hex << I << endl; //this prints the value in base 16

									   //Or assign it like this:
									   //char c;
									   //short s;
	int i;
	_asm {
		mov c, 'a'
		mov s, 0x7b //hex 123 base 10
		mov i, 00000000000000000000000001111011b //binary 123 base 10

	}
	cout << "c= " << c << endl;
	cout << "mov s, 0x7b; uses hexadecimal to assign 123 into s\n";
	cout << "s= " << s << endl;
	cout << "cout << dec will display s in decimal format:\n";
	cout << "s= dec " << dec << s << "or oct " << oct << s << endl;
	//cout << "s= " << oct << s << endl;
	cout << "i= " << dec << i << endl;
	cout << "i= " << oct << i << " at base 8" << endl;
	cout << "i= " << hex << i << " at base 16" << endl;
	cout << "\tnote: any output following the use of dec, hex, or oct will continue to\n";
	cout << "\tprint in the last used format.\n\n";
	system("Pause");
	
}