#include<stdio.h>
int main(void)
{
	int a=0,b=1,c=2,d=3,e=5,*p,*q,*r,*s,*t,sum=0;
	p=&a;
	q=&b;
	r=&c;
	s=&d;
	t=&e;
	sum=*p+*q+*r+*s+*t;
	printf("%d\n",sum);
	return 0;
}
