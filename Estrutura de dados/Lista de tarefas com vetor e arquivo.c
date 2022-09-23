#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Lucas Brites Teixeira Cordeiro RA: 1984357
Patrick Rangel Zilz RA: 1984373

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
  ABRIR,//9
  SALVAR//10  
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
	printf("\t%d. Abrir arquivo\n", ABRIR);
	printf("\t%d. Salvar dados\n", SALVAR);
  	printf("\t%d. Sair\n", SAIR);
  	printf("> ");
  	scanf("%d", &op);
  	return op;
}

Tarefa nova_tarefa(){
	
  	static int id = 0;
  	Tarefa tarefa;
  	id++;
  	
  	tarefa.id = id; 	
  	printf("Título da tarefa: ");
	scanf(" %49[^\n]", tarefa.titulo);  	 
  	printf("Descrição da tarefa: "); 
  	scanf(" %149[^\n]", tarefa.descricao);  	
  	printf("Categoria: "); 
  	scanf(" %49[^\n]", tarefa.categoria);  	
  	printf("Data de entrega:\n");
  	printf("\t Dia: "); 
  	scanf(" %d", &tarefa.data_entrega.dia);  	
  	printf("\t Mês: "); 
  	scanf(" %d", &tarefa.data_entrega.mes);  
  	printf("\t Ano: ");
	scanf(" %d", &tarefa.data_entrega.ano);	
	tarefa.concluido = 1;// ao ser inserido, a tarefa não é dada como não concluida = 1.
  	return tarefa;
}   

Tarefa* inserir (Tarefa tarefas[], int *tamanho, int *capacidade) {
	
   	if (*tamanho >= *capacidade) {   		
     		*capacidade += 10;
     		tarefas = realloc(tarefas, *capacidade * sizeof *tarefas);
   	}
   	tarefas[*tamanho] = nova_tarefa();
   	*tamanho += 1;
   	return tarefas;
}

void excluir(Tarefa tarefas[], int *tamanho) {
	
  	int id,i,j;
  	printf("Id: ");
  	scanf("%d", &id);
  	for(i=0; i<*tamanho; i++) {
    	if (tarefas[i].id == id) {
      		for ( j = i+1; j < *tamanho; j++) {
        		tarefas[j-1] = tarefas[j]; 
      		}
      		*tamanho -= 1;
    	}
  	}
  	printf("Tarefa [%d] não encontrada.\n", id);
}

void mostrar_tarefa(Tarefa tarefa){
	
	printf("%d: %s\n", tarefa.id, tarefa.titulo);
	printf("Descrição: %s\n", tarefa.descricao);
	printf("Categoria: %s\n", tarefa.categoria); 
	printf("Data de entrega: %d/ %d/ %d \n", tarefa.data_entrega.dia, tarefa.data_entrega.mes, tarefa.data_entrega.ano);
}

void listar_categoria(Tarefa tarefas[], int tamanho){
	char categoria[50];
	int i;
  	printf("Categoria: ");
  	scanf(" %49[^\n]", categoria);
  	for( i = 0; i < tamanho; i++) {
    	if (strcmp(tarefas[i].categoria, categoria) == 0) {
		mostrar_tarefa(tarefas[i]);
    	}
  	}
	
}

void listar_todos (Tarefa tarefas[], int tamanho) {
	int i;
  	for (i = 0; i < tamanho; i++) {
    		mostrar_tarefa(tarefas[i]);
    printf("\n");
  }
}

void checar_data (Tarefa tarefas[],int tamanho){
	int i,j;
	int urgente = 0;
	for (i = 0; i < tamanho; i++){
		if(tarefas[i].concluido != SAIR){
			urgente = i;
			break;			
		}
		
	}
	for ( i+1; i < tamanho; i++){
		if(tarefas[i].concluido != SAIR){
			if (tarefas[i].data_entrega.ano < tarefas[urgente].data_entrega.ano ){
				urgente = i;			
			}
			else if (tarefas[i].data_entrega.ano > tarefas[urgente].data_entrega.ano){			
			}
			else{ // se o ano for igual para o urgente e para a tarefa i.
				if (tarefas[i].data_entrega.mes < tarefas[urgente].data_entrega.mes){
					urgente = i;			
				}
				else if (tarefas[i].data_entrega.ano > tarefas[urgente].data_entrega.ano){			
				}
				else { // se o mes for igual para o urgente e para a tarefa i.
					if (tarefas[i].data_entrega.dia < tarefas[urgente].data_entrega.dia){
						urgente = i;				
					}
					else if (tarefas[i].data_entrega.dia > tarefas[urgente].data_entrega.dia){				
					}
					else{ //  se o dia for igual para o urgente e para a tarefa i.
						if (i != urgente) {
							mostrar_tarefa (tarefas [i]);						
						}
					}
				}
			}
		}	
	}
		
	mostrar_tarefa(tarefas[urgente]);
}

void mostrar_fazer(Tarefa tarefas[],int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		if(tarefas[i].concluido == 1){
			mostrar_tarefa(tarefas[i]);			
		}
	}
}

void concluir (Tarefa tarefas[],int tamanho){
	int id,i;
	printf("Qual é o id da tarefa deseja concluir?\n>");
	scanf("%d",&id);
	for( i = 0; i < tamanho; i++){
		if(tarefas[i].id == id){
			tarefas[i].concluido = SAIR;
		}
	}	
}

void mostrar_concluidas(Tarefa tarefas[], int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		if(tarefas[i].concluido == SAIR){
			mostrar_tarefa(tarefas[i]);			
		}
	}
}

void salvar_arquivo (Tarefa tarefas [], FILE* fp, int tamanho){
	int i;
	fp = fopen("Tarefas.txt", "wt");
	if( fp == NULL){
		fprintf(stderr, "Erro ao abrir arquivo.");
	}else{
		fprintf(fp, "%d\n",tamanho);
		for (i = 0; i < tamanho; i++){
			fprintf(fp, "%d\n", tarefas[i].id);
			fprintf(fp, "%s\n", tarefas[i].titulo);
			fprintf(fp, "%s\n", tarefas[i].descricao);		
			fprintf(fp, "%s\n", tarefas[i].categoria);			
			fprintf(fp, "%d\n", tarefas[i].data_entrega.dia);
			fprintf(fp, "%d\n", tarefas[i].data_entrega.mes);
			fprintf(fp, "%d\n", tarefas[i].data_entrega.ano);
			fprintf(fp, "%d\n", tarefas[i].concluido);
		}					
	}				
	fclose(fp);
}

Tarefa* abrir_arquivo (Tarefa tarefas [], FILE* fp, int* tam){
	int i,n;	
	Tarefa t;
	fp = fopen("Tarefas.txt", "rt");
	if (fp == NULL){
    	printf("Erro ao abrir arquivo!\n");
   		exit(1);  
	}
	else{
		fscanf(fp, "%d", &n);
		tarefas = malloc ( n * sizeof *tarefas);
		for(i = 0; i < n ; i++ ){
			fscanf(fp, "%d", &t.id);
			fscanf(fp, " %[^\n]", t.titulo);
			fscanf(fp, " %[^\n]", t.descricao);		
			fscanf(fp, " %[^\n]", t.categoria);			
			fscanf(fp, "%d", &t.data_entrega.dia);
			fscanf(fp, "%d", &t.data_entrega.mes);
			fscanf(fp, "%d", &t.data_entrega.ano);
			fscanf(fp, "%d", &t.concluido);		
			tarefas [i] = t;
			
		}
	}
	*tam = n;	
	fclose(fp);
	return tarefas;
}


int main(){
	setlocale(LC_ALL, "");
	Tarefa *tarefas = NULL;// Vetor de tarefas
	FILE* fp;// ponteiro para salvar em arquivo
	int capacidade = 0;// capacidade do vetor de tarefas
	int tamanho = 0;// elementos dos vetor
	int i;
	Opcao opcao = SAIR;
	do{
		system ("pause");
		system ("cls");
		opcao = menu();
		switch (opcao){
			case SAIR:
				free(tarefas);
				tarefas = NULL;
				printf("Encerrando...\n");
				break;
			case INSERIR:
				tarefas = inserir(tarefas, &tamanho, &capacidade);
				break;
			case EXCLUIR:
				excluir(tarefas, &tamanho);
        		break;
        	case LISTAR_TODOS:
        		listar_todos(tarefas, tamanho);
        		break;
			case MOSTRAR_CAT:
				listar_categoria(tarefas, tamanho);
				break;
			case FAZER:
				checar_data(tarefas, tamanho);
				break;
			case MOSTRAR_CONCLUIDAS:
				mostrar_concluidas(tarefas, tamanho);
				break;
			case TODAS_FAZER:
				mostrar_fazer(tarefas, tamanho);
				break;
			case CONCLUIDA:
				concluir(tarefas, tamanho);				
				break;
			case ABRIR:
				tarefas = abrir_arquivo (tarefas, fp, &tamanho);
			case SALVAR:
				salvar_arquivo(tarefas, fp, tamanho);				
				break;									
			default:
        		printf("Opcão inválida [%d]\n", opcao);			
		}		
	}while(opcao!=SAIR);	
return 0;	
}

