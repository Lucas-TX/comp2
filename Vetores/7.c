#include <stdio.h>
#include <stdlib.h>
/*
7
Escreva uma função que recebe um vetor e retorna uma cópia do vetor. 
O novo vetor deverá ser alocado dinamicamente e em seguida atribuído com os valores do vetor original.
*/

double* copia(double vet[], int tam){
	int i;
	double *copia;
	copia=(double*)calloc(tam,sizeof *copia);
	for(i=0;i<tam;i++){
		copia[i]=vet[i];
	}	
	return copia;	
}

void imprimevetor(double v[], int tam){
	int i;
	for (i=0; i<tam; i++){
		printf("v[%d] = %.2lf\n", i, v[i]);
	}
}

int main(){
	double* v=NULL;
	double* c=NULL;	
	int tam=5;	
	v=(double*)calloc(tam,sizeof(*v));
	v[0]=1;
	v[1]=2;
	v[2]=3;
	v[3]=4;
	v[4]=5;
	c=copia(v,tam);	
	imprimevetor(c,tam);
	return 0;
}



