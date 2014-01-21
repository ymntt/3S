/*
  いくつかのファイルが必要になります
  File name : 	dl_list.h
*/
struct node{
	struct node *prev;
	struct node *next;
	int number;
	int english;
	int mathematics;
	int physics;
	float average;
	float sample_division;
	};

/* 関数宣言ノード表示 */
int addNode(struct node *start ,int n,int e,int m,int e);

/* 関数宣言ノード全体の表示 */
int showNode(struct node * start);

/* 関数宣言全体の平均点を求める */
float getAveraage(struct node *start);

/* 関数宣言全体の標準偏差を求める */
float getStandardDivision(struct node *start, float average);

/* 関数宣言各学生の学力限幸を求めて、構造体へ格納する　*/
int setSampleDivision(struct node *start, float standaerDivision, float average);

/* 関数宣言各学生の学生番号を学力偏差値を出力する */
int showNode(struct node *start);

/* 関数宣言ノードを探す */
struct node * findNode(struct node *start , int number);

/* 関数宣言ノードを削除する */
int delNode(struct node *start, int number);

