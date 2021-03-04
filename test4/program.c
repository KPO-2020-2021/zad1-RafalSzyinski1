#include <stdio.h>


/*
  Przy kompilacji gcc program dziala poprawnie
  Przy kompilacji g++ program nie widzi funkcji w innym pliku
  przez co wywala blad 
*/
double Dodaj();


int main( )
{
  double  Skl1 = 2.0,  Skl2 = 2.0;
  double  Wynik = Dodaj(Skl1,Skl2);

  printf("  Wynik dodawania:  %f + %f = %f\n",Skl1,Skl2,Wynik);

  return 0;
}
