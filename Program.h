#ifndef PROGRAM_H
#define PROGRAM_H

#include "GroupClass.h"
#include <stdlib.h>

vector<group> Base(vector<group> dataI) {
	vector<group> data = dataI;

	string type;
	while (true)
	{
		cout << "would you like to create 'c', remove 'r' or load 'l'?" << endl << "   ";
		getline(cin, type);

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
		while (true)
		{
			cout << "would you like to create a group 'g' or an item 'i'" << endl << "   ";
			getline(cin, type);

			if (cin.fail() || (type != "g" && type != "i"))
			{
				cout << "Err : please enter a valid input" << endl << endl;
			}
			else
			{
				break;
			}
		}

		if (type == "g")
		{
			vector<string> names(data.size());
			for (int i = 0; i < data.size(); i++)
			{
				names.at(i) = data.at(i).Dump.Name;
			}
			vector<string> keys(data.size());
			for (int i = 0; i < data.size(); i++)
			{
				keys.at(i) = data.at(i).Dump.Key;
			}

			string nameG;
			string keyG;
			string dirG;
			while (true)
			{
				cout << "what would you like to call the group?" << endl << "   ";
				getline(cin, nameG);

				if (cin.fail() || find(names.begin(), names.end(), nameG) != names.end())
				{
					cout << "Err : please enter a valid input (group may already exist)" << endl << endl;
				}
				else
				{
					break;
				}
			}

			while (true)
			{
				cout << "what would you like the shortcut to be?" << endl << "   ";
				getline(cin, keyG);

				if (cin.fail() || find(keys.begin(), keys.end(), keyG) != keys.end())
				{
					cout << "Err : please enter a valid input (key may already exist)" << endl << endl;
				}
				else
				{
					break;
				}
			}

			while (true)
			{
				cout << "what is the directory of the program?" << endl << "   ";
				getline(cin, dirG);

				if (cin.fail())
				{
					cout << "Err : please enter a valid directory" << endl << endl;
				}
				else
				{
					break;
				}
			}

			CreateGroup(nameG);
			data.push_back(group(keyG, nameG, dirG));
		}
		else
		{
			string upload;
			string keyG;
			int keyGN;
			while (true)
			{
				vector<string> keys(data.size());
				for (int i = 0; i < data.size(); i++)
				{
					keys.at(i) = data.at(i).Dump.Key;
				}

				cout << "which group are you adding to?" << endl;
				for (int i = 0; i < data.size(); i++)
				{
					cout << "-'" << data.at(i).Dump.Key << "' " << data.at(i).Dump.Name << endl;
				}

				cout << "   ";
				getline(cin, keyG);

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

			vector<string> names(data.at(keyGN).Load.size());
			for (int i = 0; i < data.at(keyGN).Load.size(); i++)
			{
				names.at(i) = data.at(keyGN).Load.at(i).Name;
			}

			vector<string> keys(data.at(keyGN).Load.size());
			for (int i = 0; i < data.at(keyGN).Load.size(); i++)
			{
				keys.at(i) = data.at(keyGN).Load.at(i).Key;
			}

			string nameI;
			string keyI;
			while (true)
			{
				cout << "what would you like to call the item?" << endl << "   ";
				getline(cin, nameI);

				if (cin.fail() || find(names.begin(), names.end(), nameI) != names.end())
				{
					cout << "Err : please enter a valid input (item may already exist)" << endl << endl;
				}
				else
				{
					break;
				}
			}

			while (true)
			{
				cout << "what would you like the shortcut to be?" << endl << "   ";
				getline(cin, keyI);

				if (cin.fail() || find(keys.begin(), keys.end(), keyI) != keys.end())
				{
					cout << "Err : please enter a valid input (key may already exist)" << endl << endl;
				}
				else
				{
					break;
				}
			}

			while (true)
			{
				cout << "would you like to upload 'u' or import current item 'i'?" << endl << "   ";
				getline(cin, upload);

				if (cin.fail() || (upload != "u" && upload != "i"))
				{
					cout << "Err : please enter a valid input" << endl << endl;
				}
				else
				{
					break;
				}
			}

			if (upload == "u")
			{
				string dir;
				while (true)
				{
					cout << "where would you like to import from?" << endl << "   ";
					getline(cin, dir);

					if (cin.fail())
					{
						cout << "Err : please enter a valid directory" << endl << endl;
					}
					else
					{
						break;
					}
				}

				CreateItem(data.at(keyGN).Dump.Name, nameI, dir);
				data.at(keyGN).Load.push_back(load(keyI, nameI));
			}
			else
			{
				CreateItem(data.at(keyGN).Dump.Name, nameI, data.at(keyGN).Dump.Data);
				data.at(keyGN).Load.push_back(load(keyI, nameI));
			}
		}
	}
	else if (type == "r")
	{
		if (data.size() == 0)
		{
			cout << "no current data, try creating some first" << endl << "rebooting" << endl << endl;
			return data;
		}

		while (true)
		{
			cout << "would you like to remove a group 'g' or an item 'i'";
			getline(cin, type);

			if (cin.fail() || (type != "g" && type != "i"))
			{
				cout << "Err : please enter a valid input" << endl << endl;
			}
			else
			{
				break;
			}
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

			cout << "which group are you removing?" << endl;
			for (int i = 0; i < data.size(); i++)
			{
				cout << "-'" << data.at(i).Dump.Key << "' " << data.at(i).Dump.Name << endl;
			}

			cout << "   ";
			getline(cin, keyG);

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

		if (type == "g")
		{
			RemoveGroup(keyG);
			data.erase(data.begin() + keyGN);
		}
		else
		{

			if (data.at(keyGN).Load.size() == 0)
			{
				cout << "no current data, try creating some first" << endl << "rebooting" << endl << endl;
				return data;
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

				cout << "which item are you removing?" << endl;
				for (int i = 0; i < data.size(); i++)
				{
					cout << "-'" << data.at(keyGN).Load.at(i).Key << "' " << data.at(keyGN).Load.at(i).Name << endl;
				}

				cout << "   ";
				getline(cin, keyI);

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

			RemoveItem(keyG, keyI);
			data.at(keyGN).Load.erase(data.at(keyGN).Load.begin() + keyIN);
		}
	}
	else if (type == "l")
	{
		if (data.size() == 0)
		{
			cout << "no current data, try creating some first" << endl << "rebooting" << endl << endl;
			return data;
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
			getline(cin, keyG);

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
			return data;
		}

		string keyI;
		int keyIN;
		while (true)
		{
			vector<string> keys(data.at(keyGN).Load.size());
			for (int i = 0; i < data.at(keyGN).Load.size(); i++)
			{
				keys.at(i) = data.at(keyGN).Load.at(i).Key;
			}

			cout << "which item are you loading?" << endl;
			for (int i = 0; i < data.at(keyGN).Load.size(); i++)
			{
				cout << "-'" << data.at(keyGN).Load.at(i).Key << "' " << data.at(keyGN).Load.at(i).Name << endl;
			}

			cout << "   ";
			getline(cin, keyI);

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

	return data;
}

#endif PROGRAM_H
