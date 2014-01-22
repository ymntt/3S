/*
  File name :typedef.c
*/
#include<stdio.h>
struct temp
{
	int x;
};
typedef struct temp test;

typedef unsigned int unit;

int main(int argc,char** argv)
{
	int i;
	int j;
	int k = 1;
	unit c;
	test calc;
	printf("数字を入力");
	scanf("%d", &calc.x);
	printf("入力した数字に1から順番にかけ算をします\n");
	for(i=1;i<101;i++){
		if(i<=10){
			j = (i)*(calc.x);
			printf("%d  ",j);
		}
		if(i>10){j = (i)*(calc.x);
		printf("%d ",j);
		}
		if(i%10 == 0){
			printf("\n");
		}
	}
	return 0;
}
