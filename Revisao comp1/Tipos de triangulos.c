#include <stdio.h>

void troca(float* x, float* y){
  float z = *x;
  *x = *y;
  *y = z;
}
	
void ordenade(float* a, float* b, float* c){
  if (*a < *b) {
   troca(a, b);    
  }
  if (*b < *c) {
    troca(b, c);    
  }
  if (*a < *b) {
    troca(a, b);    
  }
}

int main() {
  float A,B,C;
  scanf("%f %f %f", &A,&B,&C);   
  ordenade(&A,&B,&C);
  if(A>=(B+C)){
    printf("NAO FORMA TRIANGULO\n");
  }
  else if((A*A)==((B*B)+(C*C))){
    printf("TRIANGULO RETANGULO\n");
  }
  else if((A*A)>((B*B)+(C*C))){
    printf("TRIANGULO OBTUSANGULO\n");    
  }
  else if((A*A)<((B*B)+(C*C))){
    printf("TRIANGULO ACUTANGULO\n");   
  }
  if(A==B){
    if(B==C){
      printf("TRIANGULO EQUILATERO\n");      
    }
    else{
      printf("TRIANGULO ISOSCELES\n");      
    }
  }
  else if(A==C){
    if(B!=C){
      printf("TRIANGULO ISOSCELES\n");
    }else{
      printf("TRIANGULO EQUILATERO\n");
    }
  }
  else if(B==C){
    if(A==B){
      printf("TRIANGULO EQUILATERO\n");
    }
    else{
      printf("TRIANGULO ISOSCELES\n");
    }
  }
  return 0;
}
