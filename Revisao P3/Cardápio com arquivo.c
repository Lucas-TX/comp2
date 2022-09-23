#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
	int id;
	char nome[50];
	float preco;
};
typedef struct item Item;

int busca_binaria (Item *v, int n, char nome[]) {
	int i=0, f=n-1, m, c;
	do {
		m = (i+f)/2;
		c = strcmp(v[m].nome, nome);
		if (c == 0) {
			return m;
		} else if (c > 0) {
			f = m-1;
		} else {
			i = m+1;
		}
	} while (i <= f);
	return -1;
}

Item novo(int id, char nome[], float preco){
	Item i;
	i.id = id;
	strcpy(i.nome, nome);
	i.preco = preco;
	return i;
}

Item* inserir(Item* v, int *n, Item i) {
	v = (Item*) realloc(v, ((*n)+1) * sizeof(Item));
	v[*n] = i;
	*n += 1;
	return v;
}

void bolha(Item v[], int n){
	int i, j, t;
	Item aux;
	for (i = n-1; i > 0; i--) {
		t=0;
		for (j = 0; j < i; j++) {
			if (strcmp(v[j].nome, v[j+1].nome) > 0) {
			// if (v[j].preco > v[j+1].preco) {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				t++;
			}
		}
		if (t==0) {
			break;
		}
	}
}

int main(){
	Item *cardapio = NULL;
	int n = 0;
	int i;
	Item it;
	FILE * f;
	f = fopen("a.bin", "rb");
	if (f == NULL){
		fprintf(stderr, "Arquivo nao existe\n");
		// exit(1);
	} else {
    fread(&n, sizeof(int), 1, f);
    cardapio = malloc(n * sizeof(Item));
    fread(cardapio, sizeof(Item), n, f);
    fclose(f);
  }
	int opcao;
	do {
		printf("Selecione\n");
		printf("\t1. Inserir\n");
		printf("\t0. Encerrar (ordenar, mostrar, gravar em arquivo e sair)\n");
		printf("> ");
		scanf("%d", &opcao);
		switch (opcao) {
			case 1:
				printf("Id: "); scanf("%d", &it.id);
				printf("Nome: "); scanf(" %[^\n]", it.nome);
				printf("Preco: "); scanf("%f", &it.preco);
				cardapio = inserir(cardapio, &n, it);
				break;
		}
	} while (opcao != 0);
	bolha(cardapio, n);
	for (i=0; i<n; i++){
		it = cardapio[i];
		printf("%d - %s R$ %.2f\n",	it.id, it.nome, it.preco);
	}
	f = fopen("a.bin", "wb");
	if (f==NULL) {
		fprintf(stderr, "Erro ao abrir arquivo\n");
		exit(1);
	}
	fwrite(&n, sizeof(int), 1, f);
	fwrite(cardapio, sizeof(Item), n, f);
	fclose (f);
	return 0;
}

