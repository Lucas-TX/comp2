#include <stdio.h>
#include <stdlib.h>
/*
4.
Escreva uma função que remove um valor de um vetor. 
A função deverá receber o vetor, o tamanho e o valor a ser removido.
Para remover o valor a função deverá deslocar os elementos a direita do elemento a ser removido uma posição para a esquerda, 
decrementar o tamanho do vetor e realocalo.
OBS: apenas a primeira ocorrência do valor deverá ser removida.
*/

double* remov (double vet[], int *tam, double valor){
	int i,p;
	for(i=0;i<*tam;i++){
		if(vet[i]==valor){
			p=i;
		}
	}
	for(i=p;i<*tam;i++){
		vet[i]=vet[i+1];
	}
	*tam-=1;
	vet=(double*)realloc(vet,*tam * sizeof *vet);
	return vet;
}

void imprimevetor(double v[], int tam){
	int i;
	for (i=0; i<tam; i++){
		printf("v[%d] = %.2lf\n", i, v[i]);
	}
}

int main(){
	double* v;
	int tam=5,valor=3;
	v=(double*)calloc(tam,sizeof(*v));
	v[0]=1;
	v[1]=2;
	v[2]=3;
	v[3]=4;
	v[4]=5;
	remov(v,&tam,valor);
	imprimevetor(v,tam);
	return 0;
}


