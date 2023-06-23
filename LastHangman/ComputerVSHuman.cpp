#include "ComputerVSHuman.h"

char getMostFreWord(vector<string>& wordList,vector<char> remainingChars) { //lay tu co tan suat cao nhat tu wordlist, bo nhung tu khong co trong remainingChars;
	char h;
	int max = 0;
	for (int i = remainingChars.size() - 1; i >= 0; i--) {
		int  count = 0;
		for (int j = 0; j < wordList.size(); j++) {
			if (wordList[j].find(remainingChars[i])!=std::string::npos) {
				count++;
			}
		}
		if (count >= max) {
			max = count;
			h = remainingChars[i];
		}
	}
	return h;
}
int getUserWordLength() {
	cout << "Please tell me your word's length: " << endl;
	int x;
	cin >> x;
	return x;
}
void initialize(int& wordLength, string &secretWord, int &incorrectGuessCount, vector <char> &previousGuesses) {
	wordLength = getUserWordLength();
	for (int i = 0; i < wordLength; i++) {
		secretWord += "_";
	}
	incorrectGuessCount = 0;
}

void render(int& incorrectGuessCount, vector<char>& previousGuesses, string secretWord) {
	system("cls");
	printPicture(incorrectGuessCount);
	cout << endl;
	cout << "Guessed Words: ";
	for (int i = 0; i < previousGuesses.size(); i++) {
		cout << previousGuesses[i] << " ";
	}
	cout << endl;
	cout << "SecretWord is: ";
	for (int i = 0; i < secretWord.length(); i++) {
		cout << secretWord[i] << " ";
	}
	cout << endl;
}

string getUserAnswer(char guess,int wordLength) {
	string answer;
	cout << endl << "I guess " << guess << ", please enter your mask: ";
	do {
		cin >> answer;
		if (answer.length() != wordLength) {
			cout << "Inappropriate answer,please try again " << endl;
		}
	} while (answer.length() != wordLength);
	transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	return answer;
}
bool isWon(string secretWord) {
	for (int i = 0; i < secretWord.length(); i++) {
		if (secretWord[i] == '_') {
			return false;
		}
	}
	return true;
}
void update(char guess, string& mask, int& incorrectGuessCount,vector<char>&previousGuesses, string &secretWord, vector<string>& wordList, vector<char> &remainingChars,bool &stop) {
	previousGuesses.push_back(guess);
	for (int i = 0; i < remainingChars.size(); i++) {
		if (guess == remainingChars[i]) {
			remainingChars.erase(remainingChars.begin() + i);
			break;
		}
	}
	if (mask == secretWord) {
		incorrectGuessCount++;
		for (int i = 0; i < wordList.size(); i++) {
			for (int j = 0; j < wordList[i].length(); j++) {
				if (wordList[i][j] == guess) {
					wordList.erase(wordList.begin() + i);
					break;
				}
			}
		}
	}
	else {
		secretWord = mask;
		for (int i = 0; i < secretWord.length(); i++) {
			if (secretWord[i] != '_') {
				for (int j = 0; j < wordList.size(); j++) {
					if (wordList[j][i] != secretWord[i]) {
						wordList.erase(wordList.begin() + j);
						j--;
					}
				}
			}
		}
	}
	if (isWon(secretWord)) {
		stop = true;
	}
}
bool isAllDash(string secretWord) {
	for (int i = 0; i < secretWord.length(); i++) {
		if (secretWord[i] != '_') {
			return false;
		}
	}
	return true;
}

char getNextGuess(vector <char>& previousGuess, string secretWord,vector<char> &remainingChars, vector<string>&wordList) {
	if (isAllDash(secretWord)) {
		return remainingChars[0];
	}
	else {
		return getMostFreWord(wordList,remainingChars);
	}
}
void ComputerVSHuman() {
	vector<char> remainingChars = { 'e','t','a','o','i','n','d','h','r','s','l','c','u','m','w','f','g','y','p','b','v','k','j','x','q','z' };
	vector<string> wordList;
	int	wordLength;
	string secretWord = "";
	int	incorrectGuessCount;
	vector<char> previousGuesses;
	bool won = false;
	bool stop = false;
	initialize(wordLength, secretWord, incorrectGuessCount, previousGuesses);
	ifstream file("dataAI.txt");
	while (!file.eof()) {
		string s;
		file >> s;
		if (s.length() == wordLength) {
			wordList.push_back(s);
		}
	}
	render(incorrectGuessCount, previousGuesses, secretWord);
	do {
		char guess = getNextGuess(previousGuesses, secretWord, remainingChars, wordList);
		cout << "My guess is: " << guess << endl;
		string	mask = getUserAnswer(guess,wordLength);
		update(guess, mask, incorrectGuessCount, previousGuesses, secretWord, wordList, remainingChars,stop);
		render(incorrectGuessCount, previousGuesses, secretWord);
	} while (incorrectGuessCount < 7 && stop!=true);
	if (isWon(secretWord)) {
		won = true;
	}
	else {
		won = false;
	}
	displayFinalManMode2(won,wordList);
}