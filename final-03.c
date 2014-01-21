#include<stdio.h>
void show(int ar[],int size);
void func(int ar[],int size);
int main(void)
{
	int array[4]={9,8,7,6};
	int i=0;
	show(array,4);
	func(array,4);
	show(array,4);
	return 0;
}
void show(int ar[], int size)
{
	int i=0;
	for(i=0;i<size;i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
	return;
}
void func(int ar[], int size)
{
	int i=0;
	for (i=0;i<size;i++){
		if(ar[i]%3==0){
			ar[i]= -1*ar[i];
		}
	}
	return;
}
