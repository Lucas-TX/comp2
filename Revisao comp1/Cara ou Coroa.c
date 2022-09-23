#include<stdio.h>
int valida(int a){
	if(a==0){
			return 0;
		}
		else{
			return a;	
		}
	}
int main(){
	int QTD=1,R=0,i=0,N=0,contM=0,contJ=0;
	
	while(QTD!=0){
    contM=0;
    contJ=0;
		scanf("%d",&N);
		QTD=valida(N);
		if(QTD==0){
			return 0;
		}
		else{      
			for(i=0;i<QTD;i++){        
				scanf("%d",&R);        
				if(R==0){
					contM+=1;					
				}
				else{
					contJ+=1;					
				}		
			}
		printf("Mary won %d times and John won %d times\n",contM,contJ);
		}
	}
}
	


