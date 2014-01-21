#include<stdio.h>
struct node{
        struct node *next;
        int num;
};
int main(void)
{
        struct node start,myNode,yourNode,*tmp;
        start.num=0;        start.next=&myNode;
        yourNode.num=19; yourNode.next=&start;
        myNode.num=17; myNode.next=&yourNode;
        tmp=&myNode;
        while(tmp!=&start){
                printf("%d\n",tmp->num);
                tmp=tmp->next;
        }
        return 0;
}
