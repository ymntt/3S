#include<stdio.h>
#include<stdlib.h>
struct node{
  struct node *next;
  int num;
};
int main(void)
{
  struct node n1,n2,n3,n4,*tmp;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = NULL;
  n1.num = 100;
  n2.num = 120;
  n3.num = 130;
  n4.num =140;
  tmp = &n1;
  while (tmp != NULL){
    printf("%d\n" ,tmp->num);
    tmp = tmp->next;
  }
  return 0;
}
