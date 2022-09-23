/*
9
Escreva uma função que receba um vetor e calcule o maior valor e sua posição no vetor. 
Utilize passagem de parâmetros por referência. 
*/

#include <stdio.h>
#include <stdlib.h>

void maioreposicao(double vet[], int tam, double *maior, int *posicao){
	int i,p=0;
	double m=0;
	m=vet[0];
	for(i=0;i<tam;i++){
		if(m<vet[i]){
			m=vet[i];
			p=i;			
		}		
	}
	*maior=m;
	*posicao=p;
}

int main(){
	double v[5],maior=0;
	int t=5,posicao=0;
	v[0]=7;
	v[1]=0;
	v[2]=7;
	v[3]=9;
	v[4]=1;	
	maioreposicao(v,t,&maior,&posicao);
	printf("%.2lf\n%d",maior,posicao+1);
}



