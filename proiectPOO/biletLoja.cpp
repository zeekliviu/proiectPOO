#include "biletLoja.h"
int biletLoja::id = 0;
biletLoja::biletLoja()
{
	id++;
	numeSpectator = new char[strlen("O persoana") + 1];
	strcpy_s(numeSpectator, strlen("O persoana") + 1, "O persoana");
	ocupat = false;
	UID = new int[log10(id) + 1 + strlen(numeSpectator)];
	dimUID = log10(id) + strlen(numeSpectator) + 1;
	UID[0] = 0;
	for (int i = 1; i < dimUID; i++)
		UID[i] = numeSpectator[i - 1];
}
biletLoja::biletLoja(const char* numeSpectator) : biletLoja()
{
	if (numeSpectator != nullptr)
	{
		this->numeSpectator = new char[strlen(numeSpectator) + 1];
		strcpy_s(this->numeSpectator, strlen(numeSpectator) + 1, numeSpectator);
		ocupat = true;
	}
	else
	{
		this->numeSpectator = new char[strlen("O persoana") + 1];
		strcpy_s(this->numeSpectator, strlen("O persoana") + 1, "O persoana");
	}
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
biletLoja::biletLoja(const biletLoja& b)
{
	id++;
	ocupat = b.ocupat;
	if (b.numeSpectator != nullptr)
	{
		this->numeSpectator = new char[strlen(b.numeSpectator) + 1];
		strcpy_s(this->numeSpectator, strlen(b.numeSpectator) + 1, b.numeSpectator);
		ocupat = true;
	}
	else
	{
		this->numeSpectator = new char[strlen("O persoana") + 1];
		strcpy_s(this->numeSpectator, strlen("O persoana") + 1, "O persoana");
		ocupat = false;
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
		ocupat = b.ocupat;
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
ostream& operator<<(ostream& out, biletLoja b)
{
	if (b.numeSpectator)
		out << "Nume spectator: " << b.numeSpectator << endl;
	else
		out << "Nume spectator: O persoana" << endl;
	if (b.UID)
	{
		out << "UID: ";
		for (int i = 0; i < b.dimUID; i++)
			out << b.UID[i];
	}
	else
		out << "UID: 0";
	out << endl << endl;
	return out;
}
istream& operator>>(istream& in, biletLoja& b)
{
	cout << "Nume spectator: ";
	char buffer[50];
	in.getline(buffer, 50);
	if (b.numeSpectator != nullptr)
		delete[] b.numeSpectator, b.numeSpectator = nullptr;
	b.numeSpectator = new char[strlen(buffer) + 1];
	strcpy_s(b.numeSpectator, strlen(buffer) + 1, buffer);
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
	if (this->id > b.id)
		return true;
	return false;
}
bool biletLoja::operator>=(const biletLoja& b)
{
	if (this->dimUID >= b.dimUID)
		return true;
	return false;
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