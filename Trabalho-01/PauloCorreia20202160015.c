// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Paulo Correia
//  email: paulo.mo.correia@gmail.com
//  Matrícula: 20202160015	
//  Semestre: 2022.2
// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PauloCorreia20202160015.h" 

// ## função utilizada para testes  ##
/*
somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
*/
int somar(int x, int y){
    int soma = x + y;
    return soma;
}

// ## função utilizada para testes  ##
/*
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
*/
int fatorial(int x){ //função utilizada para testes
  int i, fat = 1;    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a){
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

//converter data de string para inteiro
Data_Quebrada quebraData(char data[]){
  Data_Quebrada data_int;
  char sDia[3], sMes[3], sAno[5];
	int i, j;

	//Dia
	for(i = 0; data[i] != '/'; i++)
		sDia[i] = data[i];		
	if(i == 1 || i == 2) // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final		 	
	else{
		data_int.valido = 0;
    return data_int;}  
	
	//Mês
	j = i + 1; //anda 1 cada para pular a barra
	i = 0;
	for(; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';}  // coloca o barra zero no final	
	else{
		data_int.valido = 0;
    return data_int;}

	//Ano
	j += 1; //anda 1 cada para pular a barra
	i = 0;	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;}
	if(i == 2 || i == 4) // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final	
	else{
		data_int.valido = 0;
    return data_int;}
	
	//Conversão em inteiros
	data_int.iDia = atoi(sDia); 
  data_int.iMes = atoi(sMes);	
	data_int.iAno = atoi(sAno);	
	
	data_int.valido = 1;

	return data_int;
}

//imprimir linha caracteres
void linha(char c, int num){
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);}

// Questão 01 #OK#
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês e aaaa = ano. dd e mm podem ter apenas um digito e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    Pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){
  int dataValida;
	Data_Quebrada dataQuebrada;
	
  //converter string em inteiro
  dataQuebrada = quebraData(data);  
	dataValida = dataQuebrada.valido;
	
	//printf("\nDia = %d\nMês = %d\nAno = %d", dataQuebrada.iDia, dataQuebrada.iMes, dataQuebrada.iAno);
	//printf("\nValidador = ");

	//Validações
	if(dataValida < 1) //data inválida			
    return 0;	
	
	//verificar intervalos de dias		
	if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){	
		//verificar intervalos de meses
		if(dataQuebrada.iMes > 0 && dataQuebrada.iMes <= 12){
			//limites dias dos meses
			switch(dataQuebrada.iMes){					
				case 2 :
					if(dataQuebrada.iDia <= 29){
						//limite dias fevereiro e ano bissexto	
						if((dataQuebrada.iAno % 400 == 0) || ((dataQuebrada.iAno % 4 == 0) && (dataQuebrada.iAno % 100 != 0)))
							return 1;
						else{ 
							if(dataQuebrada.iDia == 29)
								return 0;
							else
								//retorno limite dias fevereiro
								return 1;} 
					} 							
					else
						return 0;
					break;
				//limite meses 30 dias
				case 4 :
				case 6 :
				case 9 :
				case 11: 
					if(dataQuebrada.iDia <= 30)
						return 1;
					else
						return 0;
					break;			
				//limite meses 31 dias
				default: 
					if(dataQuebrada.iDia <= 31)
						return 1;
					else
						return 0;
					break;
				//retorno dias dos meses
				return 1;}  
			//retorno meses
			return 1;} 
		
		else
			return 0;
		//retorno dias
		return 1;}
	
	else
		return 0;
}
	
// Questão 02
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]){
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }
		else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }
		else{
      //verifique se a data final não é menor que a data inicial      
      //calcule a distancia entre as datas
      //se tudo der certo
      dma.retorno = 1;
      return dma;      
    }    
}

// Questão 03 #OK#
/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
  int qtdOcorrencias = 0;
	int i;
	char texto_tmp[250], char_tmp;

	strcpy(texto_tmp, texto);
	//Sem Diferenças entre Caixa Caractere		
	if(isCaseSensitive != 1){	
		char_tmp = tolower(c);
		for(i = 0; texto_tmp[i] != '\0'; i++){			
				//Converter Texto Caixa Baixa			
				texto_tmp[i] = tolower(texto_tmp[i]);
				if(texto_tmp[i] == char_tmp)
					qtdOcorrencias++;}
	}
	//Com Diferenças entre Caixa Caractere		
	else{		
		for(i = 0; texto_tmp[i] != '\0'; i++){
			if(texto_tmp[i] == c)		
				qtdOcorrencias++;}
	}	
	//printf("\nTexto saída = %s", texto_tmp);
	//printf("\nCaixa = %d", isCaseSensitive);
	//printf("\nChar = %c", c);	
	//printf("\nOcorrências = %d", qtdOcorrencias);
	printf ("\nValidador = ");
	return qtdOcorrencias;
}	

// Questão 04 #OK#
/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
	int qtdOcorrencias = 0, tam_strBusca;
	int i = 0, j = 0, h = 0; //contadores strTexto, strBusca e posicoes
	int index_strTexto = 0, validador = 1, char_especial, validador_charEspecial = 0;
	int posicao_inicial = 0, posicao_final;	

	//imprimir linha caracteres
	putchar('\n');
	linha('*', 28);
	putchar('\n');
	//retorno entrada e saída
	printf("\nstrTexto = %s", strTexto);
	printf("\nstrBusca = %s", strBusca);	
	printf("\nNº Ocorrências = %d\n", qtdOcorrencias);
	//imprimir linha caracteres
	putchar('\n');
	linha('*', 28);
	putchar('\n');
	
	//tamanho	strBusca
	tam_strBusca = strlen(strBusca) + 1;
	index_strTexto = i;
	
	//percorrer strTexto
	for(i = 0; strTexto[i] != '\0'; i++){
		printf("\nstrTexto[%d]", i);
		printf("\nChar Entrada = %c", strTexto[i]);
		printf("\nChar Busca = %c\n", strBusca[j]);
		
		//validador_charEspecial = 0;
		
		//converter char/int
		char_especial = (int)strTexto[i];
		//verificar caracter especial
		if(char_especial < 0)			
			validador_charEspecial++;
		
		//verificar strBusca
		if(strTexto[i] == strBusca[j]){			
			index_strTexto = i;
			posicao_inicial = i;
			//comparar strBusca/strTexto
			for(validador = 1, j = 0; strBusca[j] != '\0'; j++, index_strTexto++){
				if(strBusca[j] == strTexto[index_strTexto])
					validador++;
				//verificar caracter especial
				if(char_especial < 0)
					validador_charEspecial++;}				
				
				//zerar contador strBusca;
				j = 0;				
				//validar strBusca
				if(validador == tam_strBusca){
					//imprimir linha caracteres
					putchar('\n');
					linha('*', 12);
					putchar('\n');					
					//validar char especial					
					if(validador_charEspecial > 0){						
						//incrementar nº ocorrências
						qtdOcorrencias++;
						printf("\nOcorrência nº %d", qtdOcorrencias);
						//atribuir posição continuidade percorrer strTexto 
						i = index_strTexto - 1;					
						//atribuir posicao inicial strBusca em strTexto
						posicoes[h] = posicao_inicial - 1;						
						printf("\nposicoes[%d] = %d", h, posicoes[h]);
						h++;
						//atribuir posicao final strBusca em strTexto
						posicao_final = (posicao_inicial + tam_strBusca) - 2;
						posicoes[h] = posicao_final - 1;
						printf("\nposicoes[%d] = %d\n", h, posicoes[h]);					
						//incrementar vetor posicoes				
						h++;}						
					else{
						//incrementar nº ocorrências
						qtdOcorrencias++;
						printf("\nOcorrência nº %d", qtdOcorrencias);
						//atribuir posição continuidade percorrer strTexto 
						i = index_strTexto - 1;
						//atribuir posicao inicial strBusca em strTexto
						posicoes[h] = posicao_inicial + 1;											
						printf("\nposicoes[%d] = %d", h, posicoes[h]);
						h++;
						//atribuir posicao final strBusca em strTexto
						posicao_final = posicao_inicial + tam_strBusca;
						posicoes[h] = posicao_final - 1;
						printf("\nposicoes[%d] = %d\n", h, posicoes[h]);
						//incrementar vetor posicoes				
						h++;}
					
					//imprimir linha caracteres
					putchar('\n');
					linha('*', 12);
					putchar('\n');}
			}
		}	
		
	//retorno entrada e saída
	//printf("\nstrTexto = %s", strTexto);
	//printf("\nstrBusca = %s", strBusca);	
	//printf("\nNº Ocorrências = %d\n", qtdOcorrencias);
	//printf("Validador char especial = %d", validador_charEspecial);
	//imprimir linha caracteres
	putchar('\n');
	linha('*', 28);
	putchar('\n');
	//printf ("\nValidadores\n");	
	
	return qtdOcorrencias;
}

// Questão 05 #OK#
/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */
int q5(int num){
	int resto, numInvertido = 0;

	//printf("\nEntrada = %d", num);	
	while(num != 0){		
		resto = num % 10;		
		numInvertido = numInvertido * 10 + resto;
		num /= 10;}
	
	num = numInvertido;
	//printf("\nNúmero invertido = %d", numInvertido);
	//printf("\nValidador = ");
	
	return num;
}

// Questão 06
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int numerobase, int numerobusca){
  int qtdOcorrencias;
	int num, numEntrada, resto;

	num = numerobase;
	while(num != 0){
		resto = num % 10;
		numInvertido = numInvertido * 10 + resto;
		num /= 10;
		if(numerobusca == resto)
			qtdOcorrencias++;
			printf("\nNúmero ocorrências = %d", qtdOcorrencias);	
			printf("\nnum = %d", num);}

	printf("\nValidador = ");
	
   return qtdOcorrencias;
}