/* make_bmp_sample.c
   for Windows95(or later)
*/
/*
   	sample2.c(ファイル名はよくわからない？)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/* fired size 512*512 only */

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

int main(int argc, char *argv[])
{
  FILE *bmpfile;
  unsigned char img[512][512][3];
  int x,y,c;
  struct Bitmapfileheader bitmapfileheader;
  struct Bitmapinfoheader bitmapinfoheader;
  unsigned char header[14];
  unsigned char info[40];

  if (argc!=2) {
    fprintf(stderr,"Usage: ./make_bmp_sample_filename.bmp\n");
    return 1;
  }
  

  /* setup headers */
  setup_header(&bitmapfileheader, &bitmapinfoheader, header, info);

  /* make raw_date */
  for (y=0;y<512;y++){
    for(x=0;x<512;x++){
      for(c=0;c<3;c++){
	switch (c) {
	case 0:
	/* Blue */
	  img[x][y][c]= (x+sqrt(x^2+4))/2;
	break;

	case 1:
	/* Green */
	  img[x][y][c]= (y+sqrt(y^2+4))/2;
	break;

	case 2:
	/* Red */
	  img[x][y][c]= (c+sqrt(c^2+4))/2;
	break;
	}
      }
    }
  }
 

  /* n+sqrt(n^2+4))/2 is metallic ratio */

  bmpfile=fopen(argv[1],"wb");
  if(bmpfile==NULL) {
    fprintf(stderr,"Cannot open file: %s\n",argv[1]);
    return 1;
  }


  /* Write Headers */
  fwrite(header,sizeof(unsigned char), sizeof(header), bmpfile);
  fwrite(info,sizeof(unsigned char),sizeof(info), bmpfile);

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

  return 0;
}


void setup_header(struct Bitmapfileheader *bitmapfileheader,
		  struct Bitmapinfoheader *bitmapinfoheader,
		  unsigned char *header,
		  unsigned char *info)
{
  /* setup header structure */
  bitmapfileheader -> type[0] = 'B';
  bitmapfileheader -> type[1] = 'M';
  bitmapfileheader -> size =
    512*512*3+sizeof(struct Bitmapfileheader) +
    sizeof(struct Bitmapinfoheader);
  bitmapfileheader -> preserve1 = 0;
  bitmapfileheader -> preserve2 = 0;
  bitmapfileheader -> offset = 54*sizeof(char);
  
  bitmapinfoheader -> biSize = 40;
  bitmapinfoheader -> biWidth = 512;
  bitmapinfoheader -> biHeight = 512;
  bitmapinfoheader -> biPlanes = 1;
  bitmapinfoheader -> biBitCount = 24;
  bitmapinfoheader -> biCompression = 0;
  bitmapinfoheader -> biSizeImage = (512/8)*(512/8);
  bitmapinfoheader -> biXPixPerMeter = 3780;
  bitmapinfoheader -> biYPixPerMeter=3780;
  bitmapinfoheader -> biClrUsed = 0;
  bitmapinfoheader -> biClrImportant = 0;
  
  /* make memory struct from struct */
  memcpy(header,
	 &(bitmapfileheader ->type[0]), 1);
  memcpy(header+1,
	 &(bitmapfileheader ->type[1]), 1);
  memcpy(header+2,
	 &(bitmapfileheader ->size), 4);
  memcpy(header+6,
	 &(bitmapfileheader ->preserve1), 2);
  memcpy(header+8,
	 &(bitmapfileheader ->preserve2), 2);
  memcpy(header+10,
	 &(bitmapfileheader ->offset), 4);
  
  memcpy(info,
	 &(bitmapinfoheader ->biSize), 4);
  memcpy(info+4,
	 &(bitmapinfoheader ->biWidth), 4);
  memcpy(info+8,
	 &(bitmapinfoheader ->biHeight), 4);
  memcpy(info+12,
	 &(bitmapinfoheader ->biPlanes), 2);
  memcpy(info+14,
	 &(bitmapinfoheader ->biBitCount), 2);
  memcpy(info+16,
	 &(bitmapinfoheader ->biCompression), 4);
  memcpy(info+20,
	 &(bitmapinfoheader ->biSizeImage), 4);
  memcpy(info+24,
	 &(bitmapinfoheader ->biXPixPerMeter), 4);
  memcpy(info+28,
	 &(bitmapinfoheader ->biYPixPerMeter), 4);
  memcpy(info+32,
	 &(bitmapinfoheader ->biClrUsed), 4);
  memcpy(info+36,
	 &(bitmapinfoheader ->biClrImportant), 4);

  return ;
}
