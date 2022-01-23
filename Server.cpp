// server side of project

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include"Nav.h"
#include"ReadAudio.h"

using namespace std;

void findMp3 (vector<string> &files) {
	char buffer[1000];
	if (auto dir = opendir(getcwd(buffer, 1000))) {
		while (auto f = readdir(dir)) {
			if (string(f->d_name).find(".mp3") != string::npos) {
				files.push_back(f->d_name);
			}
		}

		closedir(dir);
	}
}

int main() {
	string dir;

	cout << "input directory for audio: ";
	getline(cin, dir);

	goToDir(dir);

	// find mp3 files to play on arduino
	vector<string> files;
	findMp3(files);

	return 0;
}