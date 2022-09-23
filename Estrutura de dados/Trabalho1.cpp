//Johny Kwiatkowski Oh - 18/04/2019 - Estrutura de Dados 1. Ok
#include <iostream>
#include <fstream>

using namespace std;

struct seq{
    string nome;
    string RG;
};
typedef struct seq Seq;
struct enc{
    string nome;
    string RG;
    struct enc *prox;
};
typedef struct enc Enc;

void menu(int *opt, int *tipo);

/*-------------------Sequencial------------------------------*/
Seq* opc(int opt, int *linhas, Seq *vetor, int *m, int *c);
Seq *adcInicio(Seq *vetor, int linhas, string nome, string RG, int *m, int *c);
Seq *adcFinal(Seq *vetor, int linhas, string nome, string RG, int *m, int *c);
Seq *adcMeio(Seq *vetor, int linhas, string nome, string RG, int *m, int *c);
Seq *rmvInicio(Seq *vetor, int linhas, string nome, string RG, int *m, int *c);
Seq *rmvFinal(Seq *vetor, int linhas, string nome, string RG, int *m, int *c);
Seq *rmvMeio(Seq *vetor, int linhas, string nome, string RG, int *m, int *c);
void procurarNome(Seq* vetor, int linhas, int *m, int *c);
void exibeSequencial(Seq *vetor, int linhas, int *m, int *c);
Seq *lerListaSequencial(int *linhas, int *m, int *c);
void criaTxt(Seq *vetor,int linhas, int *m, int *c);
int qtdLinhas(string& nomeArq);
/*-------------------Encadeada-------------------------------*/
void inicia(Enc *LISTA);
void opcaoEnc(Enc *LISTA, int op, int *m, int *c);
void encadeadaInicio(Enc *LISTA);
void encadeadaFinal(Enc *LISTA, int *m, int *);
void encadeadaMeio(Enc *LISTA, int *m, int *);
Enc *retiraInicio(Enc *LISTA, int *m, int *);
Enc *retiraFim(Enc *LISTA, int *m, int *);
Enc *retiraMeio(Enc *LISTA, int *m, int *);
void procuraPessoa(Enc *LISTA, int *m, int *);
void exibe(Enc *LISTA, int *m, int *);
void lerListaEnc(Enc *LISTA, int *m, int *c);
void criaTXT(Enc *LISTA, int *m, int *);
void libera(Enc *LISTA);
int vazia(Enc *LISTA);

main(){
/*------------Sequencial--------------*/

    Seq *vetor=new Seq[1];
    int opt, linhas=0, tipo, m, c;

/*------------Encadeada---------------*/

    Enc *LISTA=new Enc;

    if(!LISTA){
        cout << "Sem memoria disponivel!\n";
        exit(1);
    }
    inicia(LISTA);

/*------------------------------------*/

    do{
        menu(&opt, &tipo);
        if(tipo==1)
            vetor=opc(opt,&linhas,vetor,&m,&c);
        else if(tipo==2)
            opcaoEnc(LISTA,opt,&m,&c);
        else
            cout << "Tipo invalido!" << endl;
    }while(opt);
}
void menu(int *opt, int *tipo){
    cout << "\nQual tipo de lista voce deseja? (1) Sequencial; (2) Encadeada: ";
    cin >> *tipo;
    cout << "Menu: Digite o numero correspondente ao que deseja." << endl;
    cout << "(1) Adicionar no Inicio." << endl;
    cout << "(2) Adicionar no Final." << endl;
    cout << "(3) Adicionar no Meio." << endl;
    cout << "(4) Remover do Inicio." << endl;
    cout << "(5) Remover do Final." << endl;
    cout << "(6) Remover do Meio." << endl;
    cout << "(7) Procurar nome pelo RG." << endl;
    cout << "(8) Mostra na Tela." << endl;
    cout << "(9) Ler arquivo." << endl;
    cout << "(10) Salvar lista em um arquivo." << endl;
    cout << "(0) Sair do Sistema." << endl;
    cin >> *opt;
}
/*-----------------------------------------------Sequencial-----------------------------------------------------------------*/
Seq* opc(int opt, int *linhas, Seq *vetor, int *m, int *c){
    string nome, RG;

    if(opt>=1 && opt<=3){
        cout << "Nome e RG: ";
        cin >> nome >> RG;
    }
    if(opt==1){
        *linhas+=1;
        vetor=adcInicio(vetor,*linhas,nome,RG,m,c);
    }
    else if(opt==2){
        *linhas+=1;
        vetor=adcFinal(vetor,*linhas,nome,RG,m,c);
    }
    else if(opt==3){
        *linhas+=1;
        vetor=adcMeio(vetor,*linhas,nome,RG,m,c);
    }
    else if(opt==4){
        *linhas-=1;
        vetor=rmvInicio(vetor,*linhas,nome,RG,m,c);
    }
    else if(opt==5){
        *linhas-=1;
        vetor=rmvFinal(vetor,*linhas,nome,RG,m,c);
    }
    else if(opt==6){
        *linhas-=1;
        vetor=rmvMeio(vetor,*linhas,nome,RG,m,c);
    }
    else if(opt==7){
        procurarNome(vetor,*linhas,m,c);
    }
    else if (opt==8){
        exibeSequencial(vetor,*linhas,m,c);
    }
    else if(opt==9){
        vetor=lerListaSequencial(linhas,m,c);
    }
    else if (opt==10){
        criaTxt(vetor,*linhas,m,c);
    }
    else if(opt==0){
        exit(1);
    }
    cout << "M: " << *m << "\t" << "C: " << *c << endl;
    *m=0;
    *c=0;
    return vetor;
}
Seq *adcInicio(Seq *vetor, int linhas, string nome, string RG, int *m, int *c){
    Seq *novo=new Seq[linhas];

    novo[0].nome=nome;
    novo[0].RG=RG;

    if(linhas>1){
        for(int i=1; i<linhas; i++){
            novo[i].nome=vetor[i-1].nome;
            novo[i].RG=vetor[i-1].RG;
            *m+=1;
        }
        *c+=1;
    }

    return novo;
}
Seq *adcFinal(Seq *vetor, int linhas, string nome, string RG, int *m, int *c){
    Seq *novo=new Seq[linhas];

    novo[linhas-1].nome=nome;
    novo[linhas-1].RG=RG;

    if(linhas>1){
        for(int i=0; i<linhas-1; i++){
            novo[i].nome=vetor[i].nome;
            novo[i].RG=vetor[i].RG;
            *m+=1;
        }
        *c+=1;
    }

    return novo;
}
Seq *adcMeio(Seq *vetor, int linhas, string nome, string RG, int *m, int *c){

    Seq *novo=new Seq[linhas];

    int posicao;
    cout << "Digite a posicao que deseja colocar: ";
    cin >> posicao;

    novo[posicao-1].nome=nome;
    novo[posicao-1].RG=RG;

    if(linhas>1){
        for(int i=0; i<posicao-1; i++){
            novo[i].nome=vetor[i].nome;
            novo[i].RG=vetor[i].RG;
            *m+=1;
        }
        for(int i=posicao; i<linhas; i++){
            novo[i].nome=vetor[i-1].nome;
            novo[i].RG=vetor[i-1].RG;
            *m+=1;
        }
        *c+=1;
    }

    return novo;
}
Seq *rmvInicio(Seq *vetor, int linhas, string nome, string RG, int *m, int *c){
    Seq *novo=new Seq[linhas];

    if(linhas>1){
        for(int i=0; i<linhas; i++){
            novo[i].nome=vetor[i+1].nome;
            novo[i].RG=vetor[i+1].RG;
            *m+=1;
        }
        *c+=1;
    }

    return novo;
}
Seq *rmvFinal(Seq *vetor, int linhas, string nome, string RG, int *m, int *c){
    Seq *novo=new Seq[linhas];

    if(linhas>1){
        for(int i=0; i<linhas; i++){
            novo[i].nome=vetor[i].nome;
            novo[i].RG=vetor[i].RG;
            *m+=1;
        }
        *c+=1;
    }

    return novo;
}
Seq *rmvMeio(Seq *vetor, int linhas, string nome, string RG, int *m, int *c){
    Seq *novo=new Seq[linhas];

    int posicao;
    cout << "Digite a posicao que deseja remover: ";
    cin >> posicao;

    if(linhas>1){
        for(int i=0; i<posicao; i++){
            novo[i].nome=vetor[i].nome;
            novo[i].RG=vetor[i].RG;
            *m+=1;
        }
        for(int i=posicao-1; i<linhas; i++){
            novo[i].nome=vetor[i+1].nome;
            novo[i].RG=vetor[i+1].RG;
            *m+=1;
        }
        *c+=1;
    }

    return novo;
}
void procurarNome(Seq* vetor, int linhas, int *m, int *c){
    string RG;

    cout << "Digite o RG para procurar o nome: ";
    cin >> RG;

    for(int i=0; i<linhas; i++){
        if(RG.compare(vetor[i].RG)==0){
            cout << vetor[i].nome;
            *c+=1;
            break;
        }
        *m+=1;
    }
}
void exibeSequencial(Seq *vetor, int linhas, int *m, int *c){
    cout << "Nomes e RG's: \n";
    for(int i=0; i<linhas; i++){
        cout << "Nome: "<< vetor[i].nome << "\tRG: " << vetor[i].RG << endl;
        *m+=1;
    }
    cout << "\n";
}
Seq *lerListaSequencial(int *linhas, int *m, int *c){
    string nomeArq, linha, temp;

    cout << "Digite o nome do Arquivo que deseja abrir: ";
    cin >> nomeArq;
    ifstream arquivo(nomeArq);

    int i, contador=0;
    *linhas=qtdLinhas(nomeArq);
    Seq* novo=new Seq[*linhas];

    if(arquivo.is_open()){
        while(getline(arquivo,linha)){
            temp="";
            for(i=0; i<linha.size(); i++){
                *m+=1;
                if(linha[i]!=','){
                    temp=temp+linha[i];
                    *c+=1;
                }
                else break;
            }
            novo[contador].nome=temp;
            temp="";
            for(i=i+1; i<linha.size(); i++){
                temp=temp+linha[i];
                *m+=1;
            }
            novo[contador].RG=temp;
            contador++;
            *m+=1;
        }
        *c+=1;
    }
    else
        cout << "Nao foi possivel abrir o arquivo." << endl;
    arquivo.close();

    return novo;
}
void criaTxt(Seq *vetor,int linhas, int *m, int *c){

    int n=0;
    ofstream arquivo;
    string nome;

    cout << "Digite o nome do arquivo para cria-lo e salvar a lista nele: ";
    cin >> nome;

    arquivo.open(nome,ios::app);

    for(int i=0;i<linhas;i++){
        arquivo << vetor[i].nome << "," << vetor[i].RG << "\n";
        *m+=1;
    }
    arquivo.close();
}
int qtdLinhas(string& nomeArq){
    int tam;
    if(nomeArq=="a.txt")
        tam=10;
    else if(nomeArq=="NomeRG10.txt")
        tam=10;
    else if(nomeArq=="NomeRG50.txt")
        tam=50;
    else if(nomeArq=="NomeRG100.txt")
        tam=100;
    else if(nomeArq=="NomeRG1K.txt")
        tam=1000;
    else if(nomeArq=="NomeRG10K.txt")
        tam=10000;
    else if(nomeArq=="NomeRG1M.txt")
        tam=1000000;
    else if(nomeArq=="NomeRG100M.txt")
        tam=12000000;

    return tam;
}
/*-----------------------------------------------Encadeada-----------------------------------------------------------------*/
void inicia(Enc *LISTA){
    LISTA->prox = NULL;
}
void opcaoEnc(Enc *LISTA, int opt, int *m, int *c){
    if(opt==1)
        encadeadaInicio(LISTA);
    else if(opt==2)
        encadeadaFinal(LISTA,m,c);
    else if(opt==3)
        encadeadaMeio(LISTA,m,c);
    else if(opt==4)
        retiraInicio(LISTA,m,c);
    else if(opt==5)
        retiraFim(LISTA,m,c);
    else if(opt==6)
        retiraMeio(LISTA,m,c);
    else if(opt==7)
        procuraPessoa(LISTA,m,c);
    else if(opt==8)
        exibe(LISTA,m,c);
    else if(opt==9)
        lerListaEnc(LISTA,m,c);
    else if(opt==10)
        criaTXT(LISTA,m,c);
    else if(opt==0)
        libera(LISTA);
    cout << "M: " << *m << "\t" << "C: " << *c << endl;
    *m=0;
    *c=0;
}
void encadeadaInicio(Enc *LISTA){

    Enc *novo=new Enc;
    Enc *oldHead = LISTA->prox;

    cout << "Digite o nome e depois RG a ser inserido: ";
    cin >> novo->nome >> novo->RG;

    LISTA->prox = novo;
    novo->prox = oldHead;
}
void encadeadaFinal(Enc *LISTA, int *m, int *c){

    Enc *novo=new Enc;

    cout << "Digite o nome e o RG a ser inserido: ";
    cin >> novo->nome >> novo->RG;

    novo->prox = NULL;

    if(vazia(LISTA)){
        LISTA->prox=novo;
        *c+=1;
    }
    else{
        Enc *temp = LISTA->prox;
        while(temp->prox != NULL){
            temp = temp->prox;
            *m+=1;
        }
        temp->prox = novo;
        *c+=1;
    }
}
void encadeadaMeio(Enc *LISTA, int *m, int *c){

    int pos;
    Enc *novo = new Enc;

    cout << "Digite o nome e o RG a ser inserido: ";
    cin >> novo->nome >> novo->RG;
    cout << "Digite a posicao em que deseja inserir: ";
    cin >> pos;

    Enc *temp, *temp2;
    temp = LISTA->prox;

    for(int i=1;i<pos-1;i++){
        temp = temp->prox;
        *m+=1;
    }
    temp2=temp->prox;
    temp->prox=novo;
    novo->prox=temp2;
}
Enc *retiraInicio(Enc *LISTA, int *m, int *c){

    if(LISTA->prox==NULL){
        cout << "Lista vazia\n";
        *c+=1;
    }
    else{
        Enc *temp = LISTA->prox;
        LISTA->prox = temp->prox;
        *c+=1;
    }
}
Enc *retiraFim(Enc *LISTA, int *m, int *c){

    if(LISTA->prox == NULL){
        cout <<"Lista vazia.\n";
        *c+=1;
    }
    else{
        Enc *ultimo = LISTA->prox,
        *penultimo = LISTA;

        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
            *m+=1;
        }
        penultimo->prox = NULL;
        *c+=1;
    }
}
Enc *retiraMeio(Enc *LISTA, int *m, int *c){
    int pos;
    cout << "Digite a posicao que deseja remover: ";
    cin >> pos;

    Enc *temp, *temp2;
    temp = LISTA->prox;

    for(int i=1;i<pos-1;i++){
        temp = temp->prox;
        *m+=1;
    }
    temp2=temp->prox;
    temp->prox=temp2->prox;
}
void procuraPessoa(Enc *LISTA, int *m, int *c){

    int pos=0;
    string numRG;

    cout << "Digite o RG para verificar o nome da Pessoa: ";
    cin >> numRG;

    Enc *temp, *ant;
    temp = LISTA->prox;

    while(temp->prox!=NULL){
        if(numRG.compare(temp->RG)==0){
            *c+=1;
            break;
        }
        ant=temp;
        temp = temp->prox;
        *m+=1;
    }
    cout << "\nA pessoa com esse RG eh o " << ant->nome << endl;
}
void exibe(Enc *LISTA, int *m, int *c){

    if(vazia(LISTA)){
        cout << "Lista vazia!\n\n";
        *c+=1;
    }

    Enc *temp;
    temp = LISTA->prox;

    while( temp != NULL){
        cout << "Nome: " << temp->nome << "\tRG: " << temp->RG << endl;
        temp = temp->prox;
        *m+=1;
    }
    cout << "\n\n";
}
void lerListaEnc(Enc *LISTA, int *m, int *c){

    int i;
    string linha, temp, nomeArq;

    cout << "Digite o nome do Arquivo que deseja abrir: ";
    cin >> nomeArq;

    ifstream arquivo(nomeArq);

//    Enc *novo=new Enc;//esse eh necessario?

    if(arquivo.is_open()){
        *c+=1;
        while(getline(arquivo,linha)){
            *m+=1;
            Enc *novo=new Enc;
            novo->prox = NULL;
            temp="";
            for(i=0; i<linha.size(); i++){
                *m+=1;
                if(linha[i]!=','){
                    temp=temp+linha[i];
                    *c+=1;
                }
                else break;
            }
            novo->nome=temp;
            temp="";
            for(i=i+1; i<linha.size(); i++){
                temp=temp+linha[i];
                *m+=1;
            }
            novo->RG=temp;
            if(vazia(LISTA)){
                LISTA->prox=novo;
                *c+=1;
            }
            else{
                Enc *temp = LISTA->prox;
                while(temp->prox != NULL){
                    temp = temp->prox;
                    *c+=1;
                }
                temp->prox = novo;
            }
        }
        *c+=1;
    }
    else
        cout << "Nao foi possivel abrir o arquivo." << endl;

    arquivo.close();
}
void criaTXT(Enc *LISTA, int *m, int *c){

    int n=0;
    string nome;
    ofstream arquivo;
    Enc *temp, *ant;

    temp = LISTA->prox;

    cout << "Digite o nome do arquivo para cria-lo e salvar a lista nele: ";
    cin >> nome;

    arquivo.open(nome,ios::app);

    while(temp->prox!=NULL){
        arquivo << temp->nome << "," << temp->RG << "\n";
        ant=temp;
        temp = temp->prox;
        *m+=1;
    }
    arquivo << temp->nome << "," << temp->RG << "\n";

    arquivo.close();
}
void libera(Enc *LISTA){
    if(!vazia(LISTA)){
        Enc *proxNode, *atual;

        atual = LISTA->prox;

        while(atual != NULL){
            proxNode = atual->prox;
            delete atual;
            atual = proxNode;
        }
    }
    exit(1);
}
int vazia(Enc *LISTA){

    if(LISTA->prox == NULL)
        return 1;
    else
        return 0;
}
/*------------------------------------------------------Fim------------------------------------------------------------------*/
