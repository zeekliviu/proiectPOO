#pragma once
class timp
{
private:
	int ora, minut;
	bool flag;
public:
	timp();
	timp(int);
	timp(int, int);
	bool getFlag();
	bool verificaTimp();
};

