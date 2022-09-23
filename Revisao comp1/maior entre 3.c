#include <stdio.h>
#include <stdlib.h>
int maiorentretres(int A, int B, int C){
	int maiorAB, maiorABC;
	maiorAB=(A+B+abs(A-B))/2;
    maiorABC=(maiorAB+C+abs(maiorAB-C))/2;
    return maiorABC;    	
}

int main() {
 int A,B,C,maiorABC;
 scanf("%d %d %d",&A,&B,&C);
 maiorABC=maiorentretres (A,B,C); 
 printf("%d eh o maior",maiorABC);
  return 0;
}
