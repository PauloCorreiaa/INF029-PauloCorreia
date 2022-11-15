/*
2. Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e exiba o maior endereço.
*/

#include <stdio.h>
#include <stdlib.h>

void linha(char c, int num);

int main(){
	int *var_x, *var_y;

	//impressão linha
	putchar('\n');
	linha('*', 10);
	//impressão endereço variáveis
	printf("\nEndereços:");
	printf("\nvar_x = %x\nvar_y = %x\n", *var_x, *var_y);
	
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