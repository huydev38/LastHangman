#include "printGame.h"
void printPicture(int wrongGuessCount) {
	string picture[] = { " ------------- \n"
" | | \n"
" | \n"
" | \n"
" | \n"
" | \n"
" ----- \n"," ------------- \n"
" | | \n"
" | O \n"
" | \n"
" | \n"
" | \n"
" ----- \n"," ------------- \n"
" | | \n"
" | O \n"
" | | \n"
" | \n"
" | \n"
" ----- \n"," ------------- \n"
" | | \n"
" | O \n"
" | /| \n"
" | \n"
" | \n"
" ----- \n"," ------------- \n"
" | | \n"
" | O \n"
" | /|\\ \n"
" | \n"
" | \n"
" ----- \n"," ------------- \n"
" | | \n"
" | O \n"
" | /|\\ \n"
" | / \n"
" | \n"
" ----- \n"," ------------- \n"
" | | \n"
" | O \n"
" | /|\\ \n"
" | / \\ \n"
" | \n"
" ----- \n",




	};
	if (wrongGuessCount == 0) {
		cout << " ------------- \n"
			" | \n"
			" | \n"
			" | \n"
			" | \n"
			" | \n"
			" ----- \n";
	}
	else {
		cout << picture[wrongGuessCount - 1] << endl;
	}
}