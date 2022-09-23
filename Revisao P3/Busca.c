#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct duracao {
    int minutos;
    int segundos;
};
typedef struct duracao Duracao;

struct musica {
    char titulo[100];
    char artista[100];
    char album[100];
    Duracao duracao;
};
typedef struct musica Musica;

Musica nova(char titulo[], char artista[], char album[], int minutos, int segundos) {
    Musica m;
    strcpy(m.titulo, titulo);
    strcpy(m.artista, artista);
    strcpy(m.album, album);
    m.duracao.minutos = minutos;
    m.duracao.segundos = segundos;
    return m;
}

Musica* inserir (Musica playlist[], int *n, Musica m) {
    playlist = realloc(playlist, ((*n)+1) * sizeof(*playlist));
    playlist[*n] = m;
    *n+=1;
    return playlist;
}

void print_musica(Musica m) {
    printf("%d:%02d %s \"%s\" (%s)\n", m.duracao.minutos, m.duracao.segundos, m.artista, m.titulo, m.album);
}

void listar (Musica playlist[], int n) {
    int i;
    Musica m;
    for (i=0; i<n; i++) {
        m = playlist[i];
        print_musica(m);
    }
}


Musica* gera_dados_iniciais (int *t) {
    Musica m;
    int n = 0;
    Musica *playlist = NULL;

    m = nova("Entre tapas e beijos", "Leandro & Leonardo", "Sonho por Sonho", 2, 57);
    playlist = inserir(playlist, &n, m);
    m = nova("Eu juro", "Leandro & Leonardo", "L&L Vol. 9", 2, 57);
    playlist = inserir(playlist, &n, m);
    m = nova("Girls Just Want to Have Fun", "Cyndi Lauper", "Twelve Deadly Cyns", 3, 54);
    playlist = inserir(playlist, &n, m);
    m = nova("Highway to Hell", "AC/DC", "Highway to Hell", 3, 28);
    playlist = inserir(playlist, &n, m);
    m = nova("I Wanna Rock", "Twisted Sister", "Stay Hungry", 2, 59);
    playlist = inserir(playlist, &n, m);
    m = nova("Infinita Highway", "Engenheiros do Hawaii", "10.000 Destinos", 6, 6);
    playlist = inserir(playlist, &n, m);
    m = nova("Não aprendi dizer adeus", "Leandro & Leonardo", "Sonho por Sonho", 3, 7);
    playlist = inserir(playlist, &n, m);
    m = nova("O Papa é Pop", "Engenheiros do Hawaii", "O Papa é Pop", 3, 34);
    playlist = inserir(playlist, &n, m);
    m = nova("Panela Velha", "Trio Parada Dura", "Raizes Sertanejas", 3, 4);
    playlist = inserir(playlist, &n, m);
    m = nova("Sutilmente", "Skank", "Estandarte", 4, 2);
    playlist = inserir(playlist, &n, m);
    m = nova("T.N.T", "AC/DC", "High Voltage", 3, 34);
    playlist = inserir(playlist, &n, m);
    m = nova("Take on Me", "A-HA", "Hunting High and Low", 3, 45);
    playlist = inserir(playlist, &n, m);

    *t = n;
    return playlist;
}

void mostra_artista(Musica playlist[], int n, char artista[]) {
  int i;
  int cmp;
  for (i = 0; i < n; i++){
    cmp = strcmp (playlist[i].artista,artista);
    if(cmp == 0){
      printf ("%s\n",playlist[i].titulo);
    }
  }
    /**
    Implemente sua solução aqui!
    Utilize busca sequencial para apresentar na tela
    todas as músicas do artista recebido por parâmetro.
    */
}

int busca_binaria(Musica playlist[], int n, char titulo[]) {
  int cmp;
  int i;
  int posicao = -1;
  int menor = 0;
	int maior = n - 1;
	int meio = -1;

  while (menor <= maior) {
		meio = menor + (maior - menor) / 2;

		// elemento encontrado
		if (strcmp( playlist[meio].titulo,titulo) == 0) {
			posicao = meio;
			break;
		} else {
			// elemento desejado é maior
			if (strcmp(playlist[meio].titulo,titulo) < 0) {
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

	return posicao;

    /**
    Implemente sua solução aqui!
    Utilize busca binária para retornar a posição do vetor
    da música com o título recebido por parâmetro.
    Considere que o vetor já está ordenado por título.
    */
}

int main(){
    Musica *playlist = NULL;
    int n = 0;
    int i;

    playlist = gera_dados_iniciais(&n);

    listar(playlist, n);

    printf("--------------------------------\n");

    i = busca_binaria(playlist, n, "T.N.T");
    if (i != -1) {
        print_musica(playlist[i]);
    }

    i = busca_binaria(playlist, n, "Panela Velha");
    if (i != -1) {
        print_musica(playlist[i]);
    }

    i = busca_binaria(playlist, n, "Não aprendi dizer adeus");
    if (i != -1) {
        print_musica(playlist[i]);
    }

    printf("--------------------------------\n");

    mostra_artista(playlist, n, "Leandro & Leonardo");

    return 0;
}
