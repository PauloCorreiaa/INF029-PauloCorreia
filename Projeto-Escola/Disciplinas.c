#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <math.h>
#include "disciplina.h"
#include "funcoes_gerais.h"
#define TAM_NOME 20
#define TAM_TURMA 50 


//FUNÇÃO MENU PRINCIPAL DA DISCIPLINA;

int menuDisciplina (disciplina discpl[], int qtd_disciplina){

  int opcao=1;

  while(opcao!= 0){
    printf(" Digite a opção desejada:\n1-Cadastrar Disciplina\n2-Atualizar disciplina\n3-Excluir Disciplina\n4-Listar Disciplina\n0- SAIR\nOpção--> ");
    scanf("%d", &opcao);

    switch (opcao){
      case 0: 
        printf("SAIR");
        break;
      case 1: 
        qtd_disciplina= CadastrarDisciplina(discpl, qtd_disciplina);
        break;
     case 2: 
        AtualizarDisciplina (discpl, qtd_disciplina);
        break;
     case 3: 
        qtd_disciplina= ExcluirDisciplina(discpl, qtd_disciplina);
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

//FUNÇÃO CADASTAR DISICPLINA
int CadastrarDisciplina(disciplina discpl[], int qtd){
  
  int len1, len2, len3, aux;
  int valid_nome=0, valid_professor=0, valid_qtdAluno= 0;
    
  //nome disciplina
  while (valid_nome == 0){
    printf("Nome da Disciplina (até %d caractres): ", TAM_NOME);
    fgets(discpl[qtd].nome, sizeof(discpl[qtd].nome), stdin);
    len1 = strlen(discpl[qtd].nome);
    if (discpl[qtd].nome[len1 - 1] == '\n')
      discpl[qtd].nome[len1 - 1] = '\0';
    
    valid_nome= validarNome (discpl[qtd].nome);
    
    if (valid_nome==0)
      printf("Nome inválido, digite corretamente.\n");
  }
      
  //nome professor  
  
  while (valid_professor == 0){
    printf("Nome do professor: ");
    fgets(discpl[qtd].nome_professor, sizeof(discpl[qtd].nome_professor), stdin);
    len3 = strlen(discpl[qtd].nome_professor);
    if (discpl[qtd].nome_professor[len3 - 1] == '\n')
      discpl[qtd].nome_professor[len3 - 1] = '\0';
            
    valid_professor= validarNome (discpl[qtd].nome_professor);
    
    if (valid_professor==0)
      printf("Nome do professor inválido, digite corretamente.\n");
  } 

  //quantidade de alunos matriculados  
  
  while (valid_qtdAluno == 0){
    printf("Informe a quantidade de alunos matriculados: ");
    scanf ("%d", &aux);
    
    if (aux >0 && aux<=TAM_TURMA){
      discpl[qtd].qtd_aluno= aux;
      valid_qtdAluno=1;
    }
          
    else
      printf("Quantidade inválida");
  } 

  //codigo disciplina
  cod++;
  discpl[qtd].codigo= cod;

  return qtd=+1;
}
  

//FUNÇÃO ATUALIZAR DISCIPLINA
void AtualizarDisciplina (disciplina discpl[], int qtd){

  int valid, aux;
  
  valid= LocalizarDisciplina (discpl, qtd);
  if (valid == -1)
    printf ("Disciplina não localizada");
  else
    aux= CadastrarDisciplina(discpl, valid);
} 

//FUNÇÃO EXCLUIR DISICPLINA

int ExcluirDisciplina (disciplina discpl[], int qtd){
 
  int valid, i;
  
  valid= LocalizarDisciplina (discpl, qtd);
  
  if (valid == -1){
    printf ("Disciplina não localizada");
    return qtd;
  }
    
  if (valid> 0 && valid != (qtd-1)){
    for (i= valid; i < (qtd-1); i++){
      discpl[i]= discpl[i+1];  
     }
    return qtd--;
  }

  if (valid == (qtd-1))
    return qtd=-1;   
}

//FUNÇÃO LISTAR DISCIPLINA

void ListarDisciplina (disciplina discpl[], int qtd){ 
  
  int i;
  printf ("DISICPLINAS CADASTRADAS\n");
  for (i=0; i<qtd; i++){
    printf("Disciplina: %s (%d) - Professor: %s - %d Alunos matriculados \n",discpl[i].nome, discpl[i].codigo, discpl[i].nome_professor, discpl[i].qtd_aluno);
    printf("--------------------------------");
  } 
}

