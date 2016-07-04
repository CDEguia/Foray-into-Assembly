#pragma once

using namespace std;

//declare identifiers
short YesCount = 0, NoCount = 0, invalid = 0;
char vote;

void AskForVotes() {
	system("cls");
	cout << "------------------ VOTE COUNTER ------------------\n\n";
	cout << "Enter a string of votes: ";
}
void readVote() {
	cin.get(vote);
}
void displayVotes()
{
	cout << "\nYES votes total: " << YesCount << endl;
	cout << "NO votes total: " << NoCount << endl;
	cout << "\nInvalid votes totled: " << invalid << endl;
}
void voter() {
	cin.ignore();
	_asm {
		call AskForVotes

		whileLoop:
			
			call readVote;
			
			cmp vote, '\n';
			Je outVotes;

			cmp vote, 'y';
			Je incYes;

			cmp vote, 'Y';
			Je incYes;
			
			cmp vote, 'n';
			Je incNo;

			cmp vote, 'N';
			Je incNo;
			
			inc invalid;
			jmp cont;

			incNo:
				inc NoCount;
				jmp cont;

			incYes:
				inc YesCount;

			cont:
				jmp whileLoop;
		
		outVotes:
			call displayVotes
	}
	system("pause");
}