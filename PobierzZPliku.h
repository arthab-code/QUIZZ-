#ifndef POBIERZZPLIKU_H_INCLUDED
#define POBIERZZPLIKU_H_INCLUDED

#include <iostream>
#include "Pytanie.h"

using namespace std;
class PobierzPytanieZPliku
{
   private:
   string _nazwaPliku;
   string _sciezka;
   public:
   PobierzPytanieZPliku();
   PobierzPytanieZPliku(string nazwa_pliku);
   Pytanie WczytajPytanieZPliku(int nrPytania);

   int LiczbaPytan();

   string NazwaPliku();
};

#endif // POBIERZZPLIKU_H_INCLUDED
