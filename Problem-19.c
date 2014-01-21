/* linked-list-find.c */
#include <stdlib.h>
#include "linked-list.h"
struct node * findNode(struct node * start, int number)
{
struct node *tmp;
tmp=start;
while (tmp!=NULL) {
if ((tmp->number) == number) {
return tmp;
}
tmp = tmp->next;
}

while (tmp!=NULL) {
if (tmp->number == number) {
return t;
}
tmp = tmp->next;
}
while (tmp!=NULL) {
if (tmp->number == number) {
return t;
}
tmp = tmp->next;
}
return NULL;
}
