#include <stdio.h>
int produto(int a, int b){
	int PROD;
	PROD=a*b;
	return PROD;
}

int main() {
  int x,y,pr;
  scanf("%d \n %d",&x,&y);
  pr=produto(x,y);
  printf("PROD = %d",pr);
  return 0;
}
