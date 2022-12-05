#pragma once
#include <iostream>
#include <string>
using namespace std;
class biletCategoria2
{
private:
	static int nrBilete;
	int id;
	bool ocupat;
	char* numeSpectator;
	int* UID;
	int dimUID;
public:
	biletCategoria2();
	biletCategoria2(const char*);
	biletCategoria2(const biletCategoria2&);
	biletCategoria2& operator=(const biletCategoria2&);
	friend ostream& operator<<(ostream&, biletCategoria2);
	friend istream& operator>>(istream&, biletCategoria2&);
	char operator[](int);
	biletCategoria2& operator++();
	biletCategoria2& operator++(int);
	~biletCategoria2();
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