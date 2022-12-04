#pragma once
class data
{
private:
	int zi, luna, an;
public:
	data();
	data(const char*);
	data(char);
	data(int);
	data(int, const char*);
	data(int, const char*, const char*);
	data(int, char);
	data(int, char, char);
	data(int, int);
	data(int, int, int);
	bool verificaData();
};

