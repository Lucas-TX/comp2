#include <stdlib.h>
#include <stdio.h>

/**
 * Exerc�cio 1:
 * Escreva um programa que aloque dinamicamente um vetor de tamanho N (sendo N informado pelo usu�rio).
 * Em seguida, leia os N valores do usu�rio.
 * Encontre e imprima na tela o maior valor e sua posi��o no vetor.
 * Utilize as assinaturas de fun��o declaradas abaixo.
 * 
 * */

int* aloca_vetor(int n){
    int *vetor = NULL;
    vetor=malloc(n*sizeof(int));
    return vetor;
}

void leia_dados(int vetor[], int n) {
    int i;
    for (i=0; i<n; i++){
        printf("digite o %i� numero do vetor: ",i+1);
        scanf("%i",&vetor[i]);
        }
}

void encontra_maior_posicao(int vetor[], int n, int *maior, int *posicao){
    int i;
    *maior=0;
    for (i=0; i<n; i++){
        if(vetor[i]>*maior){
            *maior=vetor[i];
            *posicao=i+1;
            }
        }
    }


int main (){
    int *vetor = NULL;
    int n, maior, posicao;
    scanf("%d", &n);
    vetor = aloca_vetor(n);
    leia_dados(vetor, n);
    encontra_maior_posicao(vetor, n, &maior, &posicao);
    printf("O maior valor � %d e est� na posi��o %d no vetor.\n", maior, posicao);
    free(vetor);
    vetor=NULL;
    return 0;
}
