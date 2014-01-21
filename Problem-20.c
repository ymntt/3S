#include<stdio.h>
#include "linked-list.h"

int delNode(struct node *start, int number)
{
  struct node *tmp,*prev;

  tmp=start;
  prev=start;

  while(tmp!=NULL){
    if((tmp->number)==number){
      (prev->next)=(tmp->next);
      return 1;
    }
    (prev->next)=(tmp->next);
    return 1;
  }
  return -1;
}
