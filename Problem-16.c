//data6.datが必要

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
  FILE *myFile;
  char num[8];
  int count=0;
  int math=0,eng=0,phy=0,sum=0;
  int s_math=0,s_eng=0,s_phy=0;
  float a_math=0.0,a_eng=0.0,a_phy=0.0,ave=0.0;
  char line[128];
  if((myFile=fopen("data6.dat","r")) ==NULL){
      fprintf(stderr,"Cannot open:data.dat\n");
      return -1;
    }
  while (fgets(line,(int)sizeof(line),myFile)!=NULL){
    count++;
    sum = 0;
    sscanf(line,"%7c,%d,%d,%d\n",&num,&math,&eng,&phy);
    sum = math + eng + phy;
    ave = sum /(double) 3;
    printf("num:%s math:%3d\teng:%3dtphy:%3d\ttotal:%3d\taverage:%5.1f\n",num,math,eng,phy,sum,ave);
    s_math += math;
    s_eng += eng;
    s_phy += phy;
  }
  
  a_math = s_math /(double) count;
  a_eng = s_eng /(double) count;
  a_phy = s_phy /(double) count;
  
  printf("Average Math:\t%5.2f\n", a_math);
  printf("Average Eng:\t%5.2f\n", a_eng);
  printf("Average Phy:\t%5.2f\n", a_phy);

  return 0;
}
