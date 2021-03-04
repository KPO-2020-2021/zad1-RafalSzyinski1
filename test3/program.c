#include <stdio.h>

/* 
    Kompiluje sie przy gcc
    Przy g++ wywoluje blad: undefined reference to `E'
*/

extern const double PI;
extern const double E;


int main()
{
  printf("  PI: %f\n",PI);
  printf("   E: %f\n",E);
  return 0;
}
