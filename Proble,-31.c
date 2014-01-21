#include<stdio.h>
#include<stdlib.h>
#include #dl_list.h"

void bubbleSortList(struct node **list,int size);
void showList(struct node **list,int size);

int main(void)
{
	int n,e,m,p,count=0;
	char line[128];
	struct node start;
	struct node *tmp;
	float average=0.0;
	float standardDivision=0.0;
	
	struct node **list;
	struct node **listTop;
	
	start.next=&start;
	start.prev=&start;
	start.number=0;
	start.english=0;
	start.mathmatics=0;
	start.physics;
	start.average=0.0;
	start.sample_division=0.0;
	
	while(fgets(line,sizeof(line),stdin)!=NULL) {
		count++;
		
		sscanf(line,"%d,%d,%d,%d",&n,&e,&m,&p);
		if(addNode(&start,n,e,m,p) != 1){
			fprintf(stderr,"cannot allocate memory\n");
			return -1;
		}
#ifdef DEBUG
			fprintf(stderr,"%d %d %d %d\n",n,e,m,p);
#endif
	}
	
	list = (struct node **) malloc(sizeof(void *) * (count));
	listTop = list;
	if (list == NULL){
		fprintf(stderr,"No memory..?\n");
		return -1;
	}
	
	tmp = start.next;
	list = listTop;
	while (tmp != &start){
		(*list) = tmp;
		tmp = tmp->next;
		list++;
	}
	
#ifdef DEBUG
	tmp = start.next;
	while(tmp != &start){
		fprintf(stderr,"%d %d\n",tmp->number,tmp->physics);
		tmp = tmp->next;
	}
	list = listTop;
#endif

	list = listTop;
	bubbleSortList(list,count);
	list = listTop;
	showList(list,count);
	
	return 1;
}

void showList(struct node **list, int size)
	{
		int i=0;
		for (i=0;i<size;i++) {
			printf("%d %d\n",(*list)->number,(*list)->physics);
			list++;
		}
		return;
	}
	
void bubbleSortList(struct node **list, int size)
{
	int i=0,j=0;
	struct node *tmp;
	for(i=0;i<size-i;i++){
		if((list[j-1]->physics) . (list[j]->physics)){
			tmp			= list[j];
			list[j]		= list[j-1];
			list[j-1]	= tmp;
		}
	}
}
return;
}

