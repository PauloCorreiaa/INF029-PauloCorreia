/*
5. Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores de entrada e retorne o maior valor na primeira variável e o menor valor na segunda variável. Escreva o conteúdo das 2 variáveis na tela.
*/

#include <stdio.h>
#include <stdlib.h>

void linha(char c, int num);
void ordemDecrescente(int *x, int *y);

int main(){
	int var_1, var_2;

	//impressão linha
	putchar('\n');
	linha('*', 8);
	//entrada de valores
	printf("\nvar_1 = ");
	scanf("%d", &var_1);
	printf("var_2 = ");
	scanf("%d", &var_2);
	
	//função troca de valores
	ordemDecrescente(&var_1, &var_2);
	
	//impressão linha
	putchar('\n');
	linha('*', 8);
	//impressão valores pós função troca
	printf("\nvar_1 = %d", var_1);
	printf("\nvar_2 = %d", var_2);
	
	return 0;
}

//funções
//imprimir linha caracteres
void linha(char c, int num){
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);}

//troca valores
void ordemDecrescente(int *x, int *y){
	int tmp;

	if(y > x){		
		tmp = *y;
		*y = *x;
		*x = *y;}
}