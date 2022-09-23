#include<stdio.h>
//tx de crescimento de A é sempre maior.
float aumentopercentual(float a){	
	a=((a/100)+1);	
	return a;	
}
int main(){
	int anos,i,T,PA,PB;
	float GA,GB;
	scanf("%d",&T);	
	for(i=0;i<T;i++){
		scanf("%d %d %f %f",&PA,&PB,&GA,&GB);
	    GA=aumentopercentual(GA);
	    GB=aumentopercentual(GB);	
	    anos=0;
	    while(PA<=PB){
	    	PA=(GA*PA);
		    PB=(GB*PB);
		    anos+=1;
		    if(anos>100){
		    	break;
			}
		}
		if(anos>100){
			printf("Mais de 1 seculo.\n");
			PA=1;
			PB=0;
		}
		else{
			printf("%d anos.\n",anos);			
		}
		
	}
	return 0;	
}




