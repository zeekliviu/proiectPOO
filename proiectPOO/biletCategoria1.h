#pragma once
class biletCategoria1
{
private:
	int id;
	char* numeSpectator;
	int* UID;
	int dimUID;
public:
	biletCategoria1();
	biletCategoria1(int);
	biletCategoria1(int, const char*);
	biletCategoria1(const char*, int);
	biletCategoria1(const biletCategoria1&);
	biletCategoria1& operator=(const biletCategoria1&);
	friend std::ostream& operator<<(std::ostream&, const biletCategoria1&);
	friend std::istream& operator>>(std::istream&, biletCategoria1&);
	bool operator==(const biletCategoria1&);
	bool operator<(const biletCategoria1&);
	~biletCategoria1();
	int getId();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	bool checkUID(char*);
	void setId(const int);
	void setNumeSpectator(const char*);
};