// navigation of file structure to access audio files

#include"Nav.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
#include<unistd.h>
#include<vector>
#include<cctype>

using namespace std;

void moveToNewFolder(vector<string> vec) {
	for (string s : vec) {
		chdir(s.c_str());
	}
}

void createChDirPath(string &directory, vector<string> &vec) {
	char buffer[1000];
	getcwd(buffer, 1000);

	string commonRoot(buffer);

	// find common root
	int pos, count = 0;
	while (directory.find(commonRoot) == string::npos) {
		pos = commonRoot.find_last_of("/");
		commonRoot = commonRoot.substr(0, pos);
		vec.push_back("../");
		count++;
	}

	// add commands to move to new folder
	string afterRoot = directory.substr(commonRoot.length(), string::npos);
	while(!afterRoot.empty()) {
		pos = afterRoot.find_last_of("/");
		vec.push_back(afterRoot.substr(pos + 1, string::npos));
		afterRoot = afterRoot.substr(0, pos);
	}

	reverse(vec.begin() + count, vec.end());
}

void convToWSLPath(string &directory) {
	string start = "/mnt/" + directory.substr(0, 1) + "/";
	start[5] = tolower(start[5]);
	string sub = directory.substr(3, string::npos);

	directory = start + sub;
	replace(directory.begin(), directory.end(), '\\', '/');
}

void goToDir(string directory) {
	convToWSLPath(directory);

	vector<string> vec;
	createChDirPath(directory, vec);

	moveToNewFolder(vec);
}