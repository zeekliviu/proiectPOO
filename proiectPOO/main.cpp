#include <iostream>
#include <ctime>
using namespace std;
#pragma warning (disable:4996)
#include "spectacolTeatru.h"
int main()
{
	class data
	{
	public:
		int zi, luna, an;
	public:
		data()
		{
			zi = 0;
			luna = 0;
			an = 0;
		}
		data(const char* str): data()
		{}
		data(char c) : data()
		{}
		data(int zi): data()
		{
			if (zi > 0 && zi < 32)
				this->zi = zi;
			else this->zi = 0;
		}
		data(int zi, const char* str): data(zi)
		{}
		data(int zi, const char* str1, const char* str2) : data(zi)
		{}
		data(int zi, char c): data(zi)
		{}
		data(int zi, char c, char cx): data(zi)
		{}
		data(int zi, int luna): data(zi)
		{
			if (luna > 0 && luna < 13)
				this->luna = luna;
			else this->luna = 0;
			if(luna==2)
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
		data(int zi, int luna, int an): data(zi, luna)
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
	};
	/*
	data d;
	for (int an = 2019; an <= 2020; an++)
		for (int luna = -1; luna <= 13; luna++)
			for (int zi = -1; zi <= 32; zi++)
				d = data(zi, luna, an),
				cout << d.zi << "/" << d.luna << "/" << d.an << '\t'<<"Zi : "<<zi<<" Luna: "<<luna<<" An: "<<an<<endl;*/
	char str[] = "qw";
	data d = data(str);
	cout << d.zi<<d.luna<<d.an;
	/*
	cout << "Bun venit la The Ticketing App !" << endl;
	cout << "Autor: Liviu-Ioan Zecheru" << endl;
	cout << "Seria E, Grupa 1061\n";
	cout << "Versiunea: 1.0" << endl;
	cout << "Va prezentam un meniu de optiuni: " << endl<<endl;
	int optiune;
	int nrCrt = 0;
	spectacolTeatru* spectacole = new spectacolTeatru[10];
	do
	{
		cout << "\n1. Adaugare spectacol " << endl;
		cout << "2. Afisare spectacole " << endl;
		cout << "3. Rezervare bilet " << endl;
		cout << "4. Afisare nr. bilete rezervate pentru un spectacol" << endl;
		cout << "5. Afisare nr. bilete disponibile pentru un anumit spectacol" << endl;
		cout << "6. Afisare nr. bilete disponibile pe categorii pentru un anumit spectacol" << endl;
		cout << "7. Afisare nr. bilete rezervate pe categorii pentru un anumit spectacol " << endl;
		cout << "8. Verificare bilet" << endl;
		cout << "0. Iesire\n\nAlegerea ta: ";
		cin >> optiune;
		cin.ignore();
		if (optiune == 1)
		{
			cout << "Cate locuri doriti sa fie disponibile in total la spectacol: ";
			int nrLocuri;
			cin >> nrLocuri;
			cin.ignore();
			spectacolTeatru s(nrLocuri);
			if (nrLocuri)
			{
				std::cin >> s;
				spectacole[nrCrt++] = s;
			}
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
								if (spectacole[alegereSpectacol].getBileteCat1()[i][j].getId() != 0)
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
							if (spectacole[alegereSpectacol].getBileteCat1()[rand - 1][loc - 1].getId() == 0)
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
								if (spectacole[alegereSpectacol].getBileteCat2()[i][j].getId() != 0)
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
							if (spectacole[alegereSpectacol].getBileteCat2()[rand - 1][loc - 1].getId() == 0)
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
								if (spectacole[alegereSpectacol].getBileteCat2()[i][j].getId() != 0)
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
							if (spectacole[alegereSpectacol].getBileteLoja()[rand - 1][loc - 1].getId() == 0)
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
							if (spectacole[alegereSpectacol].getBileteCat1()[i][j].getId() != 0)
								total++;
				if (spectacole[alegereSpectacol].getBileteCat2() != nullptr)
					for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriCat2(); i++)
						for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteCat2(); j++)
							if (spectacole[alegereSpectacol].getBileteCat2()[i][j].getId() != 0)
								total++;
				if (spectacole[alegereSpectacol].getBileteLoja() != nullptr)
					for (int i = 0; i < spectacole[alegereSpectacol].getNrRanduriLoja(); i++)
						for (int j = 0; j < spectacole[alegereSpectacol].getNrBileteLoja(); j++)
							if (spectacole[alegereSpectacol].getBileteLoja()[i][j].getId() != 0)
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
		else if(optiune==0)
		{
			cout << "\nMultumim ca ati apelat la serviciile noastre de ticketing!\nMade with <3 by Zeek Liviu\nv1.0\nI won't lie, it was so !fun to make this project, especially when the MEMORY ACCESS VIOLATION comes into place. " << char(1)<<'\n';
		}
		else cout << "\nOptiunea aleasa nu exista, te rog sa introduci alta optiune.\n\n";
	}while (optiune != 0);*/
	return 0;
}