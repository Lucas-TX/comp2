#include<stdio.h>
#include<stdlib.h>

void lermatriz(float mat[12][12], int m, int n){
	int i,j;
	for(i=0; i<m; i++){
		for (j=0;j<n; j++){
			scanf("%f", &mat[i][j]);			
		}		
	}		
}

int main(){
	int m=12,n=12,i,j;
	char op;
	float M[12][12],soma=0,media=0,cont=0;
	scanf("%c",&op);
	lermatriz(M,m,n);
	switch (op){
		case 's':
			for(i=0; i<m; i++){
				for (j=0;j<n; j++){
					if(j>i){
						soma+=M[i][j];
					}
				}	
			}
			printf("%f",soma);
			break;
		case 'm':
			for(i=0; i<m; i++){
				for (j=0;j<n; j++){
					if(j>i){
						soma+=M[i][j];
						cont+=1;
					}
				}	
			}
			media=(soma/(cont));
			printf("%f",media);			
			break;
	}
	return 0;	
}
