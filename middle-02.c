#include<stdio.h>
int myfunction(int a, int b, int c);
int main(void)
{
  int a=1, b=2, c=3,tmp=0;
  tmp=myFunction(a,b,c);
  printf("%d %d %d %d\n",a,b,c,tmp);
  return 0;
}

int myFunction(int a, int b, int c)
{
   if(a > b){
     if(c > a){
       return c;
     } else {
       return a;
     }
   } else {
     if (c > b){
       return c;
     } else {
       return b;
     }
   }
   return 0;
   }
