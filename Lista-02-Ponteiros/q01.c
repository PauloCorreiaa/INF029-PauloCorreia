/*
1. Escreva um programa que declare um inteiro, um real e um char e ponteiros para inteiro, real e char. Associe as variáveis aos ponteiros (use &).  Modifique os valores de cada variável usando os ponteiros. Imprima os valores das variáveis antes e após a modificação.
*/

#include <stdio.h>
#include <stdlib.h>

void linha(char c, int num);

int main(){
	int *ptr_inteiro, inteiro = 1;
	float *ptr_real, real = 2.5;
	char *ptr_caractere, caractere = 'A';	
	//atribuicao ponteiros/end. variaveis	
	ptr_inteiro = &inteiro;
	ptr_real = &real;
	ptr_caractere = &caractere;
	//impressao linha
	putchar('\n');
	linha('*', 8);
	//impressao variaveis	
	printf("\nInteiro = %d", inteiro);
	printf("\nReal = %.2f", real);
	printf("\nCaractere = %c\n", caractere);
	//atribuicao valores ponteiros
	*ptr_inteiro = 5;
	*ptr_real = 5.5;
	*ptr_caractere = 'C';
	//impressao linha
	putchar('\n');
	linha('*', 8);
	//impressao variaveis pos modifica
	printf("\nInteiro = %d", inteiro);	
	printf("\nReal = %.2f", real);
	printf("\nCaractere = %c", caractere);	
	
	return 0;
}

//funções
//imprimir linha caracteres
void linha(char c, int num){
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);}