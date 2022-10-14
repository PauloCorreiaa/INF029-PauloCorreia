#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesGerais.h"
#include "Professores.h"
#define TAM_LINHA 13
#define TAM_MAX_PROFS 10

//Função Principal de Professores
int mainProfessores(Professor lista[], int qtd_professor){	
	Professor lista_professores[TAM_MAX_PROFS];
	int qtd_professores; 
	int opcao;	
		
	while (opcao!=0){
	opcao = menuProfessores();
		switch(opcao){				
			case 0: 
				break;				
			case 1:{
				qtd_professores = inserirMatriculaProf(lista_professores, qtd_professores);
				break;						
			}
			case 2:{	
				listarMatriculasProf(lista_professores, qtd_professores);
				break;
			}
			case 3:{	
				puts("Escolha a matrícula para ser excluída");	
				listarMatriculasExclusaoProf(lista_professores, qtd_professores);
				qtd_professores = excluirMatriculaProf(lista_professores, qtd_professores);				
				putchar('\n');
				break;
			}			
			default:{
				puts("\n\nOpção inválida\n\n");
				break;
			}
		}			
	}
	return qtd_professores;
}

//Funções
// Validação de Nome
int validarTextoProf(char string[]){
  int i, tam_str, tam_max, validador = 0;
  tam_max = 20;

  tam_str = strlen(string);
  if (tam_str > tam_max || string[0] == '\0')
    validador++;

  return validador;
}

//Menu professores
int menuProfessores(){	
	int opcao;
	
	putchar('\n');
	linha('*', TAM_LINHA);
	puts("\nMenu Professores");
	linha('*', TAM_LINHA);
	puts("\n[0] Menu Principal\n[1] Inserir\n[2] Listar\n[3] Excluir\n[4] Atualizar");
	printf("Sua opção: "); scanf("%d", &opcao);
	fflush(stdin);

	return opcao;
}

// Leitura dados do professor (matrícula, nome, cpf, nascimento e sexo)
int inserirMatriculaProf(Professor lista[], int qtd_professor){	
	char texto[101];	
	
	__fpurge(stdin);
  linha('*', TAM_LINHA);
	puts("\nNovo Professor:");
  
	printf("Nome = ");
  fgets(texto, 101, stdin);
  if (validarTextoProf(texto) > 0)
    printf("\nNome não cadastrado.\nLimite de caracteres excedido.\n");
  else{
    strcpy(lista[qtd_professor].nome, texto);
  }
	
  puts("Data de nascimento");
  printf("\tDia = "); scanf("%d", &lista[qtd_professor].dia);
  printf("\tMês = "); scanf("%d", &lista[qtd_professor].mes);
  printf("\tAno = "); scanf("%d", &lista[qtd_professor].ano);
  printf("Cpf = "); scanf("%ld", &lista[qtd_professor].cpf);
  __fpurge(stdin);
  
	printf("Sexo\n\tf = feminino\n\tm = masculino\n\to = outro\n\tSua resposta = "); 
	scanf("%c", &lista[qtd_professor].sexo);
	__fpurge(stdin);
	
	lista[qtd_professor].matricula = MATRICULA_PROFESSOR++;
	printf("Matrícula = %d\n", MATRICULA_PROFESSOR);
	
	qtd_professor++;
	
	linha('*', TAM_LINHA);
	puts("\nCadastro realizado com sucesso.");
	printf("Total de alunos cadastrados = %0d", qtd_professor);
	
  return qtd_professor;
}

//Listar alunos cadastrados
void listarMatriculasProf(Professor lista[], int qtd_professor){	
	for(int i=0; i<qtd_professor; i++){
			linha('*', TAM_LINHA);
			printf("\nAluno %d", i+1);			
			printf("\nNome = %s", lista[i].nome);
			printf("Data de nascimento = %d/%d/%d", lista[i].dia, lista[i].mes, lista[i].ano);
			printf("\nCpf = %ld", lista[i].cpf);
			printf("\nSexo = %c", lista[i].sexo);
			printf("\nMatrícula = %d", lista[i].matricula);
		}
}

//Listar Matrículas para exlcusão
void listarMatriculasExclusaoProf(Professor lista[], int qtd_professor){	
	for(int i=0; i<qtd_professor; i++){
			linha('*', TAM_LINHA);						
			printf("\nNome = %s", lista[i].nome);
			printf("\nMatrícula = %d", lista[i].matricula);
		}
}

//Excluir aluno 
int excluirMatriculaProf(Professor lista[], int qtd_professor){	
	int opcao, i;	
	
	if(qtd_professor < 1) 
		printf("Erro na exclusão. Não existe nenhum cadastro de aluno.");	
	
	else{
		printf("Matrícula selecionada = ");
		scanf("%d", &opcao);
		
		for(i=0; i<qtd_professor; i++){
				if(opcao == lista[i].matricula)
					lista[i] = lista[i+1];		
		}
		qtd_professor--;
		puts("Exclusão realizada com sucesso.");
	}
	return qtd_professor;
}