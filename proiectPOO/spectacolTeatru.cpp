#include <iostream>
#include "spectacolTeatru.h"
#include "biletCategoria1.h"
#include "biletCategoria2.h"
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
}
spectacolTeatru::spectacolTeatru(int nrMaximLocuri) : nrMaximLocuri(nrMaximLocuri)
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
}
spectacolTeatru::spectacolTeatru(const char* denumire) : nrMaximLocuri(0)
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
	if (denumire != nullptr && strlen(denumire) > 0)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else
		this->denumire = nullptr;
}
spectacolTeatru::spectacolTeatru(int nrMaximLocuri, const char* denumire) : nrMaximLocuri(nrMaximLocuri)
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
	if (denumire != nullptr && strlen(denumire) > 0)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else
		this->denumire = nullptr;
}
spectacolTeatru::~spectacolTeatru()
{
	if (bileteCat1)
	{
		for (int i = 0; i < nrRanduriCat1; i++)
			delete[] bileteCat1[i];
		delete[] bileteCat1;
		bileteCat1 = nullptr;
	}
	if (bileteCat2)
	{
		for (int i = 0; i < nrRanduriCat2; i++)
			delete[] bileteCat2[i];
		delete[] bileteCat2;
		bileteCat2 = nullptr;
	}
	if (bileteLoja)
	{
		for (int i = 0; i < nrRanduriLoja; i++)
			delete[] bileteLoja[i];
		delete[] bileteLoja;
		bileteLoja = nullptr;
	}
	if (denumire)
		delete[] denumire, denumire = nullptr;
}
char* spectacolTeatru::getDenumire()
{
	return denumire;
}
int spectacolTeatru::getNrMaximLocuri()
{
	return nrMaximLocuri;
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
