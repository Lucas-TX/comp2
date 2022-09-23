#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int N=0,k=99,i,j,cmp;
	char a[20]="0";
	char b[20]="0";	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		cmp=0;
		scanf("%d",&k);			
		if((k>=2)||(k<=100)){					
			scanf("%s",a);			
			for(j=1;j<k;j++){			
				scanf("%s",b);				
				cmp = strcmp(a,b);
				strcpy(a,b);
			}
			if(cmp==0){
				printf("%s\n",a);			
			}
			else{
				printf("ingles\n");
			}
		}
		else{
			N+=1;
		}
	}
	return 0;	
}
