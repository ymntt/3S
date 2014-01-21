#include<stdio.h>
int main(void)
{
	int i=0,j=0;
	int array[3][5]={{1,2,3,4,5},{3,1,4,1,5},{2,7,1,8,2}};
	
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			printf("%d",array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
