#ifndef QUIZMANAGER_H_INCLUDED
#define QUIZMANAGER_H_INCLUDED

#include "Pytanie.h"
#include "PobierzZPliku.h"

class QuizManager
{
   private:
   PobierzPytanieZPliku _pobierzZPliku;
   Pytanie *_pytanie;
   int _liczbaPytan;
   int _liczbaPunktow;

   public:
   QuizManager();

   QuizManager(string nazwaPliku);

   void SetPytania();

   void ShowQuiz();

   void StartQuiz();

   int GetPunkty();

   int GetLiczbaPytan();

   ~QuizManager();



};

#endif // QUIZMANAGER_H_INCLUDED
