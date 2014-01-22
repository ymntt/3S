#include<stdio.h>
int main(void)
{
  int a,b,c;
  printf("0x12345678,0xffffffff��AND,OR,XOR���s���܂�\n");
  a = 0x12345678 & 0xffffffff;
  b = 0x12345678 | 0xffffffff;
  c = 0x12345678 ^ 0xffffffff;
  printf("AND(&) :%d\n",a);
  printf("OR(|) :%d\n",b);
  printf("XOR(^) :%d\n",c);
  return 0;
}

