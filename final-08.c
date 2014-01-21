#include<stdio.h>
int main(void)
{
	char msg[]="The more I learn, the more I realize I don't know. The more I realize I don't know, the more I want to learn.";
	char *c;
	int count=0;
	c=msg;
	while(*c!='\0'){
		if(*c=='I'){
			count++;
		}
		c++;
	}
	printf("%d",count);
	return 0;
}
