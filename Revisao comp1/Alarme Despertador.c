#include <stdio.h>
int main(){
	int H,h,M,m,a,b;
	while(!((H==0)&&(M==0)&&(h==0)&&(m==0))){
	
	do{
		scanf("%d %d %d %d",&H,&M,&h,&m);		
	}while((H<0)||(H>23)||(M<0)||(M>59)||(h<0)||(h>23)||(m<0)||(m>59));
	

		
	if(H==h){
		if(M==m){
			return 0;
		}
		else if(m>M){
			printf("%d\n",m-M);			
		}
		else{//M<m
			b=(((M-60)*(-1)+m));			
			printf("%d\n",b+1380);
		}			
	}
	
	
	else{//H!=h
		if(H>h){
			a=((((H-23)*(-1))+h)*60);
			b=(((M-60)*(-1)+m));
			if(M>=m){
				printf("%d\n",a+b);
			}
			else{//m>M
			    printf("%d\n",a+(m-M));				
			}			
		}
		else{//h>H
			if(m>=M){
				printf("%d\n",((h-H)*60)+(m-M));
			}
			else{//M>m
				b=(((M-60)*(-1)+m));
				printf("%d\n",(h-H)+b);				
			}			
		}
	}
}
return 0;
}
	
