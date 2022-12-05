#pragma once
#include <iostream>
#include <string>
using namespace std;
class biletLoja
{
private:
	static int nrBilete;
	int id;
	bool ocupat;
	char* numeSpectator;
	int* UID;
	int dimUID;
public:
	biletLoja();
	biletLoja(const char*);
	biletLoja(const biletLoja&);
	biletLoja& operator=(const biletLoja&);
	friend ostream& operator<<(ostream&, biletLoja);
	friend istream& operator>>(istream&, biletLoja&);
	bool operator>(const biletLoja&);
	bool operator>=(const biletLoja&);
	~biletLoja();
	static int getNrBilete();
	int getId();
	bool getOccupancy();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	void setNrBilete(int);
	void setId(int);
	void setOccupancy(bool);
	void setNumeSpectator(const char*);
	void setUID(int*, int);
	bool checkUID(char*);
};