#include<stdio.h>

int main(void)
{
	int count = 0;

loop:
	printf("�����I�ɊJ�n���܂�\n");
	count++;
	printf("%d\n",count);
	if(count >= 10)goto end;
	goto loop;
end:
	printf("�v���O�������I�����܂�");
	return 0;
}
