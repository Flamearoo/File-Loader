#ifndef STOREDATA_H
#define STOREDATA_H

#include "GroupClass.h"
#include <fstream>

vector<group> ReadData() {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");
	string folder = "\\File Loader\\";

	vector<group> data;

	ifstream data_f;
	data_f.open(appdata + folder + string("group_data.txt"));

	int i = 0;
	string g;
	while (true)
	{
		if (!getline(data_f, g) || g == "")
		{
			break;
		}

		data.push_back(group());

		data.at(i).Dump.Key = g;

		getline(data_f, g);
		data.at(i).Dump.Name = g;

		getline(data_f, g);
		data.at(i).Dump.Data = g;

		int j = 0;
		while (true)
		{
			if (!getline(data_f, g) || g == "")
			{
				break;
			}

			data.at(i).Load.push_back(load());

			data.at(i).Load.at(j).Key = g;

			getline(data_f, g);
			data.at(i).Load.at(j).Name = g;

			j++;
		}

		i++;
	}

	data_f.close();

	return data;
}

void WriteData(vector<group> data) {
	size_t sz = 0;
	char* appdata;
	_dupenv_s(&appdata, &sz, "APPDATA");
	string folder = "\\File Loader\\";

	ofstream data_f;
	data_f.open(appdata + folder + string("group_data.txt"));

	for (int i = 0; i < data.size(); i++)
	{
		data_f << data.at(i).Dump.Key << endl;
		data_f << data.at(i).Dump.Name << endl;
		data_f << data.at(i).Dump.Data << endl;

		for (int j = 0; j < data.at(i).Load.size(); j++)
		{
			data_f << data.at(i).Load.at(j).Key << endl;
			data_f << data.at(i).Load.at(j).Name << endl;
		}

		data_f << endl;
	}

	data_f.close();
}

#endif STOREDATA_H
