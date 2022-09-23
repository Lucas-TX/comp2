#include<stdio.h>
void lesenha(int s){	
	while(s!=EOF){
		scanf("%s",&s);
		if(s!='2002'){
			printf("Senha Invalida\n");			
		}
		else{
			printf("Acesso Permitido\n");
			s=EOF;
			
			
		}		
	}
}
int main(){
	int s=0;	
	lesenha(s);
	return 0;
}

