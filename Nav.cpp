// navigation of file structure to access audio files

#include"Nav.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<dirent.h>

using namespace std;

void convToWSLPath(string &directory) {
	string start = "/mnt/c/users/";
	string sub = directory.substr(9, string::npos);

	directory = start + sub;	
}

void goToDir(string directory) {
	struct dirent *dp;
	cout << directory << endl;
	convToWSLPath(directory);
	cout << directory << endl;
	DIR *d = opendir(directory.c_str());

	while (dp = readdir(d)) {
		cout << dp << endl;
	}

	closedir(d);
}