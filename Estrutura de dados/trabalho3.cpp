#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct palavra{
    string palavra;
    int inicio;
};
typedef struct palavra Pa;

Pa *lerArquivo(Pa *vetor);
void exibe(Pa *vetor);

main(){
    Pa *vetor=new Pa[50000];

    vetor=lerArquivo(vetor);
    cout << " a\n ";
    exibe(vetor);
}
Pa *lerArquivo(Pa *vetor){
    string nomeArq, linha;

    cout << "Digite o nome do Arquivo que deseja abrir: ";
    cin >> nomeArq;

    ifstream arquivo(nomeArq);

    int i, k=0, inicio=0;
    string temp;

    if(arquivo.is_open()){
        while(getline(arquivo,linha)){
            for(i=0; i<linha.size(); i++){
                if(linha[i]!=' '){
                    vetor[i].palavra=temp;
                    vetor[i].inicio=inicio;
                    i++;
                }
            }
        }
    }
}
void exibe(Pa *vetor){
    for(int i=0;i<50;i++){
        cout << vetor[i].palavra << "  " << vetor[i].inicio << endl;
    }
}
