/*
6
Escreva uma função que recebe um vetor, seu tamanho e um valor double.
A função deverá retornar quantas vezes o valor aparece no vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int conta(double vet[], int tam, double valor){
	int i,cont=0;
	for(i=0;i<tam;i++){
		if(vet[i]==valor){
			cont+=1;
		}		
	}
	return cont;
}


int main(){
	double v[10],valor=7;
	int tam=10,qtd;
	v[0]=7;
	v[1]=0;
	v[2]=7;
	v[3]=9;
	v[4]=1;
	v[5]=7;
	v[6]=3;
	v[7]=7;
	v[8]=5;
	v[9]=10;
	qtd=conta(v,tam,valor);
	printf("%d",qtd);
	return 0;	
	
}

