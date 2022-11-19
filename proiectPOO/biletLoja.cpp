#include <iostream>
#include "biletLoja.h"
biletLoja::biletLoja()
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
biletLoja::biletLoja(int id) : biletLoja()
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
biletLoja::biletLoja(int id, const char* numeSpectator) : biletLoja(id)
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
biletLoja::biletLoja(const char* numeSpectator, int id) : biletLoja(id, numeSpectator)
{
}
biletLoja::biletLoja(const biletLoja& b)
{
	this->id = b.id;
	if (b.numeSpectator != nullptr)
	{
		this->numeSpectator = new char[strlen(b.numeSpectator) + 1];
		strcpy_s(this->numeSpectator, strlen(b.numeSpectator) + 1, b.numeSpectator);
	}
	if (b.UID != nullptr)
	{
		if (this->UID != nullptr)
			delete[] this->UID, this->UID = nullptr;
		this->UID = new int[b.dimUID];
		this->dimUID = b.dimUID;
		for (int i = 0; i < b.dimUID; i++)
			this->UID[i] = b.UID[i];
	}
}
biletLoja& biletLoja::operator=(const biletLoja& b)
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
biletLoja::~biletLoja()
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
int biletLoja::getId()
{
	return id;
}
char* biletLoja::getNumeSpectator()
{
	if (numeSpectator != nullptr)
	{
		char* copie = new char[strlen(numeSpectator) + 1];
		strcpy_s(copie, strlen(numeSpectator) + 1, numeSpectator);
		return copie;
	}
	return nullptr;
}
int* biletLoja::getUID()
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
int biletLoja::getdimUID()
{
	return dimUID;
}
bool biletLoja::checkUID(int* check, int dim)
{
	if (UID != nullptr && dimUID > 0)
	{
		if (check != nullptr && dim > 0)
		{
			if (dimUID == dim)
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

void biletLoja::setId(const int i)
{
	if (i > 0)
		id = i;
}
void biletLoja::setNumeSpectator(const char* s)
{
	if (s != nullptr)
	{
		if (numeSpectator)
			delete[] numeSpectator, numeSpectator = nullptr;
		numeSpectator = new char[strlen(s) + 1];
		strcpy_s(numeSpectator, strlen(s) + 1, s);
	}
}