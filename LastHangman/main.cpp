#include "Header.h"
#include "choose_word.h"
#include "printGame.h"
#include "printFinal.h"
#include "ComputerVSHuman.h"
#include "printRankingBoard.h"
#include "HumanVSComputer.h"


void start() {
	cout << "Pick a mode: " << endl;
	cout << "1. Human vs Computer" << endl;
	cout << "2. Computer vs Human" << endl;
	int a;
	cin >> a;
	system("cls");
	
	if (a == 1) {
		HumanVSComputer();
	}
	else {
		ComputerVSHuman();
	}
}
int main() {

	cout << "HELLO!" << endl;
	cout << "PRESS y to play!" << endl;
	char x;
	cin >> x;
	x = tolower(x);
	while (x == 'y') {
		start();
		x = 'n';
		cout << "Wanna play again?" << endl;
		cout << "y/n" << endl;
		cin >> x;
		x = tolower(x);
		if (x == 'y') {
			system("cls");
		}
	}
	return 0;
}