#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"
#define TAM 10
#define TAM_AUX 15

tp_registro vetorPrincipal[TAM];

//imprimir linha caracteres
void linha(char c, int num){
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);}

//validação de posição que deve ser entre 1 e 10
int ehPosicaoValida(int posicao){
	int retorno = 0;
	
	//validação de posição que deve ser entre 1 e 10
	if (posicao < 1 || posicao > 10){
		retorno = POSICAO_INVALIDA;}
	else
		retorno = SUCESSO;

	return retorno;
}

/*
Objetivo:
criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){
	int retorno = 0;

	//validação de posição que deve ser entre 1 e 10
	if(ehPosicaoValida(posicao) < 0 && ehPosicaoValida(posicao) != -1)
		retorno = POSICAO_INVALIDA;		
		//validação de estrutura auxiliar existente
	  else if(vetorPrincipal[posicao -1].validador_estrut_aux != 0)
			retorno = JA_TEM_ESTRUTURA_AUXILIAR;		
  	//validação tamanho máximo estrutura aulixiar
		else if(tamanho > TAM_AUX)
	  	retorno = SEM_ESPACO_DE_MEMORIA;			
  	//validação entrada tamanho estrutura aulixiar maior que 1
	  else if(tamanho < 1)
			retorno = TAMANHO_INVALIDO;
  
	//criar estrutura auxiliar
	else{
		vetorPrincipal[posicao - 1].validador_estrut_aux++;
		vetorPrincipal[posicao - 1].tam_max_estrutura_aux = tamanho;
		vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar = (int*) malloc(tamanho * sizeof(int));
		retorno = SUCESSO;
		//validação alocação de memória da estrutura auxiliar
		if(vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar == NULL)
			retorno = SEM_ESPACO_DE_MEMORIA;
		else{
			retorno = SUCESSO;
			free(vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar);}
	}
	
  return retorno;
}

/*
Objetivo:
inserir número 'valor' em estrutura auxiliar da posição 'posicao'

Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
	int retorno = 0;
	int cont;

	//validação de posição que deve ser entre 1 e 10
	if(ehPosicaoValida(posicao) < 0 && ehPosicaoValida(posicao) != -1)
		retorno = POSICAO_INVALIDA;		
		//validação de estrutura auxiliar existente	
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;		
		//validação de espaço livre na estrutura auxiliar
		else if((vetorPrincipal[posicao - 1].tam_max_estrutura_aux == vetorPrincipal[posicao - 1].cont_estrutura_aux) && (vetorPrincipal[posicao - 1].tam_max_estrutura_aux > 0))
			retorno = SEM_ESPACO;
				
	//inserir novo número na estrutura auxiliar
	else{		
		cont = vetorPrincipal[posicao - 1].cont_estrutura_aux;
		vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar[cont] = valor;
		vetorPrincipal[posicao - 1].cont_estrutura_aux++;
		retorno = SUCESSO;}
		
	return retorno;
}

/*
Objetivo:
excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

etorno (int)
	SUCESSO - excluido com sucesso
	ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
	SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
	POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
	int retorno = 0;
	int cont;	

	//validação de posição que deve ser entre 1 e 10
	if(ehPosicaoValida(posicao) < 0 && ehPosicaoValida(posicao) != -1)
		retorno = POSICAO_INVALIDA;
		//validação de estrutura auxiliar existente	
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;		
		//validação de espaço livre na estrtutura auxiliar
		else if(vetorPrincipal[posicao - 1].cont_estrutura_aux == 0)
			retorno = ESTRUTURA_AUXILIAR_VAZIA;

	//exclusão do último número da estrutura auxiliar
	else{
		vetorPrincipal[posicao - 1].cont_estrutura_aux--;
		retorno = SUCESSO;}	
	
  return retorno;
}

/*
Objetivo: 
excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica

Retorno (int)
	SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
	NUMERO_INEXISTENTE - Número não existe
	ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
	SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
	POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
  int retorno = 0;
	int validador = 0;	
	
	//validação de posição que deve ser entre 1 e 10
	if(ehPosicaoValida(posicao) < 0 && ehPosicaoValida(posicao) != -1)
		retorno = POSICAO_INVALIDA;
		//validação de estrutura auxiliar existente	
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;
		//validação de espaço livre na estrtutura auxiliar
		else if(vetorPrincipal[posicao - 1].cont_estrutura_aux == 0)
			retorno = ESTRUTURA_AUXILIAR_VAZIA;
		
	else{
		//validação busca número entrada na estrutura auxiliar
		for(int i = 0; i < vetorPrincipal[posicao - 1].tam_max_estrutura_aux; i++){
			if(vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar[i] == valor){				
				//atualização da ordem estrtutura auxiliar após exclusão
				vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar[i] = vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar[i + 1];				
				//atualização da quantidade de elementos na estrutura auxiliar
				vetorPrincipal[posicao - 1].cont_estrutura_aux--;				
				//variável de controle para validação busca número entrada
				validador++;}
		}
		
		//confirmação exclusão e atualização da estrutura auxiliar
		if(validador > 0)
			retorno = SUCESSO;
		else
			retorno = NUMERO_INEXISTENTE;}
	
	return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	int retorno = 0;	

	//validação de posição que deve ser entre 1 e 10
	if(ehPosicaoValida(posicao) < 0 && ehPosicaoValida(posicao) != -1)
		retorno = POSICAO_INVALIDA;
		//validação de estrutura auxiliar existente	
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;

	else{
		for(int i = 0; i < vetorPrincipal[posicao - 1].cont_estrutura_aux; i++){
			vetorAux[i] = vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar[i];}		
		retorno = SUCESSO;}

	return retorno;
}

/*
Objetivo: 
retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
	int retorno = 0;	
	int i, j, cont; //contadores
	int aux;

	//validação de posição que deve ser entre 1 e 10
	if(ehPosicaoValida(posicao) < 0 && ehPosicaoValida(posicao) != -1)
		retorno = POSICAO_INVALIDA;
		//validação de estrutura auxiliar existente	
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;
	
	else{
		//ordenação da estrutura auxiliar para vetor auxiliar		
		cont = vetorPrincipal[posicao - 1].cont_estrutura_aux;

		//passagem de estrutura auxiliar para vetor auxiliar
		for(i = 0; i < cont; i++)
			vetorAux[i] = vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar[i];

		//ordenação valores crescente 
		for(i = 1; i < cont; i++){
			for(j = 0; j < cont; j++)
				if(vetorAux[i] < vetorAux[j]){
					//troca de posição de valores
					aux = vetorAux[i];
					vetorAux[i] = vetorAux[j];
					vetorAux[j] = aux;}
		}		
		retorno = SUCESSO;}

	return retorno;
}

/*
Objetivo: 
retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){	
	int retorno = 0;
	int validador = 0;
	int i, j, h = 0, cont; //contadores	

	for(i = 0; i < TAM; i++){
		//validação de estrutura auxiliar vazia			
		if(vetorPrincipal[i].validador_estrut_aux == 0 && vetorPrincipal[i].tam_max_estrutura_aux > 0)
			validador++;			
		//passagem de estrutura auxiliar para vetor auxiliar
		else{
			for(j = 0; j < vetorPrincipal[i].cont_estrutura_aux; j++, h++)
				vetorAux[h] = vetorPrincipal[i].vetor_estrutura_auxiliar[j];
				cont = h;}	
	}
	//retorno validação
	if(validador == cont)
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;	
	else
		retorno = SUCESSO;
	
	return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int retorno = 0;
	int validador = 0;
	int i, j, h = 0, cont; //contadores
	int aux;

	for(i = 0; i < TAM; i++){
		//validação de estrutura auxiliar vazia			
		if(vetorPrincipal[i].validador_estrut_aux == 0 && vetorPrincipal[i].tam_max_estrutura_aux > 0)
			validador++;		
		//passagem de estrutura auxiliar para vetor auxiliar
		else{
			for(j = 0; j < vetorPrincipal[i].cont_estrutura_aux; j++, h++)
				vetorAux[h] = vetorPrincipal[i].vetor_estrutura_auxiliar[j];
				cont = h;}	
	}
	//retorno validação
	if(validador == cont)
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;	
	else{		
		//ordenação valores crescente 
		for(i = 1; i < cont; i++){
			for(j = 0; j < cont; j++)
				//troca de posição de valores
				if(vetorAux[i] < vetorAux[j]){
					aux = vetorAux[i];
					vetorAux[i] = vetorAux[j];
					vetorAux[j] = aux;}
			}
			retorno = SUCESSO;}
	
	return retorno;
}

/*
Objetivo: 
modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Retorno (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
	int retorno = 0;
	int tamanho;
	
	//validação novo tamanho alocação
	if(novoTamanho < 0)
		retorno = NOVO_TAMANHO_INVALIDO;
		//validação de posição que deve ser entre 1 e 10
		else if(ehPosicaoValida(posicao) < SUCESSO)
			retorno = POSICAO_INVALIDA;
		//validação de estrutura auxiliar existente	
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;
		//validação de estrutura auxiliar vazia			
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0 && vetorPrincipal[posicao - 1].tam_max_estrutura_aux > 0)
			retorno = ESTRUTURA_AUXILIAR_VAZIA;
			
	//realocação de memória da estrutura auxiliar
	else{
		tamanho = vetorPrincipal[posicao - 1].tam_max_estrutura_aux + novoTamanho;
		vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar = realloc(vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar, tamanho * sizeof(int));
		//validação realocação de memória
		if(vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar == NULL)
			retorno = SEM_ESPACO_DE_MEMORIA;
		else{
			vetorPrincipal[posicao - 1].tam_max_estrutura_aux = tamanho;
			retorno = SUCESSO;
			free(vetorPrincipal[posicao - 1].vetor_estrutura_auxiliar);}
	}	
	
	return retorno;
}

/*
Objetivo:
retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    POSICAO_INVALIDA - posição inválida
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
	int retorno = 0;
	int tamanho;
	
	//validação de posição que deve ser entre 1 e 10
	if(ehPosicaoValida(posicao) < 0 && ehPosicaoValida(posicao) != -1)
		retorno = POSICAO_INVALIDA;
		//validação de estrutura auxiliar existente	
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;
		//validação de estrutura auxiliar vazia			
		else if(vetorPrincipal[posicao - 1].validador_estrut_aux == 0 && vetorPrincipal[posicao - 1].tam_max_estrutura_aux > 0)
			retorno = ESTRUTURA_AUXILIAR_VAZIA;

	else
			retorno = vetorPrincipal[posicao - 1].cont_estrutura_aux;
	
	return retorno;
}

//no trabalho 02 não é proposto desenvolver uma lista encadeada
/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote

*//*
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

*//*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*//*
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}


*//*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*//*
void destruirListaEncadeadaComCabecote(No **inicio)
{
}
*/

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/
void inicializar(){	
	for(int i = 0; i < TAM; i++){
		vetorPrincipal[i].validador_estrut_aux = 0;
		vetorPrincipal[i].tam_max_estrutura_aux = 0;
		vetorPrincipal[i].cont_estrutura_aux = 0;
		vetorPrincipal[i].vetor_estrutura_auxiliar = NULL;
	}
	printf("\nPrograma iniciado.\n");
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/
void finalizar(){
	for(int i = 0; i < TAM; i++)
		free(vetorPrincipal[i].vetor_estrutura_auxiliar);
	printf("Programa encerrado.");}