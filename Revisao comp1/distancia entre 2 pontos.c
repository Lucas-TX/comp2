#include <stdio.h>
#include <math.h>

double raiz (double x){
	double b;
	b=sqrt(x);
	return b;
}

int main(){
	float x1,x2,y1,y2;
	double distancia,x;
	scanf("%f %f \n %f %f", &x1,&y1, &x2,&y2);
	x=(pow(x2-x1,2))+(pow(y2-y1,2));
	distancia=raiz(x);
	printf("%.4lf",distancia);
	return 0;

}
