#include <stdio.h>
	#include <stdlib.h>
	
	int* uniao_vetores(int* a, int* b, int tam_a, int tam_b) {
		int i;
	  a = realloc(a, (tam_a + tam_b) * sizeof *a);
	  for ( i = tam_a; i<(tam_a + tam_b); i++){
	    a[i] = b[i-tam_a];
	  }
	  return a;
	}
	
	int main(void) {
		int i;
	  int* a = NULL;
	  int* b = NULL;
	  a = malloc (5 * sizeof *a);
	  if (a == NULL) {
	    printf("Erro ao alocar memória!\n");
	    exit(EXIT_FAILURE);
	  }
	  a[0] = 10;
	  a[1] = 12;
	  a[2] = 15;
	  a[3] = 18;
	  a[4] = 21;
	
	  b = malloc (5 * sizeof *b);
	  if (b == NULL) {
	    printf("Erro ao alocar memória!\n");
	    exit(EXIT_FAILURE);
	  }
	  b[0] = 20;
	  b[1] = 22;
	  b[2] = 25;
	  b[3] = 28;
	  b[4] = 31;
	
	  a = uniao_vetores(a, b, 5, 5);
	  free(b);
	  b=NULL;
	
	  for(i=0; i<10; i++){
	    printf("%d ", a[i]);
	  }
	  printf("\n");
	  return 0;
}
