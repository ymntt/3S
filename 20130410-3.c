#include<stdio.h>
int main(void)
{
  int array[]={27,1,8,2,8,1,8,3};
  int i=0;
  for (i=0;i<9;i++){
    printf("%d %d ", i, array[i]);
  }
  return 0;
}
