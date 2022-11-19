#include <iostream>
using namespace std;
#include "spectacolTeatru.h"
int main()
{
	/*spectacolTeatru s1(10, "A");
	cout << "Denumire spectacol: " << s1.getDenumire() << endl;
	cout << "Data spectacol: " << s1.getData() << endl;
	cout << "Ora spectacol: " << s1.getOra() << endl;
	cout << "Nr. maxim locuri: " <<s1.getNrMaximLocuri() << endl;
	cout << "Nr. randuri Categoria 1: " <<s1.getNrRanduriCat1() << endl;
	cout << "Nr. bilete Categoria 2: " << s1.getNrBileteCat1() << endl;
	cout << "Nr. randuri Categoria 2: " <<s1.getNrRanduriCat2() << endl;
	cout << "Nr. bilete Categoria 2: " <<s1.getNrBileteCat2() << endl;
	cout << "Nr. randuri loja: " <<s1.getNrRanduriLoja() << endl;
	cout << "Nr. bilete loja: " <<s1.getNrBileteLoja() << endl;
	cout << "Id spectacol: " <<s1.idSpectacol << endl;*/
	/*biletLoja b;
	cout << "Id bilet: " << b.getId() << endl;
	cout << "Nume spectator: " << b.getNumeSpectator() << endl;
	cout << "UID spectator: ";
	for (int i = 0; i < b.getdimUID(); i++)
		cout << b.getUID()[i]<< " ";
	cout << endl<<"UID spectator: ";
	int* UID = new int[b.getdimUID()];
	for (int i = 0; i < b.getdimUID(); i++)
		UID[i] = i, cout << UID[i] << " ";
	cout << endl;
	cout<<b.checkUID(UID, b.getdimUID());*/
	/*int* p;
	p = new int[4];
	for (int i = 0; i < 4; i++)
		p[i] = i;
	for (int i = 0; i < 4; i++)
		cout << p[i] << " ";
	cout << endl;
	int* aux = new int[4];
	for (int i = 0; i < 4; i++)
		aux[i] = p[i];
	p = new int[5];
	p[4] = 4;
	for (int i = 0; i < 4; i++)
		p[i] = aux[i];
	for (int i = 0; i < 5; i++)
		cout << p[i] << " ";*/
	/*spectacolTeatru s1(100, "A",2,3,3,2,1,5);
	bool distributieEgala = !s1;
	cout << s1.getNrBileteCat1() << s1.getNrRanduriCat1() << endl;
	cout << s1.getNrBileteCat2() << s1.getNrRanduriCat2() << endl;
	cout << s1.getNrBileteLoja() << s1.getNrRanduriLoja() << endl;
	cout << distributieEgala;*/
	biletCategoria1 b1(1, "Popescq");
	biletCategoria1 b2(2, "Popescu");
	cout << b1.getId();
	cout << b2.getId();
	cout << (b1 < b2);
	return 0;
}