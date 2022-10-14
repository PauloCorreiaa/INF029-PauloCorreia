//Discentes: Lídia Campos e Paulo Correia

#include <stdio.h>
#include <stdlib.h>
#include "FuncoesGerais.h"
#include "Alunos.h"
//#include "Professores.h"
//#include "Disciplinas.h"
#include "Escola.h"

#define TAM_LINHA 13
#define TAM_MAX_ALUNOS 10
//#define TAM_MAX_PROFESSORES 10
//#define TAM_MAX_DISCIPLINAS 10

int main(){	
	Aluno lista_alunos[TAM_MAX_ALUNOS];
	//Professor lista_professores[TAM_MAX_PROFESSORES];
	//Disciplina lista_disciplinas[TAM_MAX_DISCIPLINAS];
	int qtd_alunos;
	//qtd_professores, qtd_disciplinas;
	int opcao = 1;
	
	while(opcao!=0){	
		opcao = menuPrincipal();		
		switch(opcao){			
			case 0:{
				puts("Programa encerrado.");				
				break;
			}				
			case 1:{
				qtd_alunos = menuAlunos(lista_alunos, qtd_alunos);
				break;
			}
			/*case 2:{
				qtd_professores = mainProfessores(lista_professores, qtd_professores);
				break;
			}
			case 3:{
				qtd_disciplinas = menuDisciplinas(lista_disciplinas, qtd_disciplinas);
				break;
			}
			*/
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
			
	fflush(stdin);
	linha('*', TAM_LINHA);
	puts("\nMenu Principal");
	linha('*', TAM_LINHA);
	puts("\n[0] Sair\n[1] Alunos\n[2] Professores\n[3] Disciplinas");
	printf("Sua opção: "); 
	scanf("%d", &opcao);
	fflush(stdin);

	return opcao;
}