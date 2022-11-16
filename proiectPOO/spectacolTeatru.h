#pragma once
#include "biletCategoria1.h"
#include "biletCategoria2.h"
#include "biletLoja.h"
class spectacolTeatru
{
	char* denumire=nullptr;
	const int nrMaximLocuri;
	biletCategoria1** bileteCat1;
	int nrRanduriCat1;
	int nrBileteCat1;
	biletCategoria2** bileteCat2;
	int nrRanduriCat2;
	int nrBileteCat2;
	biletLoja** bileteLoja;
	int nrRanduriLoja;
	int nrBileteLoja;
public:
	spectacolTeatru();
	spectacolTeatru(int);
	spectacolTeatru(const char*);
	spectacolTeatru(int, const char*);
	int getNrMaximLocuri();
	int getNrBileteCat1();
	int getNrBileteCat2();
	int getNrBileteLoja();
	char* getDenumire();
	biletCategoria1* getRandCat1(int);
	biletCategoria2* getRandCat2(int);
	biletLoja* getRandLoja(int);
	biletCategoria1 getBiletCat1(int, int);
	biletCategoria2 getBiletCat2(int, int);
	biletLoja getBiletLoja(int, int);
	~spectacolTeatru();
};

