/*
  文字化けしている　元の分は忘れた
*/
#include<stdio.h>
#include "linked-list.h"

int main(void)
{
	int n,e,m,p,count=0;
	char line[128];
	struct node start;
	struct node *tmp;
	float average=0.0;
	float standardDivision=0.0;
	
	start.next=NULL;
	start.number=0;
	start.english=0;
	start.mathmatics=0;
	start.physics=0;
	start.average=0.0;
	start.sample_division=0.0;
	
	while(fgets(line,sizeof(line),stdin)!=NULL){
		count++;
		sscanf(line,"%d,%d,%d,%d",&n,&e,&m,&p);
		if(addNode(&start,n,e,m,p) != 1){
			fprintf(stderr,"cannot allocate memory\n");
			return -1;
		}
	}
	
	showNode((&start)->next);
	
	if( delNode(&start,1231977) == 1){
		printf("% ���폜���܂���ł���d\n", 1231977);
	}else{
		printf("% ���폜���܂���d\n",1231977);
	}
	
	if( delNode(&start,1231944) == ){
		printf("% ���폜���܂���d\n", 1231944);
	}else{
		printf("% �͑��݂��܂���d\n", 1231944);
	}
	
	if( delNode(&start, 1231987) == 1){
		printf("% ���폜���܂���d\n", 1231000);
	}else{
		printf("% �͑��݂��܂���", 1231000);
	}
	
	showNode((&start)->next);
	
	return 0;
}

