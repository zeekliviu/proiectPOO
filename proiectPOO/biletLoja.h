#pragma once
#include <iostream>
using namespace std;
class biletLoja
{
private:
	static int id;
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
	int getId();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	bool checkUID(char*);
	void setId(const int);
	void setNumeSpectator(const char*);
};
