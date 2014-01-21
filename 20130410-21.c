#include<stdio.h>
int main(void)
{
  int i;
  int sum;
  for(i=0;i<10;i++){
    if(i<10){
      i=i+1;
      sum=sum+i;
    }else {
      printf("%d", sum);
    }
  }
  return 0;
}
