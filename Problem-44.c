
#include<stdio.h>

enum Alpha {YAMADA , SATO , TANAKA };

int main(void)
{
  enum Alpha cats;
  
  cats = YAMADA;
  printf("YAMADA = %d\n",cats);
  cats = SATO;
  printf("SATO = %d\n",cats);
  cats = TANAKA;
  printf("TANAKA = %d\n",cats);

  return 0;
}
