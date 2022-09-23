#include<stdio.h>
int teste(int X,int Y){
	float r,b,c;
	r=(9*X*X)+(Y*Y);
	b=(X*X*2)+(25*Y*Y);
	c=(Y*Y*Y)-(100*X);
	if(r>b){
		if(r>c){
			printf("Rafael ganhou\n");
			return 0;			
		}
		else{
			printf("Carlos ganhou\n");
			return 0;
		}
	}
	else if(b>c){
		if(b>r){
			printf("Beto ganhou\n");			
			return 0;
		}
		else{
			printf("Rafael ganhou\n");			
			return 0;
		}		
	}else if(c>r){
		printf("Carlos ganhou\n");		
	}	
}
int main(){
	int N,x,i,y;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&x,&y);
		teste(x,y);		
	}	
	return 0;
}
