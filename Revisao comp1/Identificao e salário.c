#include <stdio.h>
float salario(int b, float c){
	float sal;
	sal=b*c;
	return sal;	
}

int main() {
  int id, horas;
  float salphora, sal;
  scanf("%d \n %d \n %f", &id,&horas,&salphora);
  sal=salario(horas,salphora);
  printf("NUMBER = %d \nSALARY = U$ %.2f", id, sal);
  return 0;
}
