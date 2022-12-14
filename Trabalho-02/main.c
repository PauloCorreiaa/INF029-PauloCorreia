#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"

int menu();
//void dobrar(int *x);

int menu(){
	int op;
	
	linha('*', 11);
	putchar('\n');
	printf("\nTabela de registros\n");	
	putchar('\n');
	printf("[0] - Sair\n");
	printf("[1] - Inserir\n");
	printf("[2] - Excluir\n");
	//printf("[3] - Listar uma estrutura\n");
	/*printf("4 - Dobrar Numero\n");
	printf("5 - \n");*/
	__fpurge(stdin);
	printf("\nDigite sua opção = ");
	__fpurge(stdin);
	scanf("%d ", &op);

	return op;
}

int main(){
	int op, confirma;
	int tam_usuario, valor_usuario;
	int ret, sair = 0;
	
	putchar('\n');
	linha('*', 11);
	inicializar();	
	
	while(!sair)
	{
		op = menu();
		switch (op){
			case 0:{
				sair = 1;
				putchar('\n');
				linha('*', 11);
				putchar('\n');
				finalizar();
				linha('*', 11);
				putchar('\n');
				break;
			}
			
			//inserir novo elemento								
			case 1:{ 
				__fpurge(stdin);
				printf("Posição no vetor principal = ");
				scanf("%d", &tam_usuario);
				__fpurge(stdin);
				printf("Novo elemento = ");
				scanf("%d", &valor_usuario);
					
				ret = inserirNumeroEmEstrutura(tam_usuario, valor_usuario);
								
				//validações
				if (ret == POSICAO_INVALIDA)
					printf("\nPosição inválida.");
				else
					if (ret == SEM_ESTRUTURA_AUXILIAR){
					printf("\nSem estrutura auxiliar.");
						//criar nova estrutura								
						__fpurge(stdin);
						printf("\nCriar nova estrutura?");
						printf("\n\t[0] - Sair");
						printf("\n\t[1] - Criar");
						printf("\nDigite sua opção = ");
						scanf("%d", &confirma);
		
						switch(confirma){
							case 0:{
								break;
							}
		
							case 1:{
								ret = inserirNumeroEmEstrutura(tam_usuario, valor_usuario);								
								//validação
								if (ret == SUCESSO)
									printf("Inserido com sucesso");									
									else if (ret == SEM_ESPACO)
										printf("\nSem Espaço");
							}
						}
					}
				break;
			}
	
			case 2:
			{ //excluir
				__fpurge(stdin);
				printf("Posição no vetor principal =");
				scanf("%d", &tam_usuario);
				__fpurge(stdin);
				printf("Elemento para exclusão =");
				scanf("%d", &valor_usuario);
					
				ret = excluirNumeroEspecificoDeEstrutura(tam_usuario, valor_usuario);
								
				//validações
				if (ret == POSICAO_INVALIDA)
					printf("\nPosição inválida.");
					else if (ret == SEM_ESTRUTURA_AUXILIAR)
						printf("\nSem estrutura auxiliar.");
					else if (ret == ESTRUTURA_AUXILIAR_VAZIA)
						printf("\nEstrutura auxiliar vazia.");				
					else if (ret == SUCESSO)
						printf("Inserido com sucesso");
				
				break;
			}
	
			case 3:
			{ //listar dados estrutura auxiliar
				int tam_usuario, retorno;
				printf("Posição no vetor principal =");
				scanf("%d", &tam_usuario);

				int qtd = getQuantidadeElementosEstruturaAuxiliar(tam_usuario);

				//validações
				if (qtd == POSICAO_INVALIDA)
					printf("\nPosição inválida.");
					else if (qtd == SEM_ESTRUTURA_AUXILIAR)
						printf("\nSem estrutura auxiliar.");
					else if (qtd == ESTRUTURA_AUXILIAR_VAZIA)
						printf("\nEstrutura auxiliar vazia.");					
					
				//listar estrutura auxiliar
				else{ 
					int vetorAux[qtd];
					
					retorno = getDadosEstruturaAuxiliar(tam_usuario, vetorAux);

					if(retorno == SUCESSO){
						//imprimir dados para o usuário
						int i = 0;
						for (; i < qtd; i++){
							printf("%d", vetorAux[i]);}
					}
				}
				break;
			}
			/*
			case 10:
			{ //dobrar*//*
					//ler um numero
					int valor_usuario;
					scanf("%i", &valor_usuario);
	
					dobrar(&valor);
	
					//passar para um funcao (void dobrar(...)) que recebe o numero e dobra (EstruturaVetores.c)
	
					printf("%i", valor);
	
					break;
			}
			*/
			
			default:
			{
				printf("opcao inválida\n");
			}
		}
	}

	return 0;
}