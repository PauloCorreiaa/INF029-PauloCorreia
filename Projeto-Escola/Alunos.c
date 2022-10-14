#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncoesGerais.h"
#include "Alunos.h"
#define TAM_LINHA 13
#define TAM_MAX_ALUNOS 10

//Função Principal de Alunos
int menuAlunos(Aluno lista[], int qtd_aluno){	
	Aluno lista_alunos[TAM_MAX_ALUNOS];
	int opcao, qtd_alunos;

	putchar('\n');
	linha('*', TAM_LINHA);
	puts("\nMenu Estudantes");
	linha('*', TAM_LINHA);
	puts("\n[0] Menu Principal\n[1] Inserir\n[2] Listar\n[3] Excluir\n[4] Atualizar");
	printf("Sua opção: "); scanf("%d ", &opcao);
	fflush(stdin);
	
	while (opcao!=0){
		switch(opcao){				
			case 0: 
				break;				
			case 1:{
				qtd_alunos = inserirAluno(lista_alunos, qtd_aluno);
				break;						
			}
			/*case 2:{	
				listarMatriculasAluno(lista_alunos, qtd_alunos);
				break;
			}
			case 3:{	
				puts("Escolha a matrícula para ser excluída");	
				listarMatriculasExclusaoAluno(lista_alunos, qtd_alunos);
				qtd_alunos = excluirMatriculaAluno(lista_alunos, qtd_alunos);				
				putchar('\n');
				break;
			}*/			
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
int validarTextoAluno(char string[]){
  int i, tam_str, tam_max, validador = 0;
  tam_max = 20;

  tam_str = strlen(string);
  if (tam_str > tam_max || string[0] == '\0')
    validador++;

  return validador;
}

//Menu Alunos
/*int menuAlunos(){	
	int opcao;
	
	putchar('\n');
	linha('*', TAM_LINHA);
	puts("\nMenu Estudantes");
	linha('*', TAM_LINHA);
	puts("\n[0] Menu Principal\n[1] Inserir\n[2] Listar\n[3] Excluir\n[4] Atualizar");
	printf("Sua opção: "); scanf("%d ", &opcao);
	fflush(stdin);

	return opcao;
}*/

// Cadastro aluno (matrícula, nome, cpf, nascimento e sexo)
int inserirAluno(Aluno lista[], int qtd_aluno){	
	char texto[101];
	//tmp_sexo, tmp_cpf[12];	
	//int validadorData = 1, validadorSexo = 1, validadorCpf = 1;
	//Aluno tmp_data;	
	
	//__fpurge(stdin);
	fflush(stdin);
  linha('*', TAM_LINHA);
	puts("\nNovo Aluno:");
	
	lista[qtd_aluno].matricula = MATRICULA_ALUNO++;
	printf("Matrícula = %d\n", MATRICULA_ALUNO);
  
	printf("Nome = ");
  fgets(texto, 101, stdin);
	//__fpurge(stdin);
	fflush(stdin);
	
  if (validarTextoAluno(texto) > 0)
    printf("\nNome não cadastrado.\nLimite de caracteres excedido.\n");
  else{
    strcpy(lista[qtd_aluno].nome, texto);
  }
	/*
	while(validadorData = 0){
		puts("Data de nascimento");
	  printf("\tDia = "); scanf("%d ", &tmp_data.dia);
	  printf("\tMês = "); scanf("%d ", &tmp_data.mes);
	  printf("\tAno = "); scanf("%d ", &tmp_data.ano);
		validadorData = validarNascimento (tmp_data.dia, tmp_data.mes, tmp_data.ano);
			if(validadorData > 0){
				lista[qtd_aluno].dia = tmp_data.dia;
				lista[qtd_aluno].mes = tmp_data.mes;
				lista[qtd_aluno].ano = tmp_data.ano;
			}
			else
				printf("Dados inválidos.");
	}

	while(validadorCpf = 0){
		printf("Cpf = "); 
		scanf("%s ", tmp_cpf);
	  //__fpurge(stdin);
		fflush(stdin);
		validadorCpf = validarCPF(tmp_cpf);
			if(validadorCpf > 0)
				strcpy(lista[qtd_aluno].cpf, tmp_cpf);
			else
				printf("Dados inválidos.");
	}		
  
	while (validadorSexo = 0){
		printf("Sexo\n\tf = feminino\n\tm = masculino\n\to = outro\n\tSua resposta = "); 
		scanf("%c ", &tmp_sexo);
		//__fpurge(stdin);
		fflush(stdin);
		validadorSexo = validarSexo(tmp_sexo);
		if(validadorSexo > 0)
			strcpy(lista[qtd_aluno].sexo, tmp_sexo);
		else
			printf("Dados inválidos.");
	}	
	*/
	qtd_aluno++;
	
	linha('*', TAM_LINHA);
	puts("\nCadastro realizado com sucesso.");
	//printf("Total de alunos cadastrados = %0d", qtd_aluno);
	
  return qtd_aluno;
}
/*
//Listar alunos cadastrados
void listarAluno(Aluno lista[], int qtd_aluno){	
	for(int i=0; i<qtd_aluno; i++){
			linha('*', TAM_LINHA);
			printf("\nMatrícula = %d", lista[i].matricula);
			printf("\nAluno %d", i+1);			
			printf("\nNome = %s", lista[i].nome);
			/*printf("Data de nascimento = %d/%d/%d", lista[i].dia, lista[i].mes, lista[i].ano);
			printf("\nCpf = %s", lista[i].cpf);
			printf("\nSexo = %c", lista[i].sexo);
		}
}

//Listar Matrículas para exlcusão
void listarExclusaoAluno(Aluno lista[], int qtd_aluno){	
	for(int i=0; i<qtd_aluno; i++){
			linha('*', TAM_LINHA);						
			printf("\nNome = %s", lista[i].nome);
			printf("\nMatrícula = %d", lista[i].matricula);
		}
}

//Excluir aluno 
int excluirAluno(Aluno lista[], int qtd_aluno){	
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
		qtd_aluno--;
		puts("Exclusão realizada com sucesso.");
	}
	return qtd_aluno;
}
*/
