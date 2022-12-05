#include "timp.h"
timp::timp()
{
	ora = 0;
	minut = 0;
	flag = false;
}
timp::timp(int ora): timp()
{
	if (ora > -1 && ora < 24)
		this->ora = ora;
	else
		flag = true;
}
timp::timp(int ora, int minut) : timp(ora)
{
	if (minut > -1 && minut < 60)
		this->minut = minut;
	else
		flag = true;
}
timp::timp(const timp& t)
{
	ora = t.ora;
	minut = t.minut;
	flag = t.flag;
}
timp& timp::operator=(const timp& t)
{
	if (this != &t)
	{
		ora = t.ora;
		minut = t.minut;
		flag = t.flag;
	}
	return *this;
}
ostream& operator<<(ostream& out, timp t)
{
	if (t.flag == false)
	{
		if (t.ora < 10)
			out << "0";
		out << t.ora << ":";
		if (t.minut < 10)
			out << "0";
		out << t.minut;
	}
	else
		out << "Timpul nu este valid";
	return out;
}
istream& operator>>(istream& in, timp& t)
{
	cout << "Ora: ";
	in >> t.ora;
	while (t.verificaOra() == false)
	{
		cout << "Ora nu este valida. Introduceti o ora valida: ";
		in >> t.ora;
	}
	cout << "Minut: ";
	while (t.verificaMinut() == false)
	{
		cout << "Minutul nu este valid. Introduceti un minut valid: ";
		in >> t.minut;
	}
	in >> t.minut;
	t.verificaTimp();
	return in;
}
timp& timp::operator-(const timp& t)
{
	timp* rezultat = new timp();
	if (this->flag == false && t.flag == false)
	{
		rezultat->minut = this->minut - t.minut;
		if (rezultat->minut < 0)
		{
			rezultat->minut = 60 + rezultat->minut;
			rezultat->ora--;
		}
		rezultat->ora += (this->ora - t.ora);
		if (rezultat->ora < 0)
			rezultat->ora = 24 + rezultat->ora;
	}
	else
		rezultat->flag = true;
	return *rezultat;
}
bool timp::operator<=(const timp& t)
{
	if (this->flag == false && t.flag == false)
	{
		if (this->ora < t.ora)
			return true;
		else if (this->ora == t.ora)
			if (this->minut <= t.minut)
				return true;
	}
	return false;
}
bool timp::getFlag()
{
	return flag;
}
bool timp::verificaOra()
{
	if (ora > -1 && ora < 24)
		return true;
	else
		return false;
}
bool timp::verificaMinut()
{
	if (minut > -1 && minut < 60)
		return true;
	else
		return false;
}
bool timp::verificaTimp()
{
	if (flag)
		return false;
	return true;
}