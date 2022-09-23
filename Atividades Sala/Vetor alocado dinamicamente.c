#include <stdlib.h>
#include <stdio.h>

/**
 * Exercício 1:
 * Escreva um programa que aloque dinamicamente um vetor de tamanho N (sendo N informado pelo usuário).
 * Em seguida, leia os N valores do usuário.
 * Encontre e imprima na tela o maior valor e sua posição no vetor.
 * Utilize as assinaturas de função declaradas abaixo.
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
        printf("digite o %iº numero do vetor: ",i+1);
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
    printf("O maior valor é %d e está na posição %d no vetor.\n", maior, posicao);
    free(vetor);
    vetor=NULL;
    return 0;
}
