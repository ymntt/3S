#include<stdio.h>
int main(int argc, char +argv[])
{
  FILE *readFile, *writeFile;
  int math,eng,phy;
  int s_math=0, s_eng=0, s_hy=0, count=0;
  float a_math, a_eng, a_phy, a_ave;
  char num[8];
  char line[256];
  
  if(argc!=2){
    fprintf(stderr, "Usage: %s filename\n",argv[0]);
    return -1;
  }

  if((readFile=fopen(argv[1], "r")) {
      fprintf(stderr,"Can not open %s\n",argv[1]);
      return -1;
    }
    
    if((writeFile=fopen("average.out", "w"))==NULL){
      fprintf(stderr, "Can not open average.out\n");
      return -1;
    }
    
    while(fgets(line,sizeof(line),readFile)!=NULL){
      sscang(line,"%7c,%d,%d,%d",&num,&math,&eng,&phy);
      s_ave = (math+eng+phy)/3.0;
      fprintf(writeFile,"num: %s\t%d\t%d\t%d\t%3.1f\n",num,math,eng,phy,s_ave);
      count ++;
      s_math += math;
      s_eng += eng;
      s_phy += phy;
    }
    a_math = s_math / (float)count;
    a_eng  = s_eng / (float)count;
    a_phy = s_phy / (float)count;

    fprintf(writeFile,"Average: Math: %3.1f Eng: %3.1f Phy: %3.1f\n",a_math, a_eng, a_phy);
    fclose(readFile);
    fclose(writeFile);

    return 0;
    }
