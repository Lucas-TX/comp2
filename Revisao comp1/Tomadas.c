#include<stdio.h>
int main (){
	int t=0,qtd=0,i;
	
	for(i=0;i<4;i++){
		scanf("%d",&t);
		qtd+=t;
	}
	printf("%d",qtd-3);
	return 0;	
}
