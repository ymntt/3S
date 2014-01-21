#include<stdio.h>
int func(int a, int b, int c);
int main(void)
{
	int i=7,j=11,k=13,m=0;
	m=func(i,j,k);
	printf("%d %d %d %d\n",i,j,k,m);
	return 0;
}
int func(int a, int b, int c)
{
	int sum=0;
	sum=a+b+c;
	a=sum-a;
	b=sum-b;
	c=sum-c;
	return sum;
}

