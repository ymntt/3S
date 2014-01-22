#include<stdio.h>
#include<string.h>
int main(void)
{
	char *s="Hello World";
	int size=0;
	size =(int) strlen(s);
	printf("%s %d\n", s, size);
	return 0;
}

