#ifndef PROGRAM_H
#define PROGRAM_H

#include "GroupClass.h"
#include <stdlib.h>

void Base() {
	vector<group> data = { group("h", "hollow knight", ""), group("m", "minecraft", "") };

	string type;
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
		if (data.size() == 0)
		{
			cout << "no current data, try creating some first" << endl << "rebooting" << endl << endl;
			return;
		}

		string keyG;
		int keyGN;
		while (true)
		{
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
			cin >> keyG;

			if (cin.fail() || find(keys.begin(), keys.end(), keyG) == keys.end())
			{
				cout << "Err : please enter a valid input" << endl << endl;
			}
			else
			{
				keyGN = find(keys.begin(), keys.end(), keyG) - keys.begin();
				break;
			}
		}

		if (data.at(keyGN).Load.size() == 0)
		{
			cout << "no current data, try creating some first" << endl << "rebooting" << endl << endl;
			return;
		}

		string keyI;
		int keyIN;
		while (true)
		{
			vector<string> keys(data.size());
			for (int i = 0; i < data.size(); i++)
			{
				keys.at(i) = data.at(keyGN).Load.at(i).Key;
			}

			cout << "which group are you loading?" << endl;
			for (int i = 0; i < data.size(); i++)
			{
				cout << "-'" << data.at(keyGN).Load.at(i).Key << "' " << data.at(keyGN).Load.at(i).Name << endl;
			}

			cout << "   ";
			cin >> keyI;

			if (cin.fail() || find(keys.begin(), keys.end(), keyI) == keys.end())
			{
				cout << "Err : please enter a valid input" << endl << endl;
			}
			else
			{
				keyIN = find(keys.begin(), keys.end(), keyI) - keys.begin();
				break;
			}
		}

		LoadItem(data.at(keyGN).Dump.Name, data.at(keyGN).Load.at(keyIN).Name, data.at(keyGN).Dump.Data);
	}
}

#endif PROGRAM_H
