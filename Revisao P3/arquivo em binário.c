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

void salva_arquivo(Musica playlist[], int n, char nome_arquivo[]) {
	FILE * f;
	f = fopen("nome_arquivo.bin", "wb");
	if (f == NULL) {
		fprintf(stderr, "Erro ao abrir arquivo\n");
		exit(1);
	} else{
		fwrite(&n, sizeof(int), 1, f);
		fwrite(playlist, sizeof(Musica), n, f);
		fclose (f);
	}

    /**
    Implemente sua solução aqui.
    Esta função deverá escrever em um arquivo o tamanho n e o vetor de músicas.
    */
}

Musica* le_arquivo(int *n, char nome_arquivo[]) {
	FILE * f;
	Musica* playlist = NULL;
	
	
	f = fopen("nome_arquivo.bin", "rb");
	if (f == NULL){
		fprintf(stderr, "Arquivo nao existe\n");
		// exit(1);
	} else {
		fread(n, sizeof(int), 1, f);
		playlist = malloc(*n * sizeof(Musica));
		fread(playlist, sizeof(Musica), *n, f);
		fclose(f);
	}
	return playlist;
		

    /**
    Implemente sua solução aqui.
    Esta função deverá ler de um arquivo o tamanho n
    alocar um vetor de músicas de tamanho n
    ler o vetor do arquivo
    e retornar o valor lido,
    armazenando seu tamanho na variável n passada por referência
    */
}


Musica* gera_dados_iniciais (int *t) {
    Musica m;
    int n = 0;
    Musica *playlist = NULL;
    m = nova("T.N.T", "AC/DC", "High Voltage", 3, 34);
    playlist = inserir(playlist, &n, m);
    m = nova("Entre tapas e beijos", "Leandro & Leonardo", "Sonho por Sonho", 2, 57);
    playlist = inserir(playlist, &n, m);
    m = nova("Take on Me", "a-ha", "Hunting High and Low", 3, 45);
    playlist = inserir(playlist, &n, m);
    m = nova("Sutilmente", "Skank", "Estandarte", 4, 2);
    playlist = inserir(playlist, &n, m);
    m = nova("I Wanna Rock", "Twisted Sister", "Stay Hungry", 2, 59);
    playlist = inserir(playlist, &n, m);
    m = nova("Girls Just Want to Have Fun", "Cyndi Lauper", "Twelve Deadly Cyns", 3, 54);
    playlist = inserir(playlist, &n, m);
    m = nova("Infinita Highway", "Engenheiros do Hawaii", "10.000 Destinos", 6, 6);
    playlist = inserir(playlist, &n, m);
    m = nova("Panela Velha", "Trio Parada Dura", "Raizes Sertanejas", 3, 4);
    playlist = inserir(playlist, &n, m);
    *t = n;
    return playlist;
}


int main(){
    Musica *playlist = NULL;
    int n = 0;

    playlist = gera_dados_iniciais(&n);

    /** GRAVA A PLAYLIST NO ARQUIVO **/

    salva_arquivo(playlist, n, "temdetudo.playlist");
    free(playlist);
    n = 0;

    /** LE O ARQUIVO COM A PLAYLIST E MOSTRA NA TELA**/

    int n2;
    Musica * outra_playlist = le_arquivo(&n2, "temdetudo.playlist");
    listar(outra_playlist, n2);

    return 0;
}
