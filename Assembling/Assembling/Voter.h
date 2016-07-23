#pragma once
//----------------------------------------------------------
//		Name		Candelario Eguia
//		Course		CMPS-371
//		Project		No.1 part III
//		Due date	June 26, 2016
//		Professor	Ray Ahmadnia
//
//   This program displays:
//	Count votes
//----------------------------------------------------------

//declare identifiers
short YesCount = 0, NoCount = 0, invalid = 0;
char vote;

void AskForVotes() {
	system("cls");
	cout << "------------------ VOTE COUNTER ------------------\n\n";
	cout << "Enter a string of votes: ";
}

void readVote() { cin.get(vote); }

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
/*--------------------------------Output-----------------------------------------
------------------ VOTE COUNTER ------------------

Enter a string of votes: yNYnfED

YES votes total: 2
NO votes total: 2

Invalid votes totled: 3
Press any key to continue . . .
-------------------------------------------------------------------------------*/