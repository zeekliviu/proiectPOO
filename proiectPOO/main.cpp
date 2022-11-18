#include <iostream>
using namespace std;
#include "spectacolTeatru.h"
int main()
{
	spectacolTeatru s1="A";
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
	cout << "Id spectacol: " <<s1.idSpectacol << endl;
	return 0;
}