#include <iostream>
#include <climits>
#include "spectacolTeatru.h"
using namespace std;
int main()
{

	cout << "Bun venit la The Ticketing App !\n";
	cout << "Autor: Liviu-Ioan Zecheru\n";
	cout << "Seria E, Grupa 1061\n";
	cout << "Versiunea: 1.0\n";
	cout << "Va prezentam un meniu de optiuni:\n\n";
	int nrCrt = 0;
	int optiune;
	spectacolTeatru** spectacole = new spectacolTeatru*[USHRT_MAX];
	do
	{
		char cc, buf[USHRT_MAX];
		cout << "\n1. Adaugare spectacol\n";
		cout << "2. Afisare spectacole\n";
		cout << "3. Rezervare bilet\n";
		cout << "4. Afisare nr. bilete rezervate pentru un spectacol\n";
		cout << "5. Afisare nr. bilete disponibile pentru un anumit spectacol\n";
		cout << "6. Afisare nr. bilete disponibile pe categorii pentru un anumit spectacol\n";
		cout << "7. Afisare nr. bilete rezervate pe categorii pentru un anumit spectacol\n";
		cout << "8. Verificare bilet\n";
		cout << "9. Iesire\n\nAlegerea ta: ";
		while (true)
		{
			if (!fgets(buf, sizeof buf, stdin))
				break;
			if (sscanf_s(buf, "%d %c", &optiune, &cc) != 1)
			{
				cout << "Ai introdus gresit optiunea. Mai incearca!\nAlegerea ta: "; 
				continue;
			}
			break;
		}
		if (optiune == 1)
		{
			cout << "Cate locuri doriti sa fie disponibile in total la spectacol: ";
			int nrLocuri;
			while (true)
			{
				if (!fgets(buf, sizeof buf, stdin))
					break;
				if (sscanf_s(buf, "%d %c", &nrLocuri, &cc) != 1)
				{
					cout << "Ai introdus gresit numarul de locuri. Mai incearca!\nAlegerea ta: ";
					continue;
				}
				break;
			}
			while (nrLocuri < 0)
			{
				cout << "Numar locuri invalid!\nIntrodu altul: ";
				while (true)
				{
					if (!fgets(buf, sizeof buf, stdin))
						break;
					if (sscanf_s(buf, "%d %c", &nrLocuri, &cc) != 1)
					{
						cout << "Ai introdus gresit numarul de locuri. Mai incearca!\nAlegerea ta: ";
						continue;
					}
					break;
				}
			}
			spectacolTeatru* newSpectacol = new spectacolTeatru(nrLocuri);
			cin >> *newSpectacol;
			spectacole[nrCrt++] = newSpectacol;
		}
		else if (optiune == 2)
		{
			if(nrCrt)
			{
				cout << "\n\n================================ LISTA SPECTACOLE ================================\n\n";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << (*spectacole[i]).getDenumire() << " - " << (*spectacole[i]).getData() << " - " << (*spectacole[i]).getOra() << " - "<< (*spectacole[i]).getNrMaximLocuri()<<endl;
			}
			else
				cout << "Nu exista spectacole inregistrate in sistem!\n";
		}
		else if (optiune == 3)
		{
			if (nrCrt)
			{
				cout << "\nLa ce spectacol doresti sa rezervi bilet?" << endl;
				cout << "\n\n================================ LISTA SPECTACOLE ================================\n\n";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << (*spectacole[i]).getDenumire() << " - " << (*spectacole[i]).getData() << " - " << (*spectacole[i]).getOra() << " - " << (*spectacole[i]).getNrMaximLocuri() << endl;
				cout << "\nAlegerea ta: ";
				int alegereSpectacol;
				int ok = false;
				while (!ok)
				{
					while (true)
					{
						if (!fgets(buf, sizeof buf, stdin))
							break;
						if (sscanf_s(buf, "%d %c", &alegereSpectacol, &cc) != 1)
						{
							cout << "Ai introdus gresit indexul spectacolului. Mai incearca!\nAlegerea ta: ";
							continue;
						}
						break;
					}
					if (alegereSpectacol < nrCrt && alegereSpectacol >= 0)
						ok = true;
					if (!ok)
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
				}
				cout << "\nDeci doresti sa rezervi un bilet la spectacolul" << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << endl;
				cout << "Unde doresti sa rezervi biletul?\n1. Categoria 1\n2. Categoria 2\n3. Loja";
				int alegereCategorie;
				ok = false;
				while (!ok)
				{
					while (true)
					{
						if (!fgets(buf, sizeof buf, stdin))
							break;
						if (sscanf_s(buf, "%d %c", &alegereCategorie, &cc) != 1)
						{
							cout << "Ai introdus gresit categoria. Mai incearca!\nAlegerea ta: ";
							continue;
						}
						break;
					}
					if (alegereCategorie > 0 && alegereCategorie < 4)
						if (alegereCategorie == 1)
							ok = true;
						else if (alegereCategorie == 2)
							ok = true;
						else ok = true;
					if (!ok)
						cout << "Alegerea ta nu corespunde categoriilor disponibile, introdu o alta: ";
				}
				cout << "Deci doresti un bilet la ";
				if (alegereCategorie == 1)
					cout << "Categoria 1.";
				else if (alegereCategorie == 2)
					cout << "Categoria 2.";
				else cout << "Loja.";
				// rezervare bilet in concordanta cu alegerea facuta
				if (alegereCategorie == 1)
				{

					if ((*spectacole)[alegereSpectacol].getBileteCat1() != nullptr)
					{
						cout << "La Categoria 1, la spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " mai sunt "
							<< (*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat1() << " locuri disponibile." << endl << endl;
						if ((*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat1() != 0)
						{
							cout << "Dispunerea lor este urmatoarea:\n\n";
							cout << "Locuri Categoria 1:\n\n";
							for (int i = 0; i < (*spectacole)[alegereSpectacol].getNrRanduriCat1(); i++)
							{
								cout << endl << "Rand " << i + 1 << " ";
								for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteCat1(); j++)
									if ((*spectacole)[alegereSpectacol].getBileteCat1()[i][j].getOccupancy() != 0)
										cout << "|_" << char(1) << "_|";
									else cout << "|___|";
								cout << endl << "\t ";
								for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteCat1(); j++)
									cout << j + 1 << "    ";
								cout << endl;
							}
							cout << "\nUnde " << char(1) << " - loc ocupat.";
							ok = false;
							int rand, loc;
							while (!ok)
							{
								cout << "Unde doresti sa stai?" << endl;
								cout << "Rand: ";
								while (true)
								{
									if (!fgets(buf, sizeof buf, stdin))
										break;
									if (sscanf_s(buf, "%d %c", &rand, &cc) != 1)
									{
										cout << "Ai introdus gresit randul. Mai incearca!\nAlegerea ta: ";
										continue;
									}
									break;
								}
								while (rand - 1 < 0 && rand - 1 > (*spectacole)[alegereSpectacol].getNrRanduriCat1())
								{
									cout << "Rand incorect! Introdu alt rand: ";
									while (true)
									{
										if (!fgets(buf, sizeof buf, stdin))
											break;
										if (sscanf_s(buf, "%d %c", &rand, &cc) != 1)
										{
											cout << "Ai introdus gresit randul. Mai incearca!\nAlegerea ta: ";
											continue;
										}
										break;
									}
								}
								cout << "Loc: ";
								while (true)
								{
									if (!fgets(buf, sizeof buf, stdin))
										break;
									if (sscanf_s(buf, "%d %c", &loc, &cc) != 1)
									{
										cout << "Ai introdus gresit locul. Mai incearca!\nAlegerea ta: ";
										continue;
									}
									break;
								}
								while (loc - 1 < 0 && loc - 1 > (*spectacole)[alegereSpectacol].getNrBileteCat1())
								{
									cout << "Loc incorect! Introdu alt loc: ";
									while (true)
									{
										if (!fgets(buf, sizeof buf, stdin))
											break;
										if (sscanf_s(buf, "%d %c", &loc, &cc) != 1)
										{
											cout << "Ai introdus gresit locul. Mai incearca!\nAlegerea ta: ";
											continue;
										}
										break;
									}
								}
								if ((*spectacole)[alegereSpectacol].getBileteCat1()[rand - 1][loc - 1].getOccupancy() == 0)
								{
									int* UID = (*spectacole)[alegereSpectacol].rezervaBiletCat1(rand - 1, loc - 1);
									int dimUID = (*spectacole)[alegereSpectacol].getBiletCat1(rand - 1, loc - 1).getdimUID();
									cout << "\nBilet la Categoria 1 rezervat! Noteaza-ti undeva UID-ul (vei avea nevoie de el pentru a-ti valida biletul): ";
									for (int i = 0; i < dimUID; i++)
										cout << UID[i];
									ok = true;
								}
								else cout << "Loc deja ocupat! Mai incearca!\n";
							}
						}
						else cout << "Nu mai sunt locuri disponibile la Categoria 1!\n";
					}
					else cout << "Nu puteti rezerva un loc aici deoarece zona nu exista pentru spectacolul selectat.\n";
				}
				else if (alegereCategorie == 2)
				{
					if ((*spectacole)[alegereSpectacol].getBileteCat2() != nullptr)
					{
						cout << "La Categoria 2, la spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " mai sunt "
							<< (*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat2() << " locuri disponibile." << endl << endl;
						if ((*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat2() != 0)
						{
							cout << "Dispunerea lor este urmatoarea:\n\n";
							cout << "Locuri Categoria 2:\n\n";
							for (int i = 0; i < (*spectacole)[alegereSpectacol].getNrRanduriCat2(); i++)
							{
								cout << endl << "Rand " << i + 1 << " ";
								for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteCat2(); j++)
									if ((*spectacole)[alegereSpectacol].getBileteCat2()[i][j].getOccupancy() != 0)
										cout << "|_" << char(1) << "_|";
									else cout << "|___|";
								cout << endl << "\t ";
								for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteCat2(); j++)
									cout << j + 1 << "    ";
								cout << endl;
							}
							cout << "\nUnde " << char(1) << " - loc ocupat.";
							ok = false;
							int rand, loc;
							while (!ok)
							{
								cout << "Unde doresti sa stai?" << endl;
								cout << "Rand: ";
								while (true)
								{
									if (!fgets(buf, sizeof buf, stdin))
										break;
									if (sscanf_s(buf, "%d %c", &rand, &cc) != 1)
									{
										cout << "Ai introdus gresit randul. Mai incearca!\nAlegerea ta: ";
										continue;
									}
									break;
								}
								while (rand - 1 < 0 && rand - 1 > (*spectacole)[alegereSpectacol].getNrRanduriCat2())
								{
									cout << "Rand incorect! Introdu alt rand: ";
									while (true)
									{
										if (!fgets(buf, sizeof buf, stdin))
											break;
										if (sscanf_s(buf, "%d %c", &rand, &cc) != 1)
										{
											cout << "Ai introdus gresit randul. Mai incearca!\nAlegerea ta: ";
											continue;
										}
										break;
									}
								}
								cout << "Loc: ";
								while (true)
								{
									if (!fgets(buf, sizeof buf, stdin))
										break;
									if (sscanf_s(buf, "%d %c", &loc, &cc) != 1)
									{
										cout << "Ai introdus gresit locul. Mai incearca!\nAlegerea ta: ";
										continue;
									}
									break;
								}
								while (loc - 1 < 0 && loc - 1 > (*spectacole)[alegereSpectacol].getNrBileteCat2())
								{
									cout << "Loc incorect! Introdu alt loc: ";
									while (true)
									{
										if (!fgets(buf, sizeof buf, stdin))
											break;
										if (sscanf_s(buf, "%d %c", &loc, &cc) != 1)
										{
											cout << "Ai introdus gresit locul. Mai incearca!\nAlegerea ta: ";
											continue;
										}
										break;
									}
								}
								if ((*spectacole)[alegereSpectacol].getBileteCat2()[rand - 1][loc - 1].getOccupancy() == 0)
								{
									int* UID = (*spectacole)[alegereSpectacol].rezervaBiletCat2(rand - 1, loc - 1);
									int dimUID = (*spectacole)[alegereSpectacol].getBiletCat2(rand - 1, loc - 1).getdimUID();
									cout << "\nBilet la Categoria 2 rezervat! Noteaza-ti undeva UID-ul (vei avea nevoie de el pentru a-ti valida biletul): ";
									for (int i = 0; i < dimUID; i++)
										cout << UID[i];
									ok = true;
								}
								else cout << "Loc deja ocupat! Mai incearca!\n";
							}
						}
						else cout << "Nu mai sunt locuri disponibile la Categoria 2!\n";
					}
					else cout << "Nu puteti rezerva un loc aici deoarece zona nu exista pentru spectacolul selectat.\n";
				}
				else
				{
					if ((*spectacole)[alegereSpectacol].getBileteLoja() != nullptr)
					{
						cout << "La Loja, la spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " mai sunt "
							<< (*spectacole)[alegereSpectacol].getNrLocuriDisponibileLoja() << " locuri disponibile." << endl << endl;
						if ((*spectacole)[alegereSpectacol].getNrLocuriDisponibileLoja() != 0)
						{
							cout << "Dispunerea lor este urmatoarea:\n\n";
							cout << "Locuri Loja:\n\n";
							for (int i = 0; i < (*spectacole)[alegereSpectacol].getNrRanduriLoja(); i++)
							{
								cout << endl << "Rand " << i + 1 << " ";
								for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteLoja(); j++)
									if ((*spectacole)[alegereSpectacol].getBileteLoja()[i][j].getOccupancy() != 0)
										cout << "|_" << char(1) << "_|";
									else cout << "|___|";
								cout << endl << "\t ";
								for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteLoja(); j++)
									cout << j + 1 << "    ";
								cout << endl;
							}
							cout << "\nUnde " << char(1) << " - loc ocupat.";
							ok = false;
							int rand, loc;
							while (!ok)
							{
								cout << "Unde doresti sa stai?" << endl;
								cout << "Rand: ";
								while (true)
								{
									if (!fgets(buf, sizeof buf, stdin))
										break;
									if (sscanf_s(buf, "%d %c", &rand, &cc) != 1)
									{
										cout << "Ai introdus gresit randul. Mai incearca!\nAlegerea ta: ";
										continue;
									}
									break;
								}
								while (rand - 1 < 0 && rand - 1 > (*spectacole)[alegereSpectacol].getNrRanduriLoja())
								{
									cout << "Rand incorect! Introdu alt rand: ";
									while (true)
									{
										if (!fgets(buf, sizeof buf, stdin))
											break;
										if (sscanf_s(buf, "%d %c", &rand, &cc) != 1)
										{
											cout << "Ai introdus gresit randul. Mai incearca!\nAlegerea ta: ";
											continue;
										}
										break;
									}
								}
								cout << "Loc: ";
								while (true)
								{
									if (!fgets(buf, sizeof buf, stdin))
										break;
									if (sscanf_s(buf, "%d %c", &loc, &cc) != 1)
									{
										cout << "Ai introdus gresit locul. Mai incearca!\nAlegerea ta: ";
										continue;
									}
									break;
								}
								while (loc - 1 < 0 && loc - 1 > (*spectacole)[alegereSpectacol].getNrBileteLoja())
								{
									cout << "Loc incorect! Introdu alt loc: ";
									while (true)
									{
										if (!fgets(buf, sizeof buf, stdin))
											break;
										if (sscanf_s(buf, "%d %c", &loc, &cc) != 1)
										{
											cout << "Ai introdus gresit locul. Mai incearca!\nAlegerea ta: ";
											continue;
										}
										break;
									}
								}
								if ((*spectacole)[alegereSpectacol].getBileteLoja()[rand - 1][loc - 1].getOccupancy() == 0)
								{
									int* UID = (*spectacole)[alegereSpectacol].rezervaBiletLoja(rand - 1, loc - 1);
									int dimUID = (*spectacole)[alegereSpectacol].getBiletLoja(rand - 1, loc - 1).getdimUID();
									cout << "\nBilet la Loja rezervat! Noteaza-ti undeva UID-ul (vei avea nevoie de el pentru a-ti valida biletul): ";
									for (int i = 0; i < dimUID; i++)
										cout << UID[i];
									ok = true;
								}
								else cout << "Loc deja ocupat! Mai incearca!\n";
							}
						}
						else cout << "Nu mai sunt locuri disponibile la Loja!\n";
					}
					else cout << "Nu puteti rezerva un loc aici deoarece zona nu exista pentru spectacolul selectat.\n";
				}
			}
		else cout << "Nu exista spectacole in baza de date.\n";
		}
		else if (optiune == 4)
		{
			bool ok = false;
			if(nrCrt)
			{
				int total = 0;
				int alegereSpectacol;
				cout << "La ce spectacol doresti sa vezi nr. total de bilete rezervate?\n";
				cout << "\n\n================================ LISTA SPECTACOLE ================================\n\n";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << (*spectacole[i]).getDenumire() << " - " << (*spectacole[i]).getData() << " - " << (*spectacole[i]).getOra() << " - " << (*spectacole[i]).getNrMaximLocuri() << endl;
				cout << "Alegerea ta: ";
				while (!ok)
				{
					while (true)
					{
						if (!fgets(buf, sizeof buf, stdin))
							break;
						if (sscanf_s(buf, "%d %c", &alegereSpectacol, &cc) != 1)
						{
							cout << "Ai introdus gresit indexul spectacolului. Mai incearca!\nAlegerea ta: ";
							continue;
						}
						break;
					}
					if (alegereSpectacol < nrCrt && alegereSpectacol >= 0)
						ok = true;
					if (!ok)
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
				}
				cout << "Deci doresti sa vezi nr. de bilete rezervate la spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << endl;
				total = (*spectacole)[alegereSpectacol].getNrLocuriOcupateCat1();
				total += (*spectacole)[alegereSpectacol].getNrLocuriOcupateCat2();
				total += (*spectacole)[alegereSpectacol].getNrLocuriOcupateLoja();
				if (total != 0)
					cout << "Sunt " << total << " bilete rezervate la spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << endl;
				else
					cout << "Nu exista bilete rezervate la niciuna dintre categorii pentru spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << endl;
			}
			else
				cout << "Nu exista spectacole disponibile pentru a putea afisa biletele rezervate." << endl;
		}
		else if (optiune == 5)
		{
			bool ok = false;
			if(nrCrt)
			{
				int total = 0;
				int alegereSpectacol;
				cout << "La ce spectacol doresti sa vezi nr. total de bilete disponibile?\n";
				cout << "\n\n================================ LISTA SPECTACOLE ================================\n\n";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << (*spectacole[i]).getDenumire() << " - " << (*spectacole[i]).getData() << " - " << (*spectacole[i]).getOra() << " - " << (*spectacole[i]).getNrMaximLocuri() << endl;
				cout << "Alegerea ta: ";
				while (!ok)
				{
					while (true)
					{
						if (!fgets(buf, sizeof buf, stdin))
							break;
						if (sscanf_s(buf, "%d %c", &alegereSpectacol, &cc) != 1)
						{
							cout << "Ai introdus gresit indexul spectacolului. Mai incearca!\nAlegerea ta: ";
							continue;
						}
						break;
					}
					if (alegereSpectacol < nrCrt && alegereSpectacol >= 0)
						ok = true;
					if (!ok)
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
				}
				cout << "Deci doresti sa vezi nr. de bilete rezervate la spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << endl;
				total = (*spectacole)[alegereSpectacol].getNrMaximLocuri();
				total -= (*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat1();
				total -= (*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat2();
				total -= (*spectacole)[alegereSpectacol].getNrLocuriDisponibileLoja();
				if (total != 0)
					cout << "Nr. total de bilete disponibile la spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << " este " << total << endl;
				else
					cout << "Biletele la spectacolul " << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << " sunt \"SOLD OUT\"!";
			}
			else
				cout << "Nu exista spectacole disponibile pentru a putea afisa biletele disponibile." << endl;
		}
		else if (optiune == 6)
		{
			bool ok = false;
			if(nrCrt)
			{
				int alegereSpectacol;
				cout << "La ce spectacol doresti sa vezi nr. total de bilete disponibile pe categorii?\n";
				cout << "\n\n================================ LISTA SPECTACOLE ================================\n\n";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << (*spectacole[i]).getDenumire() << " - " << (*spectacole[i]).getData() << " - " << (*spectacole[i]).getOra() << " - " << (*spectacole[i]).getNrMaximLocuri() << endl;
				while (!ok)
				{
					while (true)
					{
						if (!fgets(buf, sizeof buf, stdin))
							break;
						if (sscanf_s(buf, "%d %c", &alegereSpectacol, &cc) != 1)
						{
							cout << "Ai introdus gresit indexul spectacolului. Mai incearca!\nAlegerea ta: ";
							continue;
						}
						break;
					}
					if (alegereSpectacol < nrCrt && alegereSpectacol >= 0)
						ok = true;
					if (!ok)
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
				}
				cout << "\nDeci doresti sa vezi nr. total de bilete disponibile pe categorii la spectacolul" << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << endl;
		
					if ((*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat1() != 0)
						cout << "\nNr. locuri disponibile la Categoria 1: " << (*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat1() << endl;
					else
						cout << "\nNu mai sunt locuri la Categoria 1.\n";
					if ((*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat2() != 0)
						cout << "\nNr. locuri disponibile la Categoria 2: " << (*spectacole)[alegereSpectacol].getNrLocuriDisponibileCat2() << endl;
					else
						cout << "\nNu mai sunt locuri la Categoria 2.\n";
					if ((*spectacole)[alegereSpectacol].getNrLocuriDisponibileLoja() != 0)
						cout << "\nNr. locuri disponibile la Loja: " << (*spectacole)[alegereSpectacol].getNrLocuriDisponibileLoja() << endl;
					else
						cout << "\nNu mai sunt locuri la Loja.\n";
			}
			else
				cout << "Nu exista spectacole disponibile pentru a putea rezerva bilete." << endl;
		}
		else if (optiune == 7)
		{
			bool ok = false;
			if(nrCrt)
			{
				int alegereSpectacol;
				cout << "La ce spectacol doresti sa vezi nr. de bilete rezervate pe categorii? \n";
				cout << "\n\n================================ LISTA SPECTACOLE ================================\n\n";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << (*spectacole[i]).getDenumire() << " - " << (*spectacole[i]).getData() << " - " << (*spectacole[i]).getOra() << " - " << (*spectacole[i]).getNrMaximLocuri() << endl;
				while (!ok)
				{
					while (true)
					{
						if (!fgets(buf, sizeof buf, stdin))
							break;
						if (sscanf_s(buf, "%d %c", &alegereSpectacol, &cc) != 1)
						{
							cout << "Ai introdus gresit indexul spectacolului. Mai incearca!\nAlegerea ta: ";
							continue;
						}
						break;
					}
					if (alegereSpectacol < nrCrt && alegereSpectacol >= 0)
						ok = true;
					if (!ok)
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
				}
				cout << "\nDeci doresti sa vezi nr. de bilete rezervate pe categorii la spectacolul" << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << endl;
					cout << "\nNr. locuri ocupate la Categoria 1: " << (*spectacole)[alegereSpectacol].getNrLocuriOcupateCat1() << endl;
				else
					cout << "\nZona Categoria 1 este libera.\n";
				if ((*spectacole)[alegereSpectacol].getNrLocuriOcupateCat2() != 0)
					cout << "\nNr. locuri ocupate la Categoria 2: " << (*spectacole)[alegereSpectacol].getNrLocuriOcupateCat2() << endl;
				else
					cout << "\nZona Categoria 2 este libera.\n";
				if ((*spectacole)[alegereSpectacol].getNrLocuriOcupateLoja() != 0)
					cout << "\nNr. locuri ocupate la Loja: " << (*spectacole)[alegereSpectacol].getNrLocuriOcupateLoja();
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
				cout << "\n\n================================ LISTA SPECTACOLE ================================\n\n";
				for (int i = 0; i < nrCrt; i++)
					cout << i << ". " << (*spectacole[i]).getDenumire() << " - " << (*spectacole[i]).getData() << " - " << (*spectacole[i]).getOra() << " - " << (*spectacole[i]).getNrMaximLocuri() << endl;
				while (!ok)
				{
					while (true)
					{
						if (!fgets(buf, sizeof buf, stdin))
							break;
						if (sscanf_s(buf, "%d %c", &alegereSpectacol, &cc) != 1)
						{
							cout << "Ai introdus gresit indexul spectacolului. Mai incearca!\nAlegerea ta: ";
							continue;
						}
						break;
					}
					if (alegereSpectacol < nrCrt && alegereSpectacol >= 0)
						ok = true;
					if (!ok)
						cout << "Alegerea ta nu corespunde spectacolelor disponibile, introdu o alta: ";
				}
				cout << "\nDeci doresti sa-ti verifici biletul pentru spectacolul" << (*spectacole)[alegereSpectacol].getDenumire() << " - " << (*spectacole)[alegereSpectacol].getData() << " - " << (*spectacole)[alegereSpectacol].getOra() << endl;
				cout << "Introdu UID-ul tau, apoi apasa Enter: ";
				char* buffer = new char[(*spectacole)[alegereSpectacol].maximdimUIDTotal() + 1];
				cin.getline(buffer);
				if ((*spectacole)[alegereSpectacol].getBileteCat1() != nullptr)
				{
					for (int i = 0; i < (*spectacole)[alegereSpectacol].getNrRanduriCat1(); i++)
						for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteCat1(); j++)
							if ((*spectacole)[alegereSpectacol].getBileteCat1()[i][j].checkUID(buffer))
								cout << "Biletul tau a fost gasit la Categoria 1, rand " << i + 1 << ", loc " << j + 1 << endl;
				}
				else if ((*spectacole)[alegereSpectacol].getBileteCat2() != nullptr)
				{
					for (int i = 0; i < (*spectacole)[alegereSpectacol].getNrRanduriCat2(); i++)
						for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteCat2(); j++)
							if ((*spectacole)[alegereSpectacol].getBileteCat2()[i][j].checkUID(buffer))
								cout << "Biletul tau a fost gasit la Categoria 2, rand " << i + 1 << ", loc " << j + 1 << endl;
				}
				else if ((*spectacole)[alegereSpectacol].getBileteLoja() != nullptr)
				{
					for (int i = 0; i < (*spectacole)[alegereSpectacol].getNrRanduriLoja(); i++)
						for (int j = 0; j < (*spectacole)[alegereSpectacol].getNrBileteLoja(); j++)
							if ((*spectacole)[alegereSpectacol].getBileteLoja()[i][j].checkUID(buffer))
								cout << "Biletul tau a fost gasit la Loja, rand " << i + 1 << ", loc " << j + 1 << endl;
				}
				else
					cout << "UID negasit. Biletul e fake.\n";
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