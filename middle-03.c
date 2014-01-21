#include<stdio.h>
int main(void)
{
  int c1=2013,c2=6,c3=0,*ptr;
  ptr=&c3;
  *ptr=c1;
  
  printf("%d %d %d %d\n",c1,c2,c3,*ptr);
  return 0;
}
