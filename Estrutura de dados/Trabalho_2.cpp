//Johny Kwiatkowski Oh - 18/04/2019 - Estrutura de Dados 1.
//Ordena ate o Quick Sort, so falta arrumar o Merge

#include <iostream>
#include <fstream>

using namespace std;

typedef struct nom Nome;
struct seq{
    string nome;
    int RG;
};
typedef struct seq Seq;
struct enc{
    string nome;
    int RG;
    struct enc *prox;
    struct enc *ant;
};
typedef struct enc Enc;

void menu(int *opt, int *tipo);

/*-------------------Sequencial------------------------------*/
Seq *opc(int opt, int *linhas, Seq *vetor, int *m, int *c);
Seq *adcInicio(Seq *vetor, int linhas, string nome, int RG, int *m, int *c);
Seq *adcFinal(Seq *vetor, int linhas, string nome, int RG, int *m, int *c);
Seq *adcMeio(Seq *vetor, int linhas, string nome, int RG, int *m, int *c);
Seq *rmvInicio(Seq *vetor, int linhas, string nome, int RG, int *m, int *c);
Seq *rmvFinal(Seq *vetor, int linhas, string nome, int RG, int *m, int *c);
Seq *rmvMeio(Seq *vetor, int linhas, string nome, int RG, int *m, int *c);
void procurarNome(Seq* vetor, int linhas, int *m, int *c);
void exibeSequencial(Seq *vetor, int linhas);
Seq *lerListaSequencial(int *linhas, int *m, int *c);
void criaTxt(Seq *vetor,int linhas, int *m, int *c);
int qtdLinhas(string& nomeArq);
Seq *selectionSort(Seq *vetor, int linhas, int *m, int *c);
Seq *insertionSort(Seq *vetor, int linhas, int *m, int *c);
Seq *bubbleSort(Seq *vetor, int linhas, int *m, int *c);
Seq *shellSort(Seq *vetor, int linhas, int *m, int *c);
void quickSort(Seq *vetor, int inicio, int fim, int *m, int *c);
void mergeS(Seq *vetor,int inicio, int meio, int fim, int *m, int *c);
void mergeSort(Seq *vetor, int inicio, int fim, int *m, int *c);
//Seq *quickSort(Seq *vetor, int inicio, int fim);
//Seq *mergeSort(Seq *vetor, int inicio,int fim);
/*-------------------Encadeada-------------------------------*/
void inicia(Enc *LISTA);
void opcaoEnc(Enc *LISTA, Enc *FIM, int op, int *m, int *c);
void encadeadaInicio(Enc *LISTA);
void encadeadaFinal(Enc *LISTA, Enc *FIM, int *m, int *c);
void encadeadaMeio(Enc *LISTA, int *m, int *);
Enc *retiraInicio(Enc *LISTA, int *m, int *);
Enc *retiraFim(Enc *LISTA, int *m, int *);
Enc *retiraMeio(Enc *LISTA, int *m, int *);
void procuraPessoa(Enc *LISTA, int *m, int *);
void exibe(Enc *LISTA, int *m, int *);
void lerListaEnc(Enc *LISTA, Enc *FIM, int *m, int *c);
void criaTXT(Enc *LISTA, int *m, int *);
void libera(Enc *LISTA);
int vazia(Enc *LISTA);
void selectionSortEnc(Enc *LISTA);

main(){
/*------------Sequencial--------------*/

    Seq *vetor=new Seq[1];
    int opt, linhas=0, tipo, m, c;

/*------------Encadeada---------------*/

    Enc *LISTA=new Enc;
    Enc *FIM=new Enc;

    if(!LISTA){
        cout << "Sem memoria disponivel!\n";
        exit(1);
    }
    inicia(LISTA);
    inicia(FIM);

/*------------------------------------*/

    do{
        menu(&opt, &tipo);
        if(tipo==1)
            vetor=opc(opt,&linhas,vetor,&m,&c);
        else if(tipo==2)
            opcaoEnc(LISTA,FIM,opt,&m,&c);
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
    cout << "(11) Ordenar RG (Selection Sort)." << endl;
    cout << "(12) Ordenar RG (Insertion Sort)." << endl;
    cout << "(13) Ordenar RG (Bubble Sort)." << endl;
    cout << "(14) Ordenar RG (Shell Sort)." << endl;
    cout << "(15) Ordenar RG (Quick Sort)." << endl;
    cout << "(16) Ordenar RG (Merge Sort)." << endl;
    cout << "(0) Sair do Sistema." << endl;
    cin >> *opt;
}
/*-----------------------------------------------Sequencial-----------------------------------------------------------------*/
Seq* opc(int opt, int *linhas, Seq *vetor, int *m, int *c){
    *m=0;
    *c=0;
    string nome;
    int RG;

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
        exibeSequencial(vetor,*linhas);
    }
    else if(opt==9){
        vetor=lerListaSequencial(linhas,m,c);
    }
    else if (opt==10){
        criaTxt(vetor,*linhas,m,c);
    }
    else if(opt==11){
        vetor=selectionSort(vetor,*linhas,m,c);
    }
    else if(opt==12){
        vetor=insertionSort(vetor,*linhas,m,c);
    }
    else if(opt==13){
        vetor=bubbleSort(vetor,*linhas,m,c);
    }
    else if(opt==14){
        vetor=shellSort(vetor,*linhas,m,c);
    }
    //Eu tava mandando a quantidade de linhas no lugar da posicao final, por isso dava segmentation fault, eu tinha que andar a posicao final que era a quantidade de linhas - 1
    else if(opt==15){
        quickSort(vetor,0,*linhas-1,m,c);
    }
    else if(opt==16){
        mergeSort(vetor,0,*linhas-1,m,c);
    }
    else if(opt==0){
        exit(1);
    }
    cout << "M: " << *m << "\t" << "C: " << *c << endl;

    return vetor;
}
Seq *adcInicio(Seq *vetor, int linhas, string nome, int RG, int *m, int *c){
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
Seq *adcFinal(Seq *vetor, int linhas, string nome, int RG, int *m, int *c){
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
Seq *adcMeio(Seq *vetor, int linhas, string nome, int RG, int *m, int *c){

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
Seq *rmvInicio(Seq *vetor, int linhas, string nome, int RG, int *m, int *c){
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
Seq *rmvFinal(Seq *vetor, int linhas, string nome, int RG, int *m, int *c){
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
Seq *rmvMeio(Seq *vetor, int linhas, string nome, int RG, int *m, int *c){
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
void procurarNome(Seq *vetor, int linhas, int *m, int *c){//Busca binaria
	int i=0, f=linhas-1, meio, RG;

    cout << "Digite o RG para procurar o nome: ";
    cin >> RG;

	while(i<=f){
        *m+=1;
		meio=(i+f)/2;
		if (vetor[meio].RG==RG){
            *c+=1;
			break;
        }
		else {
			if(RG>vetor[meio].RG){
                *c+=1;
                i=meio+1;
            }
			else{
                *c+=1;
				f=meio-1;
            }
		}
	}
	cout << vetor[meio].nome;
}
void exibeSequencial(Seq *vetor, int linhas){
    cout << "Nomes e RG's: \n";
    for(int i=0; i<linhas; i++){
        cout << "Nome: "<< vetor[i].nome << "\tRG: " << vetor[i].RG << endl;
    }
    cout << "\n";
}
Seq *lerListaSequencial(int *linhas, int *m, int *c){
    string nomeArq, linha, temp;

    cout << "Digite o nome do Arquivo que deseja abrir: ";
    cin >> nomeArq;
    ifstream arquivo(nomeArq);

    int i, contador=0, rg;
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
            rg=atoi(temp.c_str());
            novo[contador].RG=rg;
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
Seq *selectionSort(Seq *vetor, int linhas, int *m, int *c){
    int i, j, rgTemp, menor, indice, alavanca;
    string nomeTemp;

    for(i=0;i<linhas;i++){
        *m+=1;
        menor=vetor[i].RG;
        alavanca=0;
        for(j=i;j<linhas;j++){
            if(menor>vetor[j].RG){
                *c+=1;
                menor=vetor[j].RG;
                indice=j;
                alavanca=1;
            }
        }
        if(alavanca==1){
            *c+=1;
            rgTemp=vetor[i].RG;
            nomeTemp=vetor[i].nome;
            vetor[i].RG=vetor[indice].RG;
            vetor[i].nome=vetor[indice].nome;
            vetor[indice].RG=rgTemp;
            vetor[indice].nome=nomeTemp;
        }
    }
    return vetor;
}
Seq *insertionSort(Seq *vetor, int linhas, int *m, int *c){
    int i, j, k, menor, indice, chave;
    string nome;

    for(i=0; i<10; i++){
        *m+=1;
        chave=0;
        menor=vetor[i].RG;
        for(j=i; j<10; j++){
            *m+=1;
            if(menor>vetor[j].RG){
                *c+=1;
                indice=j;
                chave=1;
                menor=vetor[j].RG;
                nome=vetor[j].nome;
            }
        }
        if(chave==1){
            *c+=1;
            for(k=indice; k>i; k--){
                *m+=1;
                vetor[k].RG=vetor[k-1].RG;
                vetor[k].nome=vetor[k-1].nome;
            }
            vetor[i].RG=menor;
            vetor[i].nome=nome;
        }
    }
    return vetor;
}
Seq *bubbleSort(Seq *vetor, int linhas, int *m, int *c){
    int i, j, desorganizada=0, auxRG;
    string auxNome;

    while(desorganizada==0){
        *m+=1;
        desorganizada=1;
        j=1;
        for(i=0;i<linhas-1;i++){
            *m+=1;
            if(vetor[i].RG>vetor[j].RG){
                *c+=1;
                auxRG=vetor[i].RG;
                vetor[i].RG=vetor[j].RG;
                vetor[j].RG=auxRG;
                auxNome=vetor[i].nome;
                vetor[i].nome=vetor[j].nome;
                vetor[j].nome=auxNome;
                desorganizada=0;
            }
            j++;
        }
//        exibeSequencial(vetor,linhas);
    }
    return vetor;
}
Seq *shellSort(Seq *vetor, int linhas, int *m, int *c){
    int i, j, aux;
    int div=1;
    string nome;

    do{
        *m+=1;
        div=3*div+1;
    }while(div<linhas);

    do{
        *m+=1;
        div/=3;
        for(i=div; i<linhas; i++){
            *m+=1;
            aux=vetor[i].RG;
            nome=vetor[i].nome;
            j=i-div;
            while(j>=0 && aux<vetor[j].RG){
                *m+=1;
                vetor[j+div].RG=vetor[j].RG;
                vetor[j+div].nome=vetor[j].nome;
                j-=div;
            }
            vetor[j+div].RG=aux;
            vetor[j+div].nome=nome;
        }
    }while(div>1);

    return vetor;
}
void quickSort(Seq *vetor, int inicio, int fim, int *m, int *c){
    int i = inicio, j = fim;
    int temp;
    int pivo=vetor[(inicio+fim)/2].RG;
    string nome;

    while(i<=j){
        *m+=1;
        while(vetor[i].RG<pivo){
            *m+=1;
            i++;
        }
        while(vetor[j].RG>pivo){
            *m+=1;
            j--;
        }
        if(i<=j){
            *c+=1;
            temp=vetor[i].RG;
            vetor[i].RG = vetor[j].RG;
            vetor[j].RG = temp;
            nome=vetor[i].nome;
            vetor[i].nome=vetor[j].nome;
            vetor[j].nome=nome;
            i++;
            j--;
        }
    }

    if(inicio<j){
        *c+=1;
        quickSort(vetor,inicio,j,m,c);
    }
    if(i<fim){
        *c+=1;
        quickSort(vetor,i,fim,m,c);
    }
}
void mergeS(Seq *vetor, int inicio, int meio, int fim, int *m, int *c){
    int i, j, k;
    int n1=meio-inicio+1;
    int n2=fim-meio;
    Seq *aux=new Seq[fim];
    Seq *aux2=new Seq[fim];

//    int vInicio[n1], vFim[n2];

    for (i=0; i<n1; i++){//Copio para os aux
        *m+=1;
        aux[i].RG=vetor[inicio+i].RG; //
        aux[i].nome=vetor[inicio+i].nome;
    }
    for (j = 0; j < n2; j++){//Copio para a segunda parte do vetor
        *m+=1;
        aux2[j].RG=vetor[meio+1+j].RG; //
        aux2[j].nome=vetor[meio+1+j].nome;
    }

    i=0;
    j=0;
    k=inicio;
    while(i<n1 && j<n2){
        *m+=1;
        if(aux[i].RG<=aux2[j].RG){//problema ta aqui
            *c+=1;
            vetor[k].RG=aux[i].RG;
            vetor[k].nome=aux[i].nome;
            i++;
        }
        else{
            *c+=1;
            vetor[k].RG=aux2[j].RG;
            vetor[k].nome=aux2[j].nome;
            j++;
        }
        k++;
    }

    while(i<n1){//Copio o resto dos elementos se ainda tiver algum
        *m+=1;
        vetor[k].RG=aux[i].RG; //
        vetor[k].nome=aux[i].nome;
        i++;
        k++;
    }
    while(j<n2){
        *m+=1;
        vetor[k].RG=aux2[j].RG; //
        vetor[k].nome=aux2[j].nome;
        j++;
        k++;
    }

    delete []aux;
    delete []aux2;
//    cout << aux[1].nome << " ";
}
void mergeSort(Seq *vetor, int inicio, int fim, int *m, int *c){
    if(inicio<fim){
        *c+=1;
        //Faz a mesma coisa que (inicio+fim)/2, mas ele evita estouros que era onde eu tava errando
        int meio=inicio+(fim-inicio)/2;
        //Sort na primeira e na segunda metade
        mergeSort(vetor,inicio,meio,m,c);//Recursiva
        mergeSort(vetor,meio+1,fim,m,c);//Recursiva

        mergeS(vetor,inicio,meio,fim,m,c);
    }
}
/*-----------------------------------------------Encadeada-----------------------------------------------------------------*/
void inicia(Enc *LISTA){
    LISTA->prox = NULL;
}
void opcaoEnc(Enc *LISTA, Enc *FIM, int opt, int *m, int *c){
    *m=0;
    *c=0;
    if(opt==1)
        encadeadaInicio(LISTA);
    else if(opt==2)
        encadeadaFinal(LISTA,FIM,m,c);
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
        lerListaEnc(LISTA,FIM,m,c);
    else if(opt==10)
        criaTXT(LISTA,m,c);
    else if(opt==11)
        selectionSortEnc(LISTA);

    else if(opt==0)
        libera(LISTA);
    cout << "M: " << *m << "\t" << "C: " << *c << endl;
}
void encadeadaInicio(Enc *LISTA){

    Enc *novo=new Enc;
    Enc *temp = LISTA->prox;

    cout << "Digite o nome e depois RG a ser inserido: ";
    cin >> novo->nome >> novo->RG;

    LISTA->prox=novo;
    novo->prox=temp;
    novo->ant=NULL;
    temp->ant=novo;
}
void encadeadaFinal(Enc *LISTA, Enc *FIM, int *m, int *c){

    Enc *novo=new Enc;

    cout << "Digite o nome e o RG a ser inserido: ";
    cin >> novo->nome >> novo->RG;

    novo->prox = NULL;

    if(vazia(LISTA)){
        LISTA->prox=novo;
        *c+=1;
    }
    else{
        Enc *temp = FIM->prox;
        temp->prox=novo;
        FIM->prox=novo;
        novo->ant=temp;
        novo->prox=NULL;
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
    temp2->ant=novo;
    novo->ant=temp;
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
    temp2=temp2->prox;
    temp2->ant=temp;
}
void procuraPessoa(Enc *LISTA, int *m, int *c){

    int pos=0;
    int numRG;

    cout << "Digite o RG para verificar o nome da Pessoa: ";
    cin >> numRG;

    Enc *temp, *ant;
    temp = LISTA->prox;

    while(temp->prox!=NULL){
        if(numRG==temp->RG){
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
void lerListaEnc(Enc *LISTA, Enc *FIM, int *m, int *c){

    int i, rg;
    string linha, temp, nomeArq;

    cout << "Digite o nome do Arquivo que deseja abrir: ";
    cin >> nomeArq;

    ifstream arquivo(nomeArq);

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
            rg=atoi(temp.c_str());
            novo->RG=rg;
            if(vazia(LISTA)){
                LISTA->prox=novo;
                FIM->prox=novo;
                novo->ant=NULL;
                *c+=1;
            }
            else{
                Enc *temp = FIM->prox;
                temp->prox=novo;
                FIM->prox=novo;
                novo->ant=temp;
                novo->prox=NULL;
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
void selectionSortEnc(Enc *LISTA){
    int i, j, rgTemp, menorInt, indice, alavanca;
    string nomeTemp;

    Enc *andando, *inicial, *menor;
    inicial=LISTA->prox;
    //andando = do tipo struct que vai andando e verificando se ha outro valor menor
    //inicial = guarda a cabeca da lista
    //menorInt = menor do tipo inteiro que vai ir verificando qual rg eh o menor
    //menor = do tipo struct vai guardar o noh com o menor valor
    for(i=0;i<10;i++){
        andando=inicial;
        menorInt=inicial->RG;
        alavanca=0;
//        *m+=1;
        for(j=i;j<10;j++){
            if(menorInt>andando->RG){
//                *c+=1;
                menorInt=andando->RG;
                menor=andando;
                alavanca=1;
            }
            andando=andando->prox;
        }
        if(alavanca==1){
            rgTemp=inicial->RG;
            nomeTemp=inicial->nome;
            inicial->RG=menor->RG;
            inicial->nome=menor->nome;
            menor->RG=rgTemp;
            menor->nome=nomeTemp;
//            *c+=1;
        }
        inicial=inicial->prox;
    }
}

/*------------------------------------------------------Fim------------------------------------------------------------------*/
/* NomeRG10.txt
Paulo,   82475249
Ricardo, 84943658
Luiza,   70211272
Carla,   57850878
Paula,   7237709
Luiza,   15438165
Ana,     74243042
Paulo,   37522503
Ricardo, 16531729
Claudia, 43542612


Sorted:

Paula
Luiza
Ricardo
Paulo
Claudia
Carla
Luiza
Ana
Paulo
Ricardo

*/
