/*
  File name :typedef.c
*/
#include<stdio.h>
int main(void)
{
	int i;
	do{
		printf("☆必ず実行される部分☆\n\n");
		printf("続行は1、終了はその他キーを入力:");
		scanf("%d",&i);
	}while(i == 1);
		printf("\n%dが入力されました\nさようなら",i);
	return 0;
}
