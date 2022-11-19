#pragma once
class biletLoja
{
private:
	int id;
	char* numeSpectator;
	int* UID;
	int dimUID;
public:
	biletLoja();
	biletLoja(int);
	biletLoja(int, const char*);
	biletLoja(const char*, int);
	biletLoja(const biletLoja&);
	biletLoja& operator=(const biletLoja&);
	~biletLoja();
	int getId();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	bool checkUID(int*, int);
	void setId(const int);
	void setNumeSpectator(const char*);
};