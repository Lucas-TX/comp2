#include <stdio.h>
float media(float x, float y){
	float mp;
	mp=((x*3.5)+(y*7.5))/11;
	return mp;	
}
int main() {
  float a=0,b=0,m=0;
  scanf("%f %f",&a, &b);
  if (((a>=0)&&(a<=10))&&((b>=0)&&(b<=10))){
  	m=media(a,b);  	  	
  }  
  printf("MEDIA = %.5f",m);
  return 0;
}
