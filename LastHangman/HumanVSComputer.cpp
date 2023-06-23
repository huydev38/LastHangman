#include "HumanVSComputer.h"
#include <chrono>
#include <thread>
int Timer;
struct Player
{
	string name;
	int score;
	int guessTime;
	void print() {
		cout << setw(20) << left << name << setw(10) << left << score << setw(10) << left << guessTime;
	}
};
vector<Player> playerList;
void displayRankingBoard() {
	cout << setw(20) << left << "NAME" << setw(10) << left << "SCORE" << setw(10) << left << "GUESS TIME" << endl;
	ifstream file("result.txt");
	while (!file.eof()) {
		Player c;
		string tmpName;
		int tmpscore;
		int tmpguessTime;
		getline(file, tmpName, ',');
		file >> tmpscore;
		file.seekg(1, 1);
		file >> tmpguessTime;
		c.name = tmpName;
		c.score = tmpscore;
		c.guessTime = tmpguessTime;
		playerList.push_back(c);
	}
	file.close();
	for (int i = 0; i < playerList.size(); i++) {
		for (int j = i + 1; j < playerList.size(); j++) {
			if (playerList[i].score < playerList[j].score) {
				Player tmp;
				tmp = playerList[i];
				playerList[i] = playerList[j];
				playerList[j] = tmp;
			}
		}
	}
	for (int i = 0; i < playerList.size(); i++) {
		cout << setw(10) << i + 1;
		playerList[i].print();
		cout << endl;
	}
}
char getPlayerGuess() {
	cout << "Please insert your word: ";
	char h;
	cin >> h;
	h = tolower(h);
	return h;
}
void hint(const string& guessWord, const string& word) {
	for (int i = 0; i < guessWord.length(); i++) {
		if (guessWord[i] == '-') {
			cout << "Next character: " << word[i] << endl;
			break;
		}
	}
}
bool isNearly(char h, string const& word, string const& guessWord) {
	for (int i = 0; i < word.length(); i++) {
		if ((word[i] + 2 == h || word[i] - 2 == h || word[i] + 1 == h || word[i] - 1 == h) && guessWord[i] == '-') {
			cout << "CLOSE!!!" << endl;
			return true;
		}
	}
	return false;
}
void checkGuessWord(char h, int n, int& wrongGuessCount, string& guessWord, string& wrongGuess, string const word, int& score) {
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (h == word[i] && guessWord[i] == '-') {
			check = true;
			guessWord[i] = h;
		}
	}
	if (check == true) {
		score += 5;
	}
	if (check == false) {
		score -= 5;
		wrongGuessCount++;
		wrongGuess += h;
	}
}
void print(int wrongGuessCount, string guessWord, string wrongGuess, int n, const int& score, const int& Timer) {
	system("cls");
	cout << "SCORE: " << score << "                            " << "remaining time: " << Timer << endl;
	cout << ">>>>>>>>";
	for (int i = 0; i < n; i++) {
		cout << guessWord[i];
	}
	cout << "<<<<<<<<<";
	cout << endl;
	cout << "Wrong Word: ";
	for (int j = 0; j < wrongGuessCount; j++) {
		cout << wrongGuess[j] << " ";
	}
	cout << endl;
	cout << "SCORE: " << score << endl;
	printPicture(wrongGuessCount);
	cout << endl;
}
int magicNumber() {
	srand(time(NULL));
	return rand();
}

void StartTimer() {
	while (Timer > 0) {
		this_thread::sleep_for(chrono::milliseconds(1000));
		Timer--;
	}
}
void HumanVSComputer() {
	
	Player one;
	string Name;
	cout << "What is your name: ";
	cin >> Name;
	cout << endl;
	one.name = Name;
	int x;
	cout << "Choose mode: " << endl;
	cout << "1. Easy" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Hard" << endl;
	cin >> x;
	if (x == 1) {
		Timer = 90;
	}
	else if (x == 2) {
		Timer = 60;
	}
	else {
		Timer = 45;
	}
	int guessTime = Timer;
	int tmp = Timer;
	thread task(StartTimer);
	task.detach();
	system("cls");
	cout << " ------------- \n"
		" | \n"
		" | \n"
		" | \n"
		" | \n"
		" | \n"
		" ----- \n";
	string word = chooseWord(magicNumber());
	int n = word.size();
	cout << endl;
	cout << "The word has " << n << " characters!" << endl;
	for (int i = 0; i < n; i++) {
		cout << "- ";
	}
	cout << endl;
	int wrongGuessCount = 0;
	string guessWord = "";
	for (int i = 0; i < n; i++) {
		guessWord += "-";
	}
	string wrongGuess = "";
	int score = 100;
	bool won;

	do {
		cout << "Press '?' for hint" << endl;
		cout << "Press '!' to answer the whole word" << endl;
		char z = getPlayerGuess();
		if (z == '?') {
			system("cls");
			hint(guessWord, word);
			score -= 5;
			cout << "SCORE: " << score << endl;
		}
		else if (z == '!') {
			cout << "Your answer is: ";
			string tmp;
			cin >> tmp;
			if (tmp == word) {
				guessWord = word;
				won = true;
				score += 20;
				break;
			}
			else {
				cout << "Incorrect" << endl;
				score -= 5;
				cout << "SCORE: " << score << endl;
			}
		}
		else {
			checkGuessWord(z, n, wrongGuessCount, guessWord, wrongGuess, word, score);//ki?m tra xem có không, n?u có thay vào v? trí guessWord,n?u không + bi?n d?m và thêm vào wrongGuess;
			print(wrongGuessCount, guessWord, wrongGuess, n, score, Timer);
			isNearly(z, word, guessWord);
		}//in ra guessWord hi?n t?i,in ra wrongGuessCount, wrongGuess;
		guessTime = tmp - Timer;

	} while (wrongGuessCount < 7 && guessWord != word && Timer > 0);

	if (guessWord == word) {
		won = true;
		one.guessTime = guessTime;
		one.score = score;
		fstream fileout;
		fileout.open("result.txt", ios::out | ios::app);
		fileout << '\n';
		fileout << one.name << ',' << one.score << ',' << one.guessTime;
		fileout.close();
	}
	else {
		won = false;
	}
	displayFinalMan(won, word, score, guessTime);
	char t;
	cout << "Press 'r' to see ranking board, 'e' to skip" << endl;
	cin >> t;
	system("cls");
	while (t == 'r') {
		displayRankingBoard();
		cout << "Press 'e' to exit" << endl;
		cin >> t;
		t = tolower(t);
		system("cls");
	}
}