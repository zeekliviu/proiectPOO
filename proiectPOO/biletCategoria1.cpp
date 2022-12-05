#include "biletCategoria1.h"
int biletCategoria1::nrBilete = 0;
biletCategoria1::biletCategoria1()
{
	nrBilete++;
	id = nrBilete;
	numeSpectator = new char[strlen("O persoana") + 1];
	strcpy_s(numeSpectator, strlen("O persoana")+1,"O persoana");
	ocupat = false;
	UID = new int[log10(id)+1+strlen(numeSpectator)];
	dimUID = log10(id) + strlen(numeSpectator)+1;
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
biletCategoria1::biletCategoria1(const char* numeSpectator) : biletCategoria1()
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

biletCategoria1::biletCategoria1(const biletCategoria1& b)
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

biletCategoria1& biletCategoria1::operator=(const biletCategoria1& b)
{
	if (this != &b)
	{
		id = b.id;
		ocupat = b.ocupat;
		if(numeSpectator)
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
ostream& operator<<(ostream& out, biletCategoria1 b)
{

	out << "Nume spectator: " << b.numeSpectator << endl;
	out << "UID: ";
	for (int i = 0; i < b.dimUID; i++)
		out << b.UID[i];
	out << endl<<endl;
	return out;
}
istream& operator>>(istream& in, biletCategoria1& b)
{
	cout << "Nume spectator: ";
	string buffer;
	getline(cin, buffer);
	if (b.numeSpectator != nullptr)
		delete[] b.numeSpectator, b.numeSpectator=nullptr;
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
bool biletCategoria1::operator==(const biletCategoria1& b)
{
	if (strcmp(numeSpectator, b.numeSpectator))
		return false;
	return true;
}
bool biletCategoria1::operator<(const biletCategoria1& b)
{
	if (dimUID < b.dimUID)
		return true;
	return false;
}
biletCategoria1::~biletCategoria1()
{
	if (numeSpectator)
		delete[] numeSpectator, numeSpectator = nullptr;
	if (UID)
		delete[] UID, UID = nullptr;
}
int biletCategoria1::getNrBilete()
{
	return nrBilete;
}
int biletCategoria1::getId()
{
	return id;
}
bool biletCategoria1::getOccupancy()
{
	return ocupat;
}
char* biletCategoria1::getNumeSpectator()
{
	if (numeSpectator != nullptr)
	{
		char* copie = new char[strlen(numeSpectator) + 1];
		strcpy_s(copie, strlen(numeSpectator) + 1, numeSpectator);
		return copie;
	}
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
}
int biletCategoria1::getdimUID()
{
	return dimUID;
}
void biletCategoria1::setNrBilete(int nr)
{
	if (nr > 0)
		nrBilete = nr;
}
void biletCategoria1::setId(int id)
{
	if (id > 0)
		this->id = id;
}
void biletCategoria1::setOccupancy(bool stare)
{
	ocupat = stare;
}
void biletCategoria1::setNumeSpectator(const char* s)
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
void biletCategoria1::setUID(int* UID, int dim)
{
	if (UID != nullptr)
	{
		if (this->UID)
			delete[] this->UID, this->UID = nullptr;
		this->UID = new int[dim];
		for (int i = 0; i < dim; i++)
			this->UID[i] = UID[i];
		dimUID = dim;
	}
}
bool biletCategoria1::checkUID(char *check)
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