#ifndef _NAV_H_
#define _NAV_H_
//header file for nav.cpp
#include<string>

extern "C" {
	void goToDir(std::string directory);
	void convToWSLPath(std::string &directory);
}

#endif