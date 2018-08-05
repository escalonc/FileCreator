// FileCreator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DataFile.h"

struct Item
{
	int id;
	char name[30];
};

int main()
{
	string location = "products.bin";
	char path[30];
	strcpy_s(path, 30, location.c_str());

	DataFile *dataFile = new DataFile(path);

	Item item, *product = new Item();

	item.id = 1;

	strcpy_s(item.name, 30, (char*)"Product 1");

	dataFile->write(reinterpret_cast<char*>(&item), 0, sizeof(Item));

	product = reinterpret_cast<Item*>(dataFile->read(0, sizeof(Item)));

	cout << product->id << endl;
	cout << product->name << endl;
	dataFile->close();
	//system("pause");

    return 0;
}

