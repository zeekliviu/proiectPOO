#include <iostream>
#include "spectacolTeatru.h"
#include <fstream>
using namespace std;
int main()
{

	/*
	data d;
	for (int an = 2019; an <= 2020; an++)
		for (int luna = -1; luna <= 13; luna++)
			for (int zi = -1; zi <= 32; zi++)
				d = data(zi, luna, an),
				cout << d.zi << "/" << d.luna << "/" << d.an << '\t'<<"Zi : "<<zi<<" Luna: "<<luna<<" An: "<<an<<endl;
	char str[] = "qw";
	class :: data d = data::data(29,2,2019);
	cout << d.zi<<"/"<<d.luna <<"/"<< d.an;
	*/

	/*
	char data[] = "qq/qq/qqqq";
	int an = atoi(data + 6);
	int luna = atoi(data + 3);
	int zi = atoi(data);
	class::data d = data::data(zi, luna, an);
	if (d.verificaData(d))
		cout << "Data valida";
	else
		cout << "Data invalida";
	*/
	/*int x = -13;
	int nrcif = 0;
	while (x)
	{
		x /= 10;
		nrcif++;
	}
	cout << nrcif;*/

	/*char t[] = "12:42";
	char s[3];
	strncpy_s(s, t + 3, 2);
	cout << s << endl;
	int ora = atoi(t);
	int min = atoi(t + 3);
	cout << ora << ":" << min << endl;
	timp ti = timp(ora, min);
	if (!ti.getFlag())
		cout << "Timp valid";
	else
		cout << "Timp invalid";*/
		/*
		ofstream fw("C:\\Users\\thepr\\Desktop\\proiect POO\\proiectPOO\\date_iesire.txt", ofstream::out);
		string test;
		for(int a=-1; a<=9; a++)
			for(int b=-1; b<=9; b++)
				for(int c=-1; c<=9; c++)
					for (int d = -1; d <= 9; d++)
					{
						test.clear();
						test = (char)(a + '0');
						test += (char)(b + '0');
						test += ':';
						test += (char)(c + '0');
						test += (char)(d + '0');
						fw << test << endl;
						int ora, minut;
						ora = atoi(test.c_str());
						minut = atoi(test.c_str() + 3);
						int copie_ora = ora, copie_min = minut;
						int nrCifOra = 0, nrCifMin = 0;
						if (test[0] == '0')
							nrCifOra++;
						if (test[3] == '0')
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
						strncpy_s(bufOra, test.c_str(), 2);
						strncpy_s(bufMin, test.c_str() + 3, 2);
						if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
						{
							class::timp t = timp::timp(ora, minut);
							if (!t.getFlag())
								fw << "Timp valid\n";
							else
								fw << "Timp invalid\n";
						}
						else fw << "Timp invalid\n";
					}
		fw.close();
		*/


//spectacolTeatru s(10);
//cout << s;
	
	cout << "Bun venit la The Ticketing App !\n";
	cout << "Autor: Liviu-Ioan Zecheru\n";
	cout << "Seria E, Grupa 1061\n";
	cout << "Versiunea: 1.0\n";
	cout << "Va prezentam un meniu de optiuni:\n\n";
	int optiune;
	int nrCrt = 0;
	spectacolTeatru* spectacole = new spectacolTeatru[10];
	do
	{
		cout << "\n1. Adaugare spectacol\n";
		cout << "2. Afisare spectacole\n";
		cout << "3. Rezervare bilet\n";
		cout << "4. Afisare nr. bilete rezervate pentru un spectacol\n";
		cout << "5. Afisare nr. bilete disponibile pentru un anumit spectacol\n";
		cout << "6. Afisare nr. bilete disponibile pe categorii pentru un anumit spectacol\n";
		cout << "7. Afisare nr. bilete rezervate pe categorii pentru un anumit spectacol\n";
		cout << "8. Verificare bilet\n";
		cout << "9. Iesire\n\nAlegerea ta: ";
		cin >> optiune;
		if (optiune == 1)
		{
			cout << "Cate locuri doriti sa fie disponibile in total la spectacol: ";
			int nrLocuri;
			cin >> nrLocuri;
			while (nrLocuri < 0)
			{
				cout << "Numar locuri invalid! Introdu altul: ";
				cin >> nrLocuri;
			}
			spectacolTeatru s(nrLocuri);
			cin >> s;
			spectacole[nrCrt++] = s;
		}
		else if (optiune == 2)
		{
			if(nrCrt)
				for (int i = 0; i < nrCrt; i++)
					cout << spectacole[i];
			else
				cout << "Nu exista spectacole inregistrate in sistem!\n";
		}
		else if (optiune == 3)
		{
			if(nrCrt)
			{
				cout << "La ce spectacol doresti sa rezervi bilet?" << endl;
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << spectacole[i].getDenumire() << " - " << spectacole[i].getData() << " - " << spectacole[i].getOra() << endl;
				int alegereSpectacol;
				cin >> alegereSpectacol;
				cin.ignore();
				int ok = false;
				if (alegereSpectacol < nrCrt)
					cout << "Deci doresti sa rezervi un bilet la spectacolul" << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				while (!ok)
				{
					for (int i = 0; i < nrCrt; i++)
						if (alegereSpectacol == i)
							ok = true;
					if (!ok)
					{
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
						cin >> alegereSpectacol;
					}
				}
				if (!ok)
					cout << "Deci doresti sa rezervi un bilet la spectacolul" << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				cout << "Unde doresti sa rezervi biletul?\n1. Categoria 1\n2.Categoria 2\n3. Loja";
				int alegereCategorie;
				cin >> alegereCategorie;
				ok = false;
				cout << "Deci doresti un bilet la ";
				if (alegereCategorie > 0 && alegereCategorie < 4)
					if (alegereCategorie == 1)
						cout << "Categoria 1.";
					else if (alegereCategorie == 2)
						cout << "Categoria 2.";
					else cout << "Loja.";
				while (!ok)
				{
					for (int i = 1; i <= 3; i++)
						if (alegereCategorie == i)
							ok = true;
					if (!ok)
					{
						cout << "Alegerea ta nu corespunde categoriilor disponibile, introdu o alta";
						cin >> alegereCategorie;
					}
				}
				if (alegereCategorie == 1)
					cout << "Categoria 1.";
				else if (alegereCategorie == 2)
					cout << "Categoria 2.";
				else cout << "Loja.";
				// rezervare bilet in concordanta cu alegerea facuta
				if (alegereCategorie == 1)
				{

					if (spectacole[alegereSpectacol].getBileteCat1() != nullptr)
					{
						cout << "La Categoria 1, la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " mai sunt "
							<< spectacole[alegereSpectacol].getNrLocuriDisponibileCat1() << " locuri disponibile." << endl << endl;
						cout << "Dispunerea lor este urmatoarea:\n\n";
						cout << "Locuri Categoria 1:\n\n";
						for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriCat1(); i++)
						{
							cout << endl << "Rand " << i + 1 << " ";
							for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat1(); j++)
								if (spectacole[alegereSpectacol].getBileteCat1()[i][j].getOccupancy() != 0)
									cout << "|_" << char(1) << "_|";
								else cout << "|___|";
							cout << endl << "\t ";
							for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat1(); j++)
								cout << j + 1 << "    ";
							cout << endl;
						}
						cout << "\nUnde " << char(1) << " - loc ocupat.";
						ok = false;
						while (!ok)
						{
							int rand, loc;
							cout << "Unde doresti sa stai?" << endl;
							cout << "Rand: ";
							cin >> rand;
							while (rand - 1 < 0 && rand - 1 > spectacole[alegereSpectacol].getNrRanduriCat1())
							{
								cout << "Rand incorect! Introdu alt rand: ";
								cin >> rand;
							}
							cout << "Loc: ";
							cin >> loc;
							while (loc - 1 < 0 && loc - 1 > spectacole[alegereSpectacol].getNrBileteCat1())
							{
								cout << "Loc incorect! Introdu alt loc: ";
								cin >> loc;
							}
							if (spectacole[alegereSpectacol].getBileteCat1()[rand - 1][loc - 1].getOccupancy() == 0)
							{
								int* UID = spectacole[alegereSpectacol].rezervaBiletCat1(rand - 1, loc - 1);
								int dimUID = spectacole[alegereSpectacol].getBiletCat1(rand - 1, loc - 1).getdimUID();
								cout << "Bilet la Categoria1 rezervat! Noteaza-ti undeva UID-ul (vei avea nevoie de el pentru a-ti valida biletul): ";
								for (int i = 0; i < dimUID; i++)
									cout << UID[i];
								ok = true;
							}
							else cout << "Loc deja ocupat! Mai incearca!\n";
						}
					}
					else cout << "Nu puteti rezerva un loc aici deoarece zona nu exista pentru spectacolul selectat.";
				}
				else if (alegereCategorie == 2)
				{
					if (spectacole[alegereSpectacol].getBileteCat2() != nullptr)
					{
						cout << "La Categoria 2, la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " mai sunt " << spectacole[alegereSpectacol].getNrLocuriDisponibileCat2() << " locuri disponibile.\n\n";
						cout << "Dispunerea lor este urmatoarea:\n\n";
						cout << "Locuri Categoria 2:\n\n";
						for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriCat2(); i++)
						{
							cout << endl << "Rand " << i + 1 << " ";
							for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat2(); j++)
								if (spectacole[alegereSpectacol].getBileteCat2()[i][j].getOccupancy() != 0)
									cout << "|_" << char(1) << "_|";
								else
									cout << "|___|";
							cout << "\n\t ";
							for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat2(); j++)
								cout << j + 1 << "    ";
							cout << '\n';
						}
						cout << "\nUnde " << char(1) << " - loc ocupat.";
						ok = false;
						while (!ok)
						{
							int rand, loc;
							cout << "Unde doresti sa stai?\n";
							cout << "Rand: ";
							cin >> rand;
							while (rand - 1 < 0 && rand - 1 > spectacole[alegereSpectacol].getNrRanduriCat2())
							{
								cout << "Rand incorect! Introdu alt rand: ";
								cin >> rand;
							}
							cout << "Loc: ";
							cin >> loc;
							while (loc - 1 < 0 && loc - 1 > spectacole[alegereSpectacol].getNrBileteCat2())
							{
								cout << "Loc incorect! Introdu alt loc: ";
								cin >> loc;
							}
							if (spectacole[alegereSpectacol].getBileteCat2()[rand - 1][loc - 1].getOccupancy() == 0)
							{
								int* UID = spectacole[alegereSpectacol].rezervaBiletCat2(rand - 1, loc - 1);
								int dimUID = spectacole[alegereSpectacol].getBiletCat2(rand - 1, loc - 1).getdimUID();
								cout << "Bilet la Categoria2 rezervat! Noteaza-ti undeva UID-ul (vei avea nevoie de el pentru a-ti valida biletul): ";
								for (int i = 0; i < dimUID; i++)
									cout << UID[i];
								ok = true;
							}
						}
					}
					else cout << "Nu puteti rezerva un loc aici deoarece zona nu exista pentru spectacolul selectat.";
				}
				else
				{
					if (spectacole[alegereSpectacol].getBileteLoja() != nullptr)
					{
						cout << "La Loja, la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " mai sunt " << spectacole[alegereSpectacol].getNrLocuriDisponibileLoja() << " locuri disponibile.\n\n";
						cout << "Dispunerea lor este urmatoarea:\n\n";
						cout << "Locuri Loja:\n\n";
						for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriLoja(); i++)
						{
							cout << "\nRand " << i + 1 << " ";
							for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteLoja(); j++)
								if (spectacole[alegereSpectacol].getBileteCat2()[i][j].getOccupancy() != 0)
									cout << "|_" << char(1) << "_|";
								else
									cout << "|___|";
							cout << "\n\t";
							for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteLoja(); j++)
								cout << j + 1 << "    ";
							cout << '\n';
						}
						cout << "\nUnde " << char(1) << " - loc ocupat.";
						ok = false;
						while (!ok)
						{
							int rand, loc;
							cout << "Unde doresti sa stai?\n";
							cout << "Rand: ";
							cin >> rand;
							while ((rand - 1) < 0 && (rand - 1) > spectacole[alegereSpectacol].getNrRanduriLoja())
							{
								cout << "Rand incorect! Introdu alt rand:";
								cin >> rand;
							}
							cout << "Loc: ";
							cin >> loc;
							while (loc - 1 < 0 && loc - 1 > spectacole[alegereSpectacol].getNrBileteLoja())
							{
								cout << "Loc incorect! Introdu alt loc: ";
								cin >> loc;
							}
							if (spectacole[alegereSpectacol].getBileteLoja()[rand - 1][loc - 1].getOccupancy() == 0)
							{
								int* UID = spectacole[alegereSpectacol].rezervaBiletLoja(rand - 1, loc - 1);
								int dimUID = spectacole[alegereSpectacol].getBiletLoja(rand - 1, loc - 1).getdimUID();
								cout << "Bilet la Loja rezervat! Noteaza-ti undeva UID-ul (vei avea nevoie de el pentru a-ti valida biletul): ";
								for (int i = 0; i < dimUID; i++)
									cout << UID[i];
								ok = true;
							}
						}
					}
					else cout << "Nu puteti rezerva un loc aici deoarece zona nu exista pentru spectacolul selectat.";
				}
			}
			else cout << "Nu exista spectacole in baza de date.\n";
		}
		else if (optiune == 4)
		{
			if(nrCrt)
			{
				int total = 0;
				int alegereSpectacol;
				cout << "La ce spectacol doresti sa vezi nr. total de bilete rezervate? ";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << spectacole[i].getDenumire() << " - " << spectacole[i].getData() << " - " << spectacole[i].getOra() << endl;
				cin >> alegereSpectacol;
				cin.ignore();
				int ok = false;
				if (alegereSpectacol < nrCrt)
					cout << "Deci doresti sa vezi nr. de bilete rezervate la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				while (!ok)
				{
					for (int i = 0; i < nrCrt; i++)
						if (alegereSpectacol == i)
							ok = true;
					if (!ok)
					{
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
						cin >> alegereSpectacol;
					}
				}
				if (!ok)
					cout << "Deci doresti sa vezi nr. total de bilete rezervate la spectacolul" << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				if (spectacole[alegereSpectacol].getBileteCat1() != nullptr)
					for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriCat1(); i++)
						for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat1(); j++)
							if (spectacole[alegereSpectacol].getBileteCat1()[i][j].getOccupancy() != 0)
								total++;
				if (spectacole[alegereSpectacol].getBileteCat2() != nullptr)
					for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriCat2(); i++)
						for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat2(); j++)
							if (spectacole[alegereSpectacol].getBileteCat2()[i][j].getOccupancy() != 0)
								total++;
				if (spectacole[alegereSpectacol].getBileteLoja() != nullptr)
					for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriLoja(); i++)
						for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteLoja(); j++)
							if (spectacole[alegereSpectacol].getBileteLoja()[i][j].getOccupancy() != 0)
								total++;
				if (total != 0)
					cout << "Sunt " << total << " bilete rezervate la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				else
					cout << "Nu exista bilete rezervate la niciuna dintre categorii pentru spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
			}
			else
				cout << "Nu exista spectacole disponibile pentru a putea afisa biletele rezervate." << endl;
		}
		else if (optiune == 5)
		{
			if(nrCrt)
			{
				int total = 0;
				int alegereSpectacol;
				cout << "La ce spectacol doresti sa vezi nr. total de bilete disponibile? ";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << spectacole[i].getDenumire() << " - " << spectacole[i].getData() << " - " << spectacole[i].getOra() << endl;
				cin >> alegereSpectacol;
				cin.ignore();
				int ok = false;
				if (alegereSpectacol < nrCrt)
					cout << "Deci doresti sa vezi nr. de bilete disponibile la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				while (!ok)
				{
					for (int i = 0; i < nrCrt; i++)
						if (alegereSpectacol == i)
							ok = true;
					if (!ok)
					{
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
						cin >> alegereSpectacol;
					}
				}
				if (!ok)
					cout << "Deci doresti sa vezi nr. total de bilete disponibile la spectacolul" << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				total = spectacole[alegereSpectacol].getNrLocuriDisponibileCat1() + spectacole[alegereSpectacol].getNrLocuriDisponibileCat2() + spectacole[alegereSpectacol].getNrLocuriDisponibileLoja();
				if (total != 0)
					cout << "Nr. total de bilete disponibile la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << " este " << total << endl;
				else
					cout << "Biletele la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << " sunt \"SOLD OUT\"!";
			}
			else
				cout << "Nu exista spectacole disponibile pentru a putea afisa biletele disponibile." << endl;
		}
		else if (optiune == 6)
		{
			if(nrCrt)
			{
				int alegereSpectacol;
				cout << "La ce spectacol doresti sa vezi nr. total de bilete disponibile pe categorii? ";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << spectacole[i].getDenumire() << " - " << spectacole[i].getData() << " - " << spectacole[i].getOra() << endl;
				cin >> alegereSpectacol;
				cin.ignore();
				int ok = false;
				if (alegereSpectacol < nrCrt)
					cout << "Deci doresti sa vezi nr. de bilete disponibile pe categorii la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				while (!ok)
				{
					for (int i = 0; i < nrCrt; i++)
						if (alegereSpectacol == i)
							ok = true;
					if (!ok)
					{
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
						cin >> alegereSpectacol;
					}
				}
				if (!ok)
					cout << "Deci doresti sa vezi nr. total de bilete disponibile pe categorii la spectacolul" << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				if (spectacole[alegereSpectacol].getNrLocuriDisponibileCat1() != 0)
					cout << "\nNr. locuri disponibile la Categoria 1: " << spectacole[alegereSpectacol].getNrLocuriDisponibileCat1() << endl;
				else
					cout << "\nNu mai sunt locuri la Categoria 1.\n";
				if (spectacole[alegereSpectacol].getNrLocuriDisponibileCat2() != 0)
					cout << "\nNr. locuri disponibile la Categoria 2: " << spectacole[alegereSpectacol].getNrLocuriDisponibileCat2() << endl;
				else
					cout << "\nNu mai sunt locuri la Categoria 2.\n";
				if (spectacole[alegereSpectacol].getNrLocuriDisponibileLoja() != 0)
					cout << "\nNr. locuri disponibile la Loja: " << spectacole[alegereSpectacol].getNrLocuriDisponibileLoja() << endl;
				else
					cout << "\nNu mai sunt locuri la Loja.\n";
			}
			else
				cout << "Nu exista spectacole disponibile pentru a putea rezerva bilete." << endl;
		}
		else if (optiune == 7)
		{
			if(nrCrt)
			{
				int alegereSpectacol;
				cout << "La ce spectacol doresti sa vezi nr. de bilete rezervate pe categorii? \n";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << spectacole[i].getDenumire() << " - " << spectacole[i].getData() << " - " << spectacole[i].getOra() << endl;
				cin >> alegereSpectacol;
				cin.ignore();
				int ok = false;
				if (alegereSpectacol < nrCrt)
					cout << "Deci doresti sa vezi nr. de bilete rezervate pe categorii la spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				while (!ok)
				{
					for (int i = 0; i < nrCrt; i++)
						if (alegereSpectacol == i)
							ok = true;
					if (!ok)
					{
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
						cin >> alegereSpectacol;
					}
				}
				if (!ok)
					cout << "Deci doresti sa vezi nr. de bilete rezervate pe categorii la spectacolul" << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				if (spectacole[alegereSpectacol].getNrLocuriOcupateCat1() != 0)
					cout << "\nNr. locuri ocupate la Categoria 1: " << spectacole[alegereSpectacol].getNrLocuriOcupateCat1() << endl;
				else
					cout << "\nZona Categoria 1 este libera.\n";
				if (spectacole[alegereSpectacol].getNrLocuriOcupateCat2() != 0)
					cout << "\nNr. locuri ocupate la Categoria 2: " << spectacole[alegereSpectacol].getNrLocuriOcupateCat2() << endl;
				else
					cout << "\nZona Categoria 2 este libera.\n";
				if (spectacole[alegereSpectacol].getNrLocuriOcupateLoja() != 0)
					cout << "\nNr. locuri ocupate la Loja: " << spectacole[alegereSpectacol].getNrLocuriOcupateLoja();
				else
					cout << "\nZona Loja este libera.\n";
			}
			else cout << "Nu exista spectacole disponibile.\n";
		}
		else if (optiune == 8)
		{
			if(nrCrt)
			{
				int alegereSpectacol;
				cout << "Pentru ce spectacol doresti sa-ti verifici biletul? ";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << spectacole[i].getDenumire() << " - " << spectacole[i].getData() << " - " << spectacole[i].getOra() << endl;
				cin >> alegereSpectacol;
				cin.ignore();
				int ok = false;
				if (alegereSpectacol < nrCrt)
					cout << "Deci doresti sa-ti verifici biletul pentru spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				while (!ok)
				{
					for (int i = 0; i < nrCrt; i++)
						if (alegereSpectacol == i)
							ok = true;
					if (!ok)
					{
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
						cin >> alegereSpectacol;
					}
				}
				if (!ok)
					cout << "Deci doresti sa-ti verifici biletul pentru spectacolul " << spectacole[alegereSpectacol].getDenumire() << " - " << spectacole[alegereSpectacol].getData() << " - " << spectacole[alegereSpectacol].getOra() << endl;
				cout << "Introdu UID-ul tau, apoi apasa Enter: ";
				char* buffer = new char[spectacole[alegereSpectacol].maximdimUIDTotal() + 1];
				cin >> buffer;
				cin.ignore();
				if (spectacole[alegereSpectacol].getBileteCat1() != nullptr)
				{
					for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriCat1(); i++)
						for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat1(); j++)
							if (spectacole[alegereSpectacol].getBileteCat1()[i][j].checkUID(buffer))
								cout << "Biletul tau a fost gasit la Categoria 1, rand " << i + 1 << ", loc " << j + 1 << endl;
				}
				else if (spectacole[alegereSpectacol].getBileteCat2() != nullptr)
				{
					for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriCat2(); i++)
						for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat2(); j++)
							if (spectacole[alegereSpectacol].getBileteCat2()[i][j].checkUID(buffer))
								cout << "Biletul tau a fost gasit la Categoria 2, rand " << i + 1 << ", loc " << j + 1 << endl;
				}
				else if (spectacole[alegereSpectacol].getBileteLoja() != nullptr)
				{
					for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriLoja(); i++)
						for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteLoja(); j++)
							if (spectacole[alegereSpectacol].getBileteLoja()[i][j].checkUID(buffer))
								cout << "Biletul tau a fost gasit la Loja, rand " << i + 1 << ", loc " << j + 1 << endl;
				}
				else
					cout << "Nu ai nici un bilet rezervat pentru acest spectacol.\n";
			}
			else cout << "Nu exista spectacole disponibile.\n";
		}
		else if(optiune==9)
		{
			cout << "\nMultumim ca ati apelat la serviciile noastre de ticketing!\nMade with <3 by Zeek Liviu\nv1.0\nI won't lie, it was so !fun to make this project, especially when the _CrtIsValidHeapPointer (block) comes into place. " << char(1)<<'\n';
		}
		else cout << "\nOptiunea aleasa nu exista, te rog sa introduci alta optiune.\n\n";
	}while (optiune != 9);
	return 0;
}