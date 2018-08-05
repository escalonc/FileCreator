// FileCreator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DataFile.h"
#include "FixedSizeRegister.h"

struct Item
{
	int id;
	char name[30];
};

char * serialize(int id, char name[30], double salary, char job[20])
{
	char * data = new char[sizeof(int) + 30 + 20 + sizeof(salary)];

	memcpy(data, reinterpret_cast<char*>(&id), sizeof(int));

	memcpy(data + sizeof(id), name, 30);

	memcpy(data + sizeof(id) + 30, reinterpret_cast<char*>(&salary), sizeof(salary));

	memcpy(data + sizeof(id) + 30 + sizeof(salary), job, 20);

	return data;
}

int main()
{
	/*string location = "products.bin";
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
	system("pause");*/

	string personName = "Christopher", jobType = "Developer";

	char name[30];
	char job[20];
	unsigned int id = 1;
	double salary = 2000;

	strcpy_s(name, 30, personName.c_str());
	strcpy_s(job, 20, jobType.c_str());

	FixedSizeRegister * fileRegister = new FixedSizeRegister();

	char * data = serialize(id, name, salary, job);

	fileRegister->fromChar(data);

    return 0;
}

