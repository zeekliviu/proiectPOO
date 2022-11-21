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
	friend std::ostream& operator<<(std::ostream&, const biletCategoria2&);
	friend std::istream& operator>>(std::istream&, biletCategoria2&);
	int operator[](int);
	biletCategoria2 operator++();
	biletCategoria2 operator++(int);
	~biletCategoria2();
	int getId();
	char* getNumeSpectator();
	int* getUID();
	int getdimUID();
	bool checkUID(char*);
	void setId(const int);
	void setNumeSpectator(const char*);
};
