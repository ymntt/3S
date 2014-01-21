#include<stdio.h>
int count_character(char string[]);
int main(int argc, char * argv[])
{
  int i=0,c=0;
  if(argc == 1){
      fprintf(stderr,"Usage: ./count_char_string1_string2_..._stringN\n");
      return 1;
    }else{
      for (i = 1; i<argc; i++){
	c=count_character(argv[i]);
	printf("%s:%d\n", argv[i], c);
      }
    }
    return 0;
    }
  int count_character(char string[])
  {
    int c=0;
    for(c=0;c<argstring[c]c;c++){  }
    return(0);
  
  
/*
  これは動かないと思う　直す必要がある
*/
