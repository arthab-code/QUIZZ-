#include <iostream>
#include "QuizManager.h"

using namespace std;

   QuizManager::QuizManager()
   {
     PobierzPytanieZPliku pzp;
    _pobierzZPliku = pzp;
    _liczbaPytan = pzp.LiczbaPytan();
    _pytanie = new Pytanie[_liczbaPytan];
    _liczbaPunktow = 0;
   }

   QuizManager::QuizManager(string nazwaPliku)
   {
     PobierzPytanieZPliku pzp(nazwaPliku);
    _pobierzZPliku = pzp;
    _liczbaPytan = pzp.LiczbaPytan();
    _pytanie = new Pytanie[_liczbaPytan];
    _liczbaPunktow = 0;
   }

   void QuizManager::SetPytania()
   {
     for (int i=0;i<_liczbaPytan;i++)
     {
         _pytanie[i] = _pobierzZPliku.WczytajPytanieZPliku(i+1);
     }
   }

   void QuizManager::ShowQuiz()
   {

     for (int i=0;i<_liczbaPytan;i++)
     {
         cout << endl;
         if (_pytanie[i].ZwrocOdpowiedz() == -1) continue;

         if(_pytanie[i].ZadajPytanie(i+1))
         {
             cout << "Prawidlowa odpowiedz ! " << endl;
             _liczbaPunktow++;

         } else {

            cout << "Niepoprawna odpowiedz ! " << endl;
         }
     }

   }

   void QuizManager::StartQuiz()
   {

     SetPytania();
     ShowQuiz();

     cout << endl;
     cout << "LICZBA PKT : " << _liczbaPunktow << endl;
   }

   int QuizManager::GetPunkty()
   {
       return _liczbaPunktow;
   }

   int QuizManager::GetLiczbaPytan()
   {
       return _liczbaPytan;
   }

   QuizManager::~QuizManager()
   {
       delete[] _pytanie;
   }

