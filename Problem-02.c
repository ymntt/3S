#include<stdio.h>
#include<math.h>
#include<complex.h>

void print_answer(double a, double b, double c);
double distinction(double a, double b, double c);
int main(void)
{
  double a1=1.0, b1=-3.0, c1=2.0; /* 配布プリンとの数値を */
  double a2=1.0, b2=-6.0, c2=9.0; /* 変更し、実数解、重解、 */
  double a3=2.0, b3=1.0, c3=1.0; /* 数解が得られるようにする */

  print_answer(a1,b1,c1);
  print_answer(a2,b2,c2);
  print_answer(a3,b3,c3);

  return 0;
}
/* 判別式 */
void print_answer(double a, double b, double c)
{
  double d=0.0;
  double _Complex x1=0.0+I*0.0, x2=0.0+I*0.0;
  d=distinction(a, b,c);
  printf("\n %f *x*x + %f * x + %f = 0\n",a,b,c);
if (d > 0){
  x1=(-1*b+sqrt(d))/(2*a);
  x2=(-1*b-sqrt(d))/(2*a);
  printf("Real: %f\n", x1);
  printf("Real: %f\n", x2);
 } else if (d==0){
  x1=(-1*b)/(2*a);
  printf("Real: %f", x1);
 }else{
  x1=(-1*b)/(2*a)+(I+sqrt(abs(d))/(2*a));
  x2=(-1*b)/(2*a)-(I*sqrt(abs(d))/(2*a));
  printf("Complex_Answer: Real %f: Image: %f\n", creal(x1),cimag(x1));
  printf("Complex_Answer: Real %f: Image: %f\n", creal(x2),cimag(x2));

 }return;
}

double distinction(double a, double b, double c)
{
  double d=0.0;
  d=pow(b, 2) - 4 * a * c;
    return d;
}
