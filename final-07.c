#include<stdio.h>
int main(void)
{
	int ar[]={11,5,9,3,41,23,29,31,37,43};
	int i=0,j=0,tmp;
	for(i=0;i<10;i++){
		for(j=0;j<9;j++){
			if(ar[j]<ar[j+1]){
			tmp=ar[j];
			ar[j]=ar[j+1];
			ar[j+1]=tmp;
		}
	}
}
	for(i=0;i<10;i++){
		printf("%d ",ar[i]);
	}
}

