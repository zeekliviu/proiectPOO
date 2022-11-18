#include <iostream>
#include "spectacolTeatru.h"
#include "biletCategoria1.h"
#include "biletCategoria2.h"
int spectacolTeatru::idSpectacol = 0;
spectacolTeatru::spectacolTeatru() : nrMaximLocuri(0)
{
	bileteCat1 = nullptr;
	bileteCat2 = nullptr;
	bileteLoja = nullptr;
	nrBileteCat1 = nrMaximLocuri;
	nrBileteCat2 = nrMaximLocuri;
	nrBileteLoja = nrMaximLocuri;
	nrRanduriCat1 = nrMaximLocuri;
	nrRanduriCat2 = nrMaximLocuri;
	nrRanduriLoja = nrMaximLocuri;
	denumire = nullptr;
	data = nullptr;
	ora = nullptr;
	idSpectacol++;
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri) : nrMaximLocuri(nrMaximLocuri)
{
	bileteCat1 = nullptr;
	bileteCat2 = nullptr;
	bileteLoja = nullptr;
	nrBileteCat1 = 0;
	nrBileteCat2 = 0;
	nrBileteLoja = 0;
	nrRanduriCat1 = 0;
	nrRanduriCat2 = 0;
	nrRanduriLoja = 0;
	denumire = nullptr;
	data = nullptr;
	ora = nullptr;
	idSpectacol++;
}
spectacolTeatru::spectacolTeatru(const char* denumire) : nrMaximLocuri(0)
{
	data = nullptr;
	ora = nullptr;
	bileteCat1 = nullptr;
	bileteCat2 = nullptr;
	bileteLoja = nullptr;
	nrBileteCat1 = nrMaximLocuri;
	nrBileteCat2 = nrMaximLocuri;
	nrBileteLoja = nrMaximLocuri;
	nrRanduriCat1 = nrMaximLocuri;
	nrRanduriCat2 = nrMaximLocuri;
	nrRanduriLoja = nrMaximLocuri;
	if (denumire != nullptr && strlen(denumire) > 0)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else
		this->denumire = nullptr;
	idSpectacol++;
}
spectacolTeatru::spectacolTeatru(const char* denumire, const char* data): spectacolTeatru(denumire)
{
	if (data != nullptr && strlen(data) > 0)
	{
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	else
		this->data = nullptr;
}
spectacolTeatru::spectacolTeatru(const char* denumire, const char* data, const char* ora) : spectacolTeatru(denumire, data)
{
	if (ora != nullptr && strlen(ora) > 0)
	{
		this->ora = new char[strlen(ora) + 1];
		strcpy_s(this->ora, strlen(ora) + 1, ora);
	}
	else
		this->ora = nullptr;
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire) : spectacolTeatru(nrMaximLocuri)
{
	if (denumire != nullptr && strlen(denumire) > 0)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else
		this->denumire = nullptr;
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data) : spectacolTeatru(nrMaximLocuri, denumire)
{
	if (data != nullptr && strlen(data) > 0)
	{
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	else
		this->data = nullptr;
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora) : spectacolTeatru(nrMaximLocuri, denumire, data)
{
	if (ora != nullptr && strlen(ora) > 0)
	{
		this->ora = new char[strlen(ora) + 1];
		strcpy_s(this->ora, strlen(ora) + 1, ora);
	}
	else
		this->ora = nullptr;
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const int nrRanduriLocuriCat1Cat2Loja): nrMaximLocuri(nrMaximLocuri)
{
	if (nrRanduriLocuriCat1Cat2Loja > 0 && nrRanduriLocuriCat1Cat2Loja*nrRanduriLocuriCat1Cat2Loja<=nrMaximLocuri)
	{
		bileteCat1 = new biletCategoria1 * [nrRanduriLocuriCat1Cat2Loja];
		for (int i = 0; i < nrRanduriLocuriCat1Cat2Loja; i++)
		{
			bileteCat1[i] = new biletCategoria1[nrRanduriLocuriCat1Cat2Loja];
		}
		nrBileteCat1 = nrRanduriCat1 = nrRanduriLocuriCat1Cat2Loja;
		if (nrMaximLocuri - 2*nrRanduriLocuriCat1Cat2Loja * nrRanduriLocuriCat1Cat2Loja>=0)
		{
			bileteCat2 = new biletCategoria2 * [nrRanduriLocuriCat1Cat2Loja];
			for (int i = 0; i < nrRanduriLocuriCat1Cat2Loja; i++)
				bileteCat2[i] = new biletCategoria2[nrRanduriLocuriCat1Cat2Loja];
			nrBileteCat2 = nrRanduriCat2 = nrRanduriLocuriCat1Cat2Loja;
			if (nrMaximLocuri - 3*nrRanduriLocuriCat1Cat2Loja * nrRanduriLocuriCat1Cat2Loja>=0)
			{
				bileteLoja = new biletLoja * [nrRanduriLocuriCat1Cat2Loja];
				for (int i = 0; i < nrRanduriLocuriCat1Cat2Loja; i++)
					bileteLoja[i] = new biletLoja[nrRanduriLocuriCat1Cat2Loja];
				nrBileteLoja = nrRanduriLoja = nrRanduriLocuriCat1Cat2Loja;
			}
			else
			{
				bileteLoja = nullptr;
				nrBileteLoja = nrRanduriLoja = 0;
			}
		}
		else
		{
			bileteCat2 = nullptr;
			bileteLoja = nullptr;
			nrBileteCat2 = nrRanduriCat2 = nrRanduriLoja = nrBileteLoja = 0;
		}
	}
	else
	{
		bileteCat1 = nullptr;
		bileteCat2 = nullptr;
		bileteLoja = nullptr;
		nrRanduriCat1 = nrRanduriCat2 = nrRanduriLoja = nrBileteCat1 = nrBileteCat2 = nrBileteLoja = 0;
	}
	if (denumire != nullptr && strlen(denumire) > 0)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else
		this->denumire = nullptr;
	data = nullptr;
	ora = nullptr;
	idSpectacol++;
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const int nrRanduriLocuriCat1Cat2Loja) : spectacolTeatru(nrMaximLocuri, denumire, nrRanduriLocuriCat1Cat2Loja)
{
	if (data != nullptr && strlen(denumire) > 0)
	{
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora, const int nrRanduriLocuriCat1Cat2Loja) : spectacolTeatru(nrMaximLocuri, denumire, data, nrRanduriLocuriCat1Cat2Loja)
{
	if (ora != nullptr && strlen(ora) > 0)
	{
		this->ora = new char[strlen(ora) + 1];
		strcpy_s(this->ora, strlen(ora) + 1, ora);
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const int nrRanduriCat1, const int nrBileteCat1): spectacolTeatru(nrMaximLocuri, denumire)
{
	if ((nrRanduriCat1 * nrBileteCat1 <= nrMaximLocuri) && nrRanduriCat1 > 0 && nrBileteCat1 > 0)
	{
		bileteCat1 = new biletCategoria1 * [nrRanduriCat1];
		for (int i = 0; i < nrRanduriCat1; i++)
			bileteCat1[i] = new biletCategoria1[nrBileteCat1];
		this->nrRanduriCat1 = nrRanduriCat1;
		this->nrBileteCat1 = nrBileteCat1;
	}
	else {
		bileteCat1 = nullptr;
		this->nrRanduriCat1 = this->nrBileteCat1 = 0;
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const int nrRanduriCat1, const int nrBileteCat1): spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1)
{
	if(data!=nullptr && strlen(data)>0)
	{
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora, const int nrRanduriCat1, const int nrBileteCat1) : spectacolTeatru(nrMaximLocuri, denumire, data, nrRanduriCat1, nrBileteCat1)
{
	if (ora != nullptr && strlen(ora) > 0)
	{
		this->ora = new char[strlen(ora) + 1];
		strcpy_s(this->ora, strlen(ora) + 1, ora);
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const int nrRanduriCat1, const int nrBileteCat1, const int nrRanduriCat2, const int nrBileteCat2): spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1)
{

	if ((nrRanduriCat1 * nrBileteCat1 + nrRanduriCat2 * nrBileteCat2 <= nrMaximLocuri) && nrRanduriCat2 > 0 && nrBileteCat2 > 0)
	{
		bileteCat2 = new biletCategoria2 * [nrRanduriCat2];
		for (int i = 0; i < nrRanduriCat2; i++)
			bileteCat2[i] = new biletCategoria2[nrBileteCat2];
		this->nrRanduriCat2 = nrRanduriCat2;
		this->nrBileteCat2 = nrBileteCat2;
	}
	else {
		bileteCat2 = nullptr;
		this->nrRanduriCat2 = this->nrBileteCat2 = 0;
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const int nrRanduriCat1, const int nrBileteCat1, const int nrRanduriCat2, const int nrBileteCat2) : spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2)
{
	if (data != nullptr && strlen(data) > 0)
	{
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data)+1,data);
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora, const int nrRanduriCat1, const int nrBileteCat1, const int nrRanduriCat2, const int nrBileteCat2) : spectacolTeatru(nrMaximLocuri, denumire, data, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2)
{
	if (ora != nullptr && strlen(ora) > 0)
	{
		this->ora = new char[strlen(ora) + 1];
		strcpy_s(this->ora,strlen(ora)+1, ora);
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const int nrRanduriCat1, const int nrBileteCat1, const int nrRanduriCat2, const int nrBileteCat2, const int nrRanduriLoja, const int nrBileteLoja) : spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2)
{
	if ((nrRanduriCat1 * nrBileteCat1 + nrRanduriCat2 * nrBileteCat2 + nrRanduriLoja * nrBileteLoja <= nrMaximLocuri) && nrRanduriLoja > 0 && nrBileteLoja > 0)
	{
		bileteLoja = new biletLoja * [nrRanduriLoja];
		for (int i = 0; i < nrRanduriLoja; i++)
			bileteLoja[i] = new biletLoja[nrBileteLoja];
		this->nrRanduriLoja = nrRanduriLoja;
		this->nrBileteLoja = nrBileteLoja;
	}
	else
	{
		bileteLoja = nullptr;
		this->nrRanduriLoja = this->nrBileteLoja = 0;
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const int nrRanduriCat1, const int nrBileteCat1, const int nrRanduriCat2, const int nrBileteCat2, const int nrRanduriLoja, const int nrBileteLoja) : spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2, nrRanduriLoja, nrBileteLoja)
{
	if (data != nullptr && strlen(data) > 0)
	{
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data,strlen(data)+1, data);
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora, const int nrRanduriCat1, const int nrBileteCat1, const int nrRanduriCat2, const int nrBileteCat2, const int nrRanduriLoja, const int nrBileteLoja) : spectacolTeatru(nrMaximLocuri, denumire, data, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2, nrRanduriLoja, nrBileteLoja)
{
	if (ora != nullptr && strlen(ora) > 0)
	{
		this->ora = new char[strlen(ora) + 1];
		strcpy_s(this->ora,strlen(ora)+1, ora);
	}
}
//constructorul de copiere
spectacolTeatru::spectacolTeatru(const spectacolTeatru& st): nrMaximLocuri(st.nrMaximLocuri)
{
	//
}
spectacolTeatru::~spectacolTeatru()
{
	if (bileteCat1!=nullptr)
	{
		for (int i = 0; i < nrRanduriCat1; i++)
			delete[] bileteCat1[i];
		delete[] bileteCat1;
		bileteCat1 = nullptr;
	}
	if (bileteCat2!=nullptr)
	{
		for (int i = 0; i < nrRanduriCat2; i++)
			delete[] bileteCat2[i];
		delete[] bileteCat2;
		bileteCat2 = nullptr;
	}
	if (bileteLoja!=nullptr)
	{
		for (int i = 0; i < nrRanduriLoja; i++)
			delete[] bileteLoja[i];
		delete[] bileteLoja;
		bileteLoja = nullptr;
	}
	if (denumire!=nullptr)
		delete[] denumire, denumire = nullptr;
	if (data != nullptr)
		delete[] data, data = nullptr;
	if (ora != nullptr)
		delete[] ora, ora = nullptr;
}
char* spectacolTeatru::getDenumire()
{
	if (denumire!=nullptr)
	{
		char* copie = new char[strlen(denumire) + 1];
		strcpy_s(copie, strlen(denumire)+1,denumire);
		return copie;
	}
}
char* spectacolTeatru::getData()
{
	if (data!=nullptr)
	{
		char* copie = new char[strlen(data) + 1];
		strcpy_s(copie, strlen(data) + 1, data);
		return copie;
	}
}
char* spectacolTeatru::getOra()
{
	if (ora!=nullptr)
	{
		char* copie = new char[strlen(ora) + 1];
		strcpy_s(copie, strlen(ora) + 1, ora);
		return copie;
	}
}
int spectacolTeatru::getNrMaximLocuri()
{
	return nrMaximLocuri;
}
int spectacolTeatru::getNrRanduriCat1()
{
	return nrRanduriCat1;
}
int spectacolTeatru::getNrRanduriCat2()
{
	return nrRanduriCat2;
}
int spectacolTeatru::getNrRanduriLoja()
{
	return nrRanduriLoja;
}
int spectacolTeatru::getNrBileteCat1()
{
	return nrBileteCat1;
}
int spectacolTeatru::getNrBileteCat2()
{
	return nrBileteCat2;
}
int spectacolTeatru::getNrBileteLoja()
{
	return nrBileteLoja;
}
biletCategoria1* spectacolTeatru::getRandCat1(int i)
{
	if (i >= 0 && i < nrRanduriCat1)
		return bileteCat1[i];
	return nullptr;
}
biletCategoria2* spectacolTeatru::getRandCat2(int i)
{
	if (i >= 0 && i < nrRanduriCat2)
		return bileteCat2[i];
	return nullptr;
}
biletLoja* spectacolTeatru::getRandLoja(int i)
{
	if (i >= 0 && i < nrRanduriLoja)
		return bileteLoja[i];
	return nullptr;
}
biletCategoria1 spectacolTeatru::getBiletCat1(int i, int j)
{
	if (i >= 0 && i < nrRanduriCat1 && j >= 0 && j < nrBileteCat1)
		return bileteCat1[i][j];
	return biletCategoria1();
}
biletCategoria2 spectacolTeatru::getBiletCat2(int i, int j)
{
	if (i >= 0 && i < nrRanduriCat2 && j >= 0 && j < nrBileteCat2)
		return bileteCat2[i][j];
	return biletCategoria2();
}
biletLoja spectacolTeatru::getBiletLoja(int i, int j)
{
	if (i >= 0 && i < nrRanduriLoja && j >= 0 && j < nrBileteLoja)
		return bileteLoja[i][j];
	return biletLoja();
}
