#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int TOTAL_CONSUMO_MEMORIA = 0;
int MAX_TOTAL_CONSUMO_MEMORIA = 256000;

void exibirMemoriaConsumida();
void salvarMemoria(int memoria, int situacao);

int main() {
	printf("Rubens de Oliveira Silva\n");
	printf("***Compilador***\n\n");
	
	// abrindo arquivo
	FILE *fp;
    fp = fopen("meu-arquivo-teste.txt", "r");
    if (fp == NULL) {
    	printf ("Houve um erro ao abrir o arquivo.\n");
    	return 1;
    }
    
    // imprindo linhas do arquivo
    int i;
    int numeroLinha = 0;
    int ascii;
    
    char conteudoLinha[500];
    
    salvarMemoria(sizeof(i), 1);
    salvarMemoria(sizeof(numeroLinha), 1);
    salvarMemoria(sizeof(ascii), 1);
    salvarMemoria(sizeof(fp), 1);
    salvarMemoria(sizeof(conteudoLinha), 1);
    
    // limpando lixo memório
    for(i = 0; i < 500; i++) {
    	conteudoLinha[i] = '\0';    	
	}
    
	if (fp != NULL) {
		while ((fgets(conteudoLinha, sizeof(conteudoLinha), fp)) != NULL) {
			numeroLinha++;
//			printf("%s", conteudoLinha);
			for(i = 0; i < strlen(conteudoLinha); i++) {
				ascii = (int) conteudoLinha[i];
				
				// verifica se pertence a tabela de literais
				// a-z, A-Z, 0-9 => 97-122, 65-90, 48-57
				// +, -, *, /, %, ^, _ => 43, 45, 42, 47, 37, 94, 95
				// (), [], {}, # => 40, 41, 91, 93, 123, 125, 35 
				// ;, virgula => 59, 44
				// =, <, >, !, espaco => 61, 60, 62, 33, 32
				// tab, quebra linha => 9, 10, 13
				if (
					! (ascii >= 97 && ascii <= 122) &&
					! (ascii >= 65 && ascii <= 90)  &&
					! (ascii >= 48 && ascii <= 57) &&
					(ascii != 43) && (ascii != 45) && (ascii != 42) && (ascii != 47) && (ascii != 37) && (ascii != 94) && (ascii != 95) &&
					(ascii != 40) && (ascii != 41) && (ascii != 91) && (ascii != 93) && (ascii != 123) && (ascii != 125) && (ascii != 35) &&
					(ascii != 59) && (ascii != 44) &&
					(ascii != 61) && (ascii != 60) && (ascii != 62) && (ascii != 33) && (ascii != 32) &&
					(ascii != 9) && (ascii != 10) && (ascii != 13)
				) {
					printf("O caracter (%c) NAO pertence a tabela de literais\n", (char) ascii);
					exit(0);
				}
				
				printf("%i - %i - %c\n", numeroLinha, ascii, conteudoLinha[i]);
    			
			}
			printf("%i\n", numeroLinha);
        }
	}
    fclose(fp);
	exibirMemoriaConsumida();
		
}

void salvarMemoria(int memoria, int situacao) {
	if (situacao == 1) {
		TOTAL_CONSUMO_MEMORIA = TOTAL_CONSUMO_MEMORIA + memoria;
	} else {
		TOTAL_CONSUMO_MEMORIA = TOTAL_CONSUMO_MEMORIA - memoria;
	}

	float porcentagem = 0;
	if (MAX_TOTAL_CONSUMO_MEMORIA > 0) {
		porcentagem = (TOTAL_CONSUMO_MEMORIA * 100) / MAX_TOTAL_CONSUMO_MEMORIA;
	}

	if (porcentagem > 90 && porcentagem < 99) {
		printf("Sua memoria esta entre 90 %% a 99 %% do total disponível, memoria atual: %.2f %%\n\n", porcentagem);
	}

	if (TOTAL_CONSUMO_MEMORIA > MAX_TOTAL_CONSUMO_MEMORIA) {
		printf ("Memoria ultrapassou o limite disponivel.\n");
		exibirMemoriaConsumida();
		exit(0);
	}
}

void exibirMemoriaConsumida() {
	printf("\n---------------------------------------------------------------------\n");
	printf("\nCONSUMO DE MEMORIA: %d bytes\n\n", TOTAL_CONSUMO_MEMORIA);
	float porcentagem = 0;
	if (MAX_TOTAL_CONSUMO_MEMORIA > 0) {
		porcentagem = (TOTAL_CONSUMO_MEMORIA * 100) / MAX_TOTAL_CONSUMO_MEMORIA;
	}	 

	printf("Porcentagem consumida => %.2f %% de %i bytes\n\n" , porcentagem, MAX_TOTAL_CONSUMO_MEMORIA);
}

