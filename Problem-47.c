#include<stdio.h>
int main(void)
{
  int i;
  
  for(i = 0; i < 5; i++){
    printf("%d ",i);
    continue;
    printf("test");
  }
}
