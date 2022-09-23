#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


struct ponto3D{
	double x;
	double y;
	double z;
	struct ponto3D *proximo;
};
typedef struct ponto3D Ponto3D;


Ponto3D* novo_ponto(){    
    Ponto3D* ponto = malloc (sizeof *ponto);
    printf("Digite o ponto x:");
    scanf("%lf", ponto->x);
    printf("\nDigite o ponto y:");
    scanf("%lf", ponto->y);    
    printf("\nDigite o ponto z:");
	scanf("%lf", ponto->z);
    return ponto;
}

Ponto3D* inserir(Ponto3D* lista){
    Ponto3D* novo = novo_ponto();
    novo->proximo = lista;
    return novo;
}

Ponto3D* excluir (Ponto3D* lista){
    
    Ponto3D* ant = NULL; // ponteiro para o anterior
    Ponto3D* i; // ponteiro que percorre a lista    
    /* procura elemento v na lista */
    
    for (i = lista; i != NULL; i = i->proximo){
    	if((i->x < 0)||(i->y < 0)||(i->z < 0)){
    		ant = i;  		
		}
		/* verifica se achou o elemento */
    	if (i == NULL){
        	return lista; // não achou
    	}
    	/* retira elemento */
    	if (ant == NULL){
        	lista = i->proximo; // remove o primeiro
    	}
    	else{
        	ant->proximo = i->proximo; // remove do meio
    	}
    	free(i); // libera memória do elemento removido        
    }    
    return lista; // retorna o ponteiro para o início
}

int main (){
	int i;
	Ponto3D *pontos = NULL;
	for(i = 0; i <3; i++){
		pontos = inserir (pontos);		
	}
	pontos = excluir(pontos);	
	return 0;
}

