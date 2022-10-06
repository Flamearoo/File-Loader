#ifndef PROGRAM_H
#define PROGRAM_H

#include "GroupClass.h"

void Base() {
	string type;
	vector<group> data = {group("h", "hollow knight", ""), group("m", "minecraft", "")};

	while (true)
	{
		cout << "would you like to create 'c', remove 'r' or load 'l'" << endl << "   ";
		cin >> type;

		if (cin.fail() || (type != "c" && type != "r" && type != "l"))
		{
			cout << "Err : please enter a valid input" << endl << endl;
		}
		else
		{
			break;
		}
	}
	if (type == "c")
	{

	}
	else if (type == "r")
	{

	}
	else if (type == "l")
	{
		while (true)
		{
			string key;

			vector<string> keys(data.size());
			for (int i = 0; i < data.size(); i++)
			{
				keys.at(i) = data.at(i).Dump.Key;
			}

			cout << "which group are you loading?" << endl;
			for (int i = 0; i < data.size(); i++)
			{
				cout << "-'" << data.at(i).Dump.Key << "' " << data.at(i).Dump.Name << endl;
			}

			cout << "   ";
			cin >> key;

			if (cin.fail() || find(keys.begin(), keys.end(), key) == keys.end())
			{
				cout << "Err : please enter a valid input" << endl << endl;
			}
			else
			{
				break;
			}
		}
	}
}

#endif PROGRAM_H
