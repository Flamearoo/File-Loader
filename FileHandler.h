#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <direct.h>
#include "shlobj.h"
#include <filesystem>

using namespace std;

void CopyRecursive(const filesystem::path& src, const filesystem::path& target) noexcept
{
	try
	{
		filesystem::copy(src, target, filesystem::copy_options::overwrite_existing | filesystem::copy_options::recursive);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

int CreateLoc() {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");
	string folder = "\\File Loader\\";
	string path = appdata + folder;
	_mkdir(path.c_str());

	return -1;
}

int CreateFolder(string dir) {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");
	string folder = "\\File Loader\\";
	string path = appdata + folder + dir;
	_mkdir(path.c_str());

	return -1;
}

int CreateItem(string group, string name, string data) {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");

	CreateFolder(group + string("\\"));
	CreateFolder(group + string("\\") + name + string("\\"));

	CopyRecursive(data, appdata + string("\\File Loader\\") + group + string("\\") + name + string("\\"));

	return -1;
}

int RemoveItem(string group, string name) {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");

	filesystem::remove_all(appdata + string("\\File Loader\\") + group + string("\\") + name + string("\\"));
	return -1;
}

int CreateGroup(string group) {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");

	CreateFolder(group + string("\\"));

	return -1;
}

int RemoveGroup(string group) {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");

	filesystem::remove_all(appdata + string("\\File Loader\\") + group + string("\\"));

	return -1;
}

int LoadItem(string group, string name, string dump) {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");

	CopyRecursive(appdata + string("\\File Loader\\") + group + string("\\") + name + string("\\"), dump);

	return -1;
}
#endif FILEHANDLER_H