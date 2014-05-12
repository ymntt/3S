/*
今年の課題らしい
分からないと主張する後輩のために作った
*/
#include<stdio.h>
#include<string.h>

int main(void){
	int i,len;
	char str[]="Hello,World!";

	len=strlen(str);

	for(i=0;i<=len;i++){
			if(65<=str[i] && str[i]<=90){
			printf("%c",str[i]+32);
			}else if(97<=str[i] && str[i]<=122){
			printf("%c",str[i]-32);
			}else{
			printf("%c",str[i]);
			}
	}
	return 0;
}
