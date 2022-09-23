#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum opcao
{
    SAIR,
    INSERIR,
    LISTAR,
    CONSULTAR_ID,
    CONSULTAR_CIDADE,
    EXCLUIR
};
typedef enum opcao Opcao;

struct endereco
{
    char logradouro[50];
    char complemento[50];
    char cidade[50];
    char estado[3]; // ex.: PR
    char cep[10]; // 99999-999
};
typedef struct endereco Endereco;

struct cliente
{
    int id;
    char nome[50];
    char cpf[15]; // 999.999.999-99
    char telefone[20]; // +99 (99) 99999-9999
    Endereco endereco;
    struct cliente * proximo;
};
typedef struct cliente Cliente;

Opcao menu()
{
    Opcao op;
    printf("Selecione uma opção:\n");
    printf("\t%d. Inserir\n", INSERIR);
    printf("\t%d. Listar\n", LISTAR);
    printf("\t%d. Consultar por ID\n", CONSULTAR_ID);
    printf("\t%d. Consultar por cidade\n", CONSULTAR_CIDADE);
    printf("\t%d. Excluir\n", EXCLUIR);
    printf("\t%d. Sair\n", SAIR);
    printf("> ");
    scanf("%d", &op);
    return op;
}

Cliente* novo_cliente()
{
    static int id = 0;
    Cliente* cliente = malloc (sizeof *cliente);
    id++;
    cliente->id = id;
    printf("Nome: ");
    scanf(" %49[^\n]", cliente->nome);
    printf("CPF: ");
    scanf(" %14[^\n]", cliente->cpf);
    printf("Telefone: ");
    scanf(" %19[^\n]", cliente->telefone);
    printf("Endereço:\n");
    printf("\t Logradouro: ");
    scanf(" %49[^\n]", cliente->endereco.logradouro);
    printf("\t Complemento: ");
    scanf(" %49[^\n]", cliente->endereco.complemento);
    printf("\t Cidade: ");
    scanf(" %49[^\n]", cliente->endereco.cidade);
    printf("\t Estado: ");
    scanf(" %2[^\n]", cliente->endereco.estado);
    printf("\t CEP: ");
    scanf(" %9[^\n]", cliente->endereco.cep);
    return cliente;
}

Cliente* inserir(Cliente* lista)
{
    Cliente* novo = novo_cliente();
    novo->proximo = lista;
    return novo;
}

void mostra_cliente(Cliente* cliente)
{
    printf("%d: %s\n", cliente->id, cliente->nome);
    printf("CPF: %s\n", cliente->cpf);
    printf("Telefone: %s\n", cliente->telefone);
    Endereco endereco = cliente->endereco;
    printf("Endereço: %s, %s, %s-%s, CEP %s.\n",
           endereco.logradouro, endereco.complemento,
           endereco.cidade, endereco.estado, endereco.cep);
}

void listar(Cliente* lista)
{
    Cliente* i;
    for(i=lista; i != NULL; i = i->proximo)
    {
        mostra_cliente(i);
    }
}

void consultar_id(Cliente* lista)
{
    int id;
    printf("Id: ");
    scanf("%d", &id);
    Cliente* i;
    for(i=lista; i != NULL; i = i->proximo)
    {
        if (i->id == id)
        {
            mostra_cliente(i);
            return;
        }
    }
    printf("Cliente [%d] não encontrado.\n", id);
}

void consultar_cidade(Cliente* lista)
{
    char cidade[50];
    printf("Cidade: ");
    scanf(" %49[^\n]", cidade);
    Cliente* i;
    for(i=lista; i != NULL; i = i->proximo)
    {
        if (strcmp(i->endereco.cidade, cidade) == 0)
        {
            mostra_cliente(i);
        }
    }
}

Cliente* excluir (Cliente* lista)
{
    int id;
    printf("Id: ");
    scanf("%d", &id);
    Cliente* ant = NULL; // ponteiro para o anterior
    Cliente* i; // ponteiro que percorre a lista
    /* procura elemento v na lista */
    for (i = lista; i != NULL && i->id != id; i = i->proximo)
    {
        ant = i;
    }
    /* verifica se achou o elemento */
    if (i == NULL)
    {
        return lista; // não achou
    }
    /* retira elemento */
    if (ant == NULL)
    {
        lista = i->proximo; // remove o primeiro
    }
    else
    {
        ant->proximo = i->proximo; // remove do meio
    }
    free(i); // libera memória do elemento removido
    return lista; // retorna o ponteiro para o início
}

Cliente* liberar(Cliente *clientes){
  Cliente *i;
  Cliente *aux;
  for (i = clientes; i != NULL; i = aux) {
    aux = i->proximo;
    free(i);
  }
  return NULL;
}

int main(void)
{
    setlocale(LC_ALL, "");
    Cliente *clientes = NULL; // vetor de clientes

    /**
    Exemplo:
                 i
      -----------?-------
      |8|3|5|6|2| | | | |
      -------------------
       0 1 2 3 4 5 6 7 8
      capacidade: 9
      tamanho: 5
    */

    Opcao opcao = SAIR;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case SAIR:
            clientes = liberar(clientes);
            printf("Encerrando...\n");
            break;
        case INSERIR:
            clientes = inserir(clientes);
            break;
        case LISTAR:
            listar(clientes);
            break;
        case CONSULTAR_ID:
            consultar_id(clientes);
            break;
        case CONSULTAR_CIDADE:
            consultar_cidade(clientes);
            break;
        case EXCLUIR:
            clientes = excluir(clientes);
            break;
        default:
            printf("Opcão inválida [%d]\n", opcao);
        }
    }
    while (opcao != SAIR);

    return 0;
}
