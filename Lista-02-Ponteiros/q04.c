/*
4. Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B terá o valor de A.
*/

#include <stdio.h>
#include <stdlib.h>

void linha(char c, int num);
void troca(int *x, int *y);

int main(){
	int var_A, var_B;

	//impressão linha
	putchar('\n');
	linha('*', 8);
	//entrada de valores
	printf("\nvar_A = ");
	scanf("%d", &var_A);
	printf("var_B = ");
	scanf("%d", &var_B);
	
	//função troca de valores
	troca(&var_A, &var_B);
	
	//impressão linha
	putchar('\n');
	linha('*', 8);
	//impressão valores pós função troca
	printf("\nvar_A = %d", var_A);
	printf("\nvar_B = %d", var_B);
	
	return 0;
}

//funções
//imprimir linha caracteres
void linha(char c, int num){
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);}

//troca valores
void troca(int *x, int *y){
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;}
