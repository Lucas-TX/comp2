#include <stdio.h>
#include <stdlib.h>
/*
3.
Escreva uma fun��o que adiciona um valor em uma determinada posi��o.
A fun��o dever� realocar o vetor para receber o novo elemento,
incrementar o tamanho,
deslocar os elementos necess�rios para que o novo valor seja inserido,
inserir o novo valor e retornar o endere�o do vetor realocado.
*/

double* adiciona_posicao(double vet[], int *tam,double valor, int posicao){
	int i;
	
	vet=realloc(vet,(*tam+1) * sizeof(double));
	if (vet == NULL) {
		printf("N�o foi poss�vel alocar mem�ria!");
		return 1;
	}	
	for(i=(*tam);i>(posicao-1);i--){
		vet[i]=vet[i-1];		
	}
	vet[posicao-1]=valor;
	return vet;	
	
}
void imprimevetor(double v[], int tam){
	int i;
	for (i=0; i<tam; i++){
		printf("v[%d] = %.2lf\n", i, v[i]);
	}
}

int main(){
	double valor=99;
	double* v=NULL;
	int tam=5,pos=3;
	v=(double*) calloc ((tam), sizeof (*v));	
	v[0]=1;
	v[1]=2;
	v[2]=3;
	v[3]=4;
	v[4]=5;
	v=adiciona_posicao(v,&tam,valor,pos);
	imprimevetor(v,tam+1);
	
}
