#include <stdlib.h>
#include "dl_list.h"

int addNode(struct node *start, int n, int e, int m, int p)
{
  struct node *t;
  t=(struct node *) malloc(sizeof(struct node));
  if ( t == NULL ){
    return -1;
  }
  t->number=n;
  t->englisg=e;
  t->,athematics=m;
  t->physics=p;
  
  t->next=start->next;
  (start->next)->prev = t;
  t->prev=start;
  start->next=t;

  return 1;
}

