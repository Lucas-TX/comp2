#include<stdio.h>
int valida(int A){
	if((A<1)||(A>13)){
			return 0;
		}
		else{
			return A;	
		}
	}
int main (){
	int a=0,b=0;
	while(a==0){
		scanf("%d",&a);
		a=valida(a);		
	}
	while(b==0){
		scanf("%d",&b);
		b=valida(b);		
	}	
	if(a==b){
		printf("%d",a);		
	}
	else{
		if(a>b){
			printf("%d\n",a);
		}
		else{
			printf("%d",b);
		}
	}
	return 0;
}
	
