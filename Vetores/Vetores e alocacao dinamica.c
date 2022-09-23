#include<stdio.h>
#include<stdlib.h>
/*
1.
Escreva uma função que recebe por parâmetro um vetor de double, seu tamanho atual (por referência) e um valor double a ser adicionado.
 A função  deverá realocar o vetor para ter mais uma posição reservada. 
 Incrementar o tamanho e adicionar o novo valor ao final do vetor. 
 Por fim, a função deverá retornar o novo endereço do vetor que foi realocado.*/


double* adiciona(double* vet, int *tam, double valor){
	int i;
	*tam+=1;
	printf("*tam = %d\n",*tam);
	vet=realloc(vet,6*sizeof(double));
	vet[*tam-1]=valor;
	if (vet == NULL) {
		printf("Não foi possível alocar memória!");
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
		printf("Não foi possível alocar memória!");
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>


/*
2.
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
/*
3.
Escreva uma função que adiciona um valor em uma determinada posição.
A função deverá realocar o vetor para receber o novo elemento,
incrementar o tamanho,
deslocar os elementos necessários para que o novo valor seja inserido,
inserir o novo valor e retornar o endereço do vetor realocado.
*/

double* adiciona_posicao(double vet[], int *tam,double valor, int posicao){
	int i;
	
	vet=realloc(vet,(*tam+1) * sizeof(double));
	if (vet == NULL) {
		printf("Não foi possível alocar memória!");
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

//////////////////////////////////////////////////////////////////////////////////////////////////////////


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

/////////////////////////////////////////////////////////////////////



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


/////////////////////////////////////////////////////////////////////////////////


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

/////////////////////////////////////////////////////////////////////////////////////////////

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



