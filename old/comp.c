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

//função auxiliar 
void lerArquivo(int *vet)
{
	
	char i = 0;				//variável auxiliar de iteração
	
	FILE *arquivo;			//ponteiro para arquivo
	
	arquivo = fopen("C:\\Users\\Extra\\Google Drive\\ENGENHARIA DE COMPUTAÇÃO\\9° Período\\Compiladores\\1VAarquivo.txt", "r");
	
	for(i=0; i<15; i++) fscan(arquivo, "%d\n", &vet[i]);
	
	arquivo = fopen("teste02.txt", "w");
	
	for(i=0; i<15; i++) fprint(arquivo, "%d\n", vet[i]+2);
	
	fclose(arquivo);
}
