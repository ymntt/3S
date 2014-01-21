int showNode(struct node *start)
{
  struct node *tmp;
  tmp=start->next;
  while(tmp!=start){
    printf("tmp:%p ",tmp);
    printf("tmp->next:%p ",tmp->next);

    printf("num:%7d",tmp->number);
    printf("eng:%3d",tmp->english);
    printf("mat:%3d",tmp->mathmatics);
    printf("phy:%3d\n",tmp->physics);
    tmp=tmp->next;
  }
  return 1;
}
