#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define gets(x) scanf(" %[^\n]", (x))

/**
 * Exercício 3:
 * Escreva um programa que leia dois textos (um por linha).
 * Apresente novamente os dois textos na tela EM ORDEM ALFABETICA.
 * 
 * Exemplo:
 * 
 * entrada:
 * Bom dia
 * Ate amanha
 * 
 * saída:
 * Ate amanha
 * Bom dia
 * 
 * */

int compara_alfabetico(char texto1[], char texto2[]) {
	char copia1[100];
    char copia2[100];
	int tam1,tam2,i,cmp;	
	strcpy(copia1,texto1);
	strcpy(copia2,texto2);
	tam1=strlen(copia1);
	tam2=strlen(copia2);
	for(i=0; i<tam1; i++){
		copia1[i] = toupper(copia1[i]);
	}
	for(i=0; i<tam2; i++){
		copia2[i] = toupper(copia2[i]);
	}
	cmp=strcmp(copia1,copia2);
	if(cmp<0){
		return EOF;
	}
	else if(cmp>0){
		return 1;	
	}
	else{
		return 0;
	}
	
	
    /**
     * Implemente sua solução aqui.
     * Retorne -1 se a primeira string for menor ALFABETICAMENTE
     * Retorne 1 se a segunda string for menor ALFABETICAMENTE
     * Caso contrário retorne 0
     * */
}

int main(){
    char texto1[100];
    char texto2[100];
    gets(texto1);
    gets(texto2);
    if (compara_alfabetico(texto1, texto2) < 0){
        printf("%s\n", texto1);
        printf("%s\n", texto2);
    } else {
        printf("%s\n", texto2);
        printf("%s\n", texto1);
    }
    return 0;
}
