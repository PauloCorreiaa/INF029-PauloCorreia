#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alunos.h"
#define TAM_LINHA 13
#define TAM_MAX_ALUNOS 10

//Função Principal de Alunos
int mainAlunos(Aluno lista[], int qtd_aluno){	
	Aluno lista_alunos[TAM_MAX_ALUNOS];
	int qtd_alunos; 
	int opcao;	
		
	while (opcao!=0){
	opcao = menuAlunos();
		switch(opcao){				
			case 0: 
				break;				
			case 1:{
				qtd_alunos = inserirMatriculas(lista_alunos, qtd_alunos);
				break;						
			}
			case 2:{	
				listarMatriculas(lista_alunos, qtd_alunos);
				break;
			}
			case 3:{	
				puts("Escolha a matrícula para ser excluída");	
				listarMatriculasExclusao(lista_alunos, qtd_alunos);
				excluirMatricula(lista_alunos, qtd_alunos);
				qtd_alunos--;
				putchar('\n');
				break;
			}
			
			default:{
				puts("\n\nOpção inválida\n\n");
				break;
			}
		}			
	}
	return qtd_alunos;
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

//Menu Alunos
int menuAlunos(){	
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

// Leitura dados do aluno (matrícula, nome, cpf, nascimento e sexo)
int inserirMatricula(Aluno lista[], int qtd_aluno){	
	char texto[101];
	static int MAT = 100;
	
	__fpurge(stdin);
  linha('*', TAM_LINHA);
	puts("\nNovo Aluno:");
  
	printf("Nome = ");
  fgets(texto, 101, stdin);
  if (validarTexto(texto) > 0)
    printf("\nNome não cadastrado.\nLimite de caracteres excedido.\n");
  else{
    strcpy(lista[qtd_aluno].nome, texto);
  }
	
  puts("Data de nascimento");
  printf("\tDia = "); scanf("%d", &lista[qtd_aluno].nascimento.dia);
  printf("\tMês = "); scanf("%d", &lista[qtd_aluno].nascimento.mes);
  printf("\tAno = "); scanf("%d", &lista[qtd_aluno].nascimento.ano);
  printf("Cpf = "); scanf("%ld", &lista[qtd_aluno].cpf);
  __fpurge(stdin);
  
	printf("Sexo\n\tf = feminino\n\tm = masculino\n\to = outro\n\tSua resposta = "); 
	scanf("%c", &lista[qtd_aluno].sexo);
	__fpurge(stdin);
	
	lista[qtd_aluno].matricula = MAT++;
	printf("Matrícula = %d\n", MAT);
	
	qtd_aluno++;
	
	linha('*', TAM_LINHA);
	puts("\nCadastro realizado com sucesso.");
	printf("Total de alunos cadastrados = %0d", qtd_aluno);
	
  return qtd_aluno;
}

//Listar alunos cadastrados
void listarMatriculas(Aluno lista[], int qtd_aluno){	
	for(int i=0; i<qtd_aluno; i++){
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
void listarMatriculasExclusao(Aluno lista[], int qtd_aluno){	
	for(int i=0; i<qtd_aluno; i++){
			linha('*', TAM_LINHA);						
			printf("\nNome = %s", lista[i].nome);
			printf("\nMatrícula = %d", lista[i].matricula);
		}
}

//Excluir aluno 
void excluirMatricula(Aluno lista[], int qtd_aluno){	
	int opcao, i;	
	
	if(qtd_aluno < 1) 
		printf("Erro na exclusão. Não existe nenhum cadastro de aluno.");	
	
	else{
		printf("Matrícula selecionada = ");
		scanf("%d", &opcao);
		
		for(i=0; i<qtd_aluno; i++){
				if(opcao == lista[i].matricula)
					lista[i] = lista[i+1];		
		}		
		puts("Exclusão realizada com sucesso.");
	}
}