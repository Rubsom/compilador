#include<stdio.h>
#include<stdlib.h>

void lerArquivo(int *vet);

main()
{
	int vet[15]; //veotr local
	
	
	printf("Arquivo lido com sucesso");
	
	
	system("PAUSE");
	return 0;
}

//fun��o auxiliar 
void lerArquivo(int *vet)
{
	
	char i = 0;				//vari�vel auxiliar de itera��o
	
	FILE *arquivo;			//ponteiro para arquivo
	
	arquivo = fopen("C:\\Users\\Extra\\Google Drive\\ENGENHARIA DE COMPUTA��O\\9� Per�odo\\Compiladores\\1VAarquivo.txt", "r");
	
	for(i=0; i<15; i++) fscan(arquivo, "%d\n", &vet[i]);
	
	arquivo = fopen("teste02.txt", "w");
	
	for(i=0; i<15; i++) fprint(arquivo, "%d\n", vet[i]+2);
	
	fclose(arquivo);
}
