#include <stdio.h>
void somaeqtd(int*qtd,float*soma){
	int quan=0,i=0;
	float x=0,somato=0;
	do{
		for(i=0;i<6;i++){
			scanf("%f",&x);			
			if(x>0){
				somato=somato+x;
				quan=quan+1;									
			}			
		}		
	*qtd=quan;
	*soma=somato;		
	}while(quan==0);
			
}

int main() {
	int QTD=0;
	float MEDIA=0,SOMA=0;
	somaeqtd(&QTD,&SOMA);	
	MEDIA=SOMA/QTD;	
    printf("%d valores positivos\n%.1f", QTD, MEDIA);
    return 0;
}

