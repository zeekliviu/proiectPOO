#include "biletLoja.h"
int biletLoja::nrBilete = 0;
biletLoja::biletLoja()
{
	nrBilete++;
	id = nrBilete;
	numeSpectator = new char[strlen("O persoana") + 1];
	strcpy_s(numeSpectator, strlen("O persoana") + 1, "O persoana");
	ocupat = false;
	UID = new int[log10(id) + 1 + strlen(numeSpectator)];
	dimUID = log10(id) + strlen(numeSpectator) + 1;
	int i = 0;
	int copie = id;
	while (copie)
	{
		UID[i] = copie % 10;
		copie /= 10;
		i++;
	}
	for (int j = i; j < dimUID; j++)
		UID[j] = numeSpectator[j - i];
}
biletLoja::biletLoja(const char* numeSpectator) : biletLoja()
{
	if (numeSpectator != nullptr)
	{
		delete[] this->numeSpectator;
		this->numeSpectator = new char[strlen(numeSpectator) + 1];
		strcpy_s(this->numeSpectator, strlen(numeSpectator) + 1, numeSpectator);
		ocupat = true;
		delete[] this->UID;
		dimUID = 0;
		UID = new int[log10(id) + strlen(numeSpectator) + 1];
		dimUID = log10(id) + strlen(numeSpectator) + 1;
		int i = 0;
		int copie = id;
		while (copie)
		{
			UID[i] = copie % 10;
			copie /= 10;
			i++;
		}
		for (int j = i; j < dimUID; j++)
			UID[j] = numeSpectator[j - i];
	}
}
biletLoja::biletLoja(const biletLoja& b)
{
	nrBilete++;
	id = nrBilete;
	ocupat = b.ocupat;
	numeSpectator = new char[strlen(b.numeSpectator) + 1];
	strcpy_s(numeSpectator, strlen(b.numeSpectator) + 1, b.numeSpectator);
	UID = new int[log10(id) + strlen(numeSpectator) + 1];
	dimUID = log10(id) + strlen(numeSpectator) + 1;
	int i = 0;
	int copie = id;
	while (copie)
	{
		UID[i] = copie % 10;
		copie /= 10;
		i++;
	}
	for (int j = i; j < dimUID; j++)
		UID[j] = numeSpectator[j - i];
}
biletLoja& biletLoja::operator=(const biletLoja& b)
{
	if (this != &b)
	{
		id = b.id;
		ocupat = b.ocupat;
		if (numeSpectator)
			delete[] numeSpectator, numeSpectator = nullptr;
		numeSpectator = new char[strlen(b.numeSpectator) + 1];
		strcpy_s(numeSpectator, strlen(b.numeSpectator) + 1, b.numeSpectator);
		if (UID)
			delete[] UID, UID = nullptr;
		UID = new int[b.dimUID];
		dimUID = b.dimUID;
		for (int i = 0; i < b.dimUID; i++)
			UID[i] = b.UID[i];
	}
	return *this;
}
ostream& operator<<(ostream& out, biletLoja b)
{
	out << "Nume spectator: " << b.numeSpectator << endl;
	out << "UID: ";
	for (int i = 0; i < b.dimUID; i++)
		out << b.UID[i];
	out << endl << endl;
	return out;
}
istream& operator>>(istream& in, biletLoja& b)
{
	cout << "Nume spectator: ";
	string buffer;
	getline(cin, buffer);
	if (b.numeSpectator != nullptr)
		delete[] b.numeSpectator, b.numeSpectator = nullptr;
	b.numeSpectator = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(b.numeSpectator, strlen(buffer.c_str()) + 1, buffer.c_str());
	b.ocupat = true;
	if (b.UID != nullptr)
		delete[] b.UID, b.UID = nullptr;;
	b.UID = new int[log10(b.id) + strlen(b.numeSpectator) + 1];
	b.dimUID = log10(b.id) + strlen(b.numeSpectator) + 1;
	int i = 0;
	int copie = b.id;
	while (copie)
	{
		b.UID[i] = copie % 10;
		copie /= 10;
		i++;
	}
	for (int j = i; j < b.dimUID; j++)
		b.UID[j] = b.numeSpectator[j - i];
	return in;
}
bool biletLoja::operator>(const biletLoja& b)
{
	if (id > b.id)
		return true;
	return false;
}
bool biletLoja::operator>=(const biletLoja& b)
{
	if (dimUID >= b.dimUID)
		return true;
	return false;
}
biletLoja::~biletLoja()
{
	if (numeSpectator)
		delete[] numeSpectator, numeSpectator = nullptr;
	if (UID)
		delete[] UID, UID = nullptr;
}
int biletLoja::getNrBilete()
{
	return nrBilete;
}
int biletLoja::getId()
{
	return id;
}
bool biletLoja::getOccupancy()
{
	return ocupat;
}
char* biletLoja::getNumeSpectator()
{
	if (numeSpectator != nullptr)
	{
		char* copie = new char[strlen(numeSpectator) + 1];
		strcpy_s(copie, strlen(numeSpectator) + 1, numeSpectator);
		return copie;
	}
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
}
int biletLoja::getdimUID()
{
	return dimUID;
}
void biletLoja::setNrBilete(int nrBilete)
{
	if (nrBilete > 0)
		this->nrBilete = nrBilete;
}
void biletLoja::setId(int id)
{
	if (id > 0)
		this->id = id;
}
void biletLoja::setOccupancy(bool stare)
{
	ocupat = stare;
}
void biletLoja::setNumeSpectator(const char* s)
{
	if (s != nullptr)
	{
		if (numeSpectator)
			delete[] numeSpectator, numeSpectator = nullptr;
		numeSpectator = new char[strlen(s) + 1];
		strcpy_s(numeSpectator, strlen(s) + 1, s);
		UID = new int[log10(id) + 1 + strlen(numeSpectator)];
		dimUID = log10(id) + strlen(numeSpectator) + 1;
		int i = 0;
		int copie = id;
		while (copie)
		{
			UID[i] = copie % 10;
			copie /= 10;
			i++;
		}
		for (int j = i; j < dimUID; j++)
			UID[j] = numeSpectator[j - 1];
	}
}
void biletLoja::setUID(int* UID, int dimUID)
{
	if (UID != nullptr && dimUID > 0)
	{
		if (this->UID != nullptr)
			delete[] this->UID, this->UID = nullptr;
		this->UID = new int[dimUID];
		this->dimUID = dimUID;
		for (int i = 0; i < dimUID; i++)
			this->UID[i] = UID[i];
	}
}
bool biletLoja::checkUID(char* check)
{
	if (check != nullptr)
	{
		int dimUIDchar = 0;
		for (int i = 0; i < dimUID; i++)
		{
			int copie = UID[i];
			if (copie == 0)
				dimUIDchar++;
			else while (copie)
			{
				dimUIDchar++;
				copie /= 10;
			}
		}
		if (dimUIDchar != strlen(check))
			return false;
		char* UIDchar = new char[dimUIDchar + 1];
		int i = 0;
		for (int j = 0; j < dimUID; j++)
		{
			int copie = UID[j];
			if (copie == 0)
			{
				UIDchar[i] = '0';
				i++;
			}
			else
			{
				while (copie)
				{
					int aux = i + log10(copie);
					UIDchar[aux] = copie % 10 + '0';
					copie /= 10;
				}
				i += log10(UID[j]) + 1;
			}
		}
		UIDchar[dimUIDchar] = '\0';
		if (!strcmp(UIDchar, check))
			return true;
		return false;
	}
	return false;
}