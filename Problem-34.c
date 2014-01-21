/* bmp.c -*- Coding: utf-8-unix -*-
   No compression, Windows 3.0 (or later) version.
   Rerence: http://ja.wikipedia.org/wiki/Windows_bitmap

   Modify: change image 2012/June/08
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
/* fixed size 512*512 only */
int getstring(char *src, char *element, char *dest)
{
  int len;
  char *data, *amp;
  char *temp;

  len = (int)strlen(src) + 1;
  temp = (char *)malloc(len);

  len = (int)strlen(src);
  if (len >= 1024) {
    er();
    free(temp);
    return -1;
  }

  strcpy(temp, src);

  data = strstr(temp, element);
  if(data == NULL) {
    strcpy(dest, "no element");
    free(temp);
    return -2;
  }

  len = (int)strlen(element) + 1;

  amp = strstr(data, "&");
  if (amp == NULL) {
    strcpy(dest, data + len);
    if (dest[0] == '\0') {
      strcpy(dest, "no data");
      free(temp);
      return 0;
    }
    free(temp);
    return 1;
  }
  data[(int)(amp-data)] = '\0';
  strcpy(dest, data + len);

  if (dest[0] == '\0') {
    strcpy(dest, "no data");
    free(temp);
    return 0;
  }

  free(temp);
  return 0;
}
int er()
{
  printf("Content-type:text/html\n\n");
  printf("<HTML>\n");
  printf("<HEAD>\n");
  printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=Shift_JIS\">\n");
  printf("<TITLE>Error</TITLE>\n");
  printf("</HEAD>\n");
  printf("<BODY BGCOLOR=\"#FF0000\">\n");
  printf("error!");
  printf("</BODY>\n");
  printf("</HTML>\n");
  return 0;
}

struct Bitmapfileheader {
  char type[2];
  int size;
  short preserve1;
  short preserve2;
  int offset;
};

struct Bitmapinfoheader {
  unsigned long biSize;
  long biWidth;
  long biHeight;
  unsigned short biPlanes;
  unsigned short biBitCount;
  unsigned long biCompression;
  unsigned long biSizeImage;
  long biXPixPerMeter;
  long biYPixPerMeter;
  unsigned long biClrUsed;
  unsigned long biClrImportant;
};


void setup_header(struct Bitmapfileheader *bitmapfileheader,
		  struct Bitmapinfoheader *bitmapinfoheader,
		  unsigned char *header,
		  unsigned char *info);

int main(void)
{
  FILE *bmpfile;
  unsigned char img[512][512][3];
  int x,y,c;
  struct Bitmapfileheader bitmapfileheader;
  struct Bitmapinfoheader bitmapinfoheader;
  unsigned char header[14];
  unsigned char info[40];
  int i, len;
  char cc; 
  char *pBuf;
  char methoda[256], methodb[256], methodc[256];

  /* setup headers */
  setup_header(&bitmapfileheader, &bitmapinfoheader, header, info);

  len = atoi(getenv("CONTENT_LENGTH"));

  //あまりにも多いデータが送られてきたときはエラーとする
  if (len == 0 || len >= 1024) {
    er();
    return 0;
  }
  //データを格納するバッファを動的に確保
  pBuf = (char *)malloc(len + 1);
  if (pBuf == NULL) {
    er();
    return 0;
  }

  //データを受け取る。
  //このとき改行文字等は除外しないと後で思わぬエラーが生じる

  for (i = 0; (cc = getchar()) != EOF; i++) {
    if (cc != '\r' && cc != '\n')
      pBuf[i] = cc;
    else
      i--;
  }
  //送られてきたデータの最後にはヌル文字がないので自分で付ける
  pBuf[i] = '\0';
  getstring(pBuf, "ritea", methoda);
  getstring(pBuf, "riteb", methodb);
  getstring(pBuf, "ritec", methodc);
  printf("content-type: text/html\n");
  printf("\n");
  printf("<!DOCTYPE HTML>\n");

  printf("\n");
  printf("\n");
  printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
	printf("<meta http-equiv=\"Pragma\" content=\"no-cache\">");
	printf("<meta http-equiv=\"Cache-Control\" content=\"no-cache\">\n");
	printf("<html>\n <br>\n");

  printf(" <head>\n  <title>BMP Make</title>\n </head>\n\n<body>\n");
  printf("    Make your Image!<br><br><br>\n");
  printf("    Blue<br>  [x][y][c] = %s<br>\n", methoda);
  printf("    GREEN<br>  [x][y][c] = %s<br>\n", methodb);
  printf("    RED<br>  [x][y][c] = %s<br><br><br>\n", methodc);
  printf("<div style=\"text-align:center\">生成された画像<p>");


      
  /* make raw-date */
  for (y=0;y<512;y++) {
    for (x=0;x<512;x++) {
      for (c=0;c<3;c++) {
	switch (c) {
	case 0:
          /* Blue */
	  img[x][y][c] = *methoda;
	  break;
	case 1:
	  /* Green */
	  img[x][y][c] = *methodb;
	  break;
	case 2:
	  /* Red */
	  img[x][y][c] = *methodc;
	  break;
	}
      }
    }
  }

  free(pBuf);


  bmpfile=fopen("a.bmp","wb");
  if (bmpfile==NULL) {
    fprintf(stderr,"Canot open file: a.bmp\n");
    return 1;
  }

  /* Write Headers */
  fwrite(header,sizeof(unsigned char),sizeof(header),bmpfile);
  fwrite(info,sizeof(unsigned char),sizeof(info),bmpfile);

  /* Write data */
  for (y=0;y<512;y++) {
    for (x=0;x<512;x++) {
      for (c=0;c<3;c++) {
	fwrite(&img[x][y][c],
	       sizeof(unsigned char),
	       sizeof(img[x][y][c]),
	       bmpfile);
      }
    }
  }

  fclose(bmpfile);

  printf("<img src=a.bmp></div>");
  printf("</body></html>\n");

  return 0;
}

void setup_header(struct Bitmapfileheader *bitmapfileheader,
		struct Bitmapinfoheader *bitmapinfoheader,
		unsigned char *header,
		unsigned char *info)
{
  /* setup header structure */
  bitmapfileheader->type[0]='B';
  bitmapfileheader->type[1]='M';
  bitmapfileheader->size=
    512*512*3+sizeof(struct Bitmapfileheader) +
    sizeof(struct Bitmapinfoheader);
  bitmapfileheader->preserve1=0;
  bitmapfileheader->preserve2=0;
  bitmapfileheader->offset = 54*sizeof(char);

  bitmapinfoheader->biSize=40;
  bitmapinfoheader->biWidth=512;
  bitmapinfoheader->biHeight=512;
  bitmapinfoheader->biPlanes=1;
  bitmapinfoheader->biBitCount=24;
  bitmapinfoheader->biCompression=0;
  bitmapinfoheader->biSizeImage=(512/8)*(512/8);
  bitmapinfoheader->biXPixPerMeter=3780;
  bitmapinfoheader->biYPixPerMeter=3780;
  bitmapinfoheader->biClrUsed=0;
  bitmapinfoheader->biClrImportant=0;

  /* make memory struct from struct */
  memcpy(header,
	 &(bitmapfileheader->type[0]),1);
  memcpy(header+1,
	 &(bitmapfileheader->type[1]),1);
  memcpy(header+2,
	 &(bitmapfileheader->size),4);
  memcpy(header+6,
	 &(bitmapfileheader->preserve1),2);
  memcpy(header+8,
	 &(bitmapfileheader->preserve2),2);
  memcpy(header+10,
	 &(bitmapfileheader->offset),4);

  memcpy(info,
	 &(bitmapinfoheader->biSize),4);
  memcpy(info+4,
	 &(bitmapinfoheader->biWidth),4);
  memcpy(info+8,
	 &(bitmapinfoheader->biHeight),4);
  memcpy(info+12,
	 &(bitmapinfoheader->biPlanes),2);
  memcpy(info+14,
	 &(bitmapinfoheader->biBitCount),2);
  memcpy(info+16,
	 &(bitmapinfoheader->biCompression),4);
  memcpy(info+20,
	 &(bitmapinfoheader->biSizeImage),4);
  memcpy(info+24,
	 &(bitmapinfoheader->biXPixPerMeter),4);
  memcpy(info+28,
	 &(bitmapinfoheader->biYPixPerMeter),4);
  memcpy(info+32,
	 &(bitmapinfoheader->biClrUsed),4);
  memcpy(info+36,
	 &(bitmapinfoheader->biClrImportant),4);

  return;
}

