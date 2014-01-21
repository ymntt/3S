#include<stdio.h>
int main(void)
{
	int A[2][2];
	int B[2][2];
	int C[2][2]={{0,0},{0,0}};
	int i=0,j=0;
	
	A[0][0]=2; A[0][1]=3; A[1][0]=1; A[1][1]=4;
	B[0][0]=1; B[0][1]=4; B[1][0]=3; B[1][1]=2;
	
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			C[i][j]=A[i][j]+B[i][j];
		}
	}
	for(i=0;i<2;i++){
		printf("%d %d   %d %d   %d %d\n",A[i][0],A[i][1],B[i][1],B[i][1],C[i][0],C[i][1]);
	}
	return 0;
}
