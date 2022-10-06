#ifndef GROUPCLASS_H
#define GROUPCLASS_H

#include "FileHandler.h"

using namespace std;

class load {
public:
	string Key;
	string Name;

	load(string KeyIn, string NameIn) {
		Key = KeyIn;
		Name = NameIn;
	}
	load() {}
};

class dump {
public:
	string Key;
	string Name;
	string Data;

	dump(string KeyIn, string NameIn, string DataIn) {
		Key = KeyIn;
		Name = NameIn;
		Data = DataIn;
	}
	dump() {}
};

class group {
public:
	dump Dump;
	vector<load> Load;

	group(string KeyIn, string NameIn, string DataIn) {
		Dump.Key = KeyIn;
		Dump.Name = NameIn;
		Dump.Data = DataIn;
	}
	group() {}

	void Add(string KeyIn, string NameIn) {
		load Out;
		Out.Key = KeyIn;
		Out.Name = NameIn;
		Load.push_back(Out);
	}

	int Remove(string KeyIn) {
		int place = -1;
		for (int i = 0; i < Load.size(); i++)
		{
			if (Load.at(i).Key == KeyIn)
			{
				place = i;
			}
		}

		if (place != -1)
		{
			Load.erase(Load.begin() + place);
		}

		return place;
	}
};

#endif GROUPCLASS_H