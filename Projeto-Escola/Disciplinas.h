#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <math.h>
#include "funcoes_gerais.h"
//#include "Alunos.h"
#define TAM_NOME 20
#define TAM_TURMA 50 
#define TAM_COD_DISCPL 6

static int cod = 200;

//ESTRUTURA DE DADOS DO TIPO *DISCIPLINA*
typedef struct{
char nome[TAM_NOME];
int codigo;
char nome_professor[TAM_NOME];
int qtd_aluno;
} disciplina;


int menuDisciplina (disciplina discpl[], int qtd_disciplina);
int CadastrarDisciplina(disciplina discpl[], int qtd);
void ListarDisciplina (disciplina discpl[], int qtd);
int ExcluirDisciplina (disciplina discpl[], int qtd);
void AtualizarDisciplina (disciplina discpl[], int qtd);
