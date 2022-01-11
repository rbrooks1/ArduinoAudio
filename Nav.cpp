// navigation of file structure to access audio files

#include"Nav.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<unistd.h>
#include<vector>

using namespace std;

void moveToNewFolder(vector<string> vec) {

}

void createChDirPath(string &directory, vector<string> &vec) {
	char buffer[1000];
	getcwd(buffer, 1000);
	
	string curPath = str(buffer);

	string commonRoot = "";

	// find common root
	while (tempNewDir == tempCurDir) {
		
	}
	
	// move curPath back to common root

	// move curPath to destination
}

void convToWSLPath(string &directory) {
	string start = "/mnt/c/users/";
	string sub = directory.substr(9, string::npos);

	directory = start + sub;	
}

void goToDir(string directory) {
	convToWSLPath(directory);

	vector<string> vec;
	createChDirPath(directory, vec);

	moveToNewFolder(vec);
}