/*
  File name :kyoyotai.c
*/
/*
  文字化けしてる
*/
#include<stdio.h>

union Book {
	char sample[5];
	int price;
};

int main(void){
	union Book book = {"�v���O���~���O����"};
	union Book ary_book[2] = {{"�v���O���~���O����"},{"C������"}};
	union Book *ptr_book;
	printf("���̖{��%d�~",book.price);
	return 0;
}
