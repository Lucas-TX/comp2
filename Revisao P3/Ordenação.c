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

void listar (Musica playlist[], int n) {
    int i;
    Musica m;
    for (i=0; i<n; i++) {
        m = playlist[i];
        printf("%d:%02d %s \"%s\" (%s)\n", m.duracao.minutos, m.duracao.segundos, m.artista, m.titulo, m.album);
    }
}


Musica* gera_dados_iniciais (int *t) {
    Musica m;
    int n = 0;
    Musica *playlist = NULL;

    m = nova("Eu juro", "Leandro & Leonardo", "L&L Vol. 9", 2, 57);
    playlist = inserir(playlist, &n, m);
    m = nova("O Papa é Pop", "Engenheiros do Hawaii", "O Papa é Pop", 3, 34);
    playlist = inserir(playlist, &n, m);
    m = nova("Não aprendi dizer adeus", "Leandro & Leonardo", "Sonho por Sonho", 3, 7);
    playlist = inserir(playlist, &n, m);
    m = nova("I Wanna Rock", "Twisted Sister", "Stay Hungry", 2, 59);
    playlist = inserir(playlist, &n, m);
    m = nova("T.N.T", "AC/DC", "High Voltage", 3, 34);
    playlist = inserir(playlist, &n, m);
    m = nova("Infinita Highway", "Engenheiros do Hawaii", "10.000 Destinos", 6, 6);
    playlist = inserir(playlist, &n, m);
    m = nova("Take on Me", "A-HA", "Hunting High and Low", 3, 45);
    playlist = inserir(playlist, &n, m);
    m = nova("Girls Just Want to Have Fun", "Cyndi Lauper", "Twelve Deadly Cyns", 3, 54);
    playlist = inserir(playlist, &n, m);
    m = nova("Entre tapas e beijos", "Leandro & Leonardo", "Sonho por Sonho", 2, 57);
    playlist = inserir(playlist, &n, m);
    m = nova("Highway to Hell", "AC/DC", "Highway to Hell", 3, 28);
    playlist = inserir(playlist, &n, m);
    m = nova("Panela Velha", "Trio Parada Dura", "Raizes Sertanejas", 3, 4);
    playlist = inserir(playlist, &n, m);
    m = nova("Sutilmente", "Skank", "Estandarte", 4, 2);
    playlist = inserir(playlist, &n, m);

    *t = n;
    return playlist;
}

void ordena_titulo(Musica playlist[], int n) {
  int i, j, trocas;
  Musica aux;
  for (i = n - 1; i > 0; i--) {
    trocas = 0;
    for (j = 0; j < i; j++) {
      if (strcmp(playlist[j].titulo , playlist[j + 1].titulo ) > 0 ) {
        aux = playlist[j];
        playlist[j] = playlist[j + 1];
        playlist[j + 1] = aux;
        trocas++;
      }
    }
    if (trocas == 0) {
      break;
    }
  }

    /**
    Implemente sua solução aqui.
    Ordenar o vetor de músicas por título.
    Não é necessário converter pra maiúscula.
    */
}

void ordena_artista(Musica playlist[], int n) {

  int i, j, trocas;
  Musica aux;
  for (i = n - 1; i > 0; i--) {
    trocas = 0;
    for (j = 0; j < i; j++) {
      if (strcmp(playlist[j].artista , playlist[j + 1].artista ) > 0 ) {
        aux = playlist[j];
        playlist[j] = playlist[j + 1];
        playlist[j + 1] = aux;
        trocas++;
      }
    }
    if (trocas == 0) {
      break;
    }
  }
    /**
    Implemente sua solução aqui.
    Ordenar o vetor de músicas por artista.
    Não é necessário converter pra maiúscula.
    Utilize um método estável.
    */
}

int main(){
    Musica *playlist = NULL;
    int n = 0;

    playlist = gera_dados_iniciais(&n);

    ordena_titulo(playlist, n);
    ordena_artista(playlist, n);

    listar(playlist, n);

    return 0;
}
