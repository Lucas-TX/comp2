#include <stdio.h>
int valida(int a){
	if((a<1)&&(a>5)){
			return 0;
		}
		else{
			return a;	
		}
	}

int main() {
int soma,L=0,R=0;
	do{
		scanf("%d",&L);
		L=valida(L);	
		scanf("%d",&R);
		R=valida(R);
    	printf(" %d",L+R);
    	printf("\n");
	}while((L!=0)&&(R!=0));	
    return 0;
}
  

