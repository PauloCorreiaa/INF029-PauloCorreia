/*
Discentes:
Lídia Campos
Paulo Correia
*/

#include <stdio.h>
#include <stdlib.h>
#include "Alunos.h"
#include "Escola.h"

#define TAM_LINHA 10
#define TAM_MAX_ALUNOS 10


int main()
{	
	Aluno lista_alunos[TAM_MAX_ALUNOS];	
	int qtd_alunos;
	int opcao;
	
	while(opcao!=0){	
		opcao = menuPrincipal();		
		switch(opcao){			
			case 0:{
				puts("Programa encerrado.");				
				break;
			}				
			case 1:{
				qtd_alunos = mainAlunos(lista_alunos, qtd_alunos);
				break;
			}				
			default:{
				puts("Opção inválida");
				break;
			}
		}
	}	
	return 0;
}


//Funções

//Menu Principal com Alunos, Professores e Disciplinas
int menuPrincipal(void){
	int opcao;
			
	linha('*', TAM_LINHA);
	fflush(stdin);
	puts("\nMenu Principal");
	linha('*', TAM_LINHA);
	puts("\n[0] Sair\n[1] Alunos\n[2] Professores\n[3] Disciplinas");
	printf("Sua opção: "); scanf("%d", &opcao);
	fflush(stdin);

	return opcao;
}