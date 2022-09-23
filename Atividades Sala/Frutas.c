#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fruta {
  char nome[20];
  char cor[20];
  char sabor[20];
  float preco;
  int sementes;
};
typedef struct fruta Fruta;

Fruta nova (char nome[], char cor[], char sabor[], float preco, int sementes) {
  Fruta f;
  strcpy(f.nome, nome);
  strcpy(f.cor, cor);
  strcpy(f.sabor, sabor); 
  f.preco = preco;
  f.sementes = sementes;
  return f;
}

Fruta* inserir(Fruta fruteira[], int *qtd, Fruta f) {
  fruteira = realloc(fruteira, ((*qtd) + 1) * sizeof (*fruteira)); 
  fruteira[*qtd] = f;
  *qtd += 1;
  return fruteira;
}

void mostra (Fruta fruteira[], int qtd){
  int i;
  Fruta f;
  for (i=0; i<qtd; i++){
    f = fruteira[i];
    printf("%s: (%s, %s) R$ %.2f %s sementes\n", 
      f.nome, f.cor, f.sabor, f.preco, ((f.sementes == 1) ? "com": "sem"));
  }
}

void grava(char nome[], Fruta fruteira[], int qtd) {
  FILE * fp;
  int i;
  Fruta f;
  fp = fopen(nome, "wt");
  if (fp == NULL) {
    fprintf(stderr, "Não foi possível abrir arquivo [%s].\n", nome);
  } else {
    fprintf(fp, "%d\n", qtd);
    for (i = 0; i< qtd; i++) {
      f = fruteira[i];
      fprintf(fp, "%s\n", f.nome);
      fprintf(fp, "%s\n", f.cor);
      fprintf(fp, "%s\n", f.sabor);
      fprintf(fp, "%f\n", f.preco);
      fprintf(fp, "%d\n", f.sementes);
    }
  }
  fclose(fp);
}

Fruta* leia (char nome[], int* qtd){
  FILE* fp = fopen(nome, "rt");
  int i, n;
  Fruta * fruteira = NULL;
  *qtd = 0;
  Fruta f;
  if (fp == NULL) {
    fprintf(stderr, "Não foi possível abrir arquivo [%s].\n", nome);
  } else {
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) {
      fscanf(fp, " %[^\n]", f.nome);
      fscanf(fp, " %[^\n]", f.cor);
      fscanf(fp, " %[^\n]", f.sabor);
      fscanf(fp, "%f", &f.preco);
      fscanf(fp, "%d", &f.sementes);
      fruteira = inserir(fruteira, qtd, f);
      printf("%d\n", *qtd);
    }
  } 
  fclose(fp);
  return fruteira;
}

/** MERGESORT **/
// Combina dois subvetores
void merge(Fruta v[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* cria dois vetores */
	Fruta *L = malloc(n1 * sizeof(*L));
  Fruta *R = malloc(n2 * sizeof(*R)); 

	/* Copia os dados para os vetores L e R */
	for (i = 0; i < n1; i++) 
		L[i] = v[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = v[m + 1+ j]; 

	/* Une os vetores L e R em v*/
	i = 0; 
	j = 0;
	k = l;
	while (i < n1 && j < n2) 
	{ 
    if(strcmp(L[i].nome, R[j].nome) <= 0)
		// if (L[i].preco >= R[j].preco) 
		{ 
			v[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			v[k] = R[j]; 
			j++; 
		} 
		k++; 
	}
	/* Copia os elementos restantes de L */
	while (i < n1) 
	{ 
		v[k] = L[i]; 
		i++; 
		k++; 
	} 
	/* Copia os elementos restantes de R */
	while (j < n2) 
	{ 
		v[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l (esquerda) e r (direita) */
void mergeSort(Fruta v[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2; // (l+r)/2
		// Ordena cada metade do vetor
		mergeSort(v, l, m); 
		mergeSort(v, m+1, r); 
    // Une as duas metades ordenadas
		merge(v, l, m, r); 
	} 
} 


int main(void) {
  Fruta* fruteira = NULL;
  int qtd = 0;
  int opcao;
  char nome[20], cor[20], sabor[20];
  float preco;
  int sementes;
  
  do {
    printf("Selecione: \n");
    printf("\t1 - Inserir fruta\n");
    printf("\t2 - Ordenar frutas\n");
    printf("\t3 - Gravar em arquivo\n");
    printf("\t4 - Ler arquivo\n");
    printf("\t5 - Mostrar fruteira\n");
    printf("\t0 - Encerrar\n");
    printf("> "); scanf("%d", &opcao);
    switch(opcao) {
      case 1: 
        printf("Informe (nome, cor, sabor, preco e semenetes [0|1]:\n");
        scanf(" %[^\n]", nome);
        scanf(" %[^\n]", cor);
        scanf(" %[^\n]", sabor);
        scanf(" %f", &preco);
        scanf(" %d", &sementes);
        fruteira = inserir(fruteira, &qtd, nova(nome, cor, sabor, preco, sementes));
        break;
      case 2:
        mergeSort(fruteira, 0, qtd-1);
        break;
      case 3: 
        grava("fruteira.txt", fruteira, qtd);
        break;
      case 4:
        fruteira = leia ("olavio.txt", &qtd);
        break;
      case 5:
        mostra(fruteira, qtd);
        break;     
    }
  } while (opcao != 0);
  free(fruteira);
  fruteira=NULL;
  return 0;
}
