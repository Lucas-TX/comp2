#include <stdio.h>
#include <stdlib.h>

void lermatriz(int*** mat, int m, int n, int o){
   for(int i=0; i<m; i++)
     for (int j=0;j<n; j++)
       for (int k=0;k<o; k++)
         scanf("%d", &mat[i][j][k]);
}

void mostramatriz(int*** mat, int m, int n, int o){
   for(int i=0; i<m; i++){
     for (int j=0;j<n; j++){
       for (int k=0;k<o; k++){
           printf("\t%d", mat[i][j][k]);   
       }
       printf("\n");
    }
    printf("\n");
  }
}


int main () {

  int m, n, o;
  int i, j;
  int*** mat = NULL;
  scanf("%d %d %d", &m, &n, &o);
  mat = (int ***) malloc (m*sizeof(int**));
  for (i=0; i<m; i++){
    mat[i] = (int**) malloc (n*sizeof(int*));
    for (j=0;j<n;j++){
      mat[i][j] = (int*) malloc (o*sizeof(int));
    }
  }
  
  lermatriz(mat, m, n, o);
  mostramatriz(mat, m, n, o);

  for (i=0; i<m; i++){
    for (j=0;j<n;j++){
      free(mat[i][j]);
      mat[i][j] = NULL;
    }
    free(mat[i]);
    mat[i] = NULL;
  }
  free(mat);
  mat = NULL;
  return 0;
}

