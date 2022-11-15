#include <iostream>
#include "spectacolTeatru.h"
#include "biletCategoria1.h"
#include "biletCategoria2.h"
spectacolTeatru::spectacolTeatru() : nrMaximLocuri(0)
{
	bileteCat1 = new biletCategoria1[nrMaximLocuri];
	bileteCat2 = new biletCategoria2[nrMaximLocuri];
	bileteLoja = new biletLoja[nrMaximLocuri];
	nrBileteCat1 = nrMaximLocuri;
	nrBileteCat2 = nrMaximLocuri;
	nrBileteLoja = nrMaximLocuri;
}
spectacolTeatru::spectacolTeatru(int nrMaximLocuri) : nrMaximLocuri(nrMaximLocuri)
{
	bileteCat1 = new biletCategoria1[this->nrMaximLocuri];
	bileteCat2 = new biletCategoria2[this->nrMaximLocuri];
	bileteLoja = new biletLoja[this->nrMaximLocuri];
	nrBileteCat1 = this->nrMaximLocuri;
	nrBileteCat2 = this->nrMaximLocuri;
	nrBileteLoja = this->nrMaximLocuri;
	if (nrMaximLocuri > 0)
		for (int i = 0; i < nrMaximLocuri; i++)
		{
			bileteCat1[i] = biletCategoria1();
			bileteCat2[i] = biletCategoria2();
			bileteLoja[i] = biletLoja();
			bileteCat1[i].setId("123");
			bileteCat2[i].setId("321");
			bileteLoja[i].setId("231");
		}
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
spectacolTeatru::~spectacolTeatru()
{
	if (bileteCat1)
		delete[] bileteCat1, bileteCat1 = nullptr;
	if (bileteCat2)
		delete[] bileteCat2, bileteCat2 = nullptr;
	if (bileteLoja)
		delete[] bileteLoja, bileteLoja = nullptr;
}
biletCategoria1 spectacolTeatru::getBiletCat1(int i)
{
	if (i >= 0 && i < nrBileteCat1)
		return bileteCat1[i];
	else
		return biletCategoria1();
}
biletCategoria2 spectacolTeatru::getBiletCat2(int i)
{
	if (i >= 0 && i < nrBileteCat2)
		return bileteCat2[i];
	else
		return biletCategoria2();
}
biletLoja spectacolTeatru::getBiletLoja(int i)
{
	if (i >= 0 && i < nrBileteLoja)
		return bileteLoja[i];
	else
		return biletLoja();
}
