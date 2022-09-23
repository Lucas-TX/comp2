#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum opcao {
  SAIR,//0
  INSERIR,//1
  EXCLUIR,//2
  LISTAR_TODOS,//3
  PROCURAR_NOME,//4
  ORDENAR_PRECO,//5
  ORDENAR_NOME,//6
  LER,//7
  SALVAR//8
};
typedef enum opcao Opcao;

struct item{
  int id;
  char nome [50];
  double preco_unitario;
  int qtd;
};
typedef struct item Item;

Opcao menu (){
  Opcao op;
  printf("Selecione uma opção:\n");
  printf("\t%d. Inserir Item\n", INSERIR);
  printf("\t%d. Excluir Item\n", EXCLUIR);
  printf("\t%d. Mostrar todos os itens\n", LISTAR_TODOS);
  printf("\t%d. Procurar item por nome\n", PROCURAR_NOME);  
  printf("\t%d. Ordenar por preço\n", ORDENAR_PRECO);
  printf("\t%d. Ordenar por nome\n", ORDENAR_NOME);
	printf("\t%d. Abrir arquivo\n", LER);
	printf("\t%d. Salvar dados\n", SALVAR);
  printf("\t%d. Sair\n", SAIR);
  printf("> ");
  scanf("%d", &op);
  return op;
}

Item novo_item(){	
  static int id = 0;
  Item item;
  id++;
  	
  item.id = id; 	
  printf("Nome do item: ");
	scanf(" %49[^\n]", item.nome);  	 
  printf("Preço unitário: "); 
  scanf("%lf", &item.preco_unitario);  	  	
  printf("Quantidade necessária:");  	 
  scanf("%d", &item.qtd);
 	return item;
}   

Item* inserir (Item produtos[], int *tamanho, int *capacidade) {
  if (*tamanho >= *capacidade) {   		
  	*capacidade += 10;
  	produtos = realloc(produtos, *capacidade * sizeof *produtos);
  }
  produtos[*tamanho] = novo_item();
  *tamanho += 1;
  return produtos;
}

void excluir(Item produtos[], int *tamanho) {
	
  int i,j;
  char nome [50];
  printf("Nome: ");
  scanf(" %49[^\n]", nome );
  for(i = 0; i < *tamanho; i++) {
  	if (strcmp(produtos[i].nome,nome) == 0) {
   		for ( j = i+1; j < *tamanho; j++) {
     		produtos[j-1] = produtos[j]; 
   		}
   		*tamanho -= 1;
   	}
  }
  printf("Item [%s] não encontrada.\n", nome);
}

void mostrar_item(Item item){
	
	printf("%d: %s\n", item.id, item.nome);
	printf("Preço unitário: %lf\n", item.preco_unitario);
	printf("Quantidade: %d\n", item.qtd);
  printf("Preço Total: %lf\n", item.preco_unitario * item.qtd);	
}

void listar_todos (Item produtos[], int tamanho) {
	int i;
  	for (i = 0; i < tamanho; i++) {
    	mostrar_item(produtos[i]);
    printf("\n");
  }
}

void salvar_arquivo (Item produtos [], int tamanho){
  FILE *fp;
	int i;
	fp = fopen("Item.txt", "wt");
	if( fp == NULL){
		fprintf(stderr, "Erro ao abrir arquivo.");
	}else{
		fprintf(fp, "%d\n",tamanho);
		for (i = 0; i < tamanho; i++){
			fprintf(fp, "%d\n", produtos[i].id);
			fprintf(fp, "%s\n", produtos[i].nome);
			fprintf(fp, "%lf\n", produtos[i].preco_unitario);		
			fprintf(fp, "%d\n", produtos[i].qtd);
			
		}					
	}				
	fclose(fp);
}

void bolha (Item produtos[],int n){
  int i,j,trocas;
  Item aux;
  for (i = n - 1; i > 0; i--) {
    trocas = 0;
    for (j = 0; j < i; j++) {
      if (strcmp(produtos[j].nome, produtos[j + 1].nome ) > 0 ) {
        aux = produtos[j];
        produtos[j] = produtos[j + 1];
        produtos[j + 1] = aux;
        trocas++;
      }
    }
    if (trocas == 0) {
      break;
    }
  }
}

Item* ler_arquivo (Item produtos [], int* tam){
	int i,n;
  FILE *fp;
	fp = fopen("Item.txt", "rt");
	if (fp == NULL){
    printf("Erro ao abrir arquivo!\n");
   	exit(1);  
	}
	else{
		fscanf(fp, "%d", &n);
		produtos = malloc ( n * sizeof *produtos);
		for(i = 0; i < n ; i++ ){
			fscanf(fp, "%d", &produtos[i].id);
			fscanf(fp, " %[^\n]", produtos[i].nome);
			fscanf(fp, " %lf ", &produtos[i].preco_unitario);		
			fscanf(fp, "%d", &produtos[i].qtd);			
		}
	}
	*tam = n;	
	fclose(fp);
	return produtos;
}

void busca_por_nome(Item produtos[], int n) {
  int i;
  int posicao = -1;
  int menor = 0;
	int maior = n - 1;
	int meio = -1;
  char nome[50];

  printf("Nome:");
  scanf(" %49[^\n]",nome);

  while (menor <= maior) {
		meio = menor + (maior - menor) / 2;

		// elemento encontrado
		if (strcmp( produtos[meio].nome,nome) == 0) {
			posicao = meio;
			break;
		} else {
			// elemento desejado é maior
			if (strcmp(produtos[meio].nome,nome) < 0) {
				// encontra subconjunto da direita
				menor = meio + 1;
			}
			// elemento desejado é menor
			else {
				// encontra subconjunto da direita
				maior = meio - 1;
			}
		}
	}
	mostrar_item(produtos[posicao]);
}

void merge(Item produtos[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* cria dois vetores */
	Item *L = malloc(n1 * sizeof(*L));
  Item *R = malloc(n2 * sizeof(*R)); 

	/* Copia os dados para os vetores L e R */
	for (i = 0; i < n1; i++) 
		L[i] = produtos[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = produtos[m + 1+ j]; 

	/* Une os vetores L e R em v*/
	i = 0; 
	j = 0;
	k = l;
	while (i < n1 && j < n2) 
	{ 
    if(L[i].preco_unitario >= R[j].preco_unitario)
		// if (L[i].preco >= R[j].preco) 
		{ 
			produtos[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			produtos[k] = R[j]; 
			j++; 
		} 
		k++; 
	}
	/* Copia os elementos restantes de L */
	while (i < n1) 
	{ 
		produtos[k] = L[i]; 
		i++; 
		k++; 
	} 
	/* Copia os elementos restantes de R */
	while (j < n2) 
	{ 
		produtos[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l (esquerda) e r (direita) */
void mergeSort(Item v[], int l, int r) 
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

int main(){
  setlocale(LC_ALL, "");
	Item *produtos = NULL;// Vetor de itens
  int capacidade = 0;// capacidade do vetor de itens
	int tamanho = 0;// elementos dos vetor
  Opcao opcao = SAIR;
  do{
	opcao = menu();
	switch (opcao){
		case SAIR:
			free(produtos);
			produtos = NULL;
			printf("Encerrando...\n");
			break;
		case INSERIR:
			produtos = inserir(produtos, &tamanho, &capacidade);
			break;
		case EXCLUIR:
			excluir(produtos, &tamanho);
    	break;
    case LISTAR_TODOS:
      listar_todos(produtos, tamanho);
    	break;
		case PROCURAR_NOME:
      bolha(produtos,tamanho);
      busca_por_nome(produtos,tamanho);		
			break;
		case ORDENAR_PRECO:
      mergeSort(produtos, 0, tamanho-1);			
			break;
		case ORDENAR_NOME:
			bolha(produtos,tamanho);
			break;
		case LER:
			produtos = ler_arquivo (produtos, &tamanho);
      break;
		case SALVAR:
			salvar_arquivo(produtos, tamanho);				
			break;									
		default:
      printf("Opcão inválida [%d]\n", opcao);			
		}		
	}while(opcao!=SAIR);
  return 0;
}
