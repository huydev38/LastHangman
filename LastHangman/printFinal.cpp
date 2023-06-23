#include "printFinal.h"
#include<vector>
const string& getNextHangMan()
{
    const static string figure[] = {
"   ------------+    \n"
          "   |          /     \n"
          "   |         O      \n"
          "   |        /|\\    \n"
          "   |        / \\    \n"
          "   |        \n"
          " -----      \n" ,
          "   ------------+     \n"
          "   |           |     \n"
          "   |           O     \n"
          "   |          /|\\   \n"
          "   |          / \\   \n"
          "   |        \n"
          " -----      \n",
          "   ------------+      \n"
          "   |            \\    \n"
          "   |            O     \n"
          "   |           /|\\   \n"
          "   |           / \\   \n"
          "   |      \n"
          " -----    \n",
          "   ------------+     \n"
          "   |           |     \n"
          "   |           O     \n"
          "   |          /|\\   \n"
          "   |          / \\   \n"
          "   |        \n"
          " -----      \n",
    };
    const int sumofFigure = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % sumofFigure];
}
const string& getNextDancingMan()
{
    const static string figure[] = {
          "     O     \n"
          "    /|\\   \n"
          "    | |    \n",
          "     O     \n"
          "    /|\\   \n"
          "    / \\   \n",
          "   __O__   \n"
          "     |     \n"
          "    / \\   \n",
          "    \\O/   \n"
          "     |     \n"
          "    / \\   \n",
          "   __O__   \n"
          "     |     \n"
          "    / \\   \n",
          "     O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
          "    O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
          "     O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
          "      O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
          "     O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
    };
    const int sumofFigure = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % sumofFigure];
}


void displayFinalMan(bool won, string const& word, const int& score, const int& guessTime) {
    int i = 0;
    while (i < 20) {
        i++;
        if (won == true) {
            cout << getNextDancingMan() << endl;
            cout << "CONGRATULATION, YOU WIN" << endl;
            cout << "Your score: " << score << endl;
            cout << "Guess Time: " << guessTime << endl;
        }
        else {
            cout << getNextHangMan() << endl;
            cout << "GAME OVER! LOSER!" << endl;
            cout << "Correct Answer: " << word << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(500));
        system("cls");
    }
}

void displayFinalManMode2(bool won, vector<string>& wordList) {
    int i = 0;
    while (i < 20) {
        i++;
        if (won == true) {
            cout << getNextDancingMan() << endl;
            cout << "Haha Im win!!!" << endl;
        }
        else {
            cout << getNextHangMan() << endl;
            cout << "Im lose!!!" << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(500));
        system("cls");
    }
    if (won == false) {
        cout << "What is your word: " << endl;
        string s;
        cin >> s;
        bool check = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (s == wordList[i]) {
                check = true;
                break;
            }
        }
        if (check == false) {
            wordList.push_back(s);
        }
    }
}