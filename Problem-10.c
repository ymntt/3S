#include<stdio.h>
int main(void)
{
  int c=32;
  int count;

  for (c=32;c<127;c++){
    count= c % 8;
    if(count==0){
      printf("%c: %d \n", c, c); } else {
    printf("%c: %d ", c, c);
    }}
  return 0;
}

