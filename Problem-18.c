#include<stdio.h>
#include<stdlib.h>

struct node{
  struct node *next;
  int number;
  int english;
  int mathematics;
  int physics;
  float hensa;
};


int addNode(struct node *start, int n,int e, int m, int p);
int showNode(struct node * start);

int main(void)
{
  int n,e,m,p,count=0; /* count 読み込み行を数える */
  char line[128];
  struct node start;
  struct node *tmp;

  /* 先頭の構造体にはデーターを入れない */
  start.next=NULL;
  start.number=0;
  start.english=0;
  start.mathematics=0;
  start.physics=0;
  start.hensa=0;

  /* 1行ごと標準入力から読みこむ */
  while(fgets(line,sizeof(line),stdin)!=NULL){
    count++;
    sscanf(line,"%d,%d,%d,%d",&n,&e,&m,&p);
    if(addNode(&start,n,e,m,p)!=1){
      fprintf(stderr,"cannot allocate memory\n");
      return -1;
    }
  }

  showNode((&start)->next);
  printf("Number of Student: %d\n",count);

  return 0;
}
int addNode(struct node *start, int n, int e, int m, int p)
{
  struct node *t;
  t=(struct node *) malloc(sizeof(struct node));
  if(t ==NULL){
    return -1;
  }
  t->number=n;
  t->english=e;
  t->mathematics=m;
  t->physics=p;
  t->next=start->next;
  start->next=t;
  return 1;
}
int showNode(struct node *start)
{
  struct node *t;
  t=start;
  while(t ->next!=NULL){
    printf("number: %7d\t",t->number);
    printf("engilisg: %3d\t",t->english);
    printf("mathematics: %3d\t", t->mathematics);
    printf("physics: %3d\n", t->physics);
    t=t->next;
  }
  printf("number: %7d\t", t->number);
  printf("english: %3d\t", t->english);
  printf("mathematics: %3d\t", t->mathematics);
  printf("physics: %3d\n", t->physics);
  return 1;
}
