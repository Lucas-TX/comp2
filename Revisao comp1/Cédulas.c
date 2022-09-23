#include<stdio.h>
int lenumero(){
	int N;
	do{
		scanf("%d",&N);		
	}
	while((N<0)||(N>1000000));
	return N;	
}

int main(){
	int N,qtd,resto,resto2;
	N=lenumero();	
	printf("%d\n",N);
	qtd=N/100;
	printf("%d nota(s) de R$ 100,00\n",qtd);
	resto=N%100;
	qtd=resto/50;
	printf("%d nota(s) de R$ 50,00\n",qtd);
	resto2=resto%50;
	qtd=resto2/20;
	printf("%d nota(s) de R$ 20,00\n",qtd);
	resto=resto2%20;
	qtd=resto/10;
	printf("%d nota(s) de R$ 10,00\n",qtd);
	resto2=resto%10;
	qtd=resto/5;
	printf("%d nota(s) de R$ 5,00\n",qtd);
	resto2=resto%5;
	qtd=resto2/2;
	printf("%d nota(s) de R$ 2,00\n",qtd);
	resto=resto2%2;
	printf("%d nota(s) de R$ 1,00\n",resto);	
	return 0;
}
