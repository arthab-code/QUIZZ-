#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "PobierzZPliku.h"
#include "FolderQuizow.h"


   PobierzPytanieZPliku::PobierzPytanieZPliku()
   {
       FolderQuizow folder;
       string nazwaFolderu = folder.ZwrocFolder();
       _nazwaPliku = "pytania.txt";
       _sciezka = nazwaFolderu+"/"+_nazwaPliku;
   }

   PobierzPytanieZPliku::PobierzPytanieZPliku(string nazwa_pliku)
   : _nazwaPliku(nazwa_pliku)
    {
        FolderQuizow folder;
        string nazwaFolderu = folder.ZwrocFolder();
       _sciezka = nazwaFolderu+"/"+_nazwaPliku;
    }

   Pytanie PobierzPytanieZPliku::WczytajPytanieZPliku(int nrPytania)
   {
    fstream plik;
    string linia;

    plik.open(_sciezka.c_str());

    if (!plik.good())
    {
        cout << "Blad otwarcia pliku" << endl;
        exit(EXIT_FAILURE);
    }

    string snr = to_string(nrPytania);
    snr = "["+snr+"]";

    Pytanie p;

    while(getline(plik, linia))
    {
        if(linia == snr)
        {
        getline(plik, linia);
        p.UstawTrescPytania(linia);
        getline(plik, linia);
        p.UstawOdpowiedz(0,linia);
        getline(plik, linia);
        p.UstawOdpowiedz(1,linia);
        getline(plik, linia);
        p.UstawOdpowiedz(2,linia);
        getline(plik, linia);
        remove(linia.begin(), linia.end(), ' ');
        p.UstawOdpowiedzPrawidlowa(atoi(linia.c_str()));

        }
    }
    return p;
   }

   int PobierzPytanieZPliku::LiczbaPytan()
   {
       fstream plik;
       string linia;
       plik.open(_sciezka.c_str());

        if (!plik.good())
        {
          cout << "Blad otwarcia pliku" << endl;
           exit(EXIT_FAILURE);
        }

        int licz = 0;
        while(getline(plik, linia))
        {

         licz++;

        }

        return (licz/6);
   }

    string PobierzPytanieZPliku::NazwaPliku()
    {
        return _sciezka;
    }
