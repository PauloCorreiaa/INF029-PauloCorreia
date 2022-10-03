//Funções de uso comum
#include <stdio.h>
#include <stdlib.h>

// Impressão de linha de caracteres
void linha(char c, int num) 
{
  int i;

  for (i = 1; i < num; i++){		
    printf("%c ", c);
	}
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <math.h>
#include "disciplina.h"
#include "FuncoesGerais.h"
#include "Alunos.h"
#define TAM_LINHA 10
#define TAM_MAX_ALUNOS 10
#define TAM_NOME 20
#define TAM_TURMA 50 


//------------------FUNÇÕES DE VALIDAÇÃO---------------------------------
//FUNÇÕES DE VALIDAÇÃO --> 0= FALHA NO CADASTRO/ 1= CADASTRADO

//FUNÇÃO VALIDAR CPF
int validarCPF (char cpf_int[]){

  int cpf [11], validador, k, t, invalid;
  int i, dg1, soma_dg1=0, valid_dg1, verific_dg1=0; 
  int j, dg2, soma_dg2=0, valid_dg2, verific_dg2=0;

  if (strlen (cpf_int) != 11)
    return validador= 0;
  
  else{

    for (t=0; t<=10; t++)
      cpf[t]= cpf_int[t] - '0';
            
    for (i=0, dg1= 10; i<9; i++){
    soma_dg1= soma_dg1 + (cpf[i] * dg1);
    dg1--;
    }

    valid_dg1= (soma_dg1*10)%11;
    
    if (valid_dg1== cpf[9] || (valid_dg1== 10 && cpf[9]== 0))
      verific_dg1= 1;
    
    for (j=0, dg2= 11; j<10; j++){
      soma_dg2= soma_dg2 + (cpf[j] * dg2);
      dg2--;
    }
  
    valid_dg2= (soma_dg2*10)%11;
    
    //regra de validação de cpf
    if (valid_dg2== cpf[10] || (valid_dg2== 10 && cpf[10]== 0))
      verific_dg2= 1;
  
    for (k=0, invalid= 0; k<10; k++){
      if (cpf[k]==cpf[k+1])
        invalid++; 
    }
  
    if (verific_dg1== 1 && verific_dg2== 1 && invalid!=10)
      return validador=1;
  
    else
      return validador=0;    
    }
     
}

//FUNÇÃO VALIDAÇÃO SEXO
int validarSexo (char sx){
  
  int validador;
  
  switch (sx) {
    case 'F':
    case 'f':
    case 'M':
    case 'm':
        return validador= 1;
    break;

    default:
      return validador= 0;
    break;
}  
}

//FUNÇÃO VALIDAR TAMANHO DE NOME (ATÉ 20 CARACTERES)
int validarNome (char n[]){

  int validador, i;

  for (i=0; n[i] != '\0'; i++);

  if (i<=TAM_NOME)
    validador= 1;
  else
    validador= 0;
    
  return validador;
}

//FUNÇÃO VALIDAR DATA DE NASCIMENTO
int validarNacimento (int dia, int mes, int ano){

  int validador, valid_ano=0, valid_mes=0, valid_dia=0;
  int mes_31=0, mes_30=0, mes_29=0, mes_28=0;
  bool ano_bissexto;
  
  if (ano >= 1912 && ano <= 2022){
    valid_ano= 1;
    if ((ano%4==0 && ano%100==0 && ano && ano%400==0) || (ano%4==0 && ano%100!=0))
        ano_bissexto= true;

    else 
        ano_bissexto= false;
  }
    
  if (mes >= 1 && mes <= 12)
    valid_mes= 1;

  if (valid_mes==1 && dia>=1 && dia<= 31){
     
    switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      mes_31= 1;
    break;

    case 4:
    case 6:
    case 9:
    case 11:
      mes_30= 1;
    break;
    
    case 2: {        
      if (ano_bissexto== true && dia<=29)
        mes_29= 1;

      if (ano_bissexto== false && dia<=28)
        mes_28= 1;        
    } 
    break;
      
    }  
    
  if (dia<=31 && mes_31==1)
    valid_dia= 1;

  if (dia<=30 && mes_30==1)
    valid_dia= 1; 

  if (dia<=29 && mes_29==1)
    valid_dia= 1; 

  if (dia<=28 && mes_28==1)
    valid_dia= 1; 
  
  }

  if (valid_ano + valid_mes+ valid_dia==3)
    return validador=1;

  else
    return validador=0;
  
}

//------------------FUNÇÕES DE MENU PRINCIPAL---------------------------------
//Menu Principal com Alunos, Professores e Disciplinas
int menuPrincipal()
{
	int opcao;
			
	//linha('*', TAM_LINHA);
	puts("\nMenu Principal");
	//linha('*', TAM_LINHA);
	puts("\n[0] Sair\n[1] Alunos\n[2] Professores\n[3] Disciplinas");
	printf("Sua opção: "); scanf("%d", &opcao);
	fflush(stdin);

	return opcao;
}

//------------------FUNÇÕES LOCALIZAR DISCIPLINA (NOME)---------------------------------
int LocalizarDisciplina (disciplina discpl[], int qtd){
  
  char nome [20];
  int len, valid_nome= 0, valid= -1, i;
  while (valid_nome==0){
    printf("Informe o nome da disciplina a ser atualizada: ");
    fgets(nome, sizeof(nome), stdin);
      len = strlen(nome);
      if (nome[len - 1] == '\n')
          nome[len - 1] = '\0';
    
    valid_nome= validarNome (nome);
      
    if (valid_nome==0)
      printf("Nome inválido, digite corretamente.\n");
  }
 
  for (i=0; i<qtd; i++){
    if (strcmp (discpl[i].nome, nome) == 0){
      valid= i;
    }
  }

  if (valid==-1)  
    return -1;
  else
    return valid;
} 
