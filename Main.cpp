#include <iostream>
#include "Program.h"
#include "StoreData.h"

using namespace std;

int main() {
	CreateLoc();

	vector<group> data = ReadData();

	while (true)
	{
		data = Base(data);
		WriteData(data);
	}
}