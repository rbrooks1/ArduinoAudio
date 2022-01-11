#ifndef _NAV_H_
#define _NAV_H_
//header file for nav.cpp
#include<string>
#include<vector>

extern "C" {
	void createChDirPath(std::string &directory, std::vector<std::string> &vec);
	void goToDir(std::string directory);
	void convToWSLPath(std::string &directory);
	void moveToNewFolder(std::vector<std::string> vec);
}

#endif