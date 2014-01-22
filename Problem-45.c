#include<stdio.h>

struct c_byte{
	char low;
	char high;
};

union {
	short x;
	struct c_byte xbyte;
} u_x;

main(void)
{
	printf("4���̐������� :");
	scanf("%04x",&u_x.x);
	printf("\n��͂��ꂽ���� :%04x\n",u_x.x);
	printf("��: %02x\n��: %02x",u_x.xbyte.high,u_x.xbyte.low);
}
