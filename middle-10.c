#include<stdio.h>
int myFunction(int *pt1, int *pt2);
int main(void)
{
  int c1=4,c2=5,c3=6;
  c3=myFunction(&c1,&c2);
  printf("%d %d %d\n",c1,c2,c3);
return 0;
}
int myFunction(int *pt1, int *pt2){
  int tmp=0;
  tmp = *pt1;
  *pt1 = *pt2;
  *pt2 = tmp;
  return 0;
}
