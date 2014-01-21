#include<stdio.h>
int main(void)
{
  char string[]="DigitalSeries";
  int i=0;
  while (string[i] != '0'){
    i++;
  }
  printf("%d\n", i);
  return 0;
}
