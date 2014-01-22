#include<stdio.h>
void change(int a, int b);
int main(void)
{
  int i=5,j=10;
  change(i,j);
  printf("%d %d \n",i,j);
  return 0;
}
void change(int a,int b)
{
  int t;
  t = a;
  a = b;
  b = t;
  return;
}
