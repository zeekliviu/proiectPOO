#include <iostream>
#include "biletLoja.h"
biletLoja::biletLoja()
{
	id = nullptr;
}
biletLoja::biletLoja(char* id)
{
	if (id != nullptr && strlen(id) > 0)
	{
		this->id = new char[strlen(id) + 1];
		strcpy_s(this->id, strlen(id) + 1, id);
	}
	else
		this->id = nullptr;
}
char* biletLoja::getId()
{
	return id;
}
void biletLoja::setId(const char* s)
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