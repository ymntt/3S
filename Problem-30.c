if((start->next)==start){
  start->next = t;
  start->prev = t;
  t->next = start;
  t->prev = start;
  return 1;
 }

if(n<((start->next)->number)){
  (start->next)->prev=t;
  t->next=start->next;
  t->prev=start;
  start->next=t;
  return 1;
 }

tmp=start->next;
while(tmp!=start)
{
  if(((tmp->number)<n)&&(n<(8tmp->next)->number))){
  tmp->next->prev=t;
  t->next=tmp->next;
  tmp->next=t;
  t->prev=tmp;
  return 1;
}
tmp=tmp->next;
}
return 0;
}

