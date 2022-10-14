#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <math.h>
#include "FuncoesGerais.h"
#include "Disciplinas.h"
#define TAM_TURMA 50
#define TAM_COD_DISCPL 6

//Menu principal disciplinas
int menuDisciplinas (Disciplina discpl[], int qtd_disciplina){
  int opcao=1;

  while(opcao!= 0){
    printf(" Digite a opção desejada:\n[1] Cadastrar disciplina\n [2] Atualizar disciplina\n [3] Excluir disciplina\n [4] Listar disciplinas\n0- SAIR\nOpção--> "); scanf("%d", &opcao);

    switch (opcao){
      case 0: 
        printf("SAIR");
        break;
      case 1: 
        qtd_disciplina = CadastrarDisciplina(discpl, qtd_disciplina);
        break;
     case 2: 
        AtualizarDisciplina (discpl, qtd_disciplina);
        break;
     case 3: 
        qtd_disciplina = ExcluirDisciplina(discpl, qtd_disciplina);
        break;
      case 4: 
        ListarDisciplina(discpl, qtd_disciplina);
        break;
      default:  
        printf ("\n\nOpção invalida\n\n"); 
    }   
  }
  return qtd_disciplina;  
}

//Validação nome (ATÉ 20 CARACTERES)
/*int validarNome (char n[]){
  int validador, i;
  
	for (i = 0; n[i] != '\0'; i++);
  if (i <= TAM_NOME)
    validador = 1;
  else
    validador = 0;    
  return validador;
}*/

//Inserir disciplina
int CadastrarDisciplina(Disciplina discpl[], int qtd){  
  int len1, len2, len3, aux;
  int valid_nome = 0, valid_professor = 0, valid_qtdAluno = 0;
    
	//Nome disciplina
  while (valid_nome == 0){
    printf("Nome da Disciplina (até %d caractres): ", TAM_NOME);
    fgets(discpl[qtd].nome, sizeof(discpl[qtd].nome), stdin);
    len1 = strlen(discpl[qtd].nome);
    if (discpl[qtd].nome[len1 - 1] == '\n')
      discpl[qtd].nome[len1 - 1] = '\0';
		
    valid_nome = validarNome (discpl[qtd].nome);
    
    if (valid_nome == 0)
      printf("Nome inválido, digite corretamente.\n");
  }
      
  //Nome professor    
  while (valid_professor == 0){
    printf("Nome do professor: ");
    fgets(discpl[qtd].nome_professor, sizeof(discpl[qtd].nome_professor), stdin);
    len3 = strlen(discpl[qtd].nome_professor);
    if (discpl[qtd].nome_professor[len3 - 1] == '\n')
      discpl[qtd].nome_professor[len3 - 1] = '\0';
            
    valid_professor = validarNome (discpl[qtd].nome_professor);
    
    if (valid_professor == 0)
      printf("Nome do professor inválido, digite corretamente.\n");
  } 

  //Quantidade de alunos matriculados  
  while (valid_qtdAluno == 0){
    printf("Informe a quantidade de alunos matriculados: "); scanf ("%d", &aux);    
    if (aux > 0 && aux <= TAM_TURMA){
      discpl[qtd].qtd_aluno = aux;
      valid_qtdAluno = 1;
    }          
    else
      printf("Quantidade inválida");
  } 
  //Cóodigo Disciplina
  cod++;
  discpl[qtd].codigo = cod;

  return qtd=+1;
}

//Buscar disciplina
int LocalizarDisciplina (Disciplina discpl[], int qtd){
  
  char nome [20];
  int len, valid_nome = 0, valid = -1, i;
  while (valid_nome == 0){
    printf("Informe o nome da Disciplna a ser atualizada: ");
    fgets(nome, sizeof(nome), stdin);
      len = strlen(nome);
      if (nome[len - 1] == '\n')
          nome[len - 1] = '\0';
    
    valid_nome = validarNome(nome);
      
    if (valid_nome == 0)
      printf("Nome inválido, digite corretamente.\n");
  }
 
  for (i = 0; i < qtd; i++){
    if (strcmp (discpl[i].nome, nome) == 0){
      valid = i;
    }
  }

  if (valid == -1)  
    return -1;
  else
    return valid;
}

//Atualizar disciplina
void AtualizarDisciplina (Disciplina discpl[], int qtd){

  int valid, aux;
  
  valid= LocalizarDisciplina (discpl, qtd);
  if (valid == -1)
    printf ("Disciplina não localizada");
  else
    aux = CadastrarDisciplina(discpl, valid);
} 

//Excluir disciplinas
int ExcluirDisciplina (Disciplina discpl[], int qtd){ 
  int valid, i;
  
  valid = LocalizarDisciplina (discpl, qtd);  
  if (valid == -1){
    printf ("Disciplina não localizada");
    return qtd;
  }    
  if (valid > 0 && valid != (qtd-1)){
    for (i = valid; i < (qtd-1); i++){
      discpl[i] = discpl[i+1];  
     }
    return qtd--;
  }
  if (valid == (qtd-1))
    return qtd = -1;   
}

//Listar disciplinas
void ListarDisciplina (Disciplina discpl[], int qtd){  
  int i;
  printf ("DISICPLINAS CADASTRADAS\n");
  for (i = 0; i < qtd; i++){
    printf("Disciplina: %s (%d) - Professor: %s - %d Alunos matriculados \n",discpl[i].nome, discpl[i].codigo, discpl[i].nome_professor, discpl[i].qtd_aluno);
    printf("--------------------------------");
  } 
}

