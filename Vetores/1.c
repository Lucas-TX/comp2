#include<stdio.h>
#include<stdlib.h>
/*Escreva uma fun��o que recebe por par�metro um vetor de double, seu tamanho atual (por refer�ncia) e um valor double a ser adicionado.
 A fun��o  dever� realocar o vetor para ter mais uma posi��o reservada. 
 Incrementar o tamanho e adicionar o novo valor ao final do vetor. 
 Por fim, a fun��o dever� retornar o novo endere�o do vetor que foi realocado.*/


double* adiciona(double* vet, int *tam, double valor){
	int i;
	*tam+=1;
	printf("*tam = %d\n",*tam);
	vet=realloc(vet,6*sizeof(double));
	vet[*tam-1]=valor;
	if (vet == NULL) {
		printf("N�o foi poss�vel alocar mem�ria!");
		return 1;
	}
	
	for (i=0; i<*tam; i++){
		printf("v[%d] = %.2lf\n", i, vet[i]);
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
	double valor=99,*v;
	int t=5;	
	v = (double*) malloc (5 * sizeof(double));
	if (v == NULL) {
		printf("N�o foi poss�vel alocar mem�ria!");
		return 1;
	}
	v[0]=5;
	v[1]=5;
	v[2]=5;
	v[3]=5;
	v[4]=5;

	imprimevetor(v,t);
	adiciona(v,&t,valor);
	imprimevetor(v,t);
	
	return 0;	
}
