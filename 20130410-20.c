#include<stdio.h>
int function(int j, int k);
int main(void)
{
  int i=-1,j=0,k=1;
  i=function(i,k);
  if(i==0){
    i=function(k,i);
  }else {
    i=function(i,j);
  }
  printf("%d %d %d\n", i, j, k);
  return 0;
}
int function(int j, int k)
{
  int swap=0,sum=0;
  swap=j;
  j=k;
  k=j;
  return sum;
}
