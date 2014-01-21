#include<stdio.h>
int myFunction(int *a, int *b);
int main(void)
{
  int i=7,j=5;
  i = myFunction(&i,&j);
  printf("%d %d\n",i,j);
  return 0;
}
int myFunction(int *a, int *b)
{
  int sum=0;
  sum = *a + *b;
  return sum;
}

