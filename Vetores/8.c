/*
8
Escreva uma função que recebe dois vetores e retorna a quantidade de elementos diferentes.
Compare apenas elementos na mesma posição.
Por exemplo o vetor A={1, 2, 1, 3, 5} e o vetor B={1, 3, 2, 3, 5}.
Possui 2 elementos diferentes (o segundo e o terceiro).
OBS. a função pode assumir que os dois vetores tem o mesmo tamanho.
*/

#include <stdio.h>
#include <stdlib.h>

int conta_diferencas(double a[], double b[], int tam){
	int cont=0,i;
	for(i=0;i<tam;i++){
		if(a[i]!=b[i]){
			cont+=1;
		}
	}
	return cont;	
}


int main(){
	double v[5],vet[5];
	int tam=5,qtd=0;
	v[0]=7;
	v[1]=0;
	v[2]=7;
	v[3]=9;
	v[4]=1;
	vet[0]=7;
	vet[1]=3;
	vet[2]=7;
	vet[3]=5;
	vet[4]=10;
	qtd=conta_diferencas(v,vet,tam);
	printf("%d",qtd);
	return 0;
}

