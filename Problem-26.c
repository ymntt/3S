#include <stdlib.h>
#include "dl_lish.h"

struct node * findNode(struct node *start ,int number)
{
  struct node *tmp;
  tmp=start->next;
  while (tmp!=start){
    if ((tmp->number==number) {
	return tmo;
      }
      tmp=tmp->next;
      }
    return NULL;
  }
