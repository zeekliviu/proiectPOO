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
bool timp::getFlag()
{
	return flag;
}
bool timp::verificaTimp()
{
	if (flag)
		return false;
	return true;
}