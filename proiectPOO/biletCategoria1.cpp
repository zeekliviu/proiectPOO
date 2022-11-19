#include <iostream>
#include "biletCategoria1.h"
biletCategoria1::biletCategoria1()
{
	id = 0;
	numeSpectator = new char[strlen("O persoana") + 1];
	strcpy_s(numeSpectator, strlen("O persoana")+1,"O persoana");
	UID = new int[log(1)+1+strlen(numeSpectator)];
	dimUID = log(1) + strlen(numeSpectator)+1;
	UID[0] = 0;
	for (int i = 1; i < dimUID; i++)
		UID[i] = numeSpectator[i - 1];
}
biletCategoria1::biletCategoria1(int id): biletCategoria1()
{
	if (id > 0)
		this->id = id;
	UID = new int[log10(id) + strlen(numeSpectator)+1];
	dimUID = log10(id) + strlen(numeSpectator)+1;
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
biletCategoria1::biletCategoria1(int id, const char* numeSpectator) : biletCategoria1(id)
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
biletCategoria1::biletCategoria1(const char* numeSpectator, int id) : biletCategoria1(id, numeSpectator)
{
}
biletCategoria1::biletCategoria1(const biletCategoria1& b)
{
	this->id = b.id;
	if (b.numeSpectator != nullptr)
	{
		this->numeSpectator = new char[strlen(b.numeSpectator) + 1];
		strcpy_s(this->numeSpectator, strlen(b.numeSpectator) + 1, b.numeSpectator);
	}
	if (b.UID != nullptr)
	{
		if(this->UID!=nullptr)
			delete[] this->UID, this->UID = nullptr;
		this->UID = new int[b.dimUID];
		this->dimUID = b.dimUID;
		for (int i = 0; i < b.dimUID; i++)
			this->UID[i] = b.UID[i];
	}
}
biletCategoria1& biletCategoria1::operator=(const biletCategoria1& b)
{
	if (this != &b)
	{
		this->id = b.id;
		if (b.numeSpectator != nullptr)
		{
			if(this->numeSpectator)
				delete[] this->numeSpectator, this->numeSpectator = nullptr;
			this->numeSpectator = new char[strlen(b.numeSpectator) + 1];
			strcpy_s(this->numeSpectator, strlen(b.numeSpectator) + 1, b.numeSpectator);
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
biletCategoria1::~biletCategoria1()
{
	if (numeSpectator)
	{
		delete[] numeSpectator;
		numeSpectator = nullptr;
	}
	if (UID)
	{
		delete[] UID;
		UID = nullptr;
	}
}
int biletCategoria1::getId()
{
	return id;
}
char* biletCategoria1::getNumeSpectator()
{
	if (numeSpectator != nullptr)
	{
		char* copie = new char[strlen(numeSpectator) + 1];
		strcpy_s(copie, strlen(numeSpectator) + 1, numeSpectator);
		return copie;
	}
	return nullptr;
}
int* biletCategoria1::getUID()
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
int biletCategoria1::getdimUID()
{
	return dimUID;
}
bool biletCategoria1::checkUID(int *check, int dim)
{
	if (UID != nullptr && dimUID>0)
	{
		if(check!=nullptr && dim>0)
		{
			if(dimUID==dim)
			{
				bool ok = true;
				for (int i = 0; i < dimUID; i++)
					if (check[i] != UID[i])
						ok = false;
				if (ok)
					return true;
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}

void biletCategoria1::setId(const int i)
{
	if (i > 0)
		id = i;
}
void biletCategoria1::setNumeSpectator(const char* s)
{
	if (s != nullptr)
	{
		if (numeSpectator)
			delete[] numeSpectator, numeSpectator = nullptr;
		numeSpectator = new char[strlen(s) + 1];
		strcpy_s(numeSpectator, strlen(s) + 1, s);
	}
}