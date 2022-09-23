#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Lucas Brites Teixeira Cordeiro RA: 1984357
Patrick Rangel Zilz RA: 1984373

/*
https://www.gnu.org/software/gsl/
https://www.scipy.org/
*/
enum opcao {
  SAIR,//0
  INSERIR,//1
  EXCLUIR,//2
  LISTAR_TODOS,//3
  MOSTRAR_CAT,//4
  FAZER,//5
  MOSTRAR_CONCLUIDAS,//6
  TODAS_FAZER,//7
  CONCLUIDA,//8
  
};
typedef enum opcao Opcao;

struct data{
	int dia;
	int mes;
	int ano;
};
typedef struct data Data;

struct tarefa{
	int id;
	char titulo[50];
	char descricao [150];
	char categoria [50];
	Data data_entrega;
	int concluido;
	struct tarefa * proximo;
};
typedef struct tarefa Tarefa;

Opcao menu() {
	Opcao op;
  	printf("Selecione uma opção:\n");
  	printf("\t%d. Inserir Tarefa\n", INSERIR);
  	printf("\t%d. Excluir Tarefa\n", EXCLUIR);
  	printf("\t%d. Listar Todas as tarefas\n", LISTAR_TODOS);
  	printf("\t%d. Mostrar todas tarefas de uma categoria\n", MOSTRAR_CAT);
  	printf("\t%d. Tarefa mais urgente\n", FAZER);
  	printf("\t%d. Mostrar todas tarefas concluidas\n", MOSTRAR_CONCLUIDAS);
  	printf("\t%d. Mostrar todas tarefas para fazer\n", TODAS_FAZER);
	printf("\t%d. Marcar tarefa como concluida\n", CONCLUIDA);    	
  	printf("\t%d. Sair\n", SAIR);
  	printf("> ");
  	scanf("%d", &op);
  	return op;
}


Tarefa* nova_tarefa(){
	
  	static int id = 0;
  	Tarefa* tarefa = malloc(sizeof *tarefa);
  	id++;
  	tarefa->id = id;
  	printf("Título da tarefa: "); 
  	scanf(" %49[^\n]", tarefa->titulo);
  	printf("Descrição da tarefa: "); 
  	scanf(" %149[^\n]", tarefa->descricao);
  	printf("Categoria: "); 
  	scanf(" %49[^\n]", tarefa->categoria);
  	printf("Data de entrega:\n");
  	printf("\t Dia: "); 
  	scanf(" %d", tarefa->data_entrega.dia);
  	printf("\t Mês: "); 
  	scanf(" %d", tarefa->data_entrega.mes);
  	printf("\t Ano: ");
	scanf(" %d", tarefa->data_entrega.ano);
	tarefa->concluido=1;// ao ser inserido, a tarefa é dada como não concluida
  	return tarefa;
}   

Tarefa* inserir (Tarefa* lista) {
	Tarefa* novo = nova_tarefa();
	novo->proximo=lista;
	return novo;
	
}

Tarefa* excluir(Tarefa* lista) {
	
  	int id;  	
  	printf("Id: ");
  	scanf("%d", &id);
  	Tarefa*ant=NULL;//ponteiro para o anterior
  	Tarefa*i;//ponteiro que percorre a lista
  	// Procura o elemento v na lista
  	for(i=lista; i!=NULL && i->id!=id; i=i->proximo){
  		ant=i;
	  }
	  // verifica se achou o elemento
	  if(i==NULL){
	  	return lista;// elemento procurado não foi encontrado
	  }
	  //retira o elemento
	  if(ant=NULL){
	  	lista->proximo;// remover o primeiro elemento
	  }
	  else{// remove elemento do meio
	  	ant->proximo = i->proximo;
	  }
	  free(i);// libera memória do elemento removido
	  return lista;// retorna o ponteiro para o início
    		
}

void mostrar_tarefa(Tarefa* tarefa){
	
	printf("%d: %s\n", tarefa->id, tarefa->titulo); 
	printf("Categoria: %s\n", tarefa->categoria); 
	printf("Descrição: %s\n", tarefa->descricao);
	Data entrega = tarefa->data_entrega;
	printf("Data de entrega: %d/ %d/ %d \n", entrega.dia, entrega.mes, entrega.ano);
}


void listar_categoria(Tarefa* lista){
	char categoria[50];	
  	printf("Categoria: ");
  	scanf(" %49[^\n]", categoria);
  	Tarefa* i;
  	for( i=lista; i!=NULL; i=i->proximo) {
    		if (strcmp(i->categoria, categoria) == 0) {
      		mostrar_tarefa(i);
    		}
  	}
	
}

void listar_todos (Tarefa* lista) {
	Tarefa* i;
  	for (i=lista; i!=NULL; i=i->proximo) {
    		mostrar_tarefa(i);
    printf("\n");
  }
}

void checar_data(Tarefa* lista){
	Tarefa* i;
	Tarefa* urgente;
	int menorano,menormes,menordia;
	menorano = lista->data_entrega.ano;
	menormes = lista->data_entrega.mes;
	menordia = lista->data_entrega.dia;
	for(i=lista; i!=NULL; i=i->proximo){
		if(i->concluido==0){
			if(i->data_entrega.ano<menorano){
				urgente=i;
				menorano=i->data_entrega.ano;
			}
			else if(i->data_entrega.ano>=menorano){
				if(i->data_entrega.mes<menormes){
					urgente=i;
					menormes=i->data_entrega.ano;					
				}
				else if(i->data_entrega.mes>=menormes){
					if(i->data_entrega.dia<menordia){
						urgente=i;
						menordia=i->data_entrega.dia;						
					}
					else if(i->data_entrega.dia>=menordia){
						urgente=i;
						menordia=i->data_entrega.dia;
					}					
				}				
			}			
		}			
	}
	mostrar_tarefa(urgente);
}
	


void mostrar_fazer(Tarefa* lista){
	Tarefa* i;	
	for(i=lista; i!=NULL ; i=i->proximo){	
		if(i->concluido==1){
			mostrar_tarefa(i);			
		}
	}
}

Tarefa* concluir (Tarefa* lista){
	int id;
	Tarefa* i;
	Tarefa* con=NULL;
	printf("Qual é o id da tarefa deseja concluir?\n>");
	scanf("%d",id);
	for(i=lista;i!=NULL && i->id != id; i->proximo){
		con=i;
	}
	if(i==NULL){
	  	return lista;// elemento procurado não foi encontrado
	  }
	if(con->concluido==1){
		i->concluido=SAIR;
	}
}

void mostrar_concluidas(Tarefa* lista){
	Tarefa* i;
	for(i=lista; i!=NULL ; i=i->proximo){
		if(i->concluido==SAIR){
			mostrar_tarefa(i);			
		}
	}
}

Tarefa* liberar(Tarefa *tarefas){
  	Tarefa *i;
  	Tarefa *aux;
  	for (i = tarefas; i != NULL; i = aux) {
    		aux = i->proximo;
    		free(i);
  	}
  	return NULL;
}

int main(){
	setlocale(LC_ALL, "");
	Tarefa *tarefas=NULL;// Vetor de tarefas	
	Opcao opcao=SAIR;	
	do{
		opcao=menu();
		switch (opcao){
			case SAIR:				
				tarefas=liberar(tarefas);
				printf("Encerrando...\n");
				break;
			case INSERIR:
				tarefas = inserir(tarefas);
				break;
			case EXCLUIR:
				tarefas = excluir(tarefas);
        		break;
        	case LISTAR_TODOS:
        		listar_todos(tarefas);
        		break;
			case MOSTRAR_CAT:
				listar_categoria(tarefas);
			case FAZER:
				checar_data(tarefas);
				break;
			case MOSTRAR_CONCLUIDAS:
				mostrar_concluidas(tarefas);
				break;
			case TODAS_FAZER:
				mostrar_fazer(tarefas);
				break;
			case CONCLUIDA:
				concluir(tarefas);				
				break;
			default:
        			printf("Opcão inválida [%d]\n", opcao);			
		}		
	}while(opcao!=SAIR);	
return 0;	
}

