#include <stdio.h>
int duracao(int a, int b){
  int d;
  if(a<b){
    return b-a;
  }
  else{
    return (24-a)+b;  
  }
}
int main(){
  int i,f,du;
  do{
    scanf("%d",&i);
  }while((i<0)||(i>23));
  do{
    scanf("%d",&f);
  }while((f<0)||(f>23));  
  if(i==f){
    du=24;
    printf("O JOGO DUROU %d HORA(S)",du);
  }
  else{
    du=duracao(i,f);
    printf("O JOGO DUROU %d HORA(S)",du);
  }  
  return 0;
}
