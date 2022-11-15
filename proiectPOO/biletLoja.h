#pragma once
class biletLoja
{
	char* id;
public:
	biletLoja();
	biletLoja(char* id);
	char* getId();
	void setId(const char* s);
};