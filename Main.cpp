#include <iostream>
#include "Program.h"

using namespace std;

vector<group> data;

int main() {
	CreateLoc();

	fstream data_in;
	data_in.open("class_data", ios::in | ios::out | ios::binary);

	data_in.close();

	while (true)
	{
		Base(data);
	}

	fstream data_out;
	data_out.open("class_data", ios::in | ios::out | ios::binary);

	data_out.close();
}