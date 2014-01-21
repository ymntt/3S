#include<stdio.h>
int function(int j, int k);
int main(void)
{
  int i=-1,j=0,k=1;
  i=function(j,k);
  printf("%d %d %d\n", i, j, k);
  return 0;
}
int function(int j, int k)
{
  int sum=0;
  sum=j+k;
  return sum;
}
