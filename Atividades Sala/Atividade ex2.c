#include <stdlib.h>
#include <stdio.h>

/**
 * Exercício 2:
 * Escreva um programa que aloque dinamicamente uma matriz de tamanho MxN (sendo M e N informado pelo usuário).
 * Em seguida, leia os MxN valores do usuário.
 * Aloque dinamicamente um vetor de tamanho N, calcule e armazene no vetor a soma dos valores de cada coluna da matriz.
 * Apresente na tela o vetor calculado.
 * Utilize as assinaturas de função declaradas abaixo.
 * 
 * Exemplo:
 * 
 * matriz de entrada (3x4):
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 * 
 * vetor de saída:
 * 15 18 21 24
 * 
 * */

int* aloca_vetor(int n){
    int *vetor = NULL;    
    vetor=(int*)calloc(vetor,n*sizeof*vetor);
    if(vetor==NULL){
    	printf("Nâo foi possível alocar memória");
    	return 1;
	}
    return vetor;
}

int** aloca_matriz(int m, int n){
    int **matriz = NULL;
    int i;
    matriz=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++){
    	matriz[i]=(int*)malloc(n*sizeof(int));
	}
    return matriz;
}

void leia_dados(int **matriz, int m, int n) {
	int i,j;
	for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		scanf("%d",&matriz[i][j]);    		
		}
	}
}

int* soma_coluna(int **matriz, int m, int n) {
    int *vetor = NULL;
    int i,j;
    vetor = aloca_vetor(n);
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){    		
    		 vetor[j]=(matriz[i][j])+(vetor[j]);
		}
	}    
    return vetor;
}

void mostra_vetor(int vetor[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",vetor[i]);
	}	
}

void libera_matriz(int **matriz, int m){
	int i;
	for (i=0; i<m; i++){
    	free(matriz[i]);
    	matriz[i]=NULL;
	}
   free(matriz);
   matriz=NULL;	
}

int main (){
    int **matriz = NULL;
    int *vetor = NULL;
    int m, n;
    scanf("%d %d", &m, &n);
    matriz = aloca_matriz(m, n);
    leia_dados(matriz, m, n);    
    vetor = soma_coluna(matriz, m, n);
    libera_matriz(matriz, m);
    mostra_vetor(vetor, n);
    matriz = NULL;
    free(vetor);
    vetor = NULL;
    return 0;
}

