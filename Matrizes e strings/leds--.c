#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	char led[100];
	int N,i,j,tamanho,qtd=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf(" %99[^\n]", led);
		tamanho = strlen(led);
		qtd=0;
		for(j=0;j<tamanho;j++){
			switch (led[j]){
				case '1':
					qtd+=2;
					break;
				case '2':
					qtd+=5;
					break;
				case '3':
					qtd+=5;
					break;
				case '4':
					qtd+=4;
					break;
				case '5':
					qtd+=5;
					break;
				case '6':
					qtd+=6;
					break;
				case '7':
					qtd+=3;
					break;
				case '8':
					qtd+=7;
					break;
				case '9':
					qtd+=6;
					break;
				case '0':
					qtd+=6;
					break;					
			}			
		}
		printf("%d leds\n",qtd);
	}
	return 0;	
}
