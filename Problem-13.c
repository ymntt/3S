#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
  char *src="Hello World from Japan";
  char *dest;
  dest = (char *) malloc(strlen(src)+(size_t)1);
  if(dest == NULL){
    printf("No memory!!\n");
    return -1;
  }else{
    strcpy(dest,src);
    printf("src:  %s\n",src);
    printf("dest: %s\n",dest);
    return 0;
  }
}
