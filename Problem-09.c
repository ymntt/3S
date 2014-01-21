#include<stdio.h>
void reverse_print(char *str);
int main(int argc, char *argv[])
{
  int i=0,c=0;
  if(argc == 1){
    fprintf(stderr,"Usage: %s string1 string2 ... stringN\n",argv[0]);
    return 1;
  } else {
    for (i=1; i<argc; i++){
      reverse_print(argv[i]);
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
void reverse_print(char *str)
{
  char *tmp;
  tmp=str;
  while(*str!='\0'){
    str++;
  }
  str--;
  while(tmp<=str){
    printf("%c", *str);
    str--;
  }
}
