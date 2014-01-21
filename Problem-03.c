#include<stdio.h>
#include<limits.h>
int factorial(int number);
int main(void)
{
  int num=1,max=1;
  for (num=1;num>0;num++){
    max=factorial(num);
    if ((0<max) &&
	(max < INT_MAX)) {
      printf("%d %d \n", num, max);
    } else {
      printf("over? %d: %d\n", num, max);
      break;
    }
  }
}
int factorial(int number)
{
  if(number == 1){
    return 1;
  } else {
    number = number * factorial(number - 1);
    return number;
  }
}

