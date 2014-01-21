#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int cmp=0;
	if(argc<2){
	fprintf(stderr ,"Usage: %s str1 str2",argv[0]);
	return -1;
}
	cmp = strcmp(argv[1],argv[2]);
	if (cmp == 0){
	  printf("%d: %s is equal tp %s \n",cmp,argv[1],argv[2]);
	}else if(cmp < 0){
	  printf("%d: %s is smaller than %s \n",cmp,argv[1],argv[2]);
	}else{
	printf("%d: %s is laerger than %s \n",cmp,argv[1],argv[2]);
}
	return 0;
}
