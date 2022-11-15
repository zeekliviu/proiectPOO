#include <iostream>
#include "biletCategoria1.h"
biletCategoria1::biletCategoria1()
{
	id = nullptr;
}
biletCategoria1::biletCategoria1(char* id)
{
	if (id != nullptr && strlen(id) > 0)
	{
		this->id = new char[strlen(id) + 1];
		strcpy_s(this->id, strlen(id) + 1, id);
	}
	else
		this->id = nullptr;
}
char* biletCategoria1::getId()
{
	return id;
}
void biletCategoria1::setId(const char* s)
{
	if (id != nullptr)
		delete[] id;
	if (s != nullptr && strlen(s) > 0)
	{
		id = new char[strlen(s) + 1];
		strcpy_s(id, strlen(s) + 1, s);
	}
	else
		id = nullptr;
}