#include<stdio.h>
int main(void)
{
  int array_e[]={2,7,1,8,2,8,1,8,3};
  int array_pi[]={3,1,4,1,5,9,2,6,5};
  int array_sum[9];
  int i=0;
  for (i=0;i<9;i++){
    array_sum[i]=array_e[i]+array_pi[i];
  }
  printf("%d\n", array_sum[1]);
  return 0;
}
