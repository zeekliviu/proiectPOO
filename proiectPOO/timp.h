#pragma once
#include <iostream>
using namespace std;
class timp
{
private:
	int ora, minut;
	bool flag;
public:
	timp();
	timp(int);
	timp(int, int);
	timp(const timp&);
	timp& operator=(const timp&);
	friend ostream& operator<<(ostream&, timp);
	friend istream& operator>>(istream&, timp&);
	timp& operator-(const timp&);
	bool operator<=(const timp&);
	bool getFlag();
	bool verificaOra();
	bool verificaMinut();
	bool verificaTimp();
};

