#include <stdio.h>
#include <math.h>
double delta(float a, float b, float c){
	double D,x;	
	x=(pow(b,2))-(4*a*c);  
	if(x>=0){
		D=sqrt(x);	
		return D;
	}
	else{// qunado D<0;				
		return x;
	}			
}

void bhaskara(float a,float b, float c,double *R1, double *R2, double*D){//endereco de r1 e r2 estão nos ponteiros R1 e R2;
	double DE;
	DE=delta(a,b,c);
	*D=DE;
    *R1=(((-1)*b)+(DE))/(2*a);//resultado altera o conteudo de R1 e R2, ou seja, altera o r1 e r2;
    *R2=(((-1)*b)-(DE))/(2*a);
    }		


int main(){
	float x,y,z;
	double r1=0,r2=0,d=0;	
	scanf("%f %f %f",&x, &y, &z);			
	if(x==0){
		printf("Impossivel calcular");
		return 0;
	}
	bhaskara(x,y,z,&r1,&r2,&d);
	if(d<=0)
	{
		printf("Impossivel calcular");		
		return 0;
	}
	else{
		printf("R1 = %.5lf\nR2 = %.5lf",r1,r2);		
	}
	return 0;		
}
