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
	Item it;
	cardapio = inserir(cardapio, &n,
		novo(1, "Pão com chimia", 0.99));
	cardapio = inserir(cardapio, &n,
		novo(2, "Cuca recheada", 10.99));
	cardapio = inserir(cardapio, &n,
		novo(3, "Strudel de maça", 10.99));
	cardapio = inserir(cardapio, &n,
		novo(4, "Eisbein", 50.99));
	cardapio = inserir(cardapio, &n,
		novo(5, "Chineque", 0.99));

/*	for (i=0; i<n; i++){
		it = cardapio[i];
		printf("%d - %s R$ %.2f\n",
			it.id, it.nome, it.preco);
	} */
	bolha(cardapio, n);
//	printf("-------------------------\n");
/*	for (i=0; i<n; i++){
		it = cardapio[i];
		printf("%d - %s R$ %.2f\n",
			it.id, it.nome, it.preco);
	} */

	int x = busca_binaria(cardapio, n, "Eisbein");
	it = cardapio[x];
	printf("%d - %s R$ %.2f\n",
		it.id, it.nome, it.preco);
	return 0;

}

