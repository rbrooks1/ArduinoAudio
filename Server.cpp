// server side of project

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include"Nav.h"
#include"ReadAudio.h"

using namespace std;

void findMp3 (vector<string> &files) {
	system("ls > lspipe.txt");
	ifstream file;
	file.open("lspipe.txt", fstream::in);
	
	string fileName;
	while (getline(file, fileName)) {
		if (fileName.find(".mp3") != string::npos) {
			files.push_back(fileName);
		}
	}

	file.close();

}

int main() {
	string dir;

	cout << "input directory for audio: ";
	getline(cin, dir);

	goToDir(dir);

	// find mp3 files to play on arduino
	vector<string> files;
	system("touch lspipe.txt");
	findMp3(files);
	remove("lspipe.txt");

	return 0;
}