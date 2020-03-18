/* Verificar se a junção de caracteres, utilizando os delimitadores de cada estrutura, forma algum token válido 
- classifica-lo, se for um identificador de usuário inseri-lo na tabela de símbolos (É importante verificar se 
já não existe na tabela de símbolos.). Se em algum momento encontrar uma palavra que não se encaixa em uma das 
classificações de token válidos é necessário finalizar a execução e mostrar o erro conforme especificação.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int TOTAL_CONSUMO_MEMORIA = 0;
int MAX_TOTAL_CONSUMO_MEMORIA = 256000;

typedef struct simbolo {
	char tipo_dado[500];
    char nome_variavel[500];
    char possivel_valor[500];
} Simbolo;

typedef struct elemSimbolo {
    Simbolo dados;
    struct elemSimbolo *prox;
} ElemSimbolo;

typedef struct elemSimbolo* TabelaSimbolo;

void exibirMemoriaConsumida();
void salvarMemoria(int memoria, int situacao);
TabelaSimbolo* criaListaTabelaSimbolo();
int insereFinalTabelaSimbolo(TabelaSimbolo* lista, Simbolo simbolo);
int tamanhoTabelaSimbolo(TabelaSimbolo* lista);
int isVazioTabelaSimbolo(TabelaSimbolo* lista);
void imprimeTabelaSimbolo(TabelaSimbolo* lista);
void atualizarValorVariavel(TabelaSimbolo* simbolos, char *variavel, char *valor);
int isVerificaExistenciaVariavel(char *variavel, TabelaSimbolo* simbolos);
void limparString(char vetor[]);
void removePalavrasComAspas(char *palavra, char *palavraComAspas);

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
    int countTmp = 0;
    
    char conteudoLinha[500];
    char linhaTmp[500];
    char conteudoAspas[500];
	char reservadas[] = {"main", "puts", "gets", "if", "else", "for", "integer", "string", "decimal"};
        
    salvarMemoria(sizeof(i), 1);
    salvarMemoria(sizeof(numeroLinha), 1);
    salvarMemoria(sizeof(ascii), 1);
    salvarMemoria(sizeof(fp), 1);
    salvarMemoria(sizeof(conteudoLinha), 1);
    salvarMemoria(sizeof(linhaTmp), 1);
    salvarMemoria(sizeof(conteudoAspas), 1);
    
    // limpando lixo memório
    for(i = 0; i < 500; i++) {
    	conteudoLinha[i] = '\0';
    	linhaTmp[i] = '\0';
    	conteudoAspas[i] = '\0';
	}
    
	if (fp != NULL) {
		while ((fgets(conteudoLinha, sizeof(conteudoLinha), fp)) != NULL) {
			numeroLinha++;
			removePalavrasComAspas(conteudoLinha, conteudoAspas);
			//printf("%s", conteudoLinha);
			
			for(i = 0; i < strlen(conteudoLinha); i++) {
				ascii = (int) conteudoLinha[i];
				
				// verifica se pertence a tabela de literais
				// a-z, A-Z, 0-9 => 97-122, 65-90, 48-57
				// +, -, *, /, %, ^, _ => 43, 45, 42, 47, 37, 94, 95
				// (), [], {}, # => 40, 41, 91, 93, 123, 125, 35 
				// ;, virgula => 59, 44
				// =, <, >, !, espaco => 61, 60, 62, 33, 32
				// tab, quebra linha, ponto, " => 9, 10, 13, 46, 34
				if (
					! (ascii >= 97 && ascii <= 122) &&
					! (ascii >= 65 && ascii <= 90)  &&
					! (ascii >= 48 && ascii <= 57) &&
					(ascii != 43) && (ascii != 45) && (ascii != 42) && (ascii != 47) && (ascii != 37) && (ascii != 94) && (ascii != 95) &&
					(ascii != 40) && (ascii != 41) && (ascii != 91) && (ascii != 93) && (ascii != 123) && (ascii != 125) && (ascii != 35) &&
					(ascii != 59) && (ascii != 44) &&
					(ascii != 61) && (ascii != 60) && (ascii != 62) && (ascii != 33) && (ascii != 32) &&
					(ascii != 9) && (ascii != 10) && (ascii != 13) && (ascii != 46) && (ascii != 34)
				) {
					printf("O caracter (%c) NAO pertence a tabela de literais\n", (char) ascii);
					exit(0);
				}
				
				// validar palavras validas
				// Mapear condiçao de parada 
				// espaco, (, ), [, ], {, }, " =>  32, 40, 41, 91, 93, 123, 125, 34  
				// NULL, ponto, quebra de linha, _, -, ; => 0, 46, 10, 13, 45, 95, 59
				// !, <, >, =, virgula => 33, 60, 61, 62, 44
				
				if (
					(ascii != 32) && (ascii != 40) && (ascii != 41) && (ascii != 91) && (ascii != 93) && (ascii != 123) && (ascii != 125) && (ascii != 34) &&
					(ascii != 0) && (ascii != 46) && (ascii != 10) && (ascii != 13) && (ascii != 45) && (ascii != 95) && (ascii != 59) &&
					(ascii != 33) && (ascii != 60) && (ascii != 61) && (ascii != 62) && (ascii != 44) 
				) {
					linhaTmp[countTmp] = (char) ascii;
					//printf("%i - (%c) - (%s)\n", ascii, (char) ascii, linhaTmp);
					countTmp++;
						
				} else {
					printf("Condicao => %i - %i - (%c) - (%s) \n", numeroLinha, ascii, (char) ascii, linhaTmp);
					
					// verifica se e uma palavra reservada
					isPalavraReservada = 0;
					for (j = 0, j <= 9, j++ ) {
						if (strcmp(palavra, reservadas[i]) == 0) {
							
						}
					}
					
					
					// verifica se e uma variavel
					
					//
					
					
					limparString(linhaTmp);
					countTmp = 0;
				}
				
				// printf("%i - %i - %c\n", numeroLinha, ascii, conteudoLinha[i]);
    			
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

void removePalavrasComAspas(char *palavra, char *palavraComAspas) {

	int i, valorAscii, countPalavra = 0, countPalavraValida = 0, isPossuiAspas = 0;

	char palavraComConteudoAspas[500];
	char palavraSemConteudoAspas[500];

	salvarMemoria(sizeof(i), 1);
	salvarMemoria(sizeof(valorAscii), 1);
	salvarMemoria(sizeof(countPalavra), 1);
	salvarMemoria(sizeof(countPalavraValida), 1);
	salvarMemoria(sizeof(isPossuiAspas), 1);
	salvarMemoria(sizeof(palavraComConteudoAspas), 1);
	salvarMemoria(sizeof(palavraSemConteudoAspas), 1);

	limparString(palavraComConteudoAspas);
	limparString(palavraSemConteudoAspas);
	limparString(palavraComAspas);

	for (i = 0; i < strlen(palavra); i++) {

		valorAscii = (int) palavra[i];

		if (isPossuiAspas == 0 && valorAscii == 34) {
			isPossuiAspas = 1;
			palavraComConteudoAspas[countPalavra] = palavra[i];
			countPalavra++;
			continue;
		}

		if (isPossuiAspas > 0 && valorAscii != 34) {
			palavraComConteudoAspas[countPalavra] = palavra[i];
			countPalavra++;
			continue;
		}

		if (isPossuiAspas == 1 && valorAscii == 34) {
			palavraComConteudoAspas[countPalavra] = palavra[i];
			countPalavra++;
			isPossuiAspas = 0;
			continue;
		}

		if ((isPossuiAspas == 0)) {
			palavraSemConteudoAspas[countPalavraValida] = palavra[i];
			countPalavraValida++;
		}
	}

	strcpy(palavra, palavraSemConteudoAspas);
	strcpy(palavraComAspas, palavraComConteudoAspas);
}

TabelaSimbolo* criaListaTabelaSimbolo() {
    TabelaSimbolo* lista = (TabelaSimbolo*) malloc(sizeof(TabelaSimbolo));

    if (lista != NULL) {
        *lista = NULL;
    }

    return lista;
}

void liberaListaTabelaSimbolo(TabelaSimbolo* lista) {
    if (lista != NULL) {
        ElemSimbolo* no;

        while ((*lista) != NULL) {
            no = *lista;
            *lista = (*lista)->prox;
            free(no);
        }

        free(lista);
    }
}

int insereFinalTabelaSimbolo(TabelaSimbolo* lista, Simbolo simbolo) {
    if (lista == NULL) {
        return 0;
    }

    ElemSimbolo *no;
    no = (ElemSimbolo*) malloc(sizeof(ElemSimbolo));
    if (no == NULL) {
        return 0;
    }

    no->dados = simbolo;
    no->prox = NULL;

    // lista vazia: insere inicio
    if ((*lista) == NULL) {
        *lista = no;
    } else {
        ElemSimbolo *aux;
        aux = *lista;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = no;
    }
    return 1;
}

int tamanhoTabelaSimbolo(TabelaSimbolo* lista) {
    if (lista == NULL) {
        return 0;
    }

    int cont = 0;
    ElemSimbolo* no = *lista;

    while (no != NULL) {
        cont++;
        no = no->prox;
    }

    return cont;
}

int isVazioTabelaSimbolo(TabelaSimbolo* lista) {
	int isVazio = 0;

    if (lista == NULL) {
        isVazio = 1;
    }

    if (*lista == NULL) {
        isVazio = 1;
    }

    return isVazio;
}

void imprimeTabelaSimbolo(TabelaSimbolo* lista) {
    if (lista == NULL) {
        return;
    }

    printf("====================================================================\n");
    printf("# TABELA DE SIMBOLOS \n");
    printf("====================================================================\n");

    ElemSimbolo* no = *lista;

    if (isVazioTabelaSimbolo(lista)) {
    	printf("# A TABELA DE SIMBOLOS ESTA VAZIA.\n");
    	printf("====================================================================\n\n");
	}

    while (no != NULL) {
        printf("TIPO DE DADO: %s \n", no->dados.tipo_dado);
        printf("NOME DA VARIAVEL: %s \n", no->dados.nome_variavel);
		printf("POSSIVEL VALOR: (ainda nao esta tratando atribuicao) \n");
        printf("====================================================================\n");
        no = no->prox;
    }
}

void limparString(char vetor[]) {
	int i = 0;

	while (i < 500) {
		vetor[i] = '\0';
		i ++;
	}
}

