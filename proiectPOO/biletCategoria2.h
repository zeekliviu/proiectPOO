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
	bool getOccupancy();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	bool checkUID(char*);
	void setOccupancy(bool);
	void setNumeSpectator(const char*);
};
