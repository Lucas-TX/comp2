#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void lermatriz(int mat[n][m], int m, int n){
	int i,j;
	for(i=0; i<m; i++){
		for (j=0;j<n; j++){			
			scanf("%d", &mat[i][j]);			
		}		
	}		
}
void mostramatriz(int mat[n][m], int m, int n){
	int i,j;
	for(i=0; i<m; i++) {
		for ( j=0;j<n; j++) {
		printf("\t%d", mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int i,j,n,m;	
	int P[n][m];
	scanf("%d%d",&n,&m);
	lermatriz(P,n,m);
		
	mostramatriz(P,N,M);
/*	
	
	lermatriz(P,n,m);	
	mostramatriz(P,n,m);
*/
	
	
	return 0;

	
	
}
