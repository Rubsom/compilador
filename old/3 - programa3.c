#include <stdio.h>

int divisao(int a, int b){
	int c;
	if (b==0)
		printf("Não é possível fazer esta divisão");
	else { 
		c=(float)a/b;
		printf("%i / %i = %i", a, b, c);
	}
}
int main(){
	int a,b, c = 10;
	
	printf("Informe o valor de a=>  ");
	scanf ("%f", &a);
	
	
	printf("Informe o valor de b=>  ");
	scanf ("%f", &b);
	divisao(a,b);
	
	/*if(a<b+c){
		printf("verdade");
		}
		else printf("falso");
	
	*/
}
	
	
	
