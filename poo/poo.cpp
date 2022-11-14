/*
The Ticketing App

Creați o aplicație ce permite gestionarea biletelor emise pentru diferite evenimente (film, piesă de teatru, meci de fotbal, etc.)


Aplicația va avea următoarele funcționalități:

va permite citirea caracteristicilor locației (ex: număr maxim de locuri, număr de rânduri, zone, număr/codificare scaune pe rând, etc.)
va permite citirea caracteristicilor evenimentului (ex: dată, oră, denumire, etc.)
permite generarea de bilete nominale conform caracteristicilor dorite (ex: VIP, peluză, tribună, loje, etc.)
biletele generate vor avea un id unic ce va putea fi verificat ulterior (id-ul va fi generat aleator astfel încât să nu existe id-uri duplicate pentru același eveniment și nici posibilitatea ca participanții să ghicească id-urile biletelor)
aplicația va pune la dispoziția utilizatorului un meniu unde va putea introduce caracteristicile locației și ale evenimentului, va putea genera și ulterior valida biletele emise
aplicația trebuie să trateze orice fel de input și va afișa mesaje de eroare dacă acesta este invalid
aplicația nu va genera erori de execuție pentru niciun fel de input
NU pot fi folosite biblioteci externe (third party) pentru citirea sau validarea datelor
soluția trebuie implementată utilizând doar biblioteci standard din C++ (precum iostream, string, fstream, etc) utilizate în cadrul cursurilor și laboratoarelor. Clasele STL nu sunt acceptate decât atunci când sunt cerute în mod explicit (doar în cadrul fazei 2)


Exemple de scenarii de luat în considerare:


Emitere de bilete de fotbal într-un stadion dotat cu o peluză și două tribune (tribuna 1 și tribuna 2). Fiecare zonă are rând și loc. Biletele pentru un anumit meci se vor genera în limita locurilor disponibile. Atunci când un utilizator prezintă biletul se va verifica id-ul unic al acestuia pentru a vedea dacă este valid.
Emitere de bilete la film din categoriile Normal sau VIP. Fiecare zonă are rând și loc. Biletele se vor genera în limita locurilor disponibile. Atunci când un utilizator prezintă biletul se va verifica id-ul unic al acestuia pentru a vedea dacă este valid.
Emitere de bilete la teatru din categoriile Categoria 1, Categoria 2 și Lojă. Fiecare zonă are rând și loc. Biletele se vor genera în limita locurilor disponibile. Atunci când un utilizator prezintă biletul se va verifica id-ul unic al acestuia pentru a vedea dacă este valid.


Faza 1:
Deadline: 18.12.2022 23:59
Minim 3 clase ce au legătură cu proiectul
Clasele trebuie să conțină (per total, nu fiecare) cel puțin un vector alocat dinamic de caractere, un vector numeric alocat dinamic, un câmp constant, un câmp static și o metodă statică. Membrii trebuie să aibă legătură cu clasa.
Toate atributele vor fi definite în zona privată a clasei
Toate atributele vor avea metode de acces; setterii vor conține validări
Fiecare clasa va conține cel puțin 2 metode generice (altele decât constructorii sau metodele de acces) ce vor fi utilizate pentru a realiza diverse prelucrări
Fiecare clasă va conține cel puțin un constructor implicit și unul cu parametri. Clasele cu membri pointeri vor respecta „regula celor 3”.
Fiecare clasă va conține supraîncărcări pentru operatorii << și >>
Fiecare clasă va avea cel puțin 2 operatori supraîncărcați dintre următorii (același operator nu poate fi supraîncărcat în 2 clase diferite):
operator de indexare []
operatori aritmetici (+,-,* or /)
++ or -- (ambele forme)
cast implicit sau explicit
operator de negație !
operatori relaționali (<.>,=<,>=,==)
Clasele vor fi implementate în propriul fișier header și/sau cpp
Funcția main va fi localizată într-un alt fișier cpp
Această fază este considerată implementată dacă cel puțin 75% dintre cerințe sunt implementate
*/
#include <iostream>
#pragma warning (disable:4996)
class biletCategoria1
{
	const int id;
	char* nume;
	int rand, loc;
};
class biletCategoria2
{
	const int id;
	char* nume;
	int rand, loc;
};
class biletLoja
{
	const int id;
	char* nume;
	int rand, loc;
};
class spectacolTeatru
{
	int nrMaximLocuri;
	char* denumire;
	char* data;
	char* ora;
	biletCategoria1 b1;
	biletCategoria2 b2;
	biletLoja b3;
};
int main()
{
	
	return 0;
}
