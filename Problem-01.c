#include<math.h>
#include<stdio.h>

double square(double radius); /* 球の表面積をもとめる */
double volume(double radius); /* 球の体積をもとめる */

int main(void)
{
  double r1=1.0, r2=2.0, r3=3.5;
  double s1=0.0, s2=0.0, s3=0.0, v1=0.0, v2=0.0, v3=0.0;

  s1=square(r1);
  s2=square(r2);
  s3=square(r3);

  v1=volume(r1);
  v2=volume(r2);
  v3=volume(r3);

  printf("球の半径: %f, 面積: %f, 体積: %f\n", r1,s1,v1);
  printf("球の半径: %f, 面積: %f, 体積: %f\n", r2,s2,v2);
  printf("球の半径: %f, 面積: %f, 体積: %f\n", r3,s3,v3);

  return 0;
}
double square(double radius)
{
  double s=0.0;
  s = 4*M_PI*pow(radius, 2); /* 面積 */
  return s;
}
double volume(double radius)
{
  double v=0.0;
  v = 4 * M_PI * pow(radius, 3) / 3;
  return v;
}
