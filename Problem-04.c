#include<stdio.h>
int fib_sub(int a1, int a2);
int main(void)
{
  int i=0;
  printf("フィボナッチ数列\n");
 for (i=1;i<=30;i++) {
    printf("%d番め = %d\n",i-1,fib(i)); }
  return 0;
}

int fib(int n){
  int num=0;
  if (n==1){
 return 1;}
  else if (n==2) {return 1;} 
  else 
{ num = fib(n-1) + fib(n-2); return num; } }
