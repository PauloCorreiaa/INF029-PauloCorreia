#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Professores.h"
#define TAM_LINHA 13
#define TAM_MAX_PROFES 10

//Função Principal de Professores
int mainProfessores(Professor lista[], int qtd_professor){	
	Professor lista_alunos[TAM_MAX_PROFES];
	int qtd_professores; 
	int opcao;	
		
	while (opcao!=0){
	opcao = menuProfessores();
		switch(opcao){				
			case 0: 
				break;				
			case 1:{
				qtd_professores = inserirMatriculas(lista_alunos, qtd_professores);
				break;						
			}
			case 2:{	
				listarMatriculas(lista_alunos, qtd_professores);
				break;
			}
			case 3:{	
				puts("Escolha a matrícula para ser excluída");	
				listarMatriculasExclusao(lista_alunos, qtd_professores);
				excluirMatricula(lista_alunos, qtd_professores);
				qtd_professores--;
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
int validarTexto(char string[]){
  int i, tam_str, tam_max, validador = 0;
  tam_max = 20;

  tam_str = strlen(string);
  if (tam_str > tam_max || string[0] == '\0')
    validador++;

  return validador;
}

//Menu Professores
int menuProfessores(){	
	int opcao;
	
	putchar('\n');
	linha('*', TAM_LINHA);
	puts("\nMenu Estudantes");
	linha('*', TAM_LINHA);
	puts("\n[0] Menu Principal\n[1] Inserir\n[2] Listar\n[3] Excluir\n[4] Atualizar");
	printf("Sua opção: "); scanf("%d", &opcao);
	fflush(stdin);

	return opcao;
}

// Leitura dados do professor (matrícula, nome, cpf, nascimento e sexo)
int inserirMatricula(Professor lista[], int qtd_professor){	
	char texto[101];
	static int MAT = 100;
	
	__fpurge(stdin);
  linha('*', TAM_LINHA);
	puts("\nNovo Professor:");
  
	printf("Nome = ");
  fgets(texto, 101, stdin);
  if (validarTexto(texto) > 0)
    printf("\nNome não cadastrado.\nLimite de caracteres excedido.\n");
  else{
    strcpy(lista[qtd_professor].nome, texto);
  }
	
  puts("Data de nascimento");
  printf("\tDia = "); scanf("%d", &lista[qtd_professor].nascimento.dia);
  printf("\tMês = "); scanf("%d", &lista[qtd_professor].nascimento.mes);
  printf("\tAno = "); scanf("%d", &lista[qtd_professor].nascimento.ano);
  printf("Cpf = "); scanf("%ld", &lista[qtd_professor].cpf);
  __fpurge(stdin);
  
	printf("Sexo\n\tf = feminino\n\tm = masculino\n\to = outro\n\tSua resposta = "); 
	scanf("%c", &lista[qtd_professor].sexo);
	__fpurge(stdin);
	
	lista[qtd_professor].matricula = MAT++;
	printf("Matrícula = %d\n", MAT);
	
	qtd_professor++;
	
	linha('*', TAM_LINHA);
	puts("\nCadastro realizado com sucesso.");
	printf("Total de professores cadastrados = %0d", qtd_professor);
	
  return qtd_professor;
}

//Listar professores cadastrados
void listarMatriculas(Professor lista[], int qtd_professor){	
	for(int i=0; i<qtd_professor; i++){
			linha('*', TAM_LINHA);
			printf("\nAluno %d", i+1);			
			printf("\nNome = %s", lista[i].nome);
			printf("Data de nascimento = %d/%d/%d", lista[i].nascimento.dia, lista[i].nascimento.mes, lista[i].nascimento.ano);
			printf("\nCpf = %ld", lista[i].cpf);
			printf("\nSexo = %c", lista[i].sexo);
			printf("\nMatrícula = %d", lista[i].matricula);
		}
}

//Listar Matrículas para exlcusão
void listarMatriculasExclusao(Professor lista[], int qtd_professor){	
	for(int i=0; i<qtd_professor; i++){
			linha('*', TAM_LINHA);						
			printf("\nNome = %s", lista[i].nome);
			printf("\nMatrícula = %d", lista[i].matricula);
		}
}

//Excluir professor 
void excluirMatricula(Professor lista[], int qtd_professor){	
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
		puts("Exclusão realizada com sucesso.");
	}
}