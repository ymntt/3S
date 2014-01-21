#include<stdio.h>
#include<math,h>
struct sphere{
		double r;
		double s;
		double v;
};
double square(double radius);
double volume(double radius);
struct sphere * calc_sphere(struct sphere *s0);
int main(void)
{
	struct sphere s1,s2,s3;
	
	s1.r=1.0;
	s2.r=2.0;
	s3.r=-1.0; /* Error test */
	
	if(calc_sphere(&s1) == NULL){
		fprintf(stderr,"Error at struct sphere: radius:%f\n", s1.r);
	}else{
		printf("Sphere: radius: %f\n\t square: %f\n\t volume: %f\n", s1.r, s1.s, s1.v);
	}
	
	
	if(calc_sphere(&s2) == NULL){
		fprintf(stderr,"Error at struct sphere: radius:%f\n", s2.r);
	}else{
		printf("Sphere: radius: %f\n\t square: %f\n\t volume: %f\n", s2.r, s2.s, s2.v);
	}
		
	if(calc_sphere(&s3) == NULL){
		fprintf(stderr,"Error at struct sphere: radius:%f\n", s3.r);
	}else{
		printf("Sphere: radius: %f\n\t square: %f\n\t volume: %f\n", s3.r, s3.s, s3.v);
	}
	return 0;
}
sutruct sphere * calc_sphere(struct sphere *s0)
{
	if(s0 ->r<= 0){
		return NULL;
	}else{
		s0->s = square(s0->r);
		s0->v = volume(s0->r);
	}
}

double square(double radius)
{
	double s=0.0;
	s=4*M_PI*pow(radius, 2);
	return s;
}

double volume(double radius)
{
	double v=0.0;
	v=(4*M_PI*pow(radius, 3))/(double) 3;
	return v;
}
