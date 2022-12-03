#pragma once
#include <iostream>
#include "biletCategoria1.h"
#include "biletCategoria2.h"
#include "biletLoja.h"
using namespace std;
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
	static int nrSpectacol;
public:
	spectacolTeatru();
	spectacolTeatru(const int); 
	spectacolTeatru(const char*); 
	spectacolTeatru(const char*, const char*); 
	spectacolTeatru(const char*, const char*, const char*);
	spectacolTeatru(const int, const char*); 
	spectacolTeatru(const int, const char*, const char*); 
	spectacolTeatru(const int, const char*, const char*, const char*); 
	spectacolTeatru(const int, const char*, const int); 
	spectacolTeatru(const int, const char*, const char*, const int);
	spectacolTeatru(const int, const char*, const char*, const char*, const int);
	spectacolTeatru(const int, const char*, const int, const int); 
	spectacolTeatru(const int, const char*, const char*, const int, const int);
	spectacolTeatru(const int, const char*, const char*, const char*, const int, const int); 
	spectacolTeatru(const int, const char*, const int, const int, const int, const int); 
	spectacolTeatru(const int, const char*, const char*, const int, const int, const int, const int); 
	spectacolTeatru(const int, const char*, const char*, const char*, const int, const int, const int, const int); 
	spectacolTeatru(const int, const char*, const int, const int, const int, const int, const int, const int);
	spectacolTeatru(const int, const char*, const char*, const int, const int, const int, const int, const int, const int);
	spectacolTeatru(const int, const char*, const char*, const char*, const int, const int, const int, const int, const int, const int);
	spectacolTeatru(const spectacolTeatru&);
	spectacolTeatru& operator=(const spectacolTeatru&);
	friend ostream& operator<<(ostream&, spectacolTeatru);
	friend istream& operator>>(istream&, spectacolTeatru&);
	operator int();
	bool operator!();
	~spectacolTeatru();
	char* getDenumire();
	char* getData();
	char* getOra();
	int getNrMaximLocuri();
	int getNrLocuriDisponibileCat1(); 
	int getNrLocuriDisponibileCat2(); 
	int getNrLocuriDisponibileLoja();
	int getNrLocuriOcupateCat1();
	int getNrLocuriOcupateCat2();
	int getNrLocuriOcupateLoja();
	int getNrRanduriCat1();
	int getNrRanduriCat2();
	int getNrRanduriLoja();
	int getNrBileteCat1();
	int getNrBileteCat2();
	int getNrBileteLoja();
	biletCategoria1** getBileteCat1();
	biletCategoria2** getBileteCat2();
	biletLoja** getBileteLoja();
	biletCategoria1* getRandCat1(int);
	biletCategoria2* getRandCat2(int);
	biletLoja* getRandLoja(int);
	biletCategoria1& getBiletCat1(int, int);
	biletCategoria2& getBiletCat2(int, int);
	biletLoja& getBiletLoja(int, int);
	void setDenumire(const char*);
	void setData(const char*);
	void setOra(const char*);
	void setBileteCat1(int, int, biletCategoria1**);
	void setBileteCat2(int, int, biletCategoria2**);
	void setBileteLoja(int, int, biletLoja**);
	static void setnrSpectacol(const int);
	int* rezervaBiletCat1(int, int);
	int* rezervaBiletCat2(int, int); 
	int* rezervaBiletLoja(int, int);
	int maximdimUIDCat1();
	int maximdimUIDCat2();
	int maximdimUIDLoja();
	int maximdimUIDTotal();
};

