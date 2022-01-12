// server side of project

#include<iostream>
#include<stdio.h>
#include<string.h>
#include"Nav.h"
#include"ReadAudio.h"

using namespace std;

int main() {
	string dir;

	cout << "input directory for audio: ";
	getline(cin, dir);

	goToDir(dir);
	
	return 0;
}