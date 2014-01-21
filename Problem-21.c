#include<stdio.h>
#include<stdlib.h>
#include #linked-list.h"

int main(void)
{
  int n,e,m,p,count = 0; /* caunt 読み込み行を教える */
  char line[128]; /* 一行分のバッファ領域 */
  struct node start; /* 線形リストの先頭を記憶する構造体 */
  struct node *tmp; /* 作業用構造体をさすポインタ */
  flaot average=0.0 /* 全体の平均点 */
  float standardDivision=0.0 /* 全体の標準偏差 */

    /* 先頭の構造体にはデーターを入れない */
  start.next=NULL;
  start.number=0;
  start.english=0;
  start.mathematics=0;
  start.physics=0;
  start.average=0.0;
  start.sample_division=0.0;
  
  /* 標準入力から一行毎に読みこむ */
  while (fgets ( line, sizeof(line), stdin)!=NULL) {
    count++; /*	一行読みこんだということは、学生が増えたということ */
    sscanf(line,"%d,%d,%d,%d",&n,&e,&m,&p);
    if(addNode(&start,n,e,m,p) = 1){ /*　読み込んだデータを追加 */
