#include <iostream>
#include "biletCategoria2.h"
biletCategoria2::biletCategoria2()
{
	id = 0;
	numeSpectator = new char[strlen("O persoana") + 1];
	strcpy_s(numeSpectator, strlen("O persoana") + 1, "O persoana");
	UID = new int[log(1) + 1 + strlen(numeSpectator)];
	dimUID = log(1) + strlen(numeSpectator) + 1;
	UID[0] = 0;
	for (int i = 1; i < dimUID; i++)
		UID[i] = numeSpectator[i - 1];
}
biletCategoria2::biletCategoria2(int id) : biletCategoria2()
{
	if (id > 0)
		this->id = id;
	UID = new int[log10(id) + strlen(numeSpectator) + 1];
	dimUID = log10(id) + strlen(numeSpectator) + 1;
	int i = 0;
	while (id)
	{
		UID[i] = id % 10;
		id = id / 10;
		i++;
	}
	for (int j = i; j < dimUID; j++)
		UID[j] = numeSpectator[j - i];
}
biletCategoria2::biletCategoria2(int id, const char* numeSpectator) : biletCategoria2(id)
{
	if (numeSpectator != nullptr)
	{
		this->numeSpectator = new char[strlen(numeSpectator) + 1];
		strcpy_s(this->numeSpectator, strlen(numeSpectator) + 1, numeSpectator);
	}
	else
	{
		this->numeSpectator = new char[strlen("O persoana") + 1];
		strcpy_s(this->numeSpectator, strlen("O persoana") + 1, "O persoana");
	}
	UID = new int[log10(id) + strlen(numeSpectator) + 1];
	dimUID = log10(id) + strlen(numeSpectator) + 1;
	int i = 0;
	while (id)
	{
		UID[i] = id % 10;
		id = id / 10;
		i++;
	}
	for (int j = i; j < dimUID; j++)
		UID[j] = numeSpectator[j - i];
}
biletCategoria2::biletCategoria2(const char* numeSpectator, int id) : biletCategoria2(id, numeSpectator)
{
}
biletCategoria2::biletCategoria2(const biletCategoria2& b) : biletCategoria2(b.id, b.numeSpectator)
{
	
}
biletCategoria2& biletCategoria2::operator=(const biletCategoria2& b)
{
	if (this != &b)
	{
		this->id = b.id;
		if (b.numeSpectator != nullptr)
		{
			if (this->numeSpectator)
				delete[] this->numeSpectator, this->numeSpectator = nullptr;
			this->numeSpectator = new char[strlen(b.numeSpectator) + 1];
			strcpy_s(this->numeSpectator, strlen(b.numeSpectator) + 1, b.numeSpectator);
		}
		else
		{
			if (this->numeSpectator)
				delete[] this->numeSpectator, this->numeSpectator = nullptr;
			this->numeSpectator = new char[strlen("O persoana") + 1];
			strcpy_s(this->numeSpectator, strlen("O persoana") + 1, "O persoana");
		}
		if (b.UID != nullptr)
		{
			if (this->UID)
				delete[] this->UID, this->UID = nullptr;
			this->UID = new int[b.dimUID];
			this->dimUID = b.dimUID;
			for (int i = 0; i < b.dimUID; i++)
				this->UID[i] = b.UID[i];
		}
	}
	return *this;
}
biletCategoria2::~biletCategoria2()
{
	if (numeSpectator)
		delete[] numeSpectator, numeSpectator = nullptr;
	if (UID)
		delete[] UID, UID = nullptr;
}
int biletCategoria2::getId()
{
	return id;
}
char* biletCategoria2::getNumeSpectator()
{
	if (numeSpectator != nullptr)
	{
		char* copie = new char[strlen(numeSpectator) + 1];
		strcpy_s(copie, strlen(numeSpectator) + 1, numeSpectator);
		return copie;
	}
	return nullptr;
}
int* biletCategoria2::getUID()
{
	if (UID != nullptr)
	{
		int* copie = new int[dimUID];
		for (int i = 0; i < dimUID; i++)
			copie[i] = UID[i];
		return copie;
	}
	return nullptr;
}
int biletCategoria2::getdimUID()
{
	return dimUID;
}
bool biletCategoria2::checkUID(int* check, int dim)
{
	if (check != nullptr && dim > 0)
	{
		if (dim == dimUID)
		{
			for (int i = 0; i < dim; i++)
				if (check[i] != UID[i])
					return false;
			return true;
		}
	}
	return false;
}
void biletCategoria2::setId(int id)
{
	if (id > 0)
		this->id = id;
}
void biletCategoria2::setNumeSpectator(const char* numeSpectator)
{
	if (numeSpectator != nullptr)
	{
		if (this->numeSpectator)
			delete[] this->numeSpectator, this->numeSpectator = nullptr;
		this->numeSpectator = new char[strlen(numeSpectator) + 1];
		strcpy_s(this->numeSpectator, strlen(numeSpectator) + 1, numeSpectator);
	}
}