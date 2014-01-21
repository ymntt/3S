#include<stdio.h>
int main(void)
{
  int array[]={3,1,4,1,5,9,2,6};
  int i=0;
  for (i=0;i<8;i++){
    printf("%d %d ", i, array[i]);
  }
  return 0;
}
