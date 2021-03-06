#include "stdafx.h"
#include "FixedSizeRegister.h"

FixedSizeRegister::FixedSizeRegister()
{
	this->name = new char[30];
	this->job = new char[20];
}

FixedSizeRegister::~FixedSizeRegister()
{
	delete[] this->name;
	delete[] this->job;
	delete this->dataFile;
}

void FixedSizeRegister::printRegister()
{
	cout << "Id: " << this->id << endl;
	cout << "Name: " << this->name << endl;
	cout << "Job: " << this->job << endl;
	cout << "Salary: " << this->salary << endl;
}

char * FixedSizeRegister::toChar()
{
	const int size = this->getSize();
	char * data = new char[size];

	memcpy(data, reinterpret_cast<char*>(&this->id), sizeof(this->id));

	memcpy(data + sizeof(this->id), this->name, 30);

	memcpy(data + sizeof(this->id) + 30, reinterpret_cast<char*>(&this->salary), sizeof(this->salary));

	memcpy(data + sizeof(this->id) + 30 + sizeof(this->salary), this->job, 20);

	return data;
}

void FixedSizeRegister::fromChar(char * data)
{
	memcpy(&this->id, data, sizeof(this->id));

	memcpy(this->name, data + sizeof(this->id), 30);

	memcpy(&this->salary, data + sizeof(this->id) + 30, sizeof(this->salary));

	memcpy(this->job, data + sizeof(this->id) + 30 + sizeof(this->salary), 20);
}

void FixedSizeRegister::openFile(char * name)
{
	this->dataFile = new DataFile(name);
}

void FixedSizeRegister::writeIntoFile()
{
	this->dataFile->write(this->toChar(), this->getSize());
}

void FixedSizeRegister::readIntoFile(int position)
{
	char * data = this->dataFile->read(position, this->getSize());
	this->fromChar(data);
}

void FixedSizeRegister::closeFile()
{
	this->dataFile->close();
}

int FixedSizeRegister::getSize()
{
	return sizeof(this->id) + 30 + 20 + sizeof(this->salary);
}
