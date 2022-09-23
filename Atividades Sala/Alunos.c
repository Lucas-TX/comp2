#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct aluno{
  char nome[50];
  int RA;
};
typedef struct aluno Aluno;
int busca(Aluno alunos[], int n, int RA) {
	int menor = 0;
	int maior = n - 1;
	int meio = -1;
	int posicao = -1;
	while (menor <= maior) {
		meio = (menor + maior) / 2;
    printf("%d %d\n", meio, alunos[meio].RA);
		if (alunos[meio].RA == RA) {
			posicao = meio;
			break;
		} else {
			if (alunos[meio].RA < RA) {
				menor = meio + 1;
			}
			else {
				maior = meio - 1;
			}
		}
	}
	return posicao;
}
void bolha(Aluno alunos[], int n){
  int trocas;
  Aluno aux;
  for(int i=0;i<(n-1);i++){
    trocas=0;
    for(int j=0;j<n-i-1;j++){
      if(alunos[j].RA>alunos[j+1].RA){
        aux = alunos[j];
        alunos[j] = alunos[j+1];
        alunos[j+1] = aux;
        trocas++;
      }
    }
  }
}

int main(void) {
  int pedido, pesquisa, n=0,i=-1;
  Aluno *alunos,aux;
  char temp[100];
  
  alunos=(Aluno*)malloc(sizeof(Aluno)*10);
  do{
    printf("\n Acões:\n1: Inserir aluno\n2: Pesquisar aluno\n0: Encerrar+Gravar\n\nDigite a ação escohida: ");scanf("%d", &pedido);
    switch(pedido){
      case 1:
      {
        FILE*a=fopen("alunos.txt", "at");
        if(a==NULL){
          printf("\n******ERRO*****");
          exit(1);
        }
        printf("\nNome: ");scanf(" %[^\n]",alunos[n].nome);
        printf("\nRA: ");scanf("%d",&alunos[n].RA);
        if(n%10==0){
          alunos=(Aluno*)realloc(alunos,10*sizeof(Aluno));
          if(alunos==NULL){
            printf("ERRO na realocação");
            exit(1);
          }
        }
        fprintf(a,"%s\n%d\n", alunos[n].nome,alunos[n].RA);
        n++;

        fclose(a);
      }
        break;
      case 2:
       {
        FILE*a=fopen("alunos.txt", "rt");
        if(a==NULL){
          printf("\n******ERRO*****");
          exit(1);
        }
        printf("\nQual o RA desejado? ");scanf("%d",&pesquisa);
        n=0;
        while (fscanf(a, " %[^\n]", temp) != EOF ) {
          i++;
          alunos = realloc (alunos, sizeof(Aluno)*(i+1));
          strcpy(alunos[i].nome, temp);
          // fscanf(a, " %[^\n]", alunos[i].nome);
          fscanf(a, "%d", &alunos[i].RA);
          printf("%s %d\n", alunos[i].nome, alunos[i].RA);
        }
        n=i+1;
        bolha(alunos, n);
        i=busca(alunos, n, pesquisa);
        printf("\nNome: %s\nRA: %d",alunos[i].nome, alunos[i].RA);
      fclose(a);
     }
    }
  }while(pedido!=0);
  return 0;
}

