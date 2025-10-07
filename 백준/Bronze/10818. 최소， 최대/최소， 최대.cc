#include <stdio.h>

int main(void) {
	int a=0,min=1000000,max=-1000000,b=0;
	scanf("%d",&a);
	
	for(int t=0;t<=a;t++){
		scanf("%d",&b);
		if(min>b){
			min=b;
		}
		if (max<b){
			max =b;
		}
		
	}
	printf("%d %d",min,max);
	
	return 0;
}