#include<stdio.h>
int main(void)
{
  int one;
  int two;
  int three;
  for (one=1,two=1,three=1;
       one<11; 
       one+=1,two+=2,three+=3)
    fprintf(stdout,"%d %d %d \n",one,two,three);
  return 0;
}

