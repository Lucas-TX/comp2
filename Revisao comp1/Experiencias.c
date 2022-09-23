#include<stdio.h>
float porcentagem(float A, float B){
	float P;	
	P=((A/B)*100);	
	return P;
	}

int main(){
	char C='C',R='R',S='S',animal;
	int N,i,coelhos=0,ratos=0,sapos=0,qtd=0,tot=0;
	float pc=0,pr=0,ps=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d\t %c",&qtd,&animal);
		tot+=qtd;
		switch(animal){
			case 'C':
				coelhos+=qtd;				
				break;
			case 'R':
				ratos+=qtd;				
				break;
			case 'S':
				sapos+=qtd;				
				break;
		}				
	}
	pc=porcentagem(coelhos,tot);
	pr=porcentagem(ratos,tot);
	ps=porcentagem(sapos,tot);	
	printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\n",tot,coelhos,ratos,sapos);
	printf("Percentual de coelhos: %.2f %\nPercentual de ratos: %.2f %\nPercentual de sapos: %.2f %",pc,pr,ps);
	return 0;
}
