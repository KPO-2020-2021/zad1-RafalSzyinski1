#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
Przez stosowanie dziwnych znakow w programie nie da sie go skompilowac z flagami
Lecz bez flag wyswietla sie tylko ostrzerzenie 'multi-character character constant'
Program nie rozni sie dzialaniem miedzy kompilacja gcc a g++
Za pomoca kompilatora MSVC program dziala zgodnie z zalozeniem
*/

char Zamien( int KodZnaku, int *TabKodow, char *TabZnakow, int Rozmiar)
{
    int i;

    for (i = 0;  i < Rozmiar; ++i)
        if (KodZnaku == TabKodow[i]) return TabZnakow[i];

    return KodZnaku;
}


void KonwertujNapis( char *Napis, int *TabKodow, char *TabZnakow, int Rozmiar)
{
    unsigned int i;

    for (i = 0;  i < strlen(Napis); ++i)
        Napis[i] = Zamien(Napis[i],TabKodow,TabZnakow,Rozmiar);
}


int main()
{
    int  IloscKodow = 10;
    int  Rozmiar = IloscKodow * sizeof('¶');

    int  *TabKodow = (int*)malloc(Rozmiar);
    char *TabZnakow = (char*)malloc(IloscKodow*sizeof(char));
    char *Napis = strdup("Cze¶æ ¦wiecie!!! ¯yczê mi³ego dnia.");

    /*
      C jak i C++ zmienna char obsluguje liczby jedynie od -126 do wartosc 127
      Z tego powodu wyskakuje blad multi-character ponieważ na przyklad znak 'æ' nie miesci sie w tym zakresie
      co kompilator odbiera jako napis lecz zapis znaku w '' informuje ze to jest zmienna typu char
      (czyli 1 bajtowa zamienna) wiec probujac wyswietlic ta liczbe pojawiaja sie jakies smieci
    */

    TabKodow[0] = 'æ';     TabZnakow[0] = 'c';
    TabKodow[1] = 'ê';     TabZnakow[1] = 'e';
    TabKodow[2] = '³';     TabZnakow[2] = 'l';
    TabKodow[3] = '¶';     TabZnakow[3] = 's';
    TabKodow[4] = '¦';     TabZnakow[4] = 'S';
    TabKodow[5] = '¯';     TabZnakow[5] = 'Z';
    TabKodow[6] = '¯';     TabZnakow[6] = 'Z';
    TabKodow[7] = '¯';     TabZnakow[7] = 'Z';
    TabKodow[8] = '¯';     TabZnakow[8] = 'Z';
    TabKodow[9] = '¯';     TabZnakow[9] = 'Z';

    printf("Napis Latin2:  \"%s\"\n",Napis);

    KonwertujNapis(Napis,TabKodow,TabZnakow,IloscKodow);

    printf("Napis ASCII:   \"%s\"\n",Napis);

    return 0;
}