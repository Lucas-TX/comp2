#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
// olhar funcao leia.

struct ponto{
	double x;
	double y;	
};
typedef struct ponto Ponto;

struct triangulo{
	Ponto a;
	Ponto b;
	Ponto c;
};
typedef struct triangulo Triangulo;

struct poligono{
	Ponto pol [10];
	int qtdp;
};
typedef struct poligono Poligono;

double perimetro (Triangulo t){
	double p;
	p = sqrt(pow((t.a.y)-(t.c.y),2) + pow((t.a.x)-(t.c.x),2));
	p += sqrt(pow((t.a.y)-(t.b.y),2) + pow((t.a.x)-(t.b.x),2));
	p += sqrt(pow((t.b.y)-(t.c.y),2) + pow((t.b.x)-(t.c.x),2));
	return p;	
}

Triangulo retangulo (double b, double h){
	Triangulo tret;
	tret.a.x = 0;
	tret.a.y = 0;
	tret.b.x = b;
	tret.b.y = 0;
	tret.c.x = 0;
	tret.c.y = h;	
	return tret;	
}

void translacao(Triangulo *t, Ponto p){
	t->a.x += p.x; 
	t->a.y += p.y;
	t->b.x += p.x;
	t->b.y += p.y;
	t->c.x += p.x;
	t->c.y += p.y;	
}

Poligono* leia (int n){
	int i;
	Poligono *poligono;
	poligono->qtdp = n;
	for (i = 0; i<n; i++){
		scanf("%lf",&poligono->pol[i].x);
		scanf("%lf",&poligono->pol[i].y);		
	}
	return *poligono;
}


int main (){
	setlocale(LC_ALL, "");
	double peri,base,haltura,n;
	Ponto deslocamento;
	Poligono* poligono;
	Triangulo t;
	t = retangulo(base,haltura);
	peri = perimetro (t);
	printf("%lf",peri);
	translacao( &t, deslocamento);
	poligono = leia (n);
	return 0;	
}
