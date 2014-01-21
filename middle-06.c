#include<stdio.h>
int main(int argc, char *argv[])
{
  int i=0;
  char *ptr;
  if (argc<2){
    fprintf(stderr,"%s requires more arguments\n",argv[0]);
    return -1;
  }
  ptr = argv[1];
  while(*ptr != '\0'){
    printf("%c", *ptr);
    ptr++;
  }
  return 0;
}

