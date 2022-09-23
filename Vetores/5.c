#include <stdio.h>
#include <stdlib.h>
/*
5
Semelhante ao exercício anterior, 
escreva uma função que remove um elemento do vetor dado a sua posição.
*/
double* remov (double vet[], int *tam, int posicao){
	int i;
	for(i=posicao;i<*tam;i++){
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
	int tam=5,p=2;
	v=(double*)calloc(tam,sizeof(*v));
	v[0]=1;
	v[1]=2;
	v[2]=3;
	v[3]=4;
	v[4]=5;
	remov(v,&tam,p);
	imprimevetor(v,tam);
	return 0;
}


