/*
  File name : 	dl_list_stdin.c
  */
#include <stdio.h>
#include "dl_list.h"
int main(void)
{
  int n,e,m,p,count=0;
  char line[128];
  struct node start;
  struct node *tmp;
  float average=0.0; /* 全体の平均点 */
  float standardDivision=0.0; /* 全体の標準偏差 */

  start.next=&start; /* 初期化 */
  start.prev=&start; /* 初期化 */
  start.number=0;
  start.english=0;
  start.mathematics=0;
  start.physics=0;
  start.average=0.0;
  start.sample_division=0.0;

  /* 標準入力から一行ごとに読み込む */
  while(fgets(line ,sizeof(line),stdin)!=NULL) {
    count++; /* 一行読み込んだということは、学生数が1増えた */
    sscanf(line,"%d,%d,%d,%d",n,e,m,p) != 1){
    fprintf(stderr,"cannnot allocate memory\n");
    return -1;
  }
}

/* テスト用に表示する関数を呼び出す */
showNode(&start);

/* findNode()関数をテストする　1231965を探し成功する */
if(findNode(&start,1231965) !=NULL) {
  fprintf(stderr,"Found:%d\n",1231965);
 }else{
  fprintf(stderr,"Not found:%d\n",1231965);
 }

/* findNode()関数をテストする 1231000を探し失敗する */
if(findNode(&start,1231000) !=NULL) {
  fprintf(stderr,"Fount:%d\n",1231000);
 }else{
  fprintf(stderr,"Not found:%d\n",1231000);
 }

/* delNode()関数をテストする 1231965を削除し成功する */
if(delNode(&start,1231965) ==1){
  fprintf(stderr,"Deleted:%d\n",1231965);
 }else{
  fprintf(stderr,"Not found:%d\n",1231000);
 }

/* 削除確認用に再度表示する */
showNode(&start);

return 0;
}
