#pragma once
#include "biletCategoria1.h"
#include "biletCategoria2.h"
#include "biletLoja.h"
class spectacolTeatru
{
private:
	char* denumire;
	char* data;
	char* ora;
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
	static int idSpectacol;
	spectacolTeatru(); // testat
	spectacolTeatru(const int); // testat
	spectacolTeatru(const char*); // pointerii data si ora se afiseaza cu valori random
	spectacolTeatru(const char*, const char*); // pointerul ora se afiseaza cu valori random
	spectacolTeatru(const char*, const char*, const char*); // testat
	spectacolTeatru(const int, const char*); // pointerii data si ora se afiseaza cu valori random
	spectacolTeatru(const int, const char*, const char*); // pointerul ora se afiseaza cu valori random
	spectacolTeatru(const int, const char*, const char*, const char*); // testat
	spectacolTeatru(const int, const char*, const int); // pointerii data si ora se afiseaza cu valori random
	spectacolTeatru(const int, const char*, const char*, const int); // pointerul ora se afiseaza cu valori random
	spectacolTeatru(const int, const char*, const char*, const char*, const int); //testat
	spectacolTeatru(const int, const char*, const int, const int); //testat
	spectacolTeatru(const int, const char*, const char*, const int, const int); //testat
	spectacolTeatru(const int, const char*, const char*, const char*, const int, const int); //testat
	spectacolTeatru(const int, const char*, const int, const int, const int, const int); //testat
	spectacolTeatru(const int, const char*, const char*, const int, const int, const int, const int); 
	spectacolTeatru(const int, const char*, const char*, const char*, const int, const int, const int, const int); // testat
	spectacolTeatru(const int, const char*, const int, const int, const int, const int, const int, const int); // testat
	spectacolTeatru(const int, const char*, const char*, const int, const int, const int, const int, const int, const int); // testat
	spectacolTeatru(const int, const char*, const char*, const char*, const int, const int, const int, const int, const int, const int); // testat
	spectacolTeatru(const spectacolTeatru&);
	char* getDenumire();
	char* getData();
	char* getOra();
	int getNrMaximLocuri();
	int getNrRanduriCat1();
	int getNrRanduriCat2();
	int getNrRanduriLoja();
	int getNrBileteCat1();
	int getNrBileteCat2();
	int getNrBileteLoja();
	biletCategoria1* getRandCat1(int);
	biletCategoria2* getRandCat2(int);
	biletLoja* getRandLoja(int);
	biletCategoria1 getBiletCat1(int, int);
	biletCategoria2 getBiletCat2(int, int);
	biletLoja getBiletLoja(int, int);
	~spectacolTeatru();
};

