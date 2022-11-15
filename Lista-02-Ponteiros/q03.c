/*
3. Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.
*/

#include <stdio.h>
#include <stdlib.h>

void linha(char c, int num);

int main(){
	int var_x, var_y;

	//impressão linha
	putchar('\n');
	linha('*', 10);
	//leitura variáveis	
	printf("\nvar_x = ");
	scanf("%d", &var_x);
	printf("\nvar_y = ");
	scanf("%d", &var_y);
	
	//impressão linha
	putchar('\n');
	linha('*', 10);	
	if(&var_x > &var_y)
		printf("\nvar_x > var_y");
	else
		printf("\nvar_x < var_y");
	
	return 0;
}

//funções
//imprimir linha caracteres
void linha(char c, int num){
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);}