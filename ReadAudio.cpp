// cpp file for reading and interpreting audio signals from .wav/.mp3 files

#include"ReadAudio.h"
#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

void openFile (string fileName) {
	ifstream file;
	file.open(fileName, ios::in);
	if (file.good()) {
		char * buf = new char[1024];
		while (!file.eof()) {
			file.read(buf, 1024);
			cout << buf << endl;
		}
		delete[] buf;
	}
}