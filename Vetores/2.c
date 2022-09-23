#include <stdio.h>
#include <stdlib.h>


/*
Escreva uma função que recebe por parâmetro 2 vetores de double e adiciona todos os valores do segundo no primeiro.
 O tamanho do primeiro vetor, passado por referência deve ser incrementado com o tamanho do segundo vetor.
*/

double* adiciona_todos(double vet[], int *tam,double valores[], int qtd){
	int i;	
	vet = realloc(vet, ((*tam)+qtd)* sizeof(double));
	for (i = *tam; i<(*tam + qtd); i++){
	    vet[i] = valores[i-(*tam)];
	}
	if (vet == NULL) {
		printf("Não foi possível alocar memória!");
		return 1;
	}	
	return vet;
}

void imprimevetor(double v[], int tam){
	int i;
	for (i=0; i<tam; i++){
		printf("v[%d] = %.2lf\n", i, v[i]);
	}
}
int main(){
	int tam=10,qtd=5;
	double *primeiro=NULL;
	double *segundo=NULL;
	double *tudo=NULL;
	primeiro=(double*) calloc ((tam), sizeof (*primeiro));
	if (primeiro == NULL) {
		printf("Não foi possível alocar memória!");
		return 1;
	}
	segundo=(double*)calloc((qtd), sizeof (*segundo));
	if (segundo == NULL) {
		printf("Não foi possível alocar memória!");
		return 1;
	}
	primeiro[0]=1;
	primeiro[1]=2;
	primeiro[2]=3;
	primeiro[3]=4;
	primeiro[4]=5;
	primeiro[5]=6;
	primeiro[6]=7;
	primeiro[7]=8;
	primeiro[8]=9;
	primeiro[9]=10;
	segundo[0]=11;
	segundo[1]=12;
	segundo[2]=13;
	segundo[3]=14;
	segundo[4]=15;
	
	tudo=adiciona_todos(primeiro, &tam,segundo,qtd);
	imprimevetor(tudo,tam+qtd);
	free(primeiro);
	primeiro=NULL;
	free(segundo);
	segundo=NULL;
	return 0;	
	
}

 
