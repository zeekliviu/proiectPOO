#pragma once
class biletCategoria2
{
private:
	int id;
	char* numeSpectator;
	int* UID;
	int dimUID;
public:
	biletCategoria2();
	biletCategoria2(int);
	biletCategoria2(int, const char*);
	biletCategoria2(const char*, int);
	biletCategoria2(const biletCategoria2&);
	biletCategoria2& operator=(const biletCategoria2&);
	~biletCategoria2();
	int getId();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	bool checkUID(int*, int);
	void setId(const int);
	void setNumeSpectator(const char*);
};