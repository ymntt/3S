#include<stdio.h>
#include<string.h>
int main(void)
{
	char *src = "Hello World from Japan";
	char dest[256];
	strcpy(dest,src);
	printf("%s\n",dest);
	return 0;
}
