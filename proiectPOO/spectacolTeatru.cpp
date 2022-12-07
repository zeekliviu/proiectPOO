#include "spectacolTeatru.h"
int spectacolTeatru::nrSpectacol = 0;
spectacolTeatru::spectacolTeatru() : nrMaximLocuri(0)
{
	bileteCat1 = nullptr;
	bileteCat2 = nullptr;
	bileteLoja = nullptr;
	nrBileteCat1 = nrMaximLocuri;
	nrBileteCat2 = nrMaximLocuri;
	nrBileteLoja = nrMaximLocuri;
	nrRanduriCat1 = nrMaximLocuri;
	nrRanduriCat2 = nrMaximLocuri;
	nrRanduriLoja = nrMaximLocuri;
	denumire = new char[strlen("TBA") + 1];
	strcpy_s(denumire, strlen("TBA") + 1, "TBA");
	data = new char[strlen("TBA") + 1];
	strcpy_s(data, strlen("TBA") + 1, "TBA");
	ora = new char[strlen("TBA") + 1];
	strcpy_s(ora, strlen("TBA") + 1, "TBA");
	nrSpectacol++;
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri) : nrMaximLocuri(nrMaximLocuri)
{
	bileteCat1 = nullptr;
	bileteCat2 = nullptr;
	bileteLoja = nullptr;
	nrBileteCat1 = 0;
	nrBileteCat2 = 0;
	nrBileteLoja = 0;
	nrRanduriCat1 = 0;
	nrRanduriCat2 = 0;
	nrRanduriLoja = 0;
	denumire = new char[strlen("TBA") + 1];
	strcpy_s(denumire, strlen("TBA") + 1, "TBA");
	data = new char[strlen("TBA") + 1];
	strcpy_s(data, strlen("TBA") + 1, "TBA");
	ora = new char[strlen("TBA") + 1];
	strcpy_s(ora, strlen("TBA") + 1, "TBA");
	nrSpectacol++;
}
spectacolTeatru::spectacolTeatru(const char* denumire) : nrMaximLocuri(0)
{
	data = new char[strlen("TBA") + 1];
	strcpy_s(data, strlen("TBA") + 1, "TBA");
	ora = new char[strlen("TBA") + 1];
	strcpy_s(ora, strlen("TBA") + 1, "TBA");
	bileteCat1 = nullptr;
	bileteCat2 = nullptr;
	bileteLoja = nullptr;
	nrBileteCat1 = nrMaximLocuri;
	nrBileteCat2 = nrMaximLocuri;
	nrBileteLoja = nrMaximLocuri;
	nrRanduriCat1 = nrMaximLocuri;
	nrRanduriCat2 = nrMaximLocuri;
	nrRanduriLoja = nrMaximLocuri;
	if (denumire != nullptr && strlen(denumire) > 0)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else
	{
		this->denumire = new char[strlen("TBA") + 1];
		strcpy_s(this->denumire, strlen("TBA") + 1, "TBA");
	}
	nrSpectacol++;
}
spectacolTeatru::spectacolTeatru(const char* denumire, const char* data): spectacolTeatru(denumire)
{
	if (data != nullptr)
	{
		if (strlen(data) == 10)
		{
			int an, luna, zi;
			an = atoi(data + 6);
			luna = atoi(data + 3);
			zi = atoi(data);
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
			{
				if (this->data != nullptr)
					delete[] this->data;
				this->data = new char[strlen(data) + 1];
				strcpy_s(this->data, strlen(data) + 1, data);
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const char* denumire, const char* data, const char* ora) : spectacolTeatru(denumire, data)
{
	if (ora != nullptr)
	{
		if (strlen(ora) == 5)
		{
			int o, minut;
			o = atoi(ora);
			minut = atoi(ora + 3);
			int copie_ora = o, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (ora[0] == '0')
				nrCifOra++;
			if (ora[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, ora, 2);
			strncpy_s(bufMin, ora + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				class::timp t = timp::timp(o, minut);
				if (!t.getFlag())
				{
					if (this->ora != nullptr)
						delete[] this->ora;
					this->ora = new char[strlen(ora) + 1];
					strcpy_s(this->ora, strlen(ora) + 1, ora);
				}
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire) : spectacolTeatru(nrMaximLocuri)
{
	if (denumire != nullptr && strlen(denumire) > 0)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
	else
	{
		this->denumire = new char[strlen("TBA") + 1];
		strcpy_s(this->denumire, strlen("TBA") + 1, "TBA");
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data) : spectacolTeatru(nrMaximLocuri, denumire)
{
	if (data != nullptr)
	{
		if (strlen(data) == 10)
		{
			int an, luna, zi;
			an = atoi(data + 6);
			luna = atoi(data + 3);
			zi = atoi(data);
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
			{
				if (this->data != nullptr)
					delete[] this->data;
				this->data = new char[strlen(data) + 1];
				strcpy_s(this->data, strlen(data) + 1, data);
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora) : spectacolTeatru(nrMaximLocuri, denumire, data)
{
	if (ora != nullptr)
	{
		if (strlen(ora) == 5)
		{
			int o, minut;
			o = atoi(ora);
			minut = atoi(ora + 3);
			int copie_ora = o, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (ora[0] == '0')
				nrCifOra++;
			if (ora[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, ora, 2);
			strncpy_s(bufMin, ora + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				class::timp t = timp::timp(o, minut);
				if (!t.getFlag())
				{
					if (this->ora != nullptr)
						delete[] this->ora;
					this->ora = new char[strlen(ora) + 1];
					strcpy_s(this->ora, strlen(ora) + 1, ora);
				}
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, int nrRanduriLocuriCat1Cat2Loja): spectacolTeatru(nrMaximLocuri, denumire)
{
	if (nrRanduriLocuriCat1Cat2Loja > 0 && nrRanduriLocuriCat1Cat2Loja * nrRanduriLocuriCat1Cat2Loja <= nrMaximLocuri)
	{
		bileteCat1 = new biletCategoria1 * [nrRanduriLocuriCat1Cat2Loja];
		for (int i = 0; i < nrRanduriLocuriCat1Cat2Loja; i++)
		{
			bileteCat1[i] = new biletCategoria1[nrRanduriLocuriCat1Cat2Loja];
		}
		nrBileteCat1 = nrRanduriCat1 = nrRanduriLocuriCat1Cat2Loja;
		if (nrMaximLocuri - 2 * nrRanduriLocuriCat1Cat2Loja * nrRanduriLocuriCat1Cat2Loja >= 0)
		{
			bileteCat2 = new biletCategoria2 * [nrRanduriLocuriCat1Cat2Loja];
			for (int i = 0; i < nrRanduriLocuriCat1Cat2Loja; i++)
				bileteCat2[i] = new biletCategoria2[nrRanduriLocuriCat1Cat2Loja];
			nrBileteCat2 = nrRanduriCat2 = nrRanduriLocuriCat1Cat2Loja;
			if (nrMaximLocuri - 3 * nrRanduriLocuriCat1Cat2Loja * nrRanduriLocuriCat1Cat2Loja >= 0)
			{
				bileteLoja = new biletLoja * [nrRanduriLocuriCat1Cat2Loja];
				for (int i = 0; i < nrRanduriLocuriCat1Cat2Loja; i++)
					bileteLoja[i] = new biletLoja[nrRanduriLocuriCat1Cat2Loja];
				nrBileteLoja = nrRanduriLoja = nrRanduriLocuriCat1Cat2Loja;
			}
			else
			{
				bileteLoja = nullptr;
				nrBileteLoja = nrRanduriLoja = 0;
			}
		}
		else
		{
			bileteCat2 = nullptr;
			bileteLoja = nullptr;
			nrBileteCat2 = nrRanduriCat2 = nrRanduriLoja = nrBileteLoja = 0;
		}
	}
	else
	{
		bileteCat1 = nullptr;
		bileteCat2 = nullptr;
		bileteLoja = nullptr;
		nrRanduriCat1 = nrRanduriCat2 = nrRanduriLoja = nrBileteCat1 = nrBileteCat2 = nrBileteLoja = 0;
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, int nrRanduriLocuriCat1Cat2Loja) : spectacolTeatru(nrMaximLocuri, denumire, nrRanduriLocuriCat1Cat2Loja)
{
	if (data != nullptr)
	{
		if (strlen(data) == 10)
		{
			int an, luna, zi;
			an = atoi(data + 6);
			luna = atoi(data + 3);
			zi = atoi(data);
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
			{
				if (this->data != nullptr)
					delete[] this->data;
				this->data = new char[strlen(data) + 1];
				strcpy_s(this->data, strlen(data) + 1, data);
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora, int nrRanduriLocuriCat1Cat2Loja) : spectacolTeatru(nrMaximLocuri, denumire, data, nrRanduriLocuriCat1Cat2Loja)
{
	if (ora != nullptr)
	{
		if (strlen(ora) == 5)
		{
			int o, minut;
			o = atoi(ora);
			minut = atoi(ora + 3);
			int copie_ora = o, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (ora[0] == '0')
				nrCifOra++;
			if (ora[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, ora, 2);
			strncpy_s(bufMin, ora + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				class::timp t = timp::timp(o, minut);
				if (!t.getFlag())
				{
					if (this->ora != nullptr)
						delete[] this->ora;
					this->ora = new char[strlen(ora) + 1];
					strcpy_s(this->ora, strlen(ora) + 1, ora);
				}
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, int nrRanduriCat1, int nrBileteCat1): spectacolTeatru(nrMaximLocuri, denumire)
{
	if ((nrRanduriCat1 * nrBileteCat1 <= nrMaximLocuri) && nrRanduriCat1 > 0 && nrBileteCat1 > 0)
	{
		bileteCat1 = new biletCategoria1 * [nrRanduriCat1];
		for (int i = 0; i < nrRanduriCat1; i++)
			bileteCat1[i] = new biletCategoria1[nrBileteCat1];
		this->nrRanduriCat1 = nrRanduriCat1;
		this->nrBileteCat1 = nrBileteCat1;
	}
	else {
		bileteCat1 = nullptr;
		this->nrRanduriCat1 = this->nrBileteCat1 = 0;
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, int nrRanduriCat1, int nrBileteCat1): spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1)
{
	if (data != nullptr)
	{
		if (strlen(data) == 10)
		{
			int an, luna, zi;
			an = atoi(data + 6);
			luna = atoi(data + 3);
			zi = atoi(data);
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
			{
				if (this->data != nullptr)
					delete[] this->data;
				this->data = new char[strlen(data) + 1];
				strcpy_s(this->data, strlen(data) + 1, data);
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora, int nrRanduriCat1, int nrBileteCat1) : spectacolTeatru(nrMaximLocuri, denumire, data, nrRanduriCat1, nrBileteCat1)
{
	if (ora != nullptr)
	{
		if (strlen(ora) == 5)
		{
			int o, minut;
			o = atoi(ora);
			minut = atoi(ora + 3);
			int copie_ora = o, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (ora[0] == '0')
				nrCifOra++;
			if (ora[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, ora, 2);
			strncpy_s(bufMin, ora + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				class::timp t = timp::timp(o, minut);
				if (!t.getFlag())
				{
					if (this->ora != nullptr)
						delete[] this->ora;
					this->ora = new char[strlen(ora) + 1];
					strcpy_s(this->ora, strlen(ora) + 1, ora);
				}
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, int nrRanduriCat1, int nrBileteCat1, int nrRanduriCat2, int nrBileteCat2): spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1)
{

	if ((nrRanduriCat1 * nrBileteCat1 + nrRanduriCat2 * nrBileteCat2 <= nrMaximLocuri) && nrRanduriCat2 > 0 && nrBileteCat2 > 0)
	{
		bileteCat2 = new biletCategoria2 * [nrRanduriCat2];
		for (int i = 0; i < nrRanduriCat2; i++)
			bileteCat2[i] = new biletCategoria2[nrBileteCat2];
		this->nrRanduriCat2 = nrRanduriCat2;
		this->nrBileteCat2 = nrBileteCat2;
	}
	else {
		bileteCat2 = nullptr;
		this->nrRanduriCat2 = this->nrBileteCat2 = 0;
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, int nrRanduriCat1, int nrBileteCat1, int nrRanduriCat2, int nrBileteCat2) : spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2)
{
	if (data != nullptr)
	{
		if (strlen(data) == 10)
		{
			int an, luna, zi;
			an = atoi(data + 6);
			luna = atoi(data + 3);
			zi = atoi(data);
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
			{
				if (this->data != nullptr)
					delete[] this->data;
				this->data = new char[strlen(data) + 1];
				strcpy_s(this->data, strlen(data) + 1, data);
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora, int nrRanduriCat1, int nrBileteCat1, int nrRanduriCat2, int nrBileteCat2) : spectacolTeatru(nrMaximLocuri, denumire, data, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2)
{
	if (ora != nullptr)
	{
		if (strlen(ora) == 5)
		{
			int o, minut;
			o = atoi(ora);
			minut = atoi(ora + 3);
			int copie_ora = o, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (ora[0] == '0')
				nrCifOra++;
			if (ora[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, ora, 2);
			strncpy_s(bufMin, ora + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				class::timp t = timp::timp(o, minut);
				if (!t.getFlag())
				{
					if (this->ora != nullptr)
						delete[] this->ora;
					this->ora = new char[strlen(ora) + 1];
					strcpy_s(this->ora, strlen(ora) + 1, ora);
				}
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, int nrRanduriCat1, int nrBileteCat1, int nrRanduriCat2, int nrBileteCat2, int nrRanduriLoja, int nrBileteLoja) : spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2)
{
	if ((nrRanduriCat1 * nrBileteCat1 + nrRanduriCat2 * nrBileteCat2 + nrRanduriLoja * nrBileteLoja <= nrMaximLocuri) && nrRanduriLoja > 0 && nrBileteLoja > 0)
	{
		bileteLoja = new biletLoja * [nrRanduriLoja];
		for (int i = 0; i < nrRanduriLoja; i++)
			bileteLoja[i] = new biletLoja[nrBileteLoja];
		this->nrRanduriLoja = nrRanduriLoja;
		this->nrBileteLoja = nrBileteLoja;
	}
	else
	{
		bileteLoja = nullptr;
		this->nrRanduriLoja = this->nrBileteLoja = 0;
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, int nrRanduriCat1, int nrBileteCat1, int nrRanduriCat2, int nrBileteCat2, int nrRanduriLoja, int nrBileteLoja) : spectacolTeatru(nrMaximLocuri, denumire, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2, nrRanduriLoja, nrBileteLoja)
{
	if (data != nullptr)
	{
		if (strlen(data) == 10)
		{
			int an, luna, zi;
			an = atoi(data + 6);
			luna = atoi(data + 3);
			zi = atoi(data);
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
			{
				if (this->data != nullptr)
					delete[] this->data;
				this->data = new char[strlen(data) + 1];
				strcpy_s(this->data, strlen(data) + 1, data);
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const int nrMaximLocuri, const char* denumire, const char* data, const char* ora, int nrRanduriCat1, int nrBileteCat1, int nrRanduriCat2, int nrBileteCat2, int nrRanduriLoja, int nrBileteLoja) : spectacolTeatru(nrMaximLocuri, denumire, data, nrRanduriCat1, nrBileteCat1, nrRanduriCat2, nrBileteCat2, nrRanduriLoja, nrBileteLoja)
{
	if (ora != nullptr)
	{
		if (strlen(ora) == 5)
		{
			int o, minut;
			o = atoi(ora);
			minut = atoi(ora + 3);
			int copie_ora = o, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (ora[0] == '0')
				nrCifOra++;
			if (ora[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, ora, 2);
			strncpy_s(bufMin, ora + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				class::timp t = timp::timp(o, minut);
				if (!t.getFlag())
				{
					if (this->ora != nullptr)
						delete[] this->ora;
					this->ora = new char[strlen(ora) + 1];
					strcpy_s(this->ora, strlen(ora) + 1, ora);
				}
			}
		}
	}
}
spectacolTeatru::spectacolTeatru(const spectacolTeatru& st): nrMaximLocuri(st.nrMaximLocuri)
{
	denumire = new char[strlen(st.denumire) + 1];
	strcpy_s(denumire, strlen(st.denumire) + 1, st.denumire);
	data = new char[strlen(st.data) + 1];
	strcpy_s(data, strlen(st.data) + 1, st.data);
	ora = new char[strlen(st.ora) + 1];
	strcpy_s(ora, strlen(st.ora) + 1, st.ora);
	if (st.nrRanduriCat1 > 0 && st.nrBileteCat1 > 0)
	{
		if (st.bileteCat1 != nullptr)
		{
			bileteCat1 = new biletCategoria1 * [st.nrRanduriCat1];
			for (int i = 0; i < st.nrRanduriCat1; i++)
				bileteCat1[i] = new biletCategoria1[st.nrBileteCat1];
			nrRanduriCat1 = st.nrRanduriCat1;
			nrBileteCat1 = st.nrBileteCat1;
			for (int i = 0; i < st.nrRanduriCat1; i++)
				for (int j = 0; j < st.nrBileteCat1; j++)
					bileteCat1[i][j] = st.bileteCat1[i][j];
		}
	}
	else
	{
		bileteCat1 = nullptr;
		nrRanduriCat1 = nrBileteCat1 = 0;
	}
	if (st.nrRanduriCat2 > 0 && st.nrBileteCat2 > 0)
	{
		if (st.bileteCat2 != nullptr)
		{
			bileteCat2 = new biletCategoria2 * [st.nrRanduriCat2];
			for (int i = 0; i < st.nrRanduriCat2; i++)
				bileteCat2[i] = new biletCategoria2[st.nrBileteCat2];
			nrRanduriCat2 = st.nrRanduriCat2;
			nrBileteCat2 = st.nrBileteCat2;
			for (int i = 0; i < st.nrRanduriCat2; i++)
				for (int j = 0; j < st.nrBileteCat2; j++)
					bileteCat2[i][j] = st.bileteCat2[i][j];
		}
	}
	else
	{
		bileteCat2 = nullptr;
		nrRanduriCat2 = nrBileteCat2 = 0;
	}
	if (st.nrRanduriLoja > 0 && st.nrBileteLoja > 0)
	{
		if (st.bileteLoja != nullptr)
		{
			bileteLoja = new biletLoja * [st.nrRanduriLoja];
			for (int i = 0; i < st.nrRanduriLoja; i++)
				bileteLoja[i] = new biletLoja[st.nrBileteLoja];
			nrRanduriLoja = st.nrRanduriLoja;
			nrBileteLoja = st.nrBileteLoja;
			for (int i = 0; i < st.nrRanduriLoja; i++)
				for (int j = 0; j < st.nrBileteLoja; j++)
					bileteLoja[i][j] = st.bileteLoja[i][j];
		}
	}
	else
	{
		bileteLoja = nullptr;
		nrRanduriLoja = nrBileteLoja = 0;
	}
	nrSpectacol++;
}
spectacolTeatru& spectacolTeatru::operator=(const spectacolTeatru& st)
{
	if(this!=&st)
	{
		if (denumire != nullptr)
			delete[] denumire, denumire = nullptr;
		denumire = new char[strlen(st.denumire) + 1];
		strcpy_s(denumire, strlen(st.denumire) + 1, st.denumire);
		if (data != nullptr)
			delete[] data, data = nullptr;
		data = new char[strlen(st.data) + 1];
		strcpy_s(data, strlen(st.data) + 1, st.data);
		if (ora != nullptr)
			delete[] ora, ora = nullptr;
		ora = new char[strlen(st.ora) + 1];
		strcpy_s(ora, strlen(st.ora) + 1, st.ora);
		if (st.nrRanduriCat1 > 0 && st.nrBileteCat1 > 0)
		{
			if (bileteCat1)
			{
				for (int i = 0; i < nrRanduriCat1; i++)
					delete[] bileteCat1[i];
				delete[] bileteCat1;
				nrRanduriCat1 = nrBileteCat1 = 0;
			}
			if (st.bileteCat1 != nullptr)
			{
				bileteCat1 = new biletCategoria1 * [st.nrRanduriCat1];
				for (int i = 0; i < st.nrRanduriCat1; i++)
					bileteCat1[i] = new biletCategoria1[st.nrBileteCat1];
				nrRanduriCat1 = st.nrRanduriCat1;
				nrBileteCat1 = st.nrBileteCat1;
				for (int i = 0; i < st.nrRanduriCat1; i++)
					for (int j = 0; j < st.nrBileteCat1; j++)
						bileteCat1[i][j] = st.bileteCat1[i][j];
			}
		}
		else
		{
			bileteCat1 = nullptr;
			nrRanduriCat1 = nrBileteCat1 = 0;
		}
		if (st.nrRanduriCat2 > 0 && st.nrBileteCat2 > 0)
		{
			if (bileteCat2)
			{
				for (int i = 0; i < nrRanduriCat2; i++)
					delete[] bileteCat2[i];
				delete[] bileteCat2;
				nrRanduriCat2 = nrBileteCat2 = 0;
			}
			if (st.bileteCat2 != nullptr)
			{
				bileteCat2 = new biletCategoria2 * [st.nrRanduriCat2];
				for (int i = 0; i < st.nrRanduriCat2; i++)
					bileteCat2[i] = new biletCategoria2[st.nrBileteCat2];
				nrRanduriCat2 = st.nrRanduriCat2;
				nrBileteCat2 = st.nrBileteCat2;
				for (int i = 0; i < st.nrRanduriCat2; i++)
					for (int j = 0; j < st.nrBileteCat2; j++)
						bileteCat2[i][j] = st.bileteCat2[i][j];
			}
		}
		else
		{
			bileteCat2 = nullptr;
			nrRanduriCat2 = nrBileteCat2 = 0;
		}
		if (st.nrRanduriLoja > 0 && st.nrBileteLoja > 0)
		{
			if (bileteLoja)
			{
				for (int i = 0; i < nrRanduriLoja; i++)
					delete[] bileteLoja[i];
				delete[] bileteLoja;
				nrRanduriLoja = nrBileteLoja = 0;
			}
			if (st.bileteLoja != nullptr)
			{
				bileteLoja = new biletLoja * [st.nrRanduriLoja];
				for (int i = 0; i < st.nrRanduriLoja; i++)
					bileteLoja[i] = new biletLoja[st.nrBileteLoja];
				nrRanduriLoja = st.nrRanduriLoja;
				nrBileteLoja = st.nrBileteLoja;
				for (int i = 0; i < st.nrRanduriLoja; i++)
					for (int j = 0; j < st.nrBileteLoja; j++)
						bileteLoja[i][j] = st.bileteLoja[i][j];
			}
		}
		else
		{
			bileteLoja = nullptr;
			nrRanduriLoja = nrBileteLoja = 0;
		}
	}
	return *this;
}
ostream& operator<<(ostream& out, spectacolTeatru st)
{
	out << "Spectacolul " << st.denumire << " are loc in data de " << st.data << " la ora " << st.ora << "."<<endl;
	out<<"Numar locuri in sala : " << st.nrMaximLocuri << endl;
	out << "\n\nBilete categoria 1: " << endl<<endl;
	if (st.bileteCat1 != nullptr)
	{
		for (int i = 0; i < st.nrRanduriCat1; i++)
		{
			for (int j = 0; j < st.nrBileteCat1; j++)
				out << st.bileteCat1[i][j];
			out << endl<<endl;
		}
	}
	else out << "nu exista." << endl<<endl;
	out << "\n\nBilete categoria 2: " << endl<<endl;
	if (st.bileteCat2 != nullptr)
	{
		for (int i = 0; i < st.nrRanduriCat2; i++)
		{
			for (int j = 0; j < st.nrBileteCat2; j++)
				out << st.bileteCat2[i][j];
			out << endl<<endl;
		}
	}
	else out << "nu exista." << endl<<endl;
	out << "\n\nBilete loja: " << endl<<endl;
	if (st.bileteLoja != nullptr)
	{
		for (int i = 0; i < st.nrRanduriLoja; i++)
		{
			for (int j = 0; j < st.nrBileteLoja; j++)
				out << st.bileteLoja[i][j];
			out << endl<<endl;
		}
	}
	else out << "nu exista." << endl<<endl;
	return out;
}
istream& operator>>(istream& in, spectacolTeatru& st)
{
	string buffer;
	char buf[UCHAR_MAX], cc;
	cout << "Denumire spectacol: ";
	getline(in, buffer);
	if (st.denumire != nullptr)
		delete[] st.denumire, st.denumire=nullptr;
	st.denumire = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(st.denumire, strlen(buffer.c_str()) + 1, buffer.c_str());
	cout << "Data spectacol (zz/ll/aaaa): ";
	getline(in, buffer);
	bool is_ok = false;
	if (buffer.length() == 10)
	{
		int an, luna, zi;
		an = atoi(buffer.c_str() + 6);
		luna = atoi(buffer.c_str() + 3);
		zi = atoi(buffer.c_str());
		class::data d=data::data(zi, luna, an);
		if(d.verificaData())
			is_ok = true;
	}
	while (!is_ok)
	{
		cout << "Data incorecta. Introduceti data in formatul zz/ll/aaaa: ";
		getline(in, buffer);
		if (buffer.length() == 10)
		{
			int an, luna, zi;
			an = atoi(buffer.c_str() + 6);
			luna = atoi(buffer.c_str() + 3);
			zi = atoi(buffer.c_str());
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
				is_ok = true;
		}
	}
	if(st.data!=nullptr)
		delete[] st.data, st.data = nullptr;
	st.data = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(st.data, strlen(buffer.c_str()) + 1, buffer.c_str());
	cout << "Ora spectacol (hh:mm): ";
	getline(in, buffer);
	is_ok = false;
	if (buffer.length()==5)
	{
		int ora, minut;
		ora = atoi(buffer.c_str());
		minut = atoi(buffer.c_str() + 3);
		int copie_ora = ora, copie_min = minut;
		int nrCifOra = 0, nrCifMin = 0;
		if (buffer[0] == '0')
			nrCifOra++;
		if (buffer[3] == '0')
			nrCifMin++;
		if (copie_ora == 0)
			nrCifOra++;
		if (copie_min == 0)
			nrCifMin++;
		while (copie_ora)
		{
			copie_ora /= 10;
			nrCifOra++;
		}
		while (copie_min)
		{
			copie_min /= 10;
			nrCifMin++;
		}
		char bufOra[3];
		char bufMin[3];
		strncpy_s(bufOra, buffer.c_str(), 2);
		strncpy_s(bufMin, buffer.c_str()+3,2);
		if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
		{
			class::timp t = timp::timp(ora, minut);
			if (!t.getFlag())
				is_ok = true;
		}
		else is_ok = false;
	}
	while (!is_ok)
	{
		cout << "Ora incorecta. Introduceti ora in formatul hh:mm: ";
		getline(in, buffer);
		if (buffer.length()==5)
		{
			int ora, minut;
			ora = atoi(buffer.c_str());
			minut = atoi(buffer.c_str() + 3);
			int copie_ora = ora, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (buffer[0] == '0')
				nrCifOra++;
			if (buffer[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, buffer.c_str(), 2);
			strncpy_s(bufMin, buffer.c_str() + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				class::timp t = timp::timp(ora, minut);
				if (!t.getFlag())
					is_ok = true;
			}
			else is_ok = false;
		}
	}
	if (st.ora != nullptr)
		delete[] st.ora, st.ora = nullptr;
	st.ora = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(st.ora, strlen(buffer.c_str()) + 1, buffer.c_str());
	cout << "Locuri disponibile: " << st.nrMaximLocuri<<endl;
	cout << "Nr. randuri Categoria 1: ";
	while (true)
	{
		if (!fgets(buf, sizeof buf, stdin))
			break;
		if (sscanf_s(buf, "%d %c", &st.nrRanduriCat1, &cc) != 1)
		{
			cout << "Ai introdus gresit numarul de randuri la Categoria 1. Mai incearca!\nAlegerea ta: ";
			continue;
		}
		break;
	}
	cout << "Nr. bilete pe rand Categoria 1: ";
	while(true)
	{
		if (!fgets(buf, sizeof buf, stdin))
			break;
		if (sscanf_s(buf, "%d %c", &st.nrBileteCat1, &cc) != 1)
		{
			cout << "Ai introdus gresit numarul de bilete la Categoria 1. Mai incearca!\nAlegerea ta: ";
			continue;
		}
		break;
	}
	cout << "Nr. randuri Categoria 2: ";
	while (true)
	{
		if (!fgets(buf, sizeof buf, stdin))
			break;
		if (sscanf_s(buf, "%d %c", &st.nrRanduriCat2, &cc) != 1)
		{
			cout << "Ai introdus gresit numarul de randuri la Categoria 2. Mai incearca!\nAlegerea ta: ";
			continue;
		}
		break;
	}
	cout << "Nr. bilete pe rand Categoria 2: ";
	while (true)
	{
		if (!fgets(buf, sizeof buf, stdin))
			break;
		if (sscanf_s(buf, "%d %c", &st.nrBileteCat2, &cc) != 1)
		{
			cout << "Ai introdus gresit numarul de bilete la Categoria 2. Mai incearca!\nAlegerea ta: ";
			continue;
		}
		break;
	}
	cout << "Nr. randuri Loja: ";
	while (true)
	{
		if (!fgets(buf, sizeof buf, stdin))
			break;
		if (sscanf_s(buf, "%d %c", &st.nrRanduriLoja, &cc) != 1)
		{
			cout << "Ai introdus gresit numarul de randuri la Loja. Mai incearca!\nAlegerea ta: ";
			continue;
		}
		break;
	}
	cout << "Nr. bilete pe rand Loja: ";
	while (true)
	{
		if (!fgets(buf, sizeof buf, stdin))
			break;
		if (sscanf_s(buf, "%d %c", &st.nrBileteLoja, &cc) != 1)
		{
			cout << "Ai introdus gresit numarul de bilete la Loja. Mai incearca!\nAlegerea ta: ";
			continue;
		}
		break;
	}
	if (st.nrRanduriCat1 > 0 && st.nrBileteCat1 > 0)
	{
		if(st.nrRanduriCat1*st.nrBileteCat1<=st.nrMaximLocuri)
		{
			st.bileteCat1 = new biletCategoria1* [st.nrRanduriCat1];
			for (int i = 0; i < st.nrRanduriCat1; i++)
				st.bileteCat1[i] = new biletCategoria1[st.nrBileteCat1];
			for (int i = 0; i < st.nrRanduriCat1; i++)
				for (int j = 0; j < st.nrBileteCat1; j++)
				{
					cout << "Bilet Categoria 1, rand " << i + 1 << ", loc " << j + 1 << ":\n";
					in >> st.bileteCat1[i][j];
				}
		}
		else
		{
			st.bileteCat1 = nullptr;
			st.nrRanduriCat1 = st.nrBileteCat1 = 0;
		}
	}
	else
	{
		st.nrRanduriCat1 = st.nrBileteCat1 = 0;
		st.bileteCat1 = nullptr;
	}
	if (st.nrRanduriCat2 > 0 && st.nrBileteCat2 > 0)
	{
			if (st.nrRanduriCat2 * st.nrBileteCat2 <= st.nrMaximLocuri - st.nrRanduriCat1 * st.nrBileteCat1)
			{
				st.bileteCat2 = new biletCategoria2* [st.nrRanduriCat2];
				for (int i = 0; i < st.nrRanduriCat2; i++)
					st.bileteCat2[i] = new biletCategoria2[st.nrBileteCat2];
				for (int i = 0; i < st.nrRanduriCat2; i++)
					for (int j = 0; j < st.nrBileteCat2; j++)
					{
						cout << "Bilet Categoria 2, rand " << i + 1 << ", loc " << j + 1 << ":\n";
						in >> st.bileteCat2[i][j];
					}
			}
			else
			{
				st.bileteCat2 = nullptr;
				st.nrRanduriCat2 = st.nrBileteCat2 = 0;
			}
	}
	else
	{
		st.nrRanduriCat2 = st.nrBileteCat2 = 0;
		st.bileteCat2 = nullptr;
	}
	if (st.nrBileteLoja > 0 && st.nrRanduriLoja > 0)
	{
		
		if (st.nrRanduriLoja * st.nrBileteLoja <= st.nrMaximLocuri - st.nrRanduriCat1 * st.nrBileteCat1 - st.nrRanduriCat2 * st.nrBileteCat2)
			{
				st.bileteLoja = new biletLoja* [st.nrRanduriLoja];
				for (int i = 0; i < st.nrRanduriLoja; i++)
					st.bileteLoja[i] = new biletLoja[st.nrBileteLoja];
				for (int i = 0; i < st.nrRanduriLoja; i++)
					for (int j = 0; j < st.nrBileteLoja; j++)
					{
						cout << "Bilet Loja, rand " << i + 1 << ", loc " << j + 1 << ":\n";
						in >> st.bileteLoja[i][j];
					}
			}
		else
		{
				st.nrRanduriLoja = st.nrBileteLoja = 0;
				st.bileteLoja = nullptr;
		}
	}
	else
	{
		st.nrRanduriLoja = st.nrBileteLoja = 0;
		st.bileteLoja = nullptr;
	}
	return in;
}
spectacolTeatru::operator int()
{
	return nrBileteCat1*nrRanduriCat1 + nrBileteCat2*nrRanduriCat2 + nrBileteLoja*nrRanduriLoja;
}
bool spectacolTeatru::operator!()
{
	if (nrBileteCat1 * nrRanduriCat1 == nrBileteCat2 * nrRanduriCat2 && nrBileteCat2 * nrRanduriCat2 == nrBileteLoja * nrRanduriLoja)
		return true;
	return false;
}
spectacolTeatru::~spectacolTeatru()
{
	if (bileteCat1!=nullptr)
	{
		for (int i = 0; i < nrRanduriCat1; i++)
			delete[] bileteCat1[i];
		delete[] bileteCat1;
		bileteCat1 = nullptr;
	}
	if (bileteCat2!=nullptr)
	{
		for (int i = 0; i < nrRanduriCat2; i++)
			delete[] bileteCat2[i];
		delete[] bileteCat2;
		bileteCat2 = nullptr;
	}
	if (bileteLoja!=nullptr)
	{
		for (int i = 0; i < nrRanduriLoja; i++)
			delete[] bileteLoja[i];
		delete[] bileteLoja;
		bileteLoja = nullptr;
	}
	if (denumire!=nullptr)
		delete[] denumire, denumire = nullptr;
	if (data != nullptr)
		delete[] data, data = nullptr;
	if (ora != nullptr)
		delete[] ora, ora = nullptr;
	nrSpectacol--;
}
char* spectacolTeatru::getDenumire()
{
	if (denumire!=nullptr)
	{
		char* copie = new char[strlen(denumire) + 1];
		strcpy_s(copie, strlen(denumire)+1,denumire);
		return copie;
	}
}
char* spectacolTeatru::getData()
{
	if (data!=nullptr)
	{
		char* copie = new char[strlen(data) + 1];
		strcpy_s(copie, strlen(data) + 1, data);
		return copie;
	}
}
char* spectacolTeatru::getOra()
{
	if (ora!=nullptr)
	{
		char* copie = new char[strlen(ora) + 1];
		strcpy_s(copie, strlen(ora) + 1, ora);
		return copie;
	}
}
int spectacolTeatru::getNrMaximLocuri()
{
	return nrMaximLocuri;
}
int spectacolTeatru::getNrLocuriDisponibileCat1()
{
	int nrLocuri = 0;
	if (bileteCat1 != nullptr)
		for (int i = 0; i < nrRanduriCat1; i++)
			for (int j = 0; j < nrBileteCat1; j++)
				if (bileteCat1[i][j].getOccupancy() == false)
					nrLocuri++;
	return nrLocuri;
}
int spectacolTeatru::getNrLocuriDisponibileCat2()
{
	int nrLocuri = 0;
	if (bileteCat2 != nullptr)
		for (int i = 0; i < nrRanduriCat2; i++)
			for (int j = 0; j < nrBileteCat2; j++)
				if (bileteCat2[i][j].getOccupancy() == false)
					nrLocuri++;
	return nrLocuri;
}
int spectacolTeatru::getNrLocuriDisponibileLoja()
{
	int nrLocuri = 0;
	if (bileteLoja != nullptr)
		for (int i = 0; i < nrRanduriLoja; i++)
			for (int j = 0; j < nrBileteLoja; j++)
				if (bileteLoja[i][j].getOccupancy() == false)
					nrLocuri++;
	return nrLocuri;
}
int spectacolTeatru::getNrLocuriOcupateCat1()
{
	int nrLocuri = 0;
	if (bileteCat1 != nullptr)
		for (int i = 0; i < nrRanduriCat1; i++)
			for (int j = 0; j < nrBileteCat1; j++)
				if (bileteCat1[i][j].getOccupancy() != false)
					nrLocuri++;
	return nrLocuri;
}
int spectacolTeatru::getNrLocuriOcupateCat2()
{
	int nrLocuri = 0;
	if (bileteCat2 != nullptr)
		for (int i = 0; i < nrRanduriCat2; i++)
			for (int j = 0; j < nrBileteCat2; j++)
				if (bileteCat2[i][j].getOccupancy() != false)
					nrLocuri++;
	return nrLocuri;
}
int spectacolTeatru::getNrLocuriOcupateLoja()
{
	int nrLocuri = 0;
	if (bileteLoja != nullptr)
		for (int i = 0; i < nrRanduriLoja; i++)
			for (int j = 0; j < nrBileteLoja; j++)
				if (bileteLoja[i][j].getOccupancy() != false)
					nrLocuri++;
	return nrLocuri;
}
int spectacolTeatru::getNrRanduriCat1()
{
	return nrRanduriCat1;
}
int spectacolTeatru::getNrRanduriCat2()
{
	return nrRanduriCat2;
}
int spectacolTeatru::getNrRanduriLoja()
{
	return nrRanduriLoja;
}
int spectacolTeatru::getNrBileteCat1()
{
	return nrBileteCat1;
}
int spectacolTeatru::getNrBileteCat2()
{
	return nrBileteCat2;
}
int spectacolTeatru::getNrBileteLoja()
{
	return nrBileteLoja;
}
biletCategoria1** spectacolTeatru::getBileteCat1()
{
	if (bileteCat1 != nullptr)
	{
		biletCategoria1** copie = new biletCategoria1 * [nrRanduriCat1];
		for (int i = 0; i < nrRanduriCat1; i++)
			copie[i] = new biletCategoria1[nrBileteCat1];
		for (int i = 0; i < nrRanduriCat1; i++)
			for (int j = 0; j < nrBileteCat1; j++)
				copie[i][j] = bileteCat1[i][j];
		return copie;
	}
	return nullptr;
}
biletCategoria2** spectacolTeatru::getBileteCat2()
{
	if (bileteCat2 != nullptr)
	{
		biletCategoria2** copie = new biletCategoria2 * [nrRanduriCat2];
		for (int i = 0; i < nrRanduriCat2; i++)
			copie[i] = new biletCategoria2[nrBileteCat2];
		for (int i = 0; i < nrRanduriCat2; i++)
			for (int j = 0; j < nrBileteCat2; j++)
				copie[i][j] = bileteCat2[i][j];
		return copie;
	}
	return nullptr;
}
biletLoja** spectacolTeatru::getBileteLoja()
{
	if (bileteLoja != nullptr)
	{
		biletLoja** copie = new biletLoja * [nrRanduriLoja];
		for (int i = 0; i < nrRanduriLoja; i++)
			copie[i] = new biletLoja[nrBileteLoja];
		for (int i = 0; i < nrRanduriLoja; i++)
			for (int j = 0; j < nrBileteLoja; j++)
				copie[i][j] = bileteLoja[i][j];
		return copie;
	}
	return nullptr;
}
biletCategoria1* spectacolTeatru::getRandCat1(int i)
{
	if (i >= 0 && i < nrRanduriCat1)
		return bileteCat1[i];
	return nullptr;
}
biletCategoria2* spectacolTeatru::getRandCat2(int i)
{
	if (i >= 0 && i < nrRanduriCat2)
		return bileteCat2[i];
	return nullptr;
}
biletLoja* spectacolTeatru::getRandLoja(int i)
{
	if (i >= 0 && i < nrRanduriLoja)
		return bileteLoja[i];
	return nullptr;
}
biletCategoria1& spectacolTeatru::getBiletCat1(int i, int j)
{
	if (i >= 0 && i < nrRanduriCat1 && j >= 0 && j < nrBileteCat1)
		return bileteCat1[i][j];
}
biletCategoria2& spectacolTeatru::getBiletCat2(int i, int j)
{
	if (i >= 0 && i < nrRanduriCat2 && j >= 0 && j < nrBileteCat2)
		return bileteCat2[i][j];
}
biletLoja& spectacolTeatru::getBiletLoja(int i, int j)
{
	if (i >= 0 && i < nrRanduriLoja && j >= 0 && j < nrBileteLoja)
		return bileteLoja[i][j];
}
void spectacolTeatru::setDenumire(const char* denumire)
{
	if (denumire != nullptr && strlen(denumire) > 0)
	{
		if (this->denumire != nullptr)
			delete[] this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}
}
void spectacolTeatru::setData(const char* data)
{
	if (data != nullptr)
	{
		if (strlen(data) == 10)
		{
			int an, luna, zi;
			an = atoi(data + 6);
			luna = atoi(data + 3);
			zi = atoi(data);
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
			{
				if (this->data != nullptr)
					delete[] this->data;
				this->data = new char[strlen(data) + 1];
				strcpy_s(this->data, strlen(data) + 1, data);
			}
		}
	}
}
void spectacolTeatru::setOra(const char* ora)
{
	if (ora != nullptr)
	{
		if (strlen(ora) == 5)
		{
			int o, minut;
			o = atoi(ora);
			minut = atoi(ora + 3);
			int copie_ora = o, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (ora[0] == '0')
				nrCifOra++;
			if (ora[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, ora, 2);
			strncpy_s(bufMin, ora + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				class::timp t = timp::timp(o, minut);
				if (!t.getFlag())
				{
					if (this->ora != nullptr)
						delete[] this->ora;
					this->ora = new char[strlen(ora) + 1];
					strcpy_s(this->ora, strlen(ora) + 1, ora);
				}
			}
		}
	}
}
void spectacolTeatru::setBileteCat1(int nrRanduriCat1, int nrBileteCat1, biletCategoria1** s)
{
	if (nrRanduriCat1 > 0 && nrBileteCat1 > 0 && s != nullptr)
	{
		if (bileteCat1 != nullptr)
		{
			for (int i = 0; i < this->nrRanduriCat1; i++)
				delete[] bileteCat1[i];
			delete[] bileteCat1;
		}
		this->nrRanduriCat1 = nrRanduriCat1;
		this->nrBileteCat1 = nrBileteCat1;
		bileteCat1 = new biletCategoria1 * [nrRanduriCat1];
		for (int i = 0; i < nrRanduriCat1; i++)
			bileteCat1[i] = new biletCategoria1[nrBileteCat1];
		for (int i = 0; i < nrRanduriCat1; i++)
			for (int j = 0; j < nrBileteCat1; j++)
				bileteCat1[i][j] = s[i][j];
	}
}
void spectacolTeatru::setBileteCat2(int nrRanduriCat2, int nrBileteCat2, biletCategoria2** s)
{
	if (nrRanduriCat2 > 0 && nrBileteCat2 > 0 && s != nullptr)
	{
		if (bileteCat2 != nullptr)
		{
			for (int i = 0; i < this->nrRanduriCat2; i++)
				delete[] bileteCat2[i];
			delete[] bileteCat2;
		}
		this->nrRanduriCat2 = nrRanduriCat2;
		this->nrBileteCat2 = nrBileteCat2;
		bileteCat2 = new biletCategoria2 * [nrRanduriCat2];
		for (int i = 0; i < nrRanduriCat2; i++)
			bileteCat2[i] = new biletCategoria2[nrBileteCat2];
		for (int i = 0; i < nrRanduriCat2; i++)
			for (int j = 0; j < nrBileteCat2; j++)
				bileteCat2[i][j] = s[i][j];
	}
}
void spectacolTeatru::setBileteLoja(int nrRanduriLoja, int nrBileteLoja, biletLoja** s)
{
	if (nrRanduriLoja > 0 && nrBileteLoja > 0 && s != nullptr)
	{
		if (bileteLoja != nullptr)
		{
			for (int i = 0; i < this->nrRanduriLoja; i++)
				delete[] bileteLoja[i];
			delete[] bileteLoja;
		}
		this->nrRanduriLoja = nrRanduriLoja;
		this->nrBileteLoja = nrBileteLoja;
		bileteLoja = new biletLoja * [nrRanduriLoja];
		for (int i = 0; i < nrRanduriLoja; i++)
			bileteLoja[i] = new biletLoja[nrBileteLoja];
		for (int i = 0; i < nrRanduriLoja; i++)
			for (int j = 0; j < nrBileteLoja; j++)
				bileteLoja[i][j] = s[i][j];
	}
}
void spectacolTeatru::setnrSpectacol(int i)
{
	nrSpectacol = i;
}
int* spectacolTeatru::rezervaBiletCat1(int rand, int loc)
{
	if (rand >= 0 && rand < nrRanduriCat1 && loc >= 0 && loc < nrBileteCat1)
		cin >> bileteCat1[rand][loc];
	return bileteCat1[rand][loc].getUID();
}
int* spectacolTeatru::rezervaBiletCat2(int rand, int loc)
{
	if (rand >= 0 && rand < nrRanduriCat2 && loc >= 0 && loc < nrBileteCat2)
		cin >> bileteCat2[rand][loc];
	return bileteCat2[rand][loc].getUID();
}
int* spectacolTeatru::rezervaBiletLoja(int rand, int loc)
{
	if (rand >= 0 && rand < nrRanduriLoja && loc >= 0 && loc < nrBileteLoja)
		cin >> bileteLoja[rand][loc];
	return bileteLoja[rand][loc].getUID();
}
int spectacolTeatru::maximdimUIDCat1()
{
	int max = 0;
	for (int i = 0; i < nrRanduriCat1; i++)
		for (int j = 0; j < nrBileteCat1; j++)
			if (bileteCat1[i][j].getdimUID() > max)
				max = bileteCat1[i][j].getdimUID();
	return max;
}
int spectacolTeatru::maximdimUIDCat2()
{
	int max = 0;
	for (int i = 0; i < nrRanduriCat2; i++)
		for (int j = 0; j < nrBileteCat2; j++)
			if (bileteCat2[i][j].getdimUID() > max)
				max = bileteCat2[i][j].getdimUID();
	return max;
}
int spectacolTeatru::maximdimUIDLoja()
{
	int max = 0;
	for (int i = 0; i < nrRanduriLoja; i++)
		for (int j = 0; j < nrBileteLoja; j++)
			if (bileteLoja[i][j].getdimUID() > max)
				max = bileteLoja[i][j].getdimUID();
	return max;
}
int spectacolTeatru::maximdimUIDTotal()
{
	int max = 0;
	if(bileteCat1!=nullptr)
	{
		for (int i = 0; i < nrRanduriCat1; i++)
			for (int j = 0; j < nrBileteCat1; j++)
				if (bileteCat1[i][j].getdimUID() > max)
					max = bileteCat1[i][j].getdimUID();
	}
	if(bileteCat2!=nullptr)
	{
		for (int i = 0; i < nrRanduriCat2; i++)
			for (int j = 0; j < nrBileteCat2; j++)
				if (bileteCat2[i][j].getdimUID() > max)
					max = bileteCat2[i][j].getdimUID();
	}
	if(bileteLoja!=nullptr)
	{
		for (int i = 0; i < nrRanduriLoja; i++)
			for (int j = 0; j < nrBileteLoja; j++)
				if (bileteLoja[i][j].getdimUID() > max)
					max = bileteLoja[i][j].getdimUID();
	}
	return max;
}
int spectacolTeatru::getNrSpectacol()
{
	return nrSpectacol;
}