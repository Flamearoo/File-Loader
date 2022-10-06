#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <direct.h>
#include "shlobj.h"

using namespace std;

int CreateFolder() {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");
	string Folder = "\\File Loader\\";
	string path = appdata + Folder;
	_mkdir(path.c_str());
	return -1;
}

int CreateGroup() {
	return -1;
}

int CreateItem(string load, string dump, string name) {
	return -1;
}

int RemoveItem(string name) {
	return -1;
}
#endif FILEHANDLER_H