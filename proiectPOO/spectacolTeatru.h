#pragma once
#include "biletCategoria1.h"
#include "biletCategoria2.h"
#include "biletLoja.h"
class spectacolTeatru
{
	const int nrMaximLocuri;
	biletCategoria1* bileteCat1;
	int nrBileteCat1;
	biletCategoria2* bileteCat2;
	int nrBileteCat2;
	biletLoja* bileteLoja;
	int nrBileteLoja;
public:
	spectacolTeatru();
	spectacolTeatru(int nrMaximLocuri);
	int getNrBileteCat1();
	int getNrBileteCat2();
	int getNrBileteLoja();
	biletCategoria1 getBiletCat1(int i);
	biletCategoria2 getBiletCat2(int i);
	biletLoja getBiletLoja(int i);
	~spectacolTeatru();
};

