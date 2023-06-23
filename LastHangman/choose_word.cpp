#include "choose_word.h"
#include<string>
string chooseWord(int x) {
	cout << "Pick a topic: " << endl
		<< "1.Vehicle" << endl
		<< "2. Music" << endl
		<< "3. Sport" << endl
		<< "4. Appliance" << endl;
	int a;
	cin >> a;
	system("cls");
	vector <string> lib;
	vector<string> lib_def;
	string link, link_def;
	switch (a)
	{
	case 1:
		link = "vehicle.txt";
		link_def = "vehicle_def.txt";
		break;
	case 2:
		link = "music.txt";
		link_def = "music_def.txt";
		break;
	case 3:
		link = "sport.txt";
		link_def = "sport_def.txt";
		break;
	case 4:
		link = "appliance.txt";
		link_def = "appliance_def.txt";
		break;
	}
	fstream file(link);

	while (!file.eof()) {
		string s;
		file >> s;
		lib.push_back(s);
	}
	file.close();
	fstream file_def(link_def);
	while (!file_def.eof()) {
		string s;
		getline(file_def, s);
		lib_def.push_back(s);
	}
	cout << lib_def[x % lib_def.size()];
	return lib[x % lib.size()];
}