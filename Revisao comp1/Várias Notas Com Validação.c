#include<stdio.h>
float ma(float SOMA,float QTD){
	float MEDIA;
	MEDIA=SOMA/QTD;
	return MEDIA;	
}

int main(){
	float A,soma=0,media=0;
	int i,N,qtd=2;
	do{
		for(i=0;i<2;){
		scanf("%f",&A);		
		if((A>=0)&&(A<=10)){
			soma+=A;
			i+=1;
		}
		else{
			printf("nota invalida\n");			
		}		
    }
    media=ma(soma,qtd);
    printf("media = %.2f\n",media);
    N=0;
	soma=0;
    while(N!=1){
    	printf("novo calculo (1-sim 2-nao)\n");
    	scanf("%d",&N);    	
    	if(N==2){
    		return 0;
		}    	
	}
	}while(N==1);
	return 0;		
}
