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
data::data(const data& d)
{
	zi = d.zi;
	luna = d.luna;
	an = d.an;
}
class::data& data::operator=(const data& d)
{
	zi = d.zi;
	luna = d.luna;
	an = d.an;
	return *this;
}
ostream& operator<<(ostream& out, class::data d)
{
	out << d.zi << "/" << d.luna << "/" << d.an;
	return out;
}
istream& operator>>(istream& in, class::data& d)
{
	cout << "Anul: ";
	in >> d.an;
	while (d.an < 0)
	{
		cout << "Anul trebuie sa fie pozitiv! Introduceti un an valid: ";
		in >> d.an;
	}
	bool bisect;
	if (d.an % 4 == 0)
	{
		if (d.an % 100 == 0)
		{
			if (d.an % 400 == 0)
				bisect = true;
			else bisect = false;
		}
		else bisect = true;
	}
	else bisect = false;
	cout << "Luna: ";
	in >> d.luna;
	while (d.luna < 1 || d.luna > 12)
	{
		cout << "Luna trebuie sa fie intre 1 si 12! Introduceti o luna valida: ";
		in >> d.luna;
	}
	if (d.luna == 2)
	{
		if (bisect)
		{
			cout << "Ziua: ";
			in >> d.zi;
			while (d.zi < 1 || d.zi > 29)
			{
				cout << "Ziua trebuie sa fie intre 1 si 29! Introduceti o zi valida: ";
				in >> d.zi;
			}
		}
		else
		{
			cout << "Ziua: ";
			in >> d.zi;
			while (d.zi < 1 || d.zi > 28)
			{
				cout << "Ziua trebuie sa fie intre 1 si 28! Introduceti o zi valida: ";
				in >> d.zi;
			}
		}
	}
	else if (d.luna == 1 || d.luna == 3 || d.luna == 5 || d.luna == 7 || d.luna == 8 || d.luna == 10 || d.luna == 12)
	{
		cout << "Ziua: ";
		in >> d.zi;
		while (d.zi < 1 || d.zi > 31)
		{
			cout << "Ziua trebuie sa fie intre 1 si 31! Introduceti o zi valida: ";
			in >> d.zi;
		}
	}
	else if (d.luna == 4 || d.luna == 6 || d.luna == 9 || d.luna == 11)
	{
		cout << "Ziua: ";
		in >> d.zi;
		while (d.zi < 1 || d.zi > 30)
		{
			cout << "Ziua trebuie sa fie intre 1 si 30! Introduceti o zi valida: ";
			in >> d.zi;
		}
	}
	return in;
}
class::data& data::operator+(const data& d)
{
	class::data* rezultat = new class::data;
	rezultat->an = an + d.an;
	bool bisect = data::isBisect(rezultat->an);
	rezultat->luna = luna + d.luna;
	if (rezultat->luna > 12)
	{
		rezultat->luna -= 12;
		rezultat->an++;
	}
	if (rezultat->luna == 2)
	{
		if (bisect)
		{
			if (zi + d.zi > 29)
			{
				rezultat->zi = zi + d.zi - 29;
				rezultat->luna++;
			}
			else rezultat->zi = zi + d.zi;
		}
		else
		{
			if (zi + d.zi > 28)
			{
				rezultat->zi = zi + d.zi - 28;
				rezultat->luna++;
			}
			else rezultat->zi = zi + d.zi;
		}
	}
	else if (rezultat->luna == 1 || rezultat->luna == 3 || rezultat->luna == 5 || rezultat->luna == 7 || rezultat->luna == 8 || rezultat->luna == 10 || rezultat->luna == 12)
	{
		if (zi + d.zi > 31)
		{
			rezultat->zi = zi + d.zi - 31;
			rezultat->luna++;
		}
		else rezultat->zi = zi + d.zi;
	}
	else if (rezultat->luna == 4 || rezultat->luna == 6 || rezultat->luna == 9 || rezultat->luna == 11)
	{
		if (zi + d.zi > 30)
		{
			rezultat->zi = zi + d.zi - 30;
			rezultat->luna++;
		}
		else rezultat->zi = zi + d.zi;
	}
	return *rezultat;
}
class::data data::operator--()
{
	zi--;
	if (zi == 0)
	{
		luna--;
		if (luna == 0)
		{
			luna = 12;
			an--;
		}
		if (luna == 2)
		{
			if (data::isBisect(an))
				zi = 29;
			else zi = 28;
		}
		else if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
			zi = 31;
		else if (luna == 4 || luna == 6 || luna == 9 || luna == 11)
			zi = 30;
	}
	return *this;
}
class::data data::operator--(int)
{
	data copie = *this;
	zi--;
	if (zi == 0)
	{
		luna--;
		if (luna == 0)
		{
			luna = 12;
			an--;
		}
		if (luna == 2)
		{
			if (data::isBisect(an))
				zi = 29;
			else zi = 28;
		}
		else if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12)
			zi = 31;
		else if (luna == 4 || luna == 6 || luna == 9 || luna == 11)
			zi = 30;
	}
	return copie;
}
int data::getZi()
{
	return zi;
}
int data::getLuna()
{
	return luna;
}
int data::getAn()
{
	return an;
}
void data::setZi(int z)
{
	if (z > 0 && z < 32)
		zi = z;
	if (luna == 2)
		if (data::isBisect(an))
		{
			if (zi > 29)
				luna = 0;
		}
		else if (zi > 28) luna = 0;

}
void data::setLuna(int l)
{
	if (l > 0 && l < 13)
		luna = l;
	if (luna == 2)
		if (data::isBisect(an))
		{
			if (zi > 29)
				zi = 0;
		}
		else if (zi > 28) zi = 0;
}
void data::setAn(int a)
{
	if (a > 0)
		an = a;
}
bool data::verificaData()
{
	if (zi == 0 || luna == 0 || an == 0)
		return false;
	return true;
}
bool data::isBisect(int an)
{
	if (an % 4 == 0)
	{
		if (an % 100 == 0)
		{
			if (an % 400 == 0)
				return true;
			else return false;
		}
		else return true;
	}
	else return false;
}