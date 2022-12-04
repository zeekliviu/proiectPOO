#include "data.h"
data::data()
{
	zi = 0;
	luna = 0;
	an = 0;
}
data::data(const char* str) : data()
{}
data::data(char c) : data()
{}
data::data(int zi) : data()
{
	if (zi > 0 && zi < 32)
		this->zi = zi;
	else this->zi = 0;
}
data::data(int zi, const char* str) : data(zi)
{}
data::data(int zi, const char* str1, const char* str2) : data(zi)
{}
data::data(int zi, char c) : data(zi)
{}
data::data(int zi, char c, char cx) : data(zi)
{}
data::data(int zi, int luna) : data(zi)
{
	if (luna > 0 && luna < 13)
		this->luna = luna;
	else this->luna = 0;
	if (luna == 2)
	{
		if (zi > 0 && zi < 29)
			this->zi = zi;
		else this->zi = 0;
	}
	else if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
	{
		if (zi > 0 && zi < 32)
			this->zi = zi;
		else this->zi = 0;
	}
	else if (luna == 4 || luna == 6 || luna == 9 || luna == 11)
	{
		if (zi > 0 && zi < 31)
			this->zi = zi;
		else this->zi = 0;
	}
}
data::data(int zi, int luna, int an) : data(zi, luna)
{
	bool bisect;
	if (an > 0)
	{
		if (an % 4 == 0)
		{
			if (an % 100 == 0)
			{
				if (an % 400 == 0)
					bisect = true;
				else bisect = false;
			}
			else bisect = true;
		}
		else bisect = false;
		this->an = an;
	}
	else
		bisect = false;
	if (luna == 2)
		if (bisect)
		{
			if (zi > 0 && zi < 30)
				this->zi = zi;
			else
				this->zi = 0;
		}
		else
		{
			if (zi > 0 && zi < 29)
				this->zi = zi;
			else this->zi = 0;
		}
}
bool data::verificaData()
{
	if (zi == 0 || luna == 0 || an == 0)
		return false;
	return true;
}