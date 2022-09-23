#include<stdio.h>

int main(){
	int x=0,max,a=0,b=1,i;
	scanf("%d",&max);
	if(max==1){		
		printf("0");		
	}
	else if(max==2){
		printf("0 1");		
	}
	else if(max<46){
	printf("0 1 ");	
		for(i=2;i<max;i++){
			x=a+b;
			a=b;
			b=x;		
		printf("%d ",x);		
	    }
	}else{
		return 0;
	}	
}
