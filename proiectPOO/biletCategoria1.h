#pragma once
#include <iostream>
#include <string>
using namespace std;
class biletCategoria1
{
private:
	static int nrBilete;
	int id;
	bool ocupat;
	char* numeSpectator;
	int* UID;
	int dimUID;
public:
	biletCategoria1();
	biletCategoria1(const char*);
	biletCategoria1(const biletCategoria1&);
	biletCategoria1& operator=(const biletCategoria1&);
	friend ostream& operator<<(ostream&, biletCategoria1);
	friend istream& operator>>(istream&, biletCategoria1&);
	bool operator==(const biletCategoria1&);
	bool operator<(const biletCategoria1&);
	~biletCategoria1();
	bool getOccupancy();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	bool checkUID(char*);
	void setOccupancy(bool);
	void setNumeSpectator(const char*);
};