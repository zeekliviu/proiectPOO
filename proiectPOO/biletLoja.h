#pragma once
#include <iostream>
using namespace std;
class biletLoja
{
private:
	static int id;
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
	bool getOccupancy();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	bool checkUID(char*);
	void setId(const int);
	void setNumeSpectator(const char*);
};
