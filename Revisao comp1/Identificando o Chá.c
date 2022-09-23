#include<stdio.h>
int main(){
	int T,i,resp,cont=0;
	scanf("%d",&T);
	for(i=0;i<5;i++){
		scanf("%d",&resp);
		if(resp==T){
			cont+=1;
		}
	}
	printf("%d",cont);	
	return 0;
}
