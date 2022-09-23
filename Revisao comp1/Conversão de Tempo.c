#include <stdio.h>
void escrevehora(int H,int M,int S){
	printf("%d:%d:%d",H,M,S);	
}

int main() {
  int N,hora,min,seg;
  scanf("%d",&N);
  min=N/60;
  seg=N%60;  
  if(min>=60){
    hora=min/60;
    min=min%60;
  }
  else{
    hora=0;
  }
  escrevehora(hora,min,seg);  
  return 0;
}
